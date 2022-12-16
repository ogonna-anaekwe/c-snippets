#include "shuffle.h"

void create_deck(card deck[], int num_suits, int num_ranks)
{
    int card_idx = 0;

    for (int suit = 0; suit < num_suits; suit++)
    {
        for (int rank = 1; rank <= num_ranks; rank++)
        {
            deck[card_idx].suit = suit;
            deck[card_idx].rank = rank;
            card_idx++;
        }
    }
}

int random_int(int low, int high)
{
    srand(time(NULL));
    return (rand() % (high - low)) + low;
}

void swap_cards(card deck[], int card_idx, int swap_card_idx)
{
    card tmp_card;
    tmp_card.suit = deck[swap_card_idx].suit;
    tmp_card.rank = deck[swap_card_idx].rank;

    deck[swap_card_idx].suit = deck[card_idx].suit;
    deck[swap_card_idx].rank = deck[card_idx].rank;

    deck[card_idx].suit = tmp_card.suit;
    deck[card_idx].rank = tmp_card.rank;
}

void shuffle_deck(card deck[], int total_cards)
{
    for (int card_idx = 0; card_idx < total_cards; card_idx++)
    {
        int swap_card_idx = random_int(card_idx, total_cards);
        swap_cards(deck, card_idx, swap_card_idx);
    }
}

void print_deck(card deck[], int total_cards, const char *ranks[], const char *suits[])
{
    int rank_idx = 0,
        suit_idx = 0;
    ptrdiff_t card_idx;
    card *first_card = deck,
         *last_card = deck + total_cards - 1;

    for (card *curr_card = first_card; curr_card <= last_card; curr_card++)
    {
        card_idx = curr_card - first_card;
        rank_idx = deck[card_idx].rank;
        suit_idx = deck[card_idx].suit;
        printf("%s of %s\n", ranks[rank_idx], suits[suit_idx]);
    }
}
