#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>
#include <time.h>
#include "../headers/world.h"
#include "../headers/items.h"
#include "../headers/recipe.h"
#include "../headers/resources.h"
#include "../headers/player.h"
#include "../headers/npc.h"
#include "../headers/monster.h"
#include "../headers/main.h"
#define MAX 100
#define MIN 1
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
    int rand = randomMy();
    printf("Hello world!\n");
    printf("%d", rand);
   // World test =generateWorld(rand);
    return 0;
}

int randomMy(){
    srand((unsigned)time(NULL));
    return rand()%(MAX-MIN+1) + MIN;
}

