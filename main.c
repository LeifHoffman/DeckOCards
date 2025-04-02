/********************************************************************************
 * File: main.c
 * Purpose: This is the main file for deck handling
 * Author: Leif Hoffman
 * Date Updated: 4-2-2025
 ********************************************************************************/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>
 #include <ctype.h>
 #include "card.h"
 #include "deck.h"

 int main(void){

    Deck deck;
    char playerIn;
    int randNum;

    init_deck(&deck);
    srand(time(NULL));

    while (1){
        printf("Pull a card? (Y/N): ");
        randNum = rand();
        scanf(" %c", &playerIn);
        if (toupper(playerIn) == 'Y' )
            pull_card(&deck, randNum%52);
        else if (toupper(playerIn) == 'N')
            break;
        else
            printf("Error: Input not found, try again\n\n");
    }
    

    return 0;
 }