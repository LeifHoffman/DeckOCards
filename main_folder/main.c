/********************************************************************************
 * File: main.c
 * Purpose: This is the main file for deck handling
 * Author: Leif Hoffman
 * Date Updated: 4-21-2025
 ********************************************************************************/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string.h>
 #include <ctype.h>
 #include "card.h"
 #include "deck.h"
 #include "../war/war.h"
 #include "../scoundrel/scoundrel.h"

 int main(void){

    // Initialize variables, include null deck pointer and player option.
    Deck* deck = NULL;
    int playerChoice;
    char playerIn;
    char junk;

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
        printf(" 1. Play War\n 2. Play Scoundrel\n 3. Test Deck\n 4. Read Rulesets\n 5. Exit Program\n\n");
        printf("Choose: ");
        scanf("%d", &playerChoice);
        printf("\n");
        switch (playerChoice){

            case 1:
                printf("Loading War...\n\n");
                // Initialize playing deck
                deck = init_deck(deck);
                // Play game with created deck
                play_war(deck);
                // Free cards and deck afterwards
                free(deck->cards);
                free(deck);
                break;

            // Plays Scoundrel
            case 2:
                printf("Loading Scoundrel...\n\n");
                // Initialize playing deck
                deck = init_deck(deck);
                // Play game with created deck
                play_scoundrel(deck);
                // Free cards and deck afterwards;
                free(deck->cards);
                free(deck);
                break;
            
            case 3:
                // Lets a player test out a deck of 52 cards, can be shuffled and seeded
                printf("Loading test deck...\n\n");
                // Initialize a deck to deck pointer
                deck = init_deck(deck);
                // Run test_deck
                test_deck(deck);
                // Free memory allocation
                free(deck->cards);
                free(deck);
                break;

            case 4:
                // Allows players to read a chosen ruleset
                playerIn = ' ';
                scanf("%c", &junk);
                while(toupper(playerIn) != 'A' && toupper(playerIn) != 'B'){
                    printf("Choose a ruleset to read: \n");
                    printf("A. War\n");
                    printf("B. Scoundrel\n\n");
                    printf("Choose: ");
                    scanf("%c", &playerIn);
                    scanf("%c", &junk);
                    switch(toupper(playerIn)){
                        case 'A':
                            read_war_rules();
                            printf("\n");
                            break;
                        case 'B':
                            read_scoundrel_rules();
                            printf("\n");
                            break;
                        default:
                            printf("Entry unknown, please try again.\n\n");
                            break;
                    }
                }
                break;

            // Exits program
            case 5:
                printf("Exiting program...have a good day!\n");
                playerChoice = -1;
                break;

            default:
                printf("Choice not available, please enter again.\n\n");
                playerChoice = 0;
                break;
        }
    }

    return 0;
 }