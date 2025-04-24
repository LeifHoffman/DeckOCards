/****************************
 * File: scoundrel.h
 * Purpose: A header files which holds functions found in scoundrel.c
 * Author: Leif Hoffman
 * Date Updated: 4-17-2025
 ****************************/

 #ifndef SCOUNDREL_H
 #define SCOUNDREL_H

 #include <stdbool.h>
 #include "../main_folder/deck.h"
 #include "../main_folder/card.h"
 #include "../directions/directions.h"

 void play_scoundrel(Deck* deck);
 Card* fillRoom(Deck* dungeon, Card* room, int* card);
 void printRoom(Card* room);
 void skipRoom(Deck* dungeon, Card* room, int dSize, int* card);
 void performAction(Card* room, int action, int* health, int* weapon, int* last, bool origRules, bool* healing);

 #endif // SCOUNDREL_H