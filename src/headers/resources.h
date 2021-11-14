//#ifndef RESOURCES_H_INCLUDED
#define RESOURCES_H_INCLUDED

/*
**  Filename : resources.h
**
**  Made by : HAN Felix
**
**  Description : Define properties of resources in the game
*/

//  Include library
#include <string.h>
#include "allstructure.h"
#include "world.h"

//  Properties of resources
/*typedef struct {
    const WorldObject_ID worldId;
    const ToolType toolType;
    const MiningLevel miningLevel;
    const Item resourcesDrop;
    short respawnTime;
    Position position;
} Resources;*/

void  createPnj(Area area);
void createRessource(Area area, TabAll* tabAll , int numberArea);
Resources*  createPlant(Area area,Resources* resources, int numberArea);
Resources*   createWood(Area area,Resources* resources, int numberArea);
Resources*  createMineral(Area area,Resources* resources, int numberArea);
Resources* newElementResources( int type, int y, int x);
void printResource(Resources* resource);
Item* createItem(char* line);
void insertCraft(Item* pnj, FILE* filePnj);
void createCraft(Item* notPlayer, int area);
//#endif // RESOURCES_H_INCLUDED
