/****************************
 * File: scoundrel.h
 * Purpose: A header files which holds functions found in scoundrel.c
 * Author: Leif Hoffman
 * Date Updated: 4-14-2025
 ****************************/

 #ifndef SCOUNDREL_H
 #define SCOUNDREL_H

 #include "../main_folder/deck.h"
 #include "../main_folder/card.h"
 #include "../directions/directions.h"

 void play_scoundrel(Deck* deck);
 Card* fillRoom(Deck* dungeon, Card* room);
 void printRoom(Card* room);
 void performAction(Card* room, int action, int* health, int* weapon, int* last);

 #endif // SCOUNDREL_H