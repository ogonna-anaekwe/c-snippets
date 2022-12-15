#ifndef __shuffle_h__
#define __shuffle_h__

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Struct for card. Each card has two fields: suit and rank.
 *
 */
typedef struct card
{
    int suit;
    int rank;
} card;

/**
 * @brief Create a deck of cards. This deck contains 52 cards.
 *
 * @param deck Array of structs. Each struct is a card. Each card has two fields: suit and rank.
 * @param num_suits Number of suits in a deck (4): clubs, diamonds, spades, hearts.
 * @param num_ranks Number of ranks for each suit (13): ace, 2-10, jack, queen, king.
 */
void create_deck(card deck[], int num_suits, int num_ranks);

/**
 * @brief Generates (pseudo-)random number between low and high (both inclusive).
 *
 * @param low Lower bound for random number.
 * @param high Upper bound for random number.
 * @return int - Random number generated.
 */
int random_int(int low, int high);

/**
 * @brief Swaps particular card with randomly selected card.
 *
 * @param deck Array of structs. Each struct is a card. Each card has two fields: suit and rank.
 * @param card_idx Index of particular card to be swapped.
 * @param swap_card_idx Index of random card to be swapped with a particular card.
 */
void swap_cards(card deck[], int card_idx, int swap_card_idx);

/**
 * @brief Shuffles deck of cards.
 *
 * @param deck Array of structs. Each struct is a card. Each card has two fields: suit and rank.
 * @param total_cards Total number of cards in deck (52).
 */
void shuffle_deck(card deck[], int total_cards);

/**
 * @brief Prints deck of cards.
 *
 * @param deck Array of structs. Each struct is a card. Each card has two fields: suit and rank.
 * @param total_cards Total number of cards in deck (52).
 * @param suits Total number of suits (4).
 * @param ranks Total number of ranks (13).
 */
void print_deck(card deck[], int total_cards, const char *suits[], const char *ranks[]);

#endif // __shuffle_h__
