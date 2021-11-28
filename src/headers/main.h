#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/*
**  Filename : main.h
**
**  Made by : HAN Felix
**
**  Description : Start the Game Malloc World
*/
#include "allstructure.h"
//  Save the game in a file
void SaveGame ();
//  Load a Game from an file
void LoadGame ();
int randomWorld();
char* readLine(char* filename, int type, int number);
char* information(char* line, int number);

void freeAll(World* world, Player* player);
void freeMonster(Monster* monster);
void freeResources(Resources* resource);
void freeItem(Item* item);
void freeWorld(World* world);
void freeArea(Area area);
void freeTab(int number, int* tab);
void freeDoubleTab(int widthArea, int heigthArea, int** tab);
void freePlayer(Player* player);

void  toWrite(World* world, Player* player);
void toWriteArea(Area area, FILE* fp, int number);
void toWritePlayer(Player* player, FILE* fp);
#endif // MAIN_H_INCLUDED
