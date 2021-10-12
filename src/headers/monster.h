#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

/*
**  Filename : monster.h
**
**  Made by : HAN Felix
**
**  Description : Define properties of monsters
*/

//  Include library
#include <string.h>
#include "world.h"

// Properties of a monster
typedef struct  {
    const WorldObject_ID worldId;
    const char name[20];
    short hpCurrent;
    short hpMax;
    const int xpDrop;
    short respawnTime;
    Position position;
} Monster;



#endif // MONSTER_H_INCLUDED
