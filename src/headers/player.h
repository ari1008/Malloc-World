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
#include "allstructure.h"
#include "world.h"
#include "items.h"

//   Properties of player inventory

//  Properties of a player


Player *createPlayer();
void play(World* world, Player* player);

void move(World* world, Player* player);
int* verification(Area  area,int y,int x);
int moveHigh(Area area, int y, int x);
int moveRight(Area area, int y, int x);
int moveLow(Area area, int y, int x);
int moveLeft(Area area, int y, int x);

int* displayPosition(int* position, int area, int* choice);
int* position(int* position, int area, int* choice);
void displayTravel(int position, int area, char* compass, int count);
void displayResources(int position, char* compass, int count);
void displayPnj(int area, char* compass, int count);

void bottom(Area area, Player* player);
void right( Area area, Player* player);
void high(Area area, Player* player);
void left(Area area,  Player* player);


int* choseNumber(int count, int* mov,  int* box, int* choice);

Item createItemStart(int id, char* name, char* type, int ressource0[2], int ressource1[2], int durability, int damage, int hp);

char* scenePlay(int id);
int launchScene(Area area, Player* player,int id);
int nextCase(Area area,Player *player, int move);


#endif // PLAYER_H_INCLUDED
