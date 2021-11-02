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
        generateArea(worldAll->area[numberArea], numberArea);

    }
    return worldAll;

}
/*
 * * size of short 0 à 65 535
 * * but the max size is 100
 */
void  generateArea(Area area, int numberArea){
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
    createAll(area, numberArea);
}

void createAll(Area area, int numberArea){
    createTravel(area, numberArea);
    createMonster(area, numberArea);
    createPnj(area);
    createRessource(area, numberArea);
}
int randomMy(int min, int max){
    int nombre = 0;
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
    switch (numberArea) {
        case 0:
            checkCase(area, -2);
            break;
        case  1:
            checkCase(area, -2);
            checkCase(area, -3);
            break;
        case  2:
            checkCase(area, -2);
            checkCase(area, -3);
            break;
    }
}


void checkCase(Area area, int type){
    int count=0;
    int x;
    int y;
    do {
        y=randomMy(1,area.heigthArea-1);
        x=randomMy(1,area.widthArea-1);
        if(area.chunk[y][x]==0){
            area.chunk[y][x]=type;
            count++;
        }
    }while(count==0);
}

void createPnj(Area area){
    checkCase(area, 2);
}

void createMonster(Area area, int numberArea){
    switch (numberArea) {
        case 0:
            checkCase(area, randomMy(1, 20));
            checkCase(area, randomMy(1,20));
            checkCase(area, randomMy(1,20));
            break;
        case 1:
            checkCase(area, randomMy(20, 50));
            checkCase(area, randomMy(20,50));
            checkCase(area, randomMy(20,50));
            break;
        case  2:
            checkCase(area, randomMy(50, 98));
            checkCase(area, randomMy(50,98));
            checkCase(area, randomMy(50,98));
            checkCase(area, 99);
            break;

    }
}


void createRessource(Area area, int numberArea){
    createPlant(area, numberArea);
    createWood(area, numberArea);
    createMineral(area, numberArea);
}

void createPlant(Area area, int numberArea){
    if(numberArea==0){
        checkCase(area, 3);
        checkCase(area, 3);
        checkCase(area, 3);
    } else if(numberArea==1){
        checkCase(area, 6);
        checkCase(area, 6);
        checkCase(area, 6);
    } else{
        checkCase(area, 9);
        checkCase(area, 9);
        checkCase(area, 9);
    }
}

void createWood(Area area, int numberArea){
    if(numberArea==0){
        checkCase(area, 5);
        checkCase(area, 5);
        checkCase(area, 5);
    } else if(numberArea==1){
        checkCase(area, 8);
        checkCase(area, 8);
        checkCase(area, 8);
    }else{
        checkCase(area, 11);
        checkCase(area, 11);
        checkCase(area, 11);
    }
}

void createMineral(Area area, int numberArea){
    if(numberArea==0){
        checkCase(area, 4);
        checkCase(area, 4);
        checkCase(area, 4);
    } else if(numberArea==1){
        checkCase(area, 7);
        checkCase(area, 7);
        checkCase(area, 7);
    } else{
        checkCase(area, 10);
        checkCase(area, 10);
        checkCase(area, 10);
    }
}