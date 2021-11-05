//
// Created by ari on 05/11/2021.
//

#ifndef MALLOC_WORLD_ALLSTRUCTURE_H
#define MALLOC_WORLD_ALLSTRUCTURE_H
#define  PATH "/home/ari/Documents/C/Malloc-World/resources/"
#define  MONSTER "item.txt"
#define  RESOURCES "resources.txt"
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
    char name[50];
    int hpCurrent;
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

#endif //MALLOC_WORLD_ALLSTRUCTURE_H
