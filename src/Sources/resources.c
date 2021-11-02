/*
**  Filename : resources.c
**
**  Made by : HAN Felix
**
**  Description : Initialisation of resources default properties
*/

//  Includes library
#include <stdlib.h>
#include "../headers/resources.h"
#include "../headers/world.h"
//  WOOD
//  Level I
/*Resources woodI = {
    .worldId = WOOD_I,
    .toolType = AXE,
    .miningLevel = MINING_WOOD,
    .resourcesDrop.itemId = SPRUCE,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};

//  Level II
Resources woodII = {
    .worldId = WOOD_II,
    .toolType = AXE,
    .miningLevel = MINING_STONE,
    .resourcesDrop.itemId = BEECH,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};

//  Level III
Resources woodIII = {
    .worldId = WOOD_III,
    .toolType = AXE,
    .miningLevel = MINING_IRON,
    .resourcesDrop.itemId = OAK,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};

//  ROCK
//  Level I
Resources rockI = {
    .worldId = ROCK_I,
    .toolType = PICKAXE,
    .miningLevel = MINING_WOOD,
    .resourcesDrop.itemId = STONE,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};

//  Level II
Resources rockII = {
    .worldId = ROCK_II,
    .toolType = PICKAXE,
    .miningLevel = MINING_STONE,
    .resourcesDrop.itemId = IRON,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};

//  Level III
Resources rockIII = {
    .worldId = ROCK_III,
    .toolType = PICKAXE,
    .miningLevel = MINING_IRON,
    .resourcesDrop.itemId = DIAMOND,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};

//  PLANT
//  Level I
Resources plantI = {
    .worldId = PLANT_I,
    .toolType = BILLHOOK,
    .miningLevel = MINING_WOOD,
    .resourcesDrop.itemId = GRASS,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};

//  Level II
Resources plantII = {
    .worldId = PLANT_II,
    .toolType = BILLHOOK,
    .miningLevel = MINING_STONE,
    .resourcesDrop.itemId = LAVENDER,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};

//  Level III
Resources plantIII = {
    .worldId = PLANT_III,
    .toolType = BILLHOOK,
    .miningLevel = MINING_IRON,
    .resourcesDrop.itemId = HEMP,
    .resourcesDrop.quantity = 1,
    .respawnTime = 0
};
*/

void newResources(Area area){
    area.resources= malloc(sizeof(Resources));
}

 Resources* newElementResources( int type, int y, int x){
    struct Resources* resource= malloc(sizeof(Resources));
    resource->id=type;
    resource->positionX=x;
    resource->positionY=y;
    resource->respawn=10;
    resource->view=1;
    resource->resources=NULL;
    return resource;
}