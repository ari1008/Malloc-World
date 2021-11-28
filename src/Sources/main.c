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



/*
 * Start the program generously for everyone and the card
 */
int main(void) {
    srand(time(NULL));
    World *world= generateWorld(1);
    Player *player = createPlayer();
    play(world, player);
    return 0;
}

/*
 *Random function to give the x and y size of the map
 */
int randomWorld(){
    int nombre = 0;
    // Initialisation de la donnée seed
    nombre = (rand() % (MAX - MIN + 1)) + MIN;
    return nombre;

}

/*
 * Allows you to read a file line by line
 */
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

/*
 * Retrieves the information between two; in what has in the row data.
 */
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

/*
 * To free everything
 */
void freeAll(World* world, Player* player){
    freeWorld(world);
    free(world);
    free(player);
}

/*
 * To free player
 */
void freePlayer(Player* player){
    for(int x=0;x<50;x++){
        free(player->username[x]);
    }
}

/*
 * To free monster
 */
void freeMonster(Monster* monster){
    if (monster->next != NULL){
        freeMonster((Monster *) monster->next);
    }
    //free(monster);
}

/*
 * To free Resources
 */
void freeResources(Resources* resource){
    if (resource->next != NULL){
        freeResources((Resources *) resource->next);
    }
    free(resource);
}

/*
 * To free Item
 */
void freeItem(Item* item){
    if (item->next != NULL){
        freeItem((Item *) item->next);
    }
    free(item);
}

/*
 * To free World
 */
void freeWorld(World* world){
    freeArea(world->area[0]);
    freeArea(world->area[1]);
    freeArea(world->area[2]);
}

/*
 * To free Area
 */
void freeArea(Area area){
    freeMonster(area.monster);
    freeResources(area.plant);
    freeResources(area.mineral);
    freeResources(area.wood);
    freeItem(area.pnj);
    //freeItem(area.storage);
    free((void *) area.three);
    free((void *) area.two);
    //freeTab(2,area.two);
    //freeDoubleTab(area.widthArea, area.heigthArea,  area.chunk);
}

/*
 * To free  arrays but not work
 */
void freeTab(int number, int* tab){
    for(int i=0;i<number;i++){
        free(&tab[i]);
    }
}

/*
 * To free double arrays but not work
 */
void freeDoubleTab(int widthArea, int heigthArea, int** tab){
    int y;
    for (y=heigthArea-1; y >= 0; y--){
        for (int  x  =widthArea-1; x >= 0; x--) {
            free(tab[y][x]);
        }
    }
}

/*
 * Write anything to the backup file
 */
void  toWrite(World* world, Player* player){
    char* path=malloc(sizeof(char)*62);
    strcpy(path,PATH );
    strcat(path,SAVE);
    FILE *fp = fopen(path,"w+");
    fprintf( fp, " === MAP === \n");
    for (int i = 0; i < 3; ++i) {
        toWriteArea(world->area[i], fp, i);
    }
    toWritePlayer(player, fp);

}

/*
 * Write the card to the backup file
 */
void toWriteArea(Area area, FILE* fp, int number){
    switch (number) {
        case 0:
            fprintf(fp," -- ZONE 1 -- \n");
            break;
        case 1:
            fprintf(fp," -- ZONE 2 -- \n");
            break;
        case 2:
            fprintf(fp," -- ZONE 3 -- \n");
            break;
    }
    for (int y = 0; y < area.heigthArea; ++y) {
        for (int x = 0; x < area.widthArea; ++x) {
            fprintf(fp,"%d ", area.chunk[y][x]);
        }
        fprintf(fp,"\n");
    }
}

/*
 * Write everything you need for the player
 */
void toWritePlayer(Player* player, FILE* fp){
    fprintf(fp,"=== PLAYER ===\n");
    fprintf(fp,"{%d}{%d}\n", player->xpCurrent, player->xpNext);
    fprintf(fp,"{%d}{%d}\n", player->hpCurrent, player->hpMax);
    fprintf(fp," -- INVENTORY --\n");
    fprintf(fp,"\n -- STORAGE --\n");
}