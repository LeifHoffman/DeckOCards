/*************************************************************
 * File: card.h
 * Purpose: Header file to include card struct and functions
 * Author: Leif Hoffman
 * Date Updated: 4-2-2025
 *************************************************************/

#ifndef CARD_H
#define CARD_H

 // Define card struct, which has a rank, suit, and value associated to it.
typedef struct Card_struct{
    char rank[6];
    char suit[9];
    int value;
} Card;

void readRank(Card* card, char r[]);
void readSuit(Card* card, char s[]);
void readValue(Card* card, int v);

#endif // CARD_H