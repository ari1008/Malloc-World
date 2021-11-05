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

#define  MIN 5
#define  MAX 10

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
    srand(time(NULL));
    World *world= generateWorld(1);
    Player *player = createPlayer();
    play(world, player);
    /*char* filename="resources.txt\0";
    printf("%s",readLigne(filename, 7, 1));*/
    return 0;
}

int randomWorld(){
    int nombre = 0;
    // Initialisation de la donnée seed
    nombre = (rand() % (MAX - MIN + 1)) + MIN;
    return nombre;

}

char* readLine(char* filename, int type, int number){
    char* path=malloc(sizeof(char)*62);
    strcpy(path,PATH );
    strcat(path,filename);
    FILE *file = fopen(path, "r");
    int count;
    char line[256];
    if(strcmp(filename,"resources.txt" )==0){
        count=-3;
    }else{
        count=1;
    }
    if (file != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) {
            if(type==count){
                char *result=information(line,number);
                return result;
            }
            count++;
        }
        fclose(file);
    }
    return NULL;

}

char* information(char* line, int number){
    char* separators=";";
    int count=0;
    char * strToken = strtok ( line, separators );
    while ( strToken != NULL ) {
        count++;
        if(count==number){
            return strToken;
        }
        strToken = strtok ( NULL, separators );
    }

    return NULL;
}





