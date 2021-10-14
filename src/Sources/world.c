/*
**  Filename : world.c
**
**  Made by : HAN Felix
**
**  Description :
*/

//  Includes library
#include "../headers/world.h"


/*
 ** To create the world
 */
World generateWorld (int seed){
    World mallocWorld;
    mallocWorld.seed=seed;
    Area area1;
    return mallocWorld;

}
/*
 * * size of short 0 à 65 535
 * * but the max size is 100
 */
Area generateArea(unsigned short heigthArea,  unsigned short widthArea){
    Area area;
    area.heigthArea=heigthArea;
    area.widthArea=widthArea;
    area.chunk=malloc(sizeof(short)*heigthArea*widthArea);
    for (int y=0;y<heigthArea;y++){
        for(int x=0;x<widthArea;x++){
            area.chunk[x][y]=0;
        }
    }
    return area;
}
