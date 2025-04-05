/*************************************************************
 * File: card.c
 * Purpose: Card file which holds functions to set cards
 * Author: Leif Hoffman
 * Date Updated: 4-2-2025
 *************************************************************/

#include <string.h>
#include "card.h"

// Initializes card rank
void readRank(Card* card, char r[]){
    strcpy(card->rank, r);
}

// Initializes card suit
void readSuit(Card* card, char s[]){
    strcpy(card->suit, s);
}

// Initializes card value
void readValue(Card* card, int v){
    card->value = v;
}