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
ItemTwo* insertCraft(Item* pnj, FILE* filePnj);
Item* createCraft(Item* notPlayer, int area);
void printCraft(Item* item);

void verifResources(Area area,Resources* resources);
void recupResources(Area area,Player* player,char* element, int type);
int  recupMinerals(Area area,Player* player,int* durability, int type);
void recupMineral(Area area,Player* player,int durability, int numberResources, int indice, int type);
void recupWoods(Area area,Player* player,int type);
void recupPlants(Area area,Player* player,int type);
void createNewRessourceInventory(Item item, int id, int number, char* name, char* type);

int verifIntResources(int* resources, int size);
int recupFinishRessources(Player* player, int number, int pourcent, int nbrInventory);
//#endif // RESOURCES_H_INCLUDED
