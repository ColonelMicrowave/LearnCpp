#include <iostream>
#include <cassert>
#include <algorithm>
#include <array>
#include "Random.h"

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

int main()
{
	Deck deck{};
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	deck.shuffle();
	std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

	return 0;
}
