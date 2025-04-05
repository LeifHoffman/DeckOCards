/********************************************************************************
 * File: deck.h
 * Purpose: This is the header file for function definitions and struct for deck
 * Author: Leif Hoffman
 * Date Updated: 4-2-2025
 ********************************************************************************/

 #ifndef DECK_H
 #define DECK_H

 #include "card.h"

 // Define Deck struct including 52 cards
typedef struct Deck_struct{
    Card card[52];
} Deck;

// Construct standard deck
void init_deck(Deck* d);
void test_deck(Deck* d);
void pull(Deck* d, int index);
void pullRemove(Deck* d, int removed[], int index);
void shuffle(Deck* d, int seed);
#endif // DECK_H