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

Resources* createRessource(Area area, Resources* resources, int numberArea){
    resources=createPlant(area,resources, numberArea);
    createWood(area,resources, numberArea);
    createMineral(area,resources, numberArea);
    return resources;
}

Resources* createPlant(Area area,Resources* resources, int numberArea){
    int xYPlant[2];
    if(numberArea==0){
        for (int i = 0; i < 3; ++i) {
            checkCase(area, 3,xYPlant);
            if (i == 0) {
                resources = newElementResources(3, xYPlant[0], xYPlant[1]);

            } else {
                resources->resources = newElementResources(3, xYPlant[0], xYPlant[1]);
            }
        }
        return resources;
    } else if(numberArea==1){
        for (int i = 0; i < 3; ++i) {
            checkCase(area, 6, xYPlant);
            if(i==0){
                resources= newElementResources(6,xYPlant[0], xYPlant[1]);
            } else{
                resources->resources= newElementResources(6,xYPlant[0], xYPlant[1]);
            }
        }
    } else{
        for (int i = 0; i < 3; ++i) {
            checkCase(area, 9, xYPlant);
            if(i==0){
                resources= newElementResources(9,xYPlant[0], xYPlant[1]);
            } else{
                resources->resources= newElementResources(9,xYPlant[0], xYPlant[1]);
            }
        }
    }
    return resources;
}

void createWood(Area area,Resources* resources, int numberArea){
    int xYWood[2];
    if(numberArea==0){
        for (int i = 0; i < 3; ++i) {
            checkCase(area, 5, xYWood);
            resources->resources= newElementResources(5,xYWood[0], xYWood[1]);

        }
    } else if(numberArea==1){
        for (int i = 0; i < 3; ++i) {

            checkCase(area, 8, xYWood);
            resources->resources= newElementResources(8,xYWood[0], xYWood[1]);
        }
    }else{
        for (int i = 0; i < 3; ++i) {
            checkCase(area, 11, xYWood);
            resources->resources= newElementResources(11,xYWood[0], xYWood[1]);
        }
    }
}

void createMineral(Area area,Resources* resources, int numberArea){
    int xYMineral[2];
    if(numberArea==0){
        for (int i = 0; i < 3; ++i) {
            checkCase(area, 4, xYMineral);
            resources->resources= newElementResources(11,xYMineral[0], xYMineral[1]);
        }
    } else if(numberArea==1){
        for (int i = 0; i < 3; ++i) {
            checkCase(area, 7, xYMineral);
            resources->resources= newElementResources(7,xYMineral[0], xYMineral[1]);
        }
    } else{
        for (int i = 0; i < 3; ++i) {
            checkCase(area, 10, xYMineral);
            resources->resources= newElementResources(10,xYMineral[0], xYMineral[1]);
        }
    }
}