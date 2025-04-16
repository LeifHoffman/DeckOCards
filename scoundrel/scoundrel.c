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
 #include <stdbool.h>
 #include "scoundrel.h"
 #include "../main_folder/deck.h"
 #include "../main_folder/card.h"
 #include "../directions/directions.h"

 void play_scoundrel(Deck* deck){

    // Initilize dungeon using proper cards (Excludes red face and ace cards) and needed variables
    char userIn;
    char junk;
    bool hasSkipped = false;
    Deck* dungeon = (Deck*)malloc(sizeof(Deck));
    dungeon->cards = (Card*)malloc(sizeof(Card)*44);
    Card* room = (Card*)malloc(sizeof(Card)*4);
    int dungeonSize = 44;
    int roomSize = 4;
    int curCard = 0;
    int health = 20;
    int weapon = 0;
    int lastDefeated = 0;

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
        scanf("%c", &junk);
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
    
    printf("Now entering dungeon...\n\n");

    // Begin the game
    while (dungeonSize != 0){
        printf("Entering Room...\n\n");

        // Fill room
        if (dungeonSize > 3){
            printf("Filling room...\n");
            room = fillRoom(dungeon, room);
        }
            

        // Print out room
        printRoom(room);

        // Stay in room until three cards are played or room is skipped
        while (roomSize != 1 && hasSkipped == false){

            // Print player's current stats
            printf("Current Health: %d\n", health);
            if (weapon == 0)
                printf("Current Weapon: None\n");
            else{
                printf("Current Weapon: %d\n", weapon);
                if (lastDefeated > 0)
                printf("Last Monster Defeated: %d\n", lastDefeated);
            }
            
            

            // Print Room Actions
            if (roomSize == 4 && hasSkipped == false)
                printf("Choose Action [1 | 2 | 3 | 4 | S]: ");
            else
                printf("Choose Action [1 | 2 | 3 | 4 ]:");

            // Get User Input
            scanf(" %c", &userIn);
            scanf("%c", &junk);

            // Perform Action
            switch (userIn){
                case '1':
                    if (room[0].value == 0){
                        printf("\nThis is already cleared.\n\n");
                    } else {
                        performAction(room, 0, &health, &weapon, &lastDefeated);
                        dungeonSize--;
                        roomSize--;
                    }
                    break;
                case '2':
                    if (room[1].value == 0){
                        printf("\nThis is already cleared.\n\n");
                    } else {
                        performAction(room, 1, &health, &weapon, &lastDefeated);
                        dungeonSize--;
                        roomSize--;
                    }
                    break;
                case '3':
                    if (room[2].value == 0){
                        printf("\nThis is already cleared.\n\n");
                    } else {
                        performAction(room, 2, &health, &weapon, &lastDefeated);
                        dungeonSize--;
                        roomSize--;
                    }
                    break;
                case '4':
                    if (room[3].value == 0){
                        printf("\nThis is already cleared.\n\n");
                    } else {
                        performAction(room, 3, &health, &weapon, &lastDefeated);
                        dungeonSize--;
                        roomSize--;
                    }
                    break;
                case 'S':
                    if (hasSkipped == false){
                        printf("Skipping room...\n\n");
                        hasSkipped = true;
                    } else {
                        printf("You've either started this room or skipped the last one, complete this one to skip again.\n\n");
                    }
                    break;
                default:
                    printf("%c is not an option.\n\n", userIn);
                    break;
            }
        }
        
    }
 }

 // Fill room with cards from the top of the deck
 Card* fillRoom(Deck* dungeon, Card* room){
    for (int i = 0; i < 4; i++){
        if (room[i].value == 0){
            room[i] = dungeon->cards[i];
        }
    }
    return room;
 }

 // Show all possible options for room
 void printRoom(Card* room){
    printf("Current Room Contains:\n\n");
    printf("1: %s of %s\n", room[0].rank, room[0].suit);
    printf("2: %s of %s\n", room[1].rank, room[1].suit);
    printf("3: %s of %s\n", room[2].rank, room[2].suit);
    printf("4: %s of %s\n\n", room[3].rank, room[3].suit);
 }

 // Perform an action based on card selected
 void performAction(Card* room, int action, int* health, int* weapon, int* last){
    char userIn;
    char junk;

    // Handle fighting a monster from Spade or Club cards
    if (!strcmp(room[action].suit, "Spades") || !strcmp(room[action].suit, "Clubs")){
        printf("\nFighting monster %s of %s\n", room[action].rank, room[action].suit);
        if (room[action].value >= (*last)){
            printf("No weapon or weapon dulled! Must fight bare-handed!\n\n");
            *health -= room[action].value;
        } else {
            printf("Fight with weapon? (Y/N): ");
            scanf(" %c", &userIn);
            scanf("%c", &junk);
            if (userIn == 'Y'){
                printf("Fighting with weapon of strength %d!\n\n", *weapon);
                if (room[action].value > *weapon){
                    *health -= room[action].value - *weapon;
                }
            } else {
                printf("Fighting bare-handed!\n\n");
                *health -= room[action].value;
            }
        }
        room[action].value = 0;

    // Handle weapon equipping from Diamond cards
    } else if (!strcmp(room[action].suit, "Diamonds")){
        printf("Equiping weapon of strength %d!\n\n", room[action].value);
        *weapon = room[action].value;
        room[action].value = 0;

    // Handle healing from Heart cards
    } else {
        printf("Found a healing potion of strength %d!\n\n", room[action].value);
        if (*health < (*health)+ (room[action].value)){
            *health = 20;
        } else {
            *health = (*health)+ (room[action].value);
        }
        room[action].value = 0;
    }
 }