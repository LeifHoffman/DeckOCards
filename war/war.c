/****************************
 * File: war.c
 * Purpose: One of three card games available for players
 * Author: Leif Hoffman
 * Date Updated: 4-7-2025
 ****************************/

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include "../main_folder/deck.h"
 #include "../main_folder/card.h"

 void play_war(Deck* deck){
    // Initialize player deck pointers and card count for both sides
    Deck* p1 = (Deck*)malloc(sizeof(Deck));
    p1->cards = (Card*)malloc(32*sizeof(Card));
    Deck* p2 = (Deck*)malloc(sizeof(Deck));
    p2->cards = (Card*)malloc(32*sizeof(Card));
    int p1Cards = 32;
    int p2Cards = 32;
    int p1CurCard = 0;
    int p2CurCard = 0;
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

    while(1){
        printf("Pull a card from deck 1 or 2? (1/2): ");
        scanf("%d", &userChoice);

        switch(userChoice){
            case 1:
                printf("\nFrom pile 1:\nCard: %s of %s\nValue: %d\n\n", p1->cards[p1CurCard].rank, p1->cards[p1CurCard].suit, p1->cards[p1CurCard].value);
                p1CurCard++;
                break;
            case 2:
                printf("\nFrom pile 1:\nCard: %s of %s\nValue: %d\n\n", p2->cards[p2CurCard].rank, p2->cards[p2CurCard].suit, p2->cards[p2CurCard].value);
                p2CurCard++;
                break;
            default:
                printf("Unknown choice, enter again.\n\n");
                break;
        }
    }

 }