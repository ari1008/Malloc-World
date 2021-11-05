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

Monster* newElementMonster(int type, int y, int x){
    Monster* monster= malloc(sizeof(Monster));
    monster->hpMax=type;
    char* name=readLine(RESOURCES, type,2 );
    strcpy(monster->name, name);
    monster->hpCurrent=type;
    monster->respawnTime=15;
    monster->view=1;
    monster->x=x;
    monster->y=y;
    monster->next=NULL;
    return monster;
}

void printMonster(Monster* monster){
    while (monster != NULL){
        printf("%s\n", monster->name);
        monster= (Monster *) monster->next;
    }
}

Monster* createMonster(Area area,Monster* monster, int numberArea){
    int xYMonster[2];
    int type;
    switch (numberArea) {
        case 0:
            type = randomMy(12, 20);
            checkCase(area,type,xYMonster);
            monster= newElementMonster(type,xYMonster[0],xYMonster[1]);
            for (int i = 0; i < 2; ++i) {
                type = randomMy(12, 20);
                checkCase(area, type,xYMonster);
                monster->next= (struct Monster *) newElementMonster(type, xYMonster[0], xYMonster[1]);
            }
            break;
        case 1:
            type = randomMy(20, 50);
            checkCase(area,type ,xYMonster);
            monster= newElementMonster(type,xYMonster[0],xYMonster[1]);
            for (int i = 0; i < 2; ++i) {
                type = randomMy(20, 50);
                checkCase(area, type,xYMonster);
                monster->next= (struct Monster *) newElementMonster(type, xYMonster[0], xYMonster[1]);
            }
            break;
        case  2:
            type = randomMy(50,98);
            checkCase(area, type,xYMonster);
            monster=newElementMonster(type,xYMonster[0],xYMonster[1]);
            for (int i = 0; i < 2; ++i) {
                type = randomMy(50,98);
                checkCase(area, randomMy(50, 98),xYMonster);
                monster->next= (struct Monster *) newElementMonster(type, xYMonster[0], xYMonster[1]);
            }
            checkCase(area, 99, xYMonster);
            monster->next=(struct Monster *) newElementMonster(99, xYMonster[0], xYMonster[1]);
            break;

    }
    return monster;
}

