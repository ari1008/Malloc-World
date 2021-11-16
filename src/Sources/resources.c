/*
**  Filename : resources.c
**
**  Made by : HAN Felix
**
**  Description : Initialisation of resources default properties
*/

//  Includes library
#include <stdlib.h>
#include <stdio.h>
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
    resource->next=NULL;
    return resource;
}

void createRessource(Area area, TabAll* tabAll , int numberArea){
    tabAll->plant=createPlant(area,tabAll->plant, numberArea);
    tabAll->wood=createWood(area,tabAll->wood, numberArea);
    tabAll->mineral=createMineral(area,tabAll->mineral, numberArea);
}

Resources* createPlant(Area area,Resources* resources, int numberArea){
    int xYPlant[2];
    Resources* resources1;
    int type;
    switch (numberArea) {
        case 0:
            type=3;
            checkCase(area,type,xYPlant);
            resources= newElementResources(type, xYPlant[0], xYPlant[1]);
            resources1=resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type,xYPlant);
                resources1->next= (struct Resources *)  newElementResources(type, xYPlant[0],xYPlant[1]);
                resources1= (Resources *) resources1->next;
            }
            break;
        case 1:
            type=6;
            checkCase(area,type,xYPlant);
            resources= newElementResources(type, xYPlant[0], xYPlant[1]);
            resources1=resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type,xYPlant);
                resources1->next= (struct Resources *)  newElementResources(type, xYPlant[0],xYPlant[1]);
                resources1= (Resources *) resources1->next;
            }
            break;
        case 2:
            type=9;
            checkCase(area,type,xYPlant);
            resources= newElementResources(type, xYPlant[0], xYPlant[1]);
            resources1=resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type,xYPlant);
                resources1->next= (struct Resources *)  newElementResources(type, xYPlant[0],xYPlant[1]);
                resources1= (Resources *) resources1->next;
            }
            break;
    }
    return resources;
}

Resources*  createWood(Area area,Resources* resources, int numberArea){
    int xYWood[2];
    Resources* resources1;
    int type;
    switch (numberArea) {
        case 0:
            type=5;
            checkCase(area,type,xYWood);
            resources= newElementResources(type, xYWood[0], xYWood[1]);
            resources1=resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type,xYWood);
                resources1->next= (struct Resources *)  newElementResources(type, xYWood[0],xYWood[1]);
                resources1= (Resources *) resources1->next;
            }
            break;
        case 1:
            type=8;
            checkCase(area,type,xYWood);
            resources= newElementResources(type, xYWood[0], xYWood[1]);
            resources1=resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type,xYWood);
                resources1->next= (struct Resources *)  newElementResources(type, xYWood[0],xYWood[1]);
                resources1= (Resources *) resources1->next;
            }
            break;
        case 2:
            type=11;
            checkCase(area,type,xYWood);
            resources= newElementResources(type, xYWood[0], xYWood[1]);
            resources1=resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type,xYWood);
                resources1->next= (struct Resources *)  newElementResources(type, xYWood[0],xYWood[1]);
                resources1= (Resources *) resources1->next;
            }
            break;
    }
    return resources;
}

Resources* createMineral(Area area,Resources* resources, int numberArea){
    int xYMineral[2];
    Resources* resources1;
    int type;
    switch (numberArea) {
        case 0:
            type = 4;
            checkCase(area, type, xYMineral);
            resources = newElementResources(type, xYMineral[0], xYMineral[1]);
            resources1 = resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type, xYMineral);
                resources1->next = (struct Resources *) newElementResources(type, xYMineral[0], xYMineral[1]);
                resources1 = (Resources *) resources1->next;
            }
            break;
        case 1:
            type = 7;
            checkCase(area, type, xYMineral);
            resources = newElementResources(type, xYMineral[0], xYMineral[1]);
            resources1 = resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type, xYMineral);
                resources1->next = (struct Resources *) newElementResources(type, xYMineral[0], xYMineral[1]);
                resources1 = (Resources *) resources1->next;
            }
            break;
        case 2:
            type = 10;
            checkCase(area, type, xYMineral);
            resources = newElementResources(type, xYMineral[0], xYMineral[1]);
            resources1 = resources;
            for (int i = 0; i < 2; ++i) {
                checkCase(area, type, xYMineral);
                resources1->next = (struct Resources *) newElementResources(type, xYMineral[0], xYMineral[1]);
                resources1 = (Resources *) resources1->next;
            }
            break;
    }
    return resources;
}

void printResource(Resources* resource){
    while (resource != NULL){
        printf("%d\n",resource->id);
        resource= (Resources *) resource->next;
    }
}

Item* createCraft(Item* notPlayer, int area){
    Item* create=notPlayer;
    ItemTwo*  liste;
    if(area==0){
        char* path=malloc(sizeof(char)*62);
        strcpy(path,PATH );
        strcat(path, PNJ);
        FILE* readPnj= fopen(path, "r");
        liste=insertCraft(create, readPnj);
        fclose(readPnj);
    }else if(area==1){
        char* path1=malloc(sizeof(char)*62);
        strcpy(path1,PATH );
        strcat(path1, PNJ1);
        FILE* readPnj1= fopen(path1, "r");
        liste=insertCraft(create, readPnj1);
        fclose(readPnj1);
    }else if(area==2){
        char* path=malloc(sizeof(char)*62);
        strcpy(path,PATH );
        strcat(path, PNJ2);
        FILE* readPnj2= fopen(path, "r");
        liste=insertCraft(create, readPnj2);
        fclose(readPnj2);
    }
    return liste->item;
}

ItemTwo* insertCraft(Item* pnj, FILE* filePnj){
     ItemTwo* iteamAll= malloc(sizeof(Item));
    char line[256];
    int count=0;
    Item* test;
    if (filePnj != NULL) {
        while (fgets(line, sizeof(line), filePnj) != NULL) {
            if(count==0){
                pnj=createItem(line);
                test=pnj;
                count++;
            }else{
                test->next= (struct Item *) createItem(line);
                test= (Item *) test->next;

            }
        }
    }
    iteamAll->item=pnj;
    iteamAll->item1=test;
    return iteamAll;
}

Item *createItem(char *line) {
    Item* item= malloc(sizeof(Item));
    char* separators=";";
    int count=0;
    char * strToken = strtok ( line, separators );
    while ( strToken != NULL ) {
        count++;
        switch(count){
            case 1:
                item->id=atoi(strToken);
                break;
            case 2:
                strcpy(item->name, strToken);
                break;
            case 3:
                item->resource[0]=atoi(strToken);
                break;
            case 4:
                item->resource[1]=atoi(strToken);

                break;
            case 5:
                item->resource1[0]=atoi(strToken);
                break;
            case 6:
                item->resource1[1]=atoi(strToken);
                break;
            case 8:
                item->durability=atoi(strToken);
                break;
            case 9:
                item->damage=atoi(strToken);
                break;
            case 10:
                item->hp=atoi(strToken);
                break;
            case 11:
                strcpy(item->type, strToken);
                break;
        }
        strToken = strtok ( NULL, separators );
    }
    return item;
}

void printCraft(Item* item){
     int count=0;
    while (item!= NULL){
        printf("%s %d\n",item->name,count);
        count++;
        item= (Item *) item->next;
    }
}