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
#include "../headers/world.h"
#include "../headers/main.h"
//ajouter dans la fonction
/*
 ** To create the world
 */
World *generateWorld (int seed){
    World *worldAll= malloc(sizeof(World));
    worldAll->seed=seed;
    for (int numberArea = 0; numberArea < 3; numberArea++){
        worldAll->area[numberArea].heigthArea=randomWorld();
        worldAll->area[numberArea].widthArea=randomWorld();
        worldAll->area[numberArea].chunk = malloc(sizeof(int *) *worldAll->area[numberArea].heigthArea);
        Resources* resources= malloc(sizeof(Resources));
        Monster* monster= malloc(sizeof(Monster));
        generateArea(worldAll->area[numberArea], resources,monster, numberArea);
        worldAll->area[numberArea].monster =monster;
        worldAll->area[numberArea].resources = resources;
    }
    return worldAll;

}
/*
 * * size of short 0 à 65 535
 * * but the max size is 100
 */
void  generateArea(Area area,Resources*  resources, Monster* monster, int numberArea){
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
    TabMonsterResources *tabMonsterResources;
    tabMonsterResources = malloc(sizeof(TabMonsterResources));
    createAll( area, resources, monster, tabMonsterResources, numberArea);
    area.monster=tabMonsterResources->monster;
    area.resources=tabMonsterResources->resources;

}

void createAll(Area area,Resources* resources,Monster* monster,TabMonsterResources* tabMonsterResources, int numberArea){
    createTravel(area, numberArea);
    monster=createMonster(area,monster, numberArea);
    createPnj(area);
    resources = createRessource(area, resources, numberArea);
    tabMonsterResources->resources=resources;
    tabMonsterResources->monster=monster;
}
int randomMy(int min, int max){
    int nombre;
    nombre = (rand() % (max - min + 1)) + min;
    return nombre;
}

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

void createTravel(Area area, int numberArea){
    int xYTravel[2];
    switch (numberArea) {
        case 0:
            checkCase(area, -2,xYTravel);
            break;
        case  1:
        case  2:
            checkCase(area, -2,xYTravel);
            checkCase(area, -3,xYTravel);
            break;
    }
}


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

void createPnj(Area area){
    int xY[2];
    checkCase(area, 2,xY );
}

Monster* createMonster(Area area,Monster* monster, int numberArea){
    int xYMonster[2];
    switch (numberArea) {
        case 0:
            checkCase(area, randomMy(1, 20),xYMonster);
            monster= newElementMonster(1,xYMonster[0],xYMonster[1]);
            for (int i = 0; i < 2; ++i) {
                checkCase(area, randomMy(1, 20),xYMonster);
                monster->point= (struct Monster *) newElementMonster(1, xYMonster[0], xYMonster[1]);
            }

            break;
        case 1:
            checkCase(area, randomMy(20, 50),xYMonster);
            monster= newElementMonster(1,xYMonster[0],xYMonster[1]);
            for (int i = 0; i < 2; ++i) {
                checkCase(area, randomMy(20, 50),xYMonster);
                monster->point= (struct Monster *) newElementMonster(1, xYMonster[0], xYMonster[1]);
            }
            break;
        case  2:
            checkCase(area, randomMy(50, 98),xYMonster);
            monster=newElementMonster(1,xYMonster[0],xYMonster[1]);
            for (int i = 0; i < 2; ++i) {
                checkCase(area, randomMy(50, 98),xYMonster);
                monster->point= (struct Monster *) newElementMonster(1, xYMonster[0], xYMonster[1]);
            }
            checkCase(area, 99, xYMonster);
            monster->point=(struct Monster *) newElementMonster(1, xYMonster[0], xYMonster[1]);
            break;

    }
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


Monster* newElementMonster(int type, int y, int x){
    Monster* monster= malloc(sizeof(Monster));
    monster->hpMax=type;
    monster->hpCurrent=type;
    monster->respawnTime=15;
    monster->view=1;
    monster->x=x;
    monster->point=NULL;
    return monster;
}