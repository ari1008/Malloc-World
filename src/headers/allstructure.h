//
// Created by ari on 05/11/2021.
//

#ifndef MALLOC_WORLD_ALLSTRUCTURE_H
#define MALLOC_WORLD_ALLSTRUCTURE_H
#include <bits/types/FILE.h>
#define  PATH "/home/ari/Documents/C/Malloc-World/resources/"
#define  MONSTER "item.txt"
#define  RESOURCES "resources.txt"
#define PNJ "pnj.txt\0"
#define PNJ1 "pnj1.txt\0"
#define PNJ2 "pnj2.txt\0"

typedef enum WorldObject_ID {
    GATE_AREA_II_III = -3,
    GATE_AREA_I_II,
    WALL,
    EMPTY_SPACE,
    PLAYER,
    NON_PLAYEUR_CHARACTER,
    PLANT_I,
    ROCK_I,
    WOOD_I,
    PLANT_II,
    ROCK_II,
    WOOD_II,
    PLANT_III,
    ROCK_III,
    WOOD_III,
    ZOMBIE,
    SKELETON,
    SPIDER,
    FINAL_BOSS = 99
} WorldObject_ID;

//  Give a position to an object
typedef struct  {
    short x;
    short y;
} Position;

typedef struct  {
    int id;
    char name[50];
    char type[50];
    int hp;
    int broke;
    int save;
    int damage;
    int resistance;
    int number;
    int durability;
    int resource[2];
    int resource1[2];
    struct Item* next;
} Item;

typedef struct  {
    Item* item;
    Item* item1;
} ItemTwo;

typedef struct {
    char *username;
    short level;
    int xpCurrent;
    int xpNext;
    short hpCurrent;
    short hpMax;
    int x;
    int y;
    Item inventory[10];
    int numberInventory;
    short area;
} Player;

typedef struct  {
    char name[50];
    int hpCurrent;
    int type;
    int hpMax;
    const int xpDrop;
    int respawnTime;
    int x;
    int y;
    short view;
    struct Monster* next;
} Monster;

struct Resources {
    int id;
    int positionX;
    int positionY;
    short respawn;
    short view;
    struct Resources* next;
};
typedef struct Resources Resources;
//  Properties of the world's area
typedef struct {
    int** chunk;
    int heigthArea;
    int widthArea;
    Resources* wood;
    Resources* mineral;
    Resources* plant;
    Monster* monster;
    int* three;
    int* two;
    Item* pnj;
    Item* storage;
} Area;

//  Properties of the world
typedef struct  {
    int seed;
    Area area[3];
} World;

typedef struct {
    Monster* monster;
    Resources* plant;
    Resources* wood;
    Resources* mineral;
}TabAll;


#endif //MALLOC_WORLD_ALLSTRUCTURE_H
