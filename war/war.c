/****************************
 * File: war.c
 * Purpose: One of three card games available for players
 * Author: Leif Hoffman
 * Date Updated: 4-7-2025
 ****************************/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <ctype.h>
 #include "../main_folder/deck.h"
 #include "../main_folder/card.h"
 #include "../directions/directions.h"

 void play_war(Deck* deck){
    // Initialize player deck pointers and card count for both sides
    Deck* p1 = (Deck*)malloc(sizeof(Deck));
    p1->cards = (Card*)malloc(32*sizeof(Card));
    Deck* p2 = (Deck*)malloc(sizeof(Deck));
    p2->cards = (Card*)malloc(32*sizeof(Card));
    int p1Cards = 26;
    int p2Cards = 26;
    int p1CurCard = 0;
    int p2CurCard = 0;
    char userIn;
    // Define variable for testing purposes
    int userChoice;

    // Shuffle cards in main deck
    srand(time(NULL));
    shuffle(deck, rand(), 52);

    // Split deck into two piles of cards
    for (int i=0; i<52; i++){
        if (i%2)
            p1->cards[i/2] = deck->cards[i];
        else
            p2->cards[i/2] = deck->cards[i];
    }

    // Offer game explanation
    while (1){
        printf("Would you like to read the rules of the game? (Y/N): ");
        scanf(" %c", &userIn);
        if (toupper(userIn) == 'Y'){
            printf("\n");
            read_war_rules();
            printf("\n");
            break;
        } else if (toupper(userIn) == 'N'){
            printf("\n");
            break;
        }else
            printf("Error: Input not found, please try again.\n\n");
    }

    // Pull from one of two piles
    while(1){
        printf("Pull a card from deck 1 or 2? (1/2): ");
        scanf("%d", &userChoice);

        switch(userChoice){
            case 1:
                printf("\nFrom pile 1:\nCard: %s of %s\nValue: %d\n\n", p1->cards[p1CurCard].rank, p1->cards[p1CurCard].suit, p1->cards[p1CurCard].value);
                p1CurCard++;
                if (p1CurCard == p1Cards){
                    printf("Pile empty! Reshuffling available cards...\n\n");
                    shuffle(p1, rand(), p1Cards);
                    p1CurCard = 0;
                }
                break;
            case 2:
                printf("\nFrom pile 2:\nCard: %s of %s\nValue: %d\n\n", p2->cards[p2CurCard].rank, p2->cards[p2CurCard].suit, p2->cards[p2CurCard].value);
                p2CurCard++;
                if (p2CurCard == p2Cards){
                    printf("Pile empty! Reshuffling available cards...\n\n");
                    shuffle(p2, rand(), p2Cards);
                    p2CurCard = 0;
                }
                break;
            default:
                printf("Unknown choice, enter again.\n\n");
                break;
        }
    }

 }