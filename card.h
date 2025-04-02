/*************************************************************
 * Purpose: Header file to include card struct and functions
 * Author: Leif Hoffman
 * Date Updated: 4-2-2025
 *************************************************************/

 // Define card struct, which has a rank, suit, and value associated to it.
typedef struct Card_struct{
    char rank;
    char suit;
    int value;
} Card;

void readRank(Card* c, char r);
void readSuit(Card* c, char s);
void readValue(Card* c, int v);