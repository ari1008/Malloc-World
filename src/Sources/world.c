/*
**  Filename : world.c
**
**  Made by : HAN Felix
**
**  Description :
*/

//  Includes library
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "../headers/world.h"
#include "../headers/main.h"
//ajouter dans la fonction
/*
 ** To create the world
 * And all the things you need like monsters, resources, monsters and also points of sale and map passes.
 */
World *generateWorld (int seed){
    World *worldAll= malloc(sizeof(World));
    worldAll->seed=seed;
    for (int numberArea = 0; numberArea < 3; numberArea++){
        worldAll->area[numberArea].heigthArea=randomWorld();
        worldAll->area[numberArea].widthArea=randomWorld();
        worldAll->area[numberArea].chunk = malloc(sizeof(int *) *worldAll->area[numberArea].heigthArea);
        TabAll * tabAll= malloc(sizeof(TabAll));
        Monster* monster= malloc(sizeof(Monster));
        Item* item= malloc(sizeof(Item));
        worldAll->area[numberArea].two= malloc(sizeof(int)*2);
        worldAll->area[numberArea].three= malloc(sizeof(int)*2);
        worldAll->area[numberArea].pnj= malloc(sizeof(Item));
        worldAll->area[numberArea].pnj=createCraft(item, numberArea);
        generateArea(worldAll->area[numberArea], (TabAll *) tabAll, monster, numberArea);
        worldAll->area[numberArea].plant = tabAll->plant;
        worldAll->area[numberArea].monster = tabAll->monster;
        worldAll->area[numberArea].mineral = tabAll->mineral;
        worldAll->area[numberArea].wood= tabAll->wood;
    }
    return worldAll;

}
/*
 * * Allows you to initialize the card for one area
 */
void  generateArea(Area area,TabAll* tabAll, Monster* monster, int numberArea){
    for (int i = 0; i < area.heigthArea; i++) {
        area.chunk[i] = malloc(sizeof(int) * area.widthArea);
    }
    for (int y=0;y<area.heigthArea;y++){
        for (int x = 0; x<area.widthArea; x++){
            if(y==0 && x==0) {
                area.chunk[y][x] = 1;
            } else{
                area.chunk[y][x]=0;
            }
        }

    }
    createAll( area, monster, tabAll, numberArea);

}
/*
 * Function which groups together all that must be created for each card, monsters, PNJs, resources and passages.
 */
void createAll(Area area,Monster* monster,TabAll* tabAll, int numberArea){
    createTravel(area, numberArea);
    monster=createMonster(area,monster, numberArea);
    createPnj(area);
    createRessource(area, tabAll, numberArea);
    tabAll->monster=monster;
}


/*
 * It is a function that randomizes between two intervals.
 */
int randomMy(int min, int max){
    int nombre;
    nombre = (rand() % (max - min + 1)) + min;
    return nombre;
}

/*
 * This function allows you to display a map
 */
void  displayArea(Area area){
    const char * command = "clear";
    system(command);
    for (int y=0;y<area.heigthArea;y++){
        for (int x = 0; x<area.widthArea; x++){
            printf("%d ",area.chunk[y][x]);
        }
        printf("\n");
    }
}

/*
 *Function to put on the card and in the structure where the passages from card to card are in X and Y
 */
void createTravel(Area area, int numberArea){
    switch (numberArea) {
        case 0:
            checkCase(area, -2,area.two);
            break;
        case  1:
        case  2:
            checkCase(area, -2,area.two);
            checkCase(area, -3,area.three);

    }
}
/*
 * This function just returns the position of an empty cell.
 */

int* checkCase(Area area, int type, int* result){
    int count=0;
    do {
        result[0]=randomMy(1,area.heigthArea-1);
        result[1]=randomMy(1,area.widthArea-1);
        if(area.chunk[result[0]][result[1]]==0){
            area.chunk[result[0]][result[1]]=type;
            count++;
        }
    }while(count==0);

    return  result;
}

/*
 * Function to randomly put a PNJ on the map
 */
void createPnj(Area area){
    int xY[2];
    checkCase(area, 2,xY );
}

/*
 *This function allows you to update all the maps before displaying them.
 * If a monster is defeated or a resource is regained.
 */
void upgradeWorld(World* world, Player* player){
    for (int i = 0; i < 3; ++i) {
        verifMonster(world->area[i], world->area[i].monster);
        verifResources(world->area[i], world->area[i].mineral);
        verifResources(world->area[i], world->area[i].plant);
        verifResources(world->area[i], world->area[i].wood);
    }
    world->area[player->area].chunk[player->y][player->x]=1;
}



