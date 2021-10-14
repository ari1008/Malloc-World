#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

/*
**  Filename : world.h
**
**  Made by : HAN Felix
**
**  Description : Define the properties of world in game
*/

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

//  Properties of the world's area
typedef struct {
    short** chunk;
    unsigned  short heigthArea;
    unsigned  short widthArea;
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

//  Generate a world from a seed
World generateWorld (int seed);
Area generateArea(unsigned  short heigthArea, unsigned  short widthArea);
#endif // WORLD_H_INCLUDED


