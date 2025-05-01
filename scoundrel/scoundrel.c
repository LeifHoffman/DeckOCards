/****************************
 * File: scoundrel.c
 * Purpose: One of two card games available for players (Scoundrel)
 * Author: Leif Hoffman
 * Date Updated: 4-21-2025
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
    bool skipped = false;
    bool hasSkipped = false;
    bool originalRules = true;
    bool canHeal = true;
    Deck* dungeon = (Deck*)calloc(1, sizeof(Deck));
    dungeon->cards = (Card*)calloc(44, sizeof(Card));
    Card* room = (Card*)calloc(4, sizeof(Card));
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
    curCard = 0;

    // Shuffle deck
    srand(time(NULL));
    shuffle(dungeon, rand(), dungeonSize);

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

    // Give option to enable same room healing (modified game) or discard additional health potions found in room (original ruleset)
    while (1){
        printf("Would you like to have same room healing enabled? (Y/N): ");
        scanf(" %c", &userIn);
        scanf("%c", &junk);
        if (toupper(userIn) == 'Y'){
            originalRules = false;
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
        printf("Filling room...\n");
        roomSize = 4;
        room = fillRoom(dungeon, room, &curCard);

        // Enable healing for room
        canHeal = true;
            
        // Check if previous room was skipped, set flag if true
        if (skipped == true){
            hasSkipped = true;
            skipped = false;
        }

        // Stay in room until three cards are played, room is skipped, or health reaches zero
        while (roomSize != 1 && health > 0 && dungeonSize != 0){

            // Print out room
            printRoom(room);

            // Print player's current stats
            printf("Current Health: %d\n", health);
            if (weapon == 0)
                printf("Current Weapon: None\n");
            else{
                printf("Current Weapon: %d\n", weapon);
                if (lastDefeated > 0)
                printf("Last Monster Defeated: %d\n", lastDefeated);
            }
            printf("Remaining dungeon encounters: %d\n", dungeonSize);
            

            // Print Room Actions
            if (roomSize == 4 && hasSkipped == false)
                printf("Choose Action [1 | 2 | 3 | 4 | S]: ");
            else
                printf("Choose Action [1 | 2 | 3 | 4]: ");

            // Get User Input
            scanf(" %c", &userIn);
            scanf("%c", &junk);

            // Perform Action
            switch (userIn){
                case '1':
                    if (room[0].value == 0){
                        printf("\nThis is already cleared.\n\n");
                    } else {
                        performAction(room, 0, &health, &weapon, &lastDefeated, originalRules, &canHeal);
                        dungeonSize--;
                        roomSize--;
                    }
                    break;
                case '2':
                    if (room[1].value == 0){
                        printf("\nThis is already cleared.\n\n");
                    } else {
                        performAction(room, 1, &health, &weapon, &lastDefeated, originalRules, &canHeal);
                        dungeonSize--;
                        roomSize--;
                    }
                    break;
                case '3':
                    if (room[2].value == 0){
                        printf("\nThis is already cleared.\n\n");
                    } else {
                        performAction(room, 2, &health, &weapon, &lastDefeated, originalRules, &canHeal);
                        dungeonSize--;
                        roomSize--;
                    }
                    break;
                case '4':
                    if (room[3].value == 0){
                        printf("\nThis is already cleared.\n\n");
                    } else {
                        performAction(room, 3, &health, &weapon, &lastDefeated, originalRules, &canHeal);
                        dungeonSize--;
                        roomSize--;
                    }
                    break;
                case 'S':
                    if (hasSkipped == false && roomSize == 4){
                        printf("Skipping room...\n\n");
                        skipped = true;
                        skipRoom(dungeon, room, dungeonSize, &curCard);
                    } else {
                        printf("Unable to skip, complete this one to skip again.\n\n");
                    }
                    break;
                //Cheating tool for testing end of game functionality
                // case '~':
                //     printf("Cheating past room...\n\n");
                //     room[0].value = 0;
                //     room[1].value = 0;
                //     room[2].value = 0;
                //     dungeonSize -= 3;
                //     roomSize -= 3;
                //     break;
                default:
                    printf("%c is not an option.\n\n", userIn);
                    break;
            }
            if (skipped == true){
                break;
            }
        }


        if (health <= 0){
            printf("Health reached zero! You lost!\n\n");
            free(dungeon->cards);
            dungeon->cards = NULL;
            free(dungeon);
            dungeon = NULL;
            free(room);
            room = NULL;
            return;
        }
        else if (roomSize == 1){
            printf("Room Cleared!\n\n");
            hasSkipped = false;
        }
        
        
    }

    printf("You successfully made it through the dungeon! You won the game of Scoundrel!\n\n");
    free(dungeon->cards);
    dungeon->cards = NULL;
    free(dungeon);
    dungeon = NULL;
    free(room);
    room = NULL;
    return;
 }

 // Fill room with cards from the top of the deck
 Card* fillRoom(Deck* dungeon, Card* room, int* card){
    for (int i = 0; i < 4; i++){
        if (room[i].value == 0 && (*card) < 44){
            room[i] = dungeon->cards[*card];
            (*card)++;
        }
    }
    return room;
 }

 // Show all possible options for room
 void printRoom(Card* room){
    printf("Current Room Contains:\n\n");
    if (room[0].value != 0)
        printf("1: %s of %s\n", room[0].rank, room[0].suit);
    else
        printf("1: Cleared!\n");

    if (room[1].value != 0)
        printf("2: %s of %s\n", room[1].rank, room[1].suit);
    else
        printf("2: Cleared!\n");

    if (room[2].value != 0)    
        printf("3: %s of %s\n", room[2].rank, room[2].suit);
    else
        printf("3: Cleared!\n");

    if (room[3].value != 0)
        printf("4: %s of %s\n\n", room[3].rank, room[3].suit);
    else
        printf("4: Cleared!\n\n");
 }

 // Handle skipping room
 void skipRoom(Deck* dungeon, Card* room, int dSize, int* card){
    // Push back curCard by four
    *card -= 4;
    // Move cards to front of dungeon
    for (int i = 0; i < dSize-4; i++){
        dungeon->cards[(*card)+i] = dungeon->cards[(*card)+i+4];
    }
    // Set room to back of dungeon if there's space
    if (dSize >= 4)
        for (int i = 0; i < 4; i++){
            dungeon->cards[40+i] = room[i];
    }
    // Clear room
    for (int i = 0; i < 4; i++)
        room[i].value = 0;
    
 }

 // Perform an action based on card selected
 void performAction(Card* room, int action, int* health, int* weapon, int* last, bool origRules, bool* healing){
    char userIn;
    char junk;

    // Handle fighting a monster from Spade or Club cards
    if (!strcmp(room[action].suit, "Spades") || !strcmp(room[action].suit, "Clubs")){
        printf("\nFighting monster %s of %s\n", room[action].rank, room[action].suit);
        // Force lastDefeated to be a large value rather than zero when it starts at zero
        if ((*last == 0))
            *last = 20;
        if (room[action].value >= (*last) || (*weapon) == 0){
            printf("No weapon or weapon dulled! Must fight bare-handed!\n\n");
            *health -= room[action].value;
        } else {
            printf("Fight with weapon? (Y/N): ");
            scanf(" %c", &userIn);
            scanf("%c", &junk);
            if (toupper(userIn) == 'Y'){
                printf("Fighting with weapon of strength %d!\n\n", *weapon);
                if (room[action].value > *weapon){
                    *health -= room[action].value - *weapon;
                }
                *last = room[action].value;
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
        *last = 0;
        room[action].value = 0;

    // Handle healing from Heart cards
    } else {
        printf("Found a healing potion of strength %d!\n\n", room[action].value);
        if (origRules == false){
            if (20 < (*health) + (room[action].value)){
                *health = 20;
            } else {
                *health = (*health)+ (room[action].value);
            }
        }
        else
            if (*healing == true){
                if (20 < (*health) + (room[action].value)){
                    *health = 20;
                } else {
                    *health = (*health)+ (room[action].value);
                }
                *healing = false;
            } 
            else
                printf("Unfortunately, you already healing this room, discarding potion.\n\n");
        room[action].value = 0;
    }
 }