#include <iostream>
#include <cassert>
#include <algorithm>
#include <array>
#include <limits>
#include "Random.h"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
namespace Settings
{
	int bust{ 21 };
	int dealerStopsAt{ 17 };
}

struct Card
{
	enum Rank
	{
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,
		max_ranks
	};

	enum Suit
	{
		suit_club,
		suit_diamond,
		suit_heart,
		suit_spade,
		max_suits
	};

	static constexpr std::array<Rank, max_ranks> allRanks{ 
		rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, 
		rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king 
	};

	static constexpr std::array<Suit, max_suits> allSuits{
		suit_club, suit_diamond, suit_heart, suit_spade
	};

	Rank rank{};
	Suit suit{};

	friend std::ostream& operator<<(std::ostream& out, const Card& card)
	{
		static constexpr std::array<char, max_ranks> rankInitial{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
		static constexpr std::array<char, max_suits> suitInitial{ 'C', 'D', 'H', 'S' };

		out << rankInitial[card.rank] << suitInitial[card.suit];
		return out;
	}

	int cardValue() const
	{
		static constexpr std::array<int, max_ranks> rankValue{ 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

		return rankValue[rank];
	}
};

class Deck
{
private:
	std::array<Card, 52> m_cards{};
	std::size_t m_nextCardIndex{};

public:
	Deck()
	{
		std::size_t count{ 0 };
		for (auto suit : Card::allSuits)
		{
			for (auto rank : Card::allRanks)
			{
				m_cards[count++] = Card{ rank, suit };
			}
		}
	}

	void shuffle()
	{
		m_nextCardIndex = 0;
		std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
	}

	Card dealCard()
	{
		assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
		return m_cards[m_nextCardIndex++];
	}
};

class Player
{
private:
	int m_score{};
	int m_numOf11Aces{ 0 };

public:
	void addToScore(Card card)
	{
		m_score += card.cardValue();

		if (card.rank == Card::rank_ace)
		{
			++m_numOf11Aces;
		}

		consumeAces();
	}

	void consumeAces()
	{
		while (m_score > Settings::bust && m_numOf11Aces > 0)
		{
			m_score -= 10;
			--m_numOf11Aces;
		}
	}

	int getScore() { return m_score; }
};

bool playerHit()
{
	while (true)
	{
		std::cout << "(h) to hit, or (s) to stand: ";
		char choice{};
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input.\n\n";

			continue;
		}

		ignoreLine();

		switch (choice)
		{
		case 'h':
			return true;
		case 's':
			return false;
		default:
			std::cout << "Invalid input.\n\n";
		}
	}
}

bool playerTurn(Deck& deck, Player& player)
{
	while (playerHit())
	{
		Card card{ deck.dealCard() };
		player.addToScore(card);

		std::cout << "You were dealt " << card << ". You now have: " << player.getScore() << '\n';

		if (player.getScore() > Settings::bust)
		{
			std::cout << "You went bust!\n";
			return true;
		}
	}

	return false;
}

bool dealerTurn(Deck& deck, Player& dealer)
{
	while (dealer.getScore() < Settings::dealerStopsAt)
	{
		Card card{ deck.dealCard() };
		dealer.addToScore(card);

		std::cout << "The dealer flips a " << card << ". They now have: " << dealer.getScore() << '\n';
	}

	if (dealer.getScore() > Settings::bust)
	{
		std::cout << "The dealer went bust!\n";
		return true;
	}

	return false;
}

enum class Result
{
	win,
	loss,
	draw
};

Result playBlackjack()
{
	Deck deck{};
	deck.shuffle();

	Player dealer{};
	Player player{};

	Card dealerCard{ deck.dealCard() };
	dealer.addToScore(dealerCard);

	std::cout << "The dealer is showing " << dealerCard << " (" << dealer.getScore() << ")\n";

	Card playerCard1{ deck.dealCard() };
	Card playerCard2{ deck.dealCard() };
	player.addToScore(playerCard1);
	player.addToScore(playerCard2);

	std::cout << "You are showing " << playerCard1 << ' ' << playerCard2 << " (" << player.getScore() << ")\n";

	if (playerTurn(deck, player))
	{
		return Result::loss;
	}

	if (dealerTurn(deck, dealer))
	{
		return Result::win;
	}

	if (player.getScore() > dealer.getScore())
		return Result::win;
	else if (player.getScore() < dealer.getScore())
		return Result::loss;
	else
		return Result::draw;
}

bool playAgain()
{
	std::cout << "Would you like to play again? (y/n): ";

	while (true)
	{
		char choice{};
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Try again: ";

			continue;
		}

		ignoreLine();

		switch (choice)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << "Invalid input. Try again: ";
		}
	}
}

int main()
{
	do
	{
		switch (playBlackjack())
		{
		case Result::win:
			std::cout << "You win!\n";
			break;
		case Result::loss:
			std::cout << "You lose!\n";
			break;
		case Result::draw:
			std::cout << "You draw!\n";
			break;
		default:
			std::cout << "How have you done this???\n";
			break;
		}
	} while (playAgain());

	return 0;
}
