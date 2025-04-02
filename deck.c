/********************************************************************************
 * File: deck.c
 * Purpose: This file that handles functions found in deck.h
 * Author: Leif Hoffman
 * Date Updated: 4-2-2025
 ********************************************************************************/

#include <stdio.h>
#include "card.h"
#include "deck.h"

// Construct standard deck
void init_deck(Deck* d){
    for (int i = 0; i < 52; i++){
        // Set rank (A, 2, 3, 4, 5, 6, 7, 8, 9, J, Q, K) and value four at a time (i.e. A,A,A,A,2,2,2,2...)
        switch (i/4){
            case 0:
                readRank(&d->card[i], 'A');
                readValue(&d->card[i], 11);
                break;
            case 1:
                readRank(&d->card[i], '2');
                readValue(&d->card[i], 2);
                break;
            case 2:
                readRank(&d->card[i], '3');
                readValue(&d->card[i], 3);
                break;
            case 3:
                readRank(&d->card[i], '4');
                readValue(&d->card[i], 4);
                break;
            case 4:
                readRank(&d->card[i], '5');
                readValue(&d->card[i], 5);
                break;
            case 5:
                readRank(&d->card[i], '6');
                readValue(&d->card[i], 6);
                break;
            case 6:
                readRank(&d->card[i], '7');
                readValue(&d->card[i], 7);
                break;
            case 7:
                readRank(&d->card[i], '8');
                readValue(&d->card[i], 8);
                break;
            case 8:
                readRank(&d->card[i], '9');
                readValue(&d->card[i], 9);
                break;
            case 9:
                readRank(&d->card[i], 'J');
                readValue(&d->card[i], 10);
                break;
            case 10:
                readRank(&d->card[i], 'Q');
                readValue(&d->card[i], 10);
                break;
            default:
                readRank(&d->card[i], 'K');
                readValue(&d->card[i], 10);
                break;
        }

        // Read suit (Spade, Heart, Club, Diamond) one at a time (i.e. S,H,C,D,S...)
        switch (i%4){
            case 0:
                readSuit(&d->card[i], 'S');
                break;
            case 1:
                readSuit(&d->card[i], 'H');
                break;
            case 2:
                readSuit(&d->card[i], 'C');
                break;
            default:
                readSuit(&d->card[i], 'D');
                break;
        }
    }
}

// Pull a card from the deck
void pull_card(Deck* d, int index){
    printf("You pulled %c%c, which has a value of %d\n", d->card[index].rank, d->card[index].suit, d->card[index].value);
}