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
    //const WorldObject_ID worldId;
    char *username;
    short level;
    int xpCurrent;
    int xpNext;
    short hpCurrent;
    short hpMax;
    int x;
    int y;
    Inventory inventory;
    short area;
} Player;

Player *createPlayer();
void play(World* world, Player* player);

void move(World* world, Player* player);
int* verification(Area  area,int x,int y);
int moveHigh(Area area, int y, int x);
int moveRight(Area area, int y, int x);
int moveLow(Area area, int y, int x);
int moveLeft(Area area, int y, int x);
int displayPosition(int* position);
void bottom(Area area, Player* player);
void right( Area area, Player* player);
void high(Area area, Player* player);
void left(Area area,  Player* player);
#endif // PLAYER_H_INCLUDED
