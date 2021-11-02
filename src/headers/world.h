#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

/*
**  Filename : world.h
**
**  Made by : HAN Felix
**
**  Description : Define the properties of world in game
*/

#include "resources.h"
#include "monster.h"

// Give alias to world's objects
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

typedef struct  {
    //const WorldObject_ID worldId;
    const char name[20];
    int hpCurrent;
    int hpMax;
    const int xpDrop;
    int respawnTime;
    int x;
    int y;
    short view;
    struct Monster* point;
} Monster;

struct Resources {
    int id;
    int positionX;
    int positionY;
    short respawn;
    short view;
    struct Resources* resources;
};
typedef struct Resources Resources;
//  Properties of the world's area
typedef struct {
    int** chunk;
    int heigthArea;
    int widthArea;
    Resources* resources;
    Monster* monster;
} Area;

//  Properties of the world
typedef struct  {
    int seed;
    Area area[3];
} World;

//  Give a position to an object
typedef struct  {
    short x;
    short y;
} Position;

typedef struct {
    Monster* monster;
    Resources* resources;
}TabMonsterResources;

//  Generate a world from a seed
int randomMy(int min, int max);
World * generateWorld (int seed);
void generateArea(Area area,Resources* resources,Monster* monster, int numberArea);

void  displayArea(Area area);

void createAll(Area area,Resources* resources,Monster* monster,TabMonsterResources* tabMonsterResources, int numberArea);
void  createTravel(Area area, int numberArea );
Monster*  createMonster(Area area,Monster* monster, int numberArea);

void  createPnj(Area area);
Resources*  createRessource(Area area,Resources* resources, int numberArea);
Resources*  createPlant(Area area,Resources* resources, int numberArea);
void  createWood(Area area,Resources* resources, int numberArea);
void  createMineral(Area area,Resources* resources, int numberArea);

int* checkCase(Area area, int type, int* result);

void  newResources(Area area);
Resources* newElementResources( int type, int y, int x);
Monster*   newElementMonster(int type, int y, int x);
#endif // WORLD_H_INCLUDED


