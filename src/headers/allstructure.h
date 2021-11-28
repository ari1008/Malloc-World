//
// Created by ari on 05/11/2021.
//

#ifndef MALLOC_WORLD_ALLSTRUCTURE_H
#define MALLOC_WORLD_ALLSTRUCTURE_H
#include <bits/types/FILE.h>
#define  PATH "/home/ari/Documents/C/Malloc-World/resources/"
#define  ITEM "item.txt"
#define  RESOURCES "resources.txt"
#define PNJ "pnj.txt\0"
#define PNJ1 "pnj1.txt\0"
#define PNJ2 "pnj2.txt\0"
#define SAVE  "save.txt"

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

/*
 * It is a structure for the items in the inventory
 */
typedef struct  {
    int id; //It is the type of the object in figure
    char name[50]; // The name of the object
    char type[50]; // The type of the object a tool ...
    int hp; // Hit points
    int broke; // Is the object broken
    int save;
    int damage;
    int resistance;
    int number;
    int durability;
    int resource[2]; //The first is the number you need and the second
    int resource1[2]; // is the id of what you need
    struct Item* next;
} Item;

//Used by return to have two item structure pointers
typedef struct  {
    Item* item;
    Item* item1;
} ItemTwo;

//Player structure
typedef struct {
    char *username;
    short level;
    int xpCurrent;
    int xpNext;
    short hpCurrent;
    short hpMax;
    int x;
    int y;
    Item inventory[10]; // It is his inventory which is a structure table of 10
    int numberInventory;
    short area;
} Player;

//The structure of monsters
typedef struct  {
    char name[50];
    int hpCurrent; // How high is it
    int type; //of her type he is between 12-99
    int hpMax;
     int xpDrop;
    int respawnTime;
    int x;// position x
    int y; // position y
    short view;
    struct Monster* next; //
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
    int** chunk; // The double table of
    int heigthArea; // max Y
    int widthArea;// max X
    //These are chain lists of materials
    Resources* wood;
    Resources* mineral;
    Resources* plant;
    Monster* monster;
    //Table of x and y positions of travels
    int* three;
    int* two;
    Item* pnj; // Chain lists of what the pnj sells
    Item* storage;//Chain lists of  what is in the PNJ's safe
} Area;

//  Properties of the world
typedef struct  {
    int seed;
    Area area[3];//It is a table to have all the cards
} World;

//To retrieve all the linked lists of what the card has
typedef struct {
    Monster* monster;
    Resources* plant;
    Resources* wood;
    Resources* mineral;
}TabAll;


#endif //MALLOC_WORLD_ALLSTRUCTURE_H
