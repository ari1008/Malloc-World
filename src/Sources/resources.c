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
#include "../headers/main.h"

/*This function allows you to build a resource during the construction of the map.
 * This is why we need the type and these coordinates*/
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
/*
 * Function that calls the three functions to create the chained list of the card
 */
void createRessource(Area area, TabAll* tabAll , int numberArea){
    tabAll->plant=createPlant(area,tabAll->plant, numberArea);
    tabAll->wood=createWood(area,tabAll->wood, numberArea);
    tabAll->mineral=createMineral(area,tabAll->mineral, numberArea);
}
/*
 * This function creates the plants according to the map. It emerges a chained list
 */
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

/*
 * This function creates the Woods according to the map. It emerges a chained list
 */
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

/*
 * This function creates the Minerals according to the map. It emerges a chained list
 */
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
/*
 * It's a debug function for now to see if the resources are displayed well or are scoper here
 */
void printResource(Resources* resource){
    while (resource != NULL){
        printf("%d\n",resource->id);
        resource= (Resources *) resource->next;
    }
}
/*
 * This function opens the correct pnj (| [1-2]).
 * Txt file depending on the card. And launch the function which creates the chained list
 */
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

/*
 * This function takes the png file line by line. To be able to insert them in a chained list
 */
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
/*
 * It's a debug function for now to see if the Item are displayed well or are scoper here
 */
void printCraft(Item* item){
    while (item!= NULL){
        printf("%s\n",item->name);
        item= (Item *) item->next;
    }
}

/*
 * See if the resource should be displayed on the map
 */
void verifResources(Area area,Resources* resources){
    while (resources!= NULL){
        if(resources->view==1){
            area.chunk[resources->positionY][resources->positionY]=resources->id;
        }else{
            area.chunk[resources->positionY][resources->positionY]=0;
        }
        resources = (Resources *) resources->next;
    }
 }
/*
 * Allows you to retrieve a resource on the card according to its type
 * it dispatches on the corresponding function
 */
 void recupResources(Area area,Player* player,char* element, int type){
     int sort=0;
    printResource("Element %s\n");
     int* durability=malloc(sizeof(int)*3);
     durability[0]=10;
     durability[1]=20;
     durability[2]=40;
     if(strcmp(element, "Rock")==0){
         sort=recupMinerals(area, player, durability, type);
     }else if(strcmp(element, "Plant")==0){
         recupPlants(area, player, type);
     }else if(strcmp(element, "Wood")==0){
         recupWoods(area, player, type);
     }
 }
/*
 * The function to recover minerals
 */
 int recupMinerals(Area area,Player* player,int* durability,int type){
     int number=randomMy(1, 4);
     int* ax= malloc(sizeof(int)*player->numberInventory);
     int print=0;
     int pourcent=0;
     int result=-1;
    switch (type) {
        case 4:
            pourcent=durability[0];
            break;
        case 7:
            pourcent=durability[1];
            break;
        case 10:
            pourcent=durability[2];
    }
     for(int i=0; i< player->numberInventory;i++){
         if (player->inventory[i].broke==0){
             if(player->inventory[i].id==2 && pourcent==10){
                 recupMineral(area, player, pourcent, number, i, type );
             }else if (player->inventory[i].id==12 && (pourcent==10 || pourcent==20)){
                 recupMineral(area, player, pourcent, number, i, type);
             }else if(player->inventory[i].id==23){
                 recupMineral(area, player, pourcent, number, i, type);
             }
         }
     }
 }

void recupMineral(Area area,Player* player,int durability, int numberResources, int indice, int type){
    int typeInventory= atoi(readLine(RESOURCES , type, 4));
    int count=0;
     player->inventory[indice].durability=(100-durability)/player->inventory[indice].durability*100;
    if (player->inventory[indice].durability<=0){
        player->inventory[indice].durability=0;
        player->inventory[indice].broke=1;
    }
    for(int i=0;i< player->numberInventory; i++){
        if (player->inventory[i].id==typeInventory && player->inventory[i].number<20){
              player->inventory[i].number= (player->inventory[i].number + numberResources >20) ? 20 : player->inventory[i].number + numberResources;
              count++;
            break;
        }
    }
    if (count==0 && player->numberInventory<10){
        player->numberInventory++;
        player->inventory[player->numberInventory].id=typeInventory;
        createNewRessourceInventory(player->inventory[player->numberInventory], type, numberResources, readLine(ITEM,type, 2), readLine(ITEM,type, 3));
    }else if(count==0 && player->numberInventory==10){
        printf("There is no more space in the inventory\n");
    }
 }

void createNewRessourceInventory(Item item, int id, int number, char* name, char* type){
     item.id=id;
     item.number=number;
    strcpy(item.name, name);
    strcpy(item.type, type);
    item.next=NULL;
    item.broke=0;
 }

 /*
  *
  * This function allows you to recover plants
  */
 void recupPlants(Area area,Player* player,int type){
     printf("Not start\n");
 }


/*
*
* This function allows you to recover wood
*/
 void recupWoods(Area area,Player* player,int type){
     printf("Not start\n");
 }

int verifIntResources(int* resources, int size){
     int count=-1;
     scanf("%d",&count);
     if(count==11){
         printf("Stop\n");
         return 0;
     }
     for(int i=0;i<size;i++){
         if (resources[i]==count){
             return resources[i];
         }
     }
    return -1;
 }

int recupFinishRessources(Player* player, int number, int pourcent, int nbrInventory){
     return 1;
 }

