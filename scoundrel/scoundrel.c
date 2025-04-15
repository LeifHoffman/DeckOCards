/****************************
 * File: scoundrel.c
 * Purpose: One of two card games available for players (Scoundrel)
 * Author: Leif Hoffman
 * Date Updated: 4-14-2025
 ****************************/

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <time.h>
 #include <ctype.h>
 #include "scoundrel.h"
 #include "../main_folder/deck.h"
 #include "../main_folder/card.h"
 #include "../directions/directions.h"

 void play_scoundrel(Deck* deck){

    // Initilize dungeon using proper cards (Excludes red face and ace cards)
    char userIn;
    Deck* dungeon = (Deck*)malloc(sizeof(Deck));
    dungeon->cards = (Card*)malloc(sizeof(Card)*44);
    int curCard = 0;

    // Set up deck
    for (int i = 0; i < 52; i++){
        if (!(i%2 && deck->cards[i].value > 10)){
            dungeon->cards[curCard] = deck->cards[i];
            curCard++;
        }
    }

    // Shuffle deck
    srand(time(NULL));
    shuffle(dungeon, rand(), 44);

    // Offer game explanation
    while (1){
        printf("Would you like to read the rules of the game? (Y/N): ");
        scanf(" %c", &userIn);
        if (toupper(userIn) == 'Y'){
            printf("\n");
            read_scoundrel_rules();
            printf("\n");
            break;
        } else if (toupper(userIn) == 'N'){
            printf("\n");
            break;
        }else
            printf("Error: Input not found, please try again.\n\n");
    }
    
 }