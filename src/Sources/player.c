/*
**  Filename : player.c
**
**  Made by : HAN Felix
**
**  Description : Initialisation of player default properties
*/

//  Includes library
#include <stdlib.h>
#include "../headers/player.h"

//  Player's inventory default starter
Inventory inventory = {
    .armor[0].itemId = NONE,
    .armor[0].quantity = 0,
    .weapon[0].itemId = WOODEN_SWORD,
    .weapon[0].quantity = 1,
    .slot[0].itemId = WOODEN_PICKAXE,
    .slot[0].quantity = 1,
    .slot[1].itemId = WOODEN_AXE,
    .slot[1].quantity = 1,
    .slot[2].itemId = BILLHOOK,
    .slot[2].quantity = 1,
    .slot[3].itemId = NONE,
    .slot[3].quantity = 0,
    .slot[4].itemId = NONE,
    .slot[4].quantity = 0,
    .slot[5].itemId = NONE,
    .slot[5].quantity = 0,
    .slot[6].itemId = NONE,
    .slot[6].quantity = 0,
    .slot[7].itemId = NONE,
    .slot[7].quantity = 0,
    .slot[8].itemId = NONE,
    .slot[8].quantity = 0,
    .slot[9].itemId = NONE,
    .slot[9].quantity = 0
};

//  Player default properties at the start of the game
Player player = {
    .worldId = Player,
    .username = "Steve",
    .level = 1,
    .xpCurrent = 0,
    .xpNext = 100,
    .hpCurrent = 100,
    .hpMax = 100,
    .inventory = inventory
};
