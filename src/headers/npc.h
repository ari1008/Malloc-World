#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

/*
**  Filename : npc.h
**
**  Made by : HAN Felix
**
**  Description : Define properties of a non-player-character
*/

//  Include library
#include <string.h>
#include "items.h"

//  Properties of a warehouse
typedef struct  {
    Item item;
    struct Warehouse* next;
} Warehouse;

// Properties of a non-player-character
typedef struct {
    const WorldObject_ID worldId;
    const char name[20];
    Warehouse* warehouse;
} Npc;

#endif // NPC_H_INCLUDED
