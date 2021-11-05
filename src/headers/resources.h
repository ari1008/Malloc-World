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
Resources*  createRessource(Area area,Resources* resources, int numberArea);
Resources*  createPlant(Area area,Resources* resources, int numberArea);
void  createWood(Area area,Resources* resources, int numberArea);
void  createMineral(Area area,Resources* resources, int numberArea);
Resources* newElementResources( int type, int y, int x);


//#endif // RESOURCES_H_INCLUDED
