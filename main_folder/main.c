/********************************************************************************
 * File: main.c
 * Purpose: This is the main file for deck handling
 * Author: Leif Hoffman
 * Date Updated: 4-5-2025
 ********************************************************************************/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>
 #include <ctype.h>
 #include "card.h"
 #include "deck.h"

 int main(void){

    // Initialize variables, include null deck pointer and player option.
    Deck* deck = NULL;
    int playerChoice;
    

    // Print welcome message
    printf("\n");
    printf("********************************************************\n");
    printf("*                                                      *\n");
    printf("*                   Play Card Games!                   *\n");
    printf("*                                                      *\n");
    printf("*             What would you like to do?               *\n");
    printf("*                                                      *\n");
    printf("********************************************************\n\n");

    // Get user's choice
    while (playerChoice != -1){
        printf(" 1. Test Deck\n 2. Read Rulesets\n 3. Learn About the Programmer\n 4. Exit Program\n\n");
        printf("Choose: ");
        scanf("%d", &playerChoice);
        printf("\n");
        switch (playerChoice){
            // Lets a player test out a deck of 52 cards, can be shuffled and seeded
            case 1:
                printf("Loading test deck...\n\n");
                // Initialize a deck to deck pointer
                deck = init_deck(deck);
                // Run test_deck
                test_deck(deck);
                break;
            case 2:
                //TODO Implement rulesets for available games, will likely be moved to be included in each game
                printf("Nothing here yet. Check back later!\n\n");
                break;
            case 3:
                //TODO Not really needed, but explains a bit about me :P
                printf("Nothing here yet. Check back later!\n\n");
                break;
            // Exits program
            case 4:
                printf("Exiting program...have a good day!\n");
                playerChoice = -1;
                break;
            default:
                printf("Choice not available, please enter again.\n\n");
                break;
        }
    }
    
    free(deck);

    return 0;
 }