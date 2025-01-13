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

struct Player
{
	int score{};
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
		player.score += card.cardValue();

		std::cout << "You were dealt " << card << ". You now have: " << player.score << '\n';

		if (player.score > Settings::bust)
		{
			std::cout << "You went bust!\n";
			return true;
		}
	}

	return false;
}

bool dealerTurn(Deck& deck, Player& dealer)
{
	while (dealer.score < Settings::dealerStopsAt)
	{
		Card card{ deck.dealCard() };
		dealer.score += card.cardValue();

		std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score << '\n';
	}

	if (dealer.score > Settings::bust)
	{
		std::cout << "The dealer went bust!\n";
		return true;
	}

	return false;
}

bool playBlackjack()
{
	Deck deck{};
	deck.shuffle();

	Player dealer{ deck.dealCard().cardValue() };

	std::cout << "The dealer is showing: " << dealer.score << '\n';

	Player player{ deck.dealCard().cardValue() + deck.dealCard().cardValue() };

	std::cout << "You have score: " << player.score << '\n';

	if (playerTurn(deck, player))
	{
		return false;
	}

	if (dealerTurn(deck, dealer))
	{
		return true;
	}

	return (player.score > dealer.score);
}

int main()
{
	if (playBlackjack())
	{
		std::cout << "You win!\n";
	}
	else
	{
		std::cout << "You lose!\n";
	}

	return 0;
}
