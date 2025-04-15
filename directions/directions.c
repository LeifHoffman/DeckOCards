/********************************************************************************
 * File: directions.c
 * Purpose: This file explains how each game functions
 * Author: Leif Hoffman
 * Date Updated: 4-7-2025
 ********************************************************************************/

 #include <stdio.h>

 // Explains the rules of war
 void read_war_rules(){
    printf("In a game of War, a deck of 52 cards is split between two players in a pile of 26 cards each.");
    printf("When a turn begins, both players will flip and reveal the top card of their piles.");
    printf("The value of flipped cards are compared, and the player with the higher card value wins and takes both cards.");
    printf("The won cards are then put aside in a 'won pile' and are reshuffled into the player's pile when they run out of cards.");
    printf("If the card values are instead equal when flipped, then both players enter 'war'.");
    printf("When entering war, both players will draw two cards face-down then reveal a third drawn card.");
    printf("The winner of this draw wins all drawn cards in war. Otherwise, players will continue cycling until a winner is decided.");
    printf("The game is considered done when one player can no longer play any cards, where the player with all cards is the winner.\n");
 }

 // Explains the rules of scoundrel
 void read_scoundrel_rules(){
   printf("No rules yet, figure it our yourself lelelel.\n");
 }