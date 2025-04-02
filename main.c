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
    int discard[52];
    char playerIn;
    int randNum;

    init_deck(&deck);

    // Confirm if deck is seeded or "unseeded" (random based on time)
    while (1){
        printf("Would you like to seed deck pulls? (Y/N): ");
        scanf(" %c", &playerIn);
        printf("\n");
        if (toupper(playerIn) == 'Y'){
        printf("Enter seed: ");
        scanf("%d", &randNum);
        printf("\n");
        break;
        } else if (toupper(playerIn) == 'N'){
            randNum = time(NULL);
            break;
        }
    else
        printf("Error: Response unknown, enter again\n\n");
    }

    srand(randNum);

    while (1){
        printf("Pull a card? (Y/N): ");
        scanf(" %c", &playerIn);
        if (toupper(playerIn) == 'Y' ){
            pull(&deck, rand()%52);
        }
        else if (toupper(playerIn) == 'N')
            break;
        else
            printf("Error: Input not found, try again\n\n");
    }
    

    return 0;
 }