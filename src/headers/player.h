#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

/*
**  Filename : player.h
**
**  Made by : HAN Felix
**
**  Description : Define properties of a player in the game
*/

//  Include library
#include <string.h>
#include "world.h"
#include "items.h"

//   Properties of player inventory
typedef struct  {
    Item armor[1];
    Item weapon[3];
    Item slot[10];
} Inventory;

//  Properties of a player
typedef struct {
    const WorldObject_ID worldId;
    char username[20];
    short level;
    int xpCurrent;
    int xpNext;
    short hpCurrent;
    short hpMax;
    Position position;
    Inventory inventory;
} Player;

#endif // PLAYER_H_INCLUDED
