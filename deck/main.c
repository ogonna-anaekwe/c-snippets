#include "shuffle.h"

/**
 * @brief Creates a deck of cards, shuffles the deck, and prints it.
 * To use, run the following:
 * 1. make
 * 2. ./shuffle
 * @return int
 */
int main(void)
{
    const char *suits[] = {"Clubs", "Diamonds", "Spades", "Hearts"},
               *ranks[] = {(char *)0, "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    int num_suits = sizeof(suits) / sizeof(suits[0]),
        num_ranks = (sizeof(ranks) - 1) / sizeof(ranks[0]),
        total_cards = num_suits * num_ranks;

    card deck[total_cards];

    create_deck(deck, num_suits, num_ranks);
    shuffle_deck(deck, total_cards);
    print_deck(deck, total_cards, ranks, suits);

    return 0;
}
