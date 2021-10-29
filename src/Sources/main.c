#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>
#include <time.h>

#include "../headers/world.h"
#include "../headers/items.h"
#include "../headers/recipe.h"
#include "../headers/resources.h"
#include "../headers/npc.h"
#include "../headers/monster.h"
#include "../headers/player.h"
#include "../headers/main.h"
#include "../headers/player.h"

#define  MIN 10
#define  MAX 100

#define SIZE 1

/*
**  Filename : main.c
**
**  Made by : HAN Felix
**  and
** FUMO Aristide
**  Description :
*/

//  Includes library




int main(void) {
    World *world= generateWorld(1);
    Player *player = createPlayer();
    play(world, player);
    return 0;
}

int randomWorld(){
    int nombre = 0;
    // Initialisation de la donnée seed
    nombre = rand() % (20 + 5);
    return nombre;

}




