/*
**  Filename : world.c
**
**  Made by : HAN Felix
**
**  Description :
*/
#define  MIN 5
//  Includes library
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../headers/world.h"
#include "../headers/main.h"

#define  MIN 10
#define  MAX 100
/*
 ** To create the world
 */
World *generateWorld (int seed){
    World *worldAll= malloc(sizeof(World));
    worldAll->seed=1;
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
            if(y==0 && x==0){
                area.chunk[y][x]=1;
            } else{
                area.chunk[y][x]=0;
            }
        }

    }
}

int randomMy(int min, int max){
    srand((unsigned)time(NULL));
    return  min + rand() % (max + 1 - min);
}

void  displayArea(Area area){
    const char * command = "clear";
    system(command);
    for (int y=0;y<area.heigthArea;y++){
        for (int x = 0; x<area.widthArea; x++){
            printf("%d",area.chunk[y][x]);
        }
        printf("\n");
    }
}