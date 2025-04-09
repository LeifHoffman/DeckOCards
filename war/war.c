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
 #include "war.h"
 #include "../main_folder/deck.h"
 #include "../main_folder/card.h"
 #include "../directions/directions.h"

 void play_war(Deck* deck){

    // Initialize player deck pointers
    Deck* p1 = (Deck*)malloc(sizeof(Deck));
    p1->cards = (Card*)malloc(26*sizeof(Card));
    Deck* p2 = (Deck*)malloc(sizeof(Deck));
    p2->cards = (Card*)malloc(26*sizeof(Card));

    // Initialize player deck amounts
    int p1DeckSize = 26;
    int p1CurDeck = 26;
    Card p1CardHold[52];
    int p1NumHeld = 0;
    int p1CurCard = 0;
    int p1CurValue;
    
    int p2DeckSize = 26;
    int p2CurDeck = 26;
    Card p2CardHold[52];
    int p2NumHeld = 0;
    int p2CurCard = 0;
    int p2CurValue;

    // Initialize a hold for played cards
    Card hold[52];
    int heldCards = 0;

    // Define user inputs
    char userIn;
    //int userChoice;

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

    // TEST CODE: Pull from one of two piles

    // while(1){
    //     printf("Pull a card from deck 1 or 2? (1/2): ");
    //     scanf("%d", &userChoice);
    //     switch(userChoice){
    //         case 1:
    //             printf("\nFrom pile 1:\nCard: %s of %s\nValue: %d\n\n", p1->cards[p1CurCard].rank, p1->cards[p1CurCard].suit, p1->cards[p1CurCard].value);
    //             p1CurCard++;
    //             if (p1CurCard == p1CurDeck){
    //                 printf("Pile empty! Reshuffling available cards...\n\n");
    //                 shuffle(p1, rand(), p1CurDeck);
    //                 p1CurCard = 0;
    //             }
    //             break;
    //         case 2:
    //             printf("\nFrom pile 2:\nCard: %s of %s\nValue: %d\n\n", p2->cards[p2CurCard].rank, p2->cards[p2CurCard].suit, p2->cards[p2CurCard].value);
    //             p2CurCard++;
    //             if (p2CurCard == p2CurDeck){
    //                 printf("Pile empty! Reshuffling available cards...\n\n");
    //                 shuffle(p2, rand(), p2CurDeck);
    //                 p2CurCard = 0;
    //             }
    //             break;
    //         default:
    //             printf("Unknown choice, enter again.\n\n");
    //             break;
    //     }
    // }



    printf("Game start!\n\n");
    while (p1DeckSize != 0 && p2DeckSize != 0){
        // Wait for user input to continue
        printf("Press enter to play your next card.\n\n");
        scanf("%c", &userIn);

        // Handle Deck refill
        if (p1CurCard == p1CurDeck){
            refillDeck(p1->cards, p1CardHold, p1DeckSize);
            p1CurCard = 0;
        }
        if (p2CurCard == p2CurDeck){
            refillDeck(p2->cards, p2CardHold, p2DeckSize);
            p2CurCard = 0;
        }
        
        // Reveal top card for both decks
        printf("You: %s of %s\n", p1->cards[p1CurCard].rank, p1->cards[p1CurCard].suit);
        printf("Opponent: %s of %s\n\n", p2->cards[p2CurCard].rank, p2->cards[p2CurCard].suit);

        // Record card values and add to hold
        p1CurValue = p1->cards[p1CurCard].value;
        p2CurValue = p2->cards[p2CurCard].value;

        // Put played cards in hold
        hold[heldCards++] = p1->cards[p1CurCard];
        hold[heldCards++] = p2->cards[p2CurCard];

        // Start war if values are same
        while (p1CurValue == p2CurValue){
            printf("War! Enter to continue.\n\n");
            scanf("%c", &userIn);
            // Draw three cards and reveal last
            for (int i = 0; i < 3; i++){
                p1CurCard++;
                p2CurCard++;
                // Handle Deck refill
                if (p1CurCard == p1CurDeck){
                    refillDeck(p1->cards, p1CardHold, p1DeckSize);
                    shuffle(p1, rand(), p1DeckSize);
                    p1CurCard = 0;
                }
                if (p2CurCard == p2CurDeck){
                    refillDeck(p2->cards, p2CardHold, p2DeckSize);
                    shuffle(p2, rand(), p2DeckSize);
                    p2CurCard = 0;
                }
                hold[heldCards++] = p1->cards[p1CurCard];
                hold[heldCards++] = p2->cards[p2CurCard];
            }
            printf("You: %s of %s\n", p1->cards[p1CurCard].rank, p1->cards[p1CurCard].suit);
            printf("Opponent: %s of %s\n\n", p2->cards[p2CurCard].rank, p2->cards[p2CurCard].suit);
            p1CurValue = p1->cards[p1CurCard].value;
            p2CurValue = p2->cards[p2CurCard].value;
        }

        // Compare values if different and add cards to winner hold deck
        if (p1CurValue > p2CurValue){
            printf("You win!\n\n");
            p1DeckSize += heldCards/2;
            p2DeckSize -= heldCards/2;
            addCards(p1CardHold, &p1NumHeld, hold, &heldCards);
        } else {
            printf("You loss...\n\n");
            p2DeckSize += heldCards/2;
            p1DeckSize -= heldCards/2;
            addCards(p2CardHold, &p2NumHeld, hold, &heldCards);
        }

        // Go to next card to play
        p1CurCard++;
        p2CurCard++;
    }
 }

 // Add cards in hold pile to player hold deck
 void addCards(Card* playerHoldDeck, int* cardsHeld, Card* heldDeck, int* holdAmt){
    for (int i = 0; i < *holdAmt; i++){
        playerHoldDeck[*cardsHeld] = heldDeck[i];
        (*cardsHeld)++;
    }
    *holdAmt = 0;
 }

 // Refill player deck with their hold pile if empty
 void refillDeck(Card* pDeck, Card* pHoldDeck, int deckSize){
    pDeck = (Card*)realloc(pDeck, deckSize*sizeof(Card));
    for (int i = 0; i < deckSize; i++)
        pDeck[i] = pHoldDeck[i];
 }