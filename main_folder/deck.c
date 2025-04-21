/********************************************************************************
 * File: deck.c
 * Purpose: This file that handles functions found in deck.h
 * Author: Leif Hoffman
 * Date Updated: 4-21-2025
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "card.h"
#include "deck.h"

// Construct standard deck for testing
Deck* init_deck(Deck* d){
    d = (Deck*)calloc(1, sizeof(Deck));
    d->cards = (Card*)calloc(52, sizeof(Card));
    for (int i = 0; i < 52; i++){
        // Set rank (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K) and value four at a time (i.e. A,A,A,A,2,2,2,2...)
        switch (i/4){
            case 0:
                readRank(&d->cards[i], "Ace");
                // Starts as Aces High
                readValue(&d->cards[i], 14);
                break;
            case 1:
                readRank(&d->cards[i], "2");
                readValue(&d->cards[i], 2);
                break;
            case 2:
                readRank(&d->cards[i], "3");
                readValue(&d->cards[i], 3);
                break;
            case 3:
                readRank(&d->cards[i], "4");
                readValue(&d->cards[i], 4);
                break;
            case 4:
                readRank(&d->cards[i], "5");
                readValue(&d->cards[i], 5);
                break;
            case 5:
                readRank(&d->cards[i], "6");
                readValue(&d->cards[i], 6);
                break;
            case 6:
                readRank(&d->cards[i], "7");
                readValue(&d->cards[i], 7);
                break;
            case 7:
                readRank(&d->cards[i], "8");
                readValue(&d->cards[i], 8);
                break;
            case 8:
                readRank(&d->cards[i], "9");
                readValue(&d->cards[i], 9);
                break;
            case 9:
                readRank(&d->cards[i], "10");
                readValue(&d->cards[i], 10);
                break;
            case 10:
                readRank(&d->cards[i], "Jack");
                readValue(&d->cards[i], 11);
                break;
            case 11:
                readRank(&d->cards[i], "Queen");
                readValue(&d->cards[i], 12);
                break;
            default:
                readRank(&d->cards[i], "King");
                readValue(&d->cards[i], 13);
                break;
        }

        // Read suit (Spade, Heart, Club, Diamond) one at a time (i.e. S,H,C,D,S...)
        switch (i%4){
            case 0:
                readSuit(&d->cards[i], "Spades");
                break;
            case 1:
                readSuit(&d->cards[i], "Hearts");
                break;
            case 2:
                readSuit(&d->cards[i], "Clubs");
                break;
            default:
                readSuit(&d->cards[i], "Diamonds");
                break;
        }
    }

    return d;
}

// Test a deck with standard cards pulls going from top to bottom of deck, can be shuffled with a set seed.
void test_deck(Deck* d){
    char playerIn;
    int randNum;
    int curcards = 0;
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

    // Confirm a shuffle
    while (1){
        printf("Would you like shuffle? (Y/N): ");
        scanf(" %c", &playerIn);
        printf("\n");
        if (toupper(playerIn) == 'Y'){
            printf("Now shuffling...\n");
            shuffle(d, randNum, 52);
            printf("\n");
            break;
        } else if (toupper(playerIn) == 'N'){
            break;
        }
    else
        printf("Error: Response unknown, enter again\n\n");
    }

    while (1){
        printf("Would you like to print whole deck? (Y/N): ");
        scanf(" %c", &playerIn);
        printf("\n");
        if (toupper(playerIn) == 'Y'){
            for (int i = 0; i < 52; i++){
                printf("Card %d", i+1);
                pull(d, i);

            }
                
            return;
        } else if (toupper(playerIn) == 'N'){
            break;
        }
    else
        printf("Error: Response unknown, enter again\n\n");
    }

    while (1){
        printf("Pull a cards? (Y/N): ");
        scanf(" %c", &playerIn);
        if (toupper(playerIn) == 'Y' ){
            pull(d, curcards);
            curcards++;
            if (curcards == 52){
                printf("\nLast cards pulled! Reshuffling deck...\n");
                shuffle(d, randNum, 52);
                curcards = 0;
                printf("\nShuffle done!\n\n");
            }
        }
        else if (toupper(playerIn) == 'N'){
            printf("\nReturning to main menu...\n\n");
            break;
        }    
        else
            printf("Error: Input not found, try again\n\n");
    }
}

// Pull a cards from the deck
void pull(Deck* d, int index){
    printf("\nYou pulled %s of %s, which has a value of %d\n\n", d->cards[index].rank, d->cards[index].suit, d->cards[index].value);
}

// Pull a cards from the deck and add it to used cards (INCOMPLETE)
void pullRemove(Deck* d, int removed[], int index){
    pull(d, index);
}

// Shuffle deck by swapping two random cards repeatedly
void shuffle(Deck* d, int seed, int cardAmt){
    Card hold;
    int c1;
    int c2;
    srand(seed);
    for (int i = 0; i < 1000000; i++){
        c1 = rand()%cardAmt;
        c2 = rand()%cardAmt;
        hold = d->cards[c1];
        d->cards[c1] = d->cards[c2];
        d->cards[c2] = hold;
    }
}