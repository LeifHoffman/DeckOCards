/********************************************************************************
 * File: directions.c
 * Purpose: This file explains how each game functions
 * Author: Leif Hoffman
 * Date Updated: 4-7-2025
 ********************************************************************************/

 #include <stdio.h>

 // Explains the rules of war
 void read_war_rules(){
    printf("In a game of War, a deck of 52 cards is split between two players in a pile of 26 cards each.\n");
    printf("When a turn begins, both players will flip and reveal the top card of their piles.\n");
    printf("The value of flipped cards are compared, and the player with the higher card value wins and takes both cards.\n");
    printf("The won cards are then put aside in a 'won pile' and are reshuffled into the player's pile when they run out of cards.\n");
    printf("If the card values are instead equal when flipped, then both players enter 'war'.\n");
    printf("When entering war, both players will draw two cards face-down then reveal a third drawn card.\n");
    printf("The winner of this draw wins all drawn cards in war. Otherwise, players will continue cycling until a winner is decided.\n");
    printf("The game is considered done when one player can no longer play any cards, where the player with all cards is the winner.\n");
 }

 // Explains the rules of scoundrel
 void read_scoundrel_rules(){
   printf("In a game of Scoundrel, a shuffled deck of cards, excluding the red face and ace cards, create a dungeon (44 total cards).\n");
   printf("To win the game, you must interact with every card.\n");
   printf("Starting at 20 health, you win by going through 'rooms' consisting of four cards drawn from the top of the dungeon.\n");
   printf("Each suit has a unique interaction, where spades and clubs are monsters, diamonds are weapons, and hearts are potions.\n");
   printf("If you choose a monster, you take damage equal to the card's value (Jack=11, Queen=12, King=13, Ace=14).\n");
   printf("If you choose a weapon, you automatically equip it and can choose to use it against monsters, \nreducing the damage taken by the weapon value to a minimum of 0.\n");
   printf("However, if you choose to fight with a weapon, you can only use it subsequently against monsters of lesser value than the one you just fought.\n");
   printf("Additionally, if you pick another weapon, your old one is discarded in favor of the new one, but you can again use it on any monster value.\n");
   printf("If you choose a potion, you are healed by the card's value, up to a maximum of 20.\n");
   printf("In the standard ruleset, you can only heal once per room, discarding any other potions you find.\n");
   printf("However, you can choose to play with this rule off.\n");
   printf("Once you clear three cards in a room, the untouched card will carry over to the next one, \nwhere the next three cards in the dungeon are flipped over.\n");
   printf("Alternatively, before interacting with a room, you can choose to skip it, \nputting the current room at the bottom of the dungeon and flipping the next four cards.\n");
   printf("You can only do this once before needing to clear a room normally, however.\n");
   printf("You lose the game if your health reaches 0 or below 0.\n");
   printf("\nThis game was created by Zach Gage and Kurt Bieg, which you can find using the link below:\n");
   printf("http://www.stfj.net/art/2011/Scoundrel.pdf\n");
 }