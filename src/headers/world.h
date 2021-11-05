#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

/*
**  Filename : world.h
**
**  Made by : HAN Felix
**
**  Description : Define the properties of world in game
*/
#include "allstructure.h"
#include "resources.h"
#include "monster.h"

// Give alias to world's objects

//  Generate a world from a seed
int randomMy(int min, int max);
World * generateWorld (int seed);
void generateArea(Area area,Resources* resources,Monster* monster, int numberArea);
void  displayArea(Area area);
void createAll(Area area,Resources* resources,Monster* monster,TabMonsterResources* tabMonsterResources, int numberArea);
void  createTravel(Area area, int numberArea );
int* checkCase(Area area, int type, int* result);


#endif // WORLD_H_INCLUDED


