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
    for (int e = 0; e < 3; e++){
        worldAll->area[e].heigthArea=randomWorld();
        worldAll->area[e].widthArea=randomWorld();
        worldAll->area[e].chunk = malloc(sizeof(int *) *worldAll->area[e].heigthArea);
        generateArea(worldAll->area[e]);
        displayArea(worldAll->area[e]);
    }
    return worldAll;

}
/*
 * * size of short 0 à 65 535
 * * but the max size is 100
 */
void  generateArea(Area area){
    for (int i = 0; i < area.heigthArea; i++) {
        area.chunk[i] = malloc(sizeof(int) * area.widthArea);
    }
    for (int y=0;y<area.heigthArea;y++){
        for (int x = 0; x<area.widthArea; x++){
            area.chunk[y][x]=0;
        }

    }
}

int randomMy(int min, int max){
    srand((unsigned)time(NULL));
    return  min + rand() % (max + 1 - min);
}

void  displayArea(Area area){
    printf("\nnouvelle carte\n\n");
    for (int y=0;y<area.heigthArea;y++){
        for (int x = 0; x<area.widthArea; x++){
            printf("%d",area.chunk[y][x]);
        }
        printf("\n");
    }
    printf("\n\n");
}