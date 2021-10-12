#ifndef RESOURCES_H_INCLUDED
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
#include "world.h"
#include "items.h"

//  Properties of resources
typedef struct {
    const WorldObject_ID worldId;
    const ToolType toolType;
    const MiningLevel miningLevel;
    const Item resourcesDrop;
    short respawnTime;
    Position position;
} Resources;

#endif // RESOURCES_H_INCLUDED
