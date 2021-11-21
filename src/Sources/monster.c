/*
**  Filename : monster.c
**
**  Made by : FUMO Aristide
**
**  Description : Initialisation of monsters default properties
*/

//  Includes library
#include "../headers/monster.h"
#include "../headers/main.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Function to create a new monster in the chained list
 */
Monster* newElementMonster(int type, int y, int x){
    Monster* monster= malloc(sizeof(Monster));
    monster->hpMax=type;
    char* name=readLine(RESOURCES, type,2 );
    strcpy(monster->name, name);
    monster->hpCurrent=type;
    monster->type=type;
    monster->respawnTime=15;
    monster->view=1;
    monster->x=x;
    monster->y=y;
    monster->next=NULL;
    return monster;
}

/*
 * Display for debugging for now
 */
void printMonster(Monster* monster){
    while (monster != NULL){
        printf("%s\n",monster->name);
        monster= (Monster *) monster->next;
    }
}

/*
 * This function create the monsters according to the map.
 * And the interval of the level that they are in the chained list is displayed with the start of the chain pointer.
 */
Monster* createMonster(Area area,Monster* monster, int numberArea){
    int xYMonster[2];
    int type;
    Monster* monsterfirst;
    switch (numberArea) {
        case 0:
            type = randomMy(12, 20);
            checkCase(area,type,xYMonster);
            monster= newElementMonster(type,xYMonster[0],xYMonster[1]);
            monsterfirst=monster;
            for (int i = 0; i < 2; ++i) {
                type = randomMy(12, 20);
                checkCase(area, type,xYMonster);
                monsterfirst->next= (struct Monster *) newElementMonster(type, xYMonster[0], xYMonster[1]);
                monsterfirst= (Monster *) monsterfirst->next;
            }
            break;
        case 1:
            type = randomMy(20, 50);
            checkCase(area,type ,xYMonster);
            monster= newElementMonster(type,xYMonster[0],xYMonster[1]);
            monsterfirst=monster;
            for (int i = 0; i < 2; ++i) {
                type = randomMy(20, 50);
                checkCase(area, type,xYMonster);
                monsterfirst->next= (struct Monster *) newElementMonster(type, xYMonster[0], xYMonster[1]);
                monsterfirst= (Monster *) monsterfirst->next;
            }
            break;
        case  2:
            type = randomMy(50,98);
            checkCase(area, type,xYMonster);
            monster=newElementMonster(type,xYMonster[0],xYMonster[1]);
            monsterfirst=monster;
            for (int i = 0; i < 2; ++i) {
                type = randomMy(50,98);
                checkCase(area, randomMy(50, 98),xYMonster);
                monsterfirst->next= (struct Monster *) newElementMonster(type, xYMonster[0], xYMonster[1]);
                monsterfirst= (Monster *) monsterfirst->next;
            }
            checkCase(area, 99, xYMonster);
            monsterfirst->next=(struct Monster *) newElementMonster(99, xYMonster[0], xYMonster[1]);
            break;
    }
    return monster;
}

/*
 * This function checks whether the monster has the right to be displayed or not
 */

void verifMonster(Area area, Monster* monster){
    while (monster!=NULL){
        if(monster->view==1){
            area.chunk[monster->y][monster->y]=monster->type;
        }else{
            area.chunk[monster->y][monster->y]=0;
        }
        monster= (Monster *) monster->next;
    }
}
