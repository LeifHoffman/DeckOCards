/****************************
 * File: war.h
 * Purpose: A header files which holds functions found in war.c
 * Author: Leif Hoffman
 * Date Updated: 4-7-2025
 ****************************/

 #ifndef WAR_H
 #define WAR_H

 #include "../main_folder/deck.h"
 #include "../main_folder/card.h"
 #include "../directions/directions.h"

 void play_war(Deck* deck);
 void addCards(Card* playerHoldDeck, int* cardsHeld, Card* heldDeck, int* holdAmt);
 Card* refillDeck(Card* pDeck, Card* pHoldDeck, int deckSize, int* curDeck);

 #endif // WAR_H