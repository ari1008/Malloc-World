/*
**  Filename : player.c
**
**  Made by : Fumo Aristide
**
**  Description : Initialisation of player default properties
*/

//  Includes library
#include <stdlib.h>
#include <stdio.h>
#include "../headers/player.h"
#include "../headers/main.h"

/*
 *This function creates the day and its inventory
 */
Player*  createPlayer(){
    Player *player= malloc(sizeof(Player));
    player->level = 1;
    player->xpCurrent = 0;
    player->xpNext = 100;
    player->hpCurrent = 100;
    player->hpMax = 100;
    player->x=0;
    player->y=0;
    player->area=0;
    int resource0[2]={3,7};
    int resource1[2]={-10,-10};
    player->inventory[0]=createItemStart(1, "Wooden sword", "Armed",resource0 , resource1,10, 1, -10);
    resource0[0]=3;
    resource0[1]=7;
    resource1[0]=-10;
    resource1[1]=-10;
    player->inventory[1]=createItemStart(2, "Wooden pickaxe", "Tool",resource0 , resource1,10, -10, -10);
    resource0[0]=3;
    resource0[1]=7;
    resource1[0]=-10;
    resource1[1]=-10;
    player->inventory[2]=createItemStart(3, "Wooden billhook", "Tool",resource0 , resource1,10, -10, -10);
    resource0[0]=3;
    resource0[1]=7;
    resource1[0]=-10;
    resource1[1]=-10;
    player->inventory[3]=createItemStart(4, "Wooden ax", "Tool",resource0 , resource1,10, -10, -10);
    player->numberInventory=3;
    return player;
}

/*
 * This function allows you to create an item in a very precise way with all the possible parameters to customize
 */
Item createItemStart(int id, char* name, char* type, int* ressource0, int* ressource1, int durability, int damage, int hp){
    Item inventory;
    inventory.id=id;
    strcpy(inventory.name, name);
    strcpy(inventory.type, type);
    inventory.resource[0]=ressource0[0];
    inventory.resource[0]=ressource0[1];
    inventory.resource[1]=ressource1[0];
    inventory.resource[1]=ressource1[1];
    inventory.broke=0;
    inventory.durability=durability;
    inventory.damage=damage;
    inventory.hp=hp;
    return inventory;
}

/*
 * Allows you to launch the function that allows you to move
 */
void play(World* world, Player* player){
    move(world,player);
}

/*
 * It is a loop that allows the player to move in space according to these choices in the small menu
 */
void move(World *world, Player* player){
    int choice[2];
    int sceneSucces;
    int stop = 0;
    upgradeWorld(world, player);
    displayArea(world->area[player->area]);
    do{
        int *verif = verification(world->area[player->area], player->y, player->x);
        //
        world->area[player->area].chunk[player->y][player->x] = 0;
        displayPosition(verif, player->area, choice);
        printf("choice %d %d\n", choice[0], choice[1]);
        sceneSucces=launchScene(world->area[player->area], player, choice[1]);
        nextCase(world->area[player->area],player, choice[0]);
        upgradeWorld(world, player);
        displayArea(world->area[player->area]);
        printf("If you stop 6\n");
        scanf("%d",&stop);
    }while(stop !=6);
    ;
}

/*
 * Allows to update the player where he is according to what he has chosen
 */
int nextCase(Area area,Player *player, int move){
    switch (move) {
        case 0:
            high(area,player);
            break;
        case 1:
            right(area, player);
            break;
        case 2:
            bottom(area, player);
            break;
        case 3:
            left(area, player);
            break;
    }
    return 1;
}

/*
 * Starts the scene that must be done for the player's action,
 * either fighting a monster, recovering a resource, entering a passage.
 */
int launchScene(Area area, Player* player,int id){
    char* phase= malloc(sizeof(char)*50);
    strcpy(phase, scenePlay(id));
    printf("%s\n", phase);
    if(strcmp(phase, "Travel")==0){
        printf("Travel\n");
    }else if(strcmp(phase, "Monster")==0){
        printf("Pas encore fait\n");
    }else if(strcmp(phase, "Nothing")==0){
        printf("Nothing\n");
    }else if(strcmp(phase, "Rock")==0 || strcmp(phase, "Plant")==0 || strcmp(phase, "Wood")){
        printf("Rock\n");
        recupResources(area,player,phase, area.chunk[player->y][player->x]);
    }else if(strcmp(phase, "Sell")==0){
        printf("Sell\n");
    }
    free(phase);
    return 1;
}

/*
 * Allows to retrieve its type from the box travel, Monster, Nothing, etc.
 */
char* scenePlay(int id){
    char* scene= readLine(RESOURCES, id,3);
    return scene;
}

/*
 * Allows to put the player where he is on the next turn left
 */
void left(Area area,Player *player ){
    if(player->x == 0){
        player->x=area.widthArea-1;
    }else{
        player->x=player->x-1;
    }

}

/*
 * Allows to put the player where he is on the next turn  high
 */
void high(Area area, Player *player){
    if(player->y == 0){
        player->y=area.heigthArea-1;
    }else{
        player->y--;
    }
}

/*
 * Allows to put the player where he is on the next turn right
 */
void right(Area area, Player* player){
    if(player->x == area.widthArea-1){
        player->x=0;
    }else{
        player->x++;
    }
}

/*
 * Allows to put the player where he is on the next turn bottom
 */
void bottom(Area area, Player* player){
    if(player->y == area.heigthArea-1){
        player->y=0;
    }else{
        player->y++;
    }
}

/*
 * this function allows us to make a table of 4 boxes of
 * what the day can cause to fall on a monster etc.
 */
int* verification(Area area, int y, int x){
    int *movePosition = malloc(sizeof(int)*4);
    movePosition[0]= moveHigh(area,y, x);
    movePosition[1]= moveRight(area,y,x);
    movePosition[2]= moveLow(area,y, x);
    movePosition[3]= moveLeft(area,y, x);
    return movePosition;
}
/*
 * This function returns what is in box a High of player
 */
int moveHigh(Area area, int y,int x){
    if(y==area.heigthArea-1){
        return area.chunk[0][x];
    }else{
        return area.chunk[y+1][x];
    }
}
/*
 * This function returns what is in box a low of player
 */
int moveLow(Area area, int y,int x){
    if(0==y){
        return area.chunk[area.heigthArea-1][x];
    }else{
        return area.chunk[y-1][x];
    }
}

/*
 * This function returns what is in box a right of player
 */
int moveRight(Area area, int y, int x){
    if(x==area.widthArea-1){
        return area.chunk[y][0];
    }else{
        return area.chunk[y][x+1];
    }
}

/*
 * This function returns what is in box a left of player
 */
int moveLeft(Area area, int y, int x){
    if(x==0){
        return area.chunk[y][area.widthArea-1];
    }else{
       return area.chunk[y][x-1];
    }
}

/*
 * Allows to display all the possibilities that the player thanks to this possition.
 * it is this function which will create the small menu
 */
int* displayPosition(int* position, int area, int* choice){
    char compass[4][6]={"High\0","Right\0","Low\0","Left\0"};
    int count=0;
    int mov[4]={0,0,0,0};
    int box[4]={0,0,0,0};
    for(int i=0; i<4 ; i++){
        if(position[i]==-2 || position[i]==-3) {
            displayTravel(position[i], area, (char *) compass[i], count);
        }else if(position[i]==0){
            printf("\n%d: You can go %s",count, compass[i]);
        }else if(position[i]==2){
            displayPnj(area, (char *) compass, count);
        }else if(position[i]<=11 && position[i]>=3){
            displayResources(position[i],  (char *) compass[i], count);
        }else if(position[i]<=12){
            displayMonster(position[i], (char *) compass[i], count);
        }
        if(position[i]!=-1){
            mov[count]=i;
            count++;
            box[count]=position[i];
        }
        for (int j = 0; j < 4; ++j) {
            printf(" box[%d]=%d", j,box[j]);
        }
    }
    return choseNumber(count, mov, box, choice);
}

/*
 * This function to display in the small menu of choice when there is a monster and what type it is and or
 */
void displayMonster(int monster, char* compass, int count){
    if(monster==99){
        printf("\n%d: Face you the final boss  to %s",count, compass);
    } else{
        printf("\n%d: Face you against a level %d monster to %s",count,monster, compass);
    }
}

/*
 * This function to display in the small menu of choice when there is a pnj and what type it is and or
 */
void displayPnj(int area, char* compass, int count){
    switch (area) {
        case 1:
            printf("\n%d: You can go Joe level 1 to %s",count, compass);
            break;
        case 2:
            printf("\n%d: You can go Ben level 2 to %s",count, compass);
            break;
        case 3:
            printf("\n%d: You can go Leo level 3 to %s",count, compass);
            break;
    }
}

/*
 * This function allows you to display perfectly in the menu by launching the correct function
 */
void displayResources(int position, char* compass, int count){
    if(position%3==0){
        displayPlant(position,  compass, count);
    }else if(position==5 || position==8 || position==11){
        displayWood(position, compass, count);
    }else if(position==4 || position==7 || position==10){
        displayMineral(position, compass, count);
    }
}

/*
 * This function to display in the small menu of choice when there is a mineral and what type it is and or
 */
void displayMineral(int mineral, char* compass, int count){
    switch (mineral) {
        case 4:
            printf("\n%d: You can mine Rock to %s",count, compass );
            break;
        case 7:
            printf("\n%d: You can mine Iron to %s",count, compass );
            break;
        case 10:
            printf("\n%d: You can mine Diamond to %s",count, compass );
            break;
    }
}

/*
 * This function to display in the small choice menu when there is a wood and what type it is and or
 */
void displayWood(int wood, char* compass, int count){
    switch (wood) {
        case 5:
            printf("\n%d: You can  cut Fir to %s",count, compass );
            break;
        case 8:
            printf("\n%d: You can  cut Beech to %s",count, compass );
            break;
        case 11:
            printf("\n%d: You can cut Oak to %s",count, compass );
            break;
    }
}

/*
 * This function to display in the small menu of choice when there is a plant and what type it is and or
 */
void displayPlant(int plant, char* compass, int count){
    switch (plant) {
        case 3:
            printf("\n%d: You can collect Grass to %s",count, compass );
            break;
        case 6:
            printf("\n%d: You can collect Lavender to %s",count, compass );
            break;
        case 9:
            printf("\n%d: You can collect Hemp to %s",count, compass );
            break;
    }

}

/*
 * This function to display in the small choice menu when there is a passage and what type it is and or
 */
void displayTravel(int position, int area, char* compass, int count){
    if(area==1){
        printf("\n%d: You can teleport level %d to %s",count, area+1, compass );
    } else if(area==2){
        if( position==(-3) ){
            printf("\n%d: You can teleport level %d to %s",count, area+1, compass );
        }else{
            printf("\n%d: You can teleport level %d to %s",count, area-1, compass);
        }
    } else if(area==3){
        printf("\n%d: You can teleport level %d to %s",count, area-1, compass);
    }

}

/*
 * This function allows you to see if the number chosen by the player to advance is possible
 */
int* choseNumber(int count,int* mov,  int* box, int* choice){
    int number;
    char compass[4][6]={"High\0","Right\0","Low\0","Left\0"};
    printf("\nChoose your number ?\n");
    do {
        scanf("%d",&number);
        if(number >=0 && number <count){
            if(strcmp(compass[mov[number]],compass[0])==0){
                choice[0]=0;
                choice[1]=box[0];
            }else if(strcmp(compass[mov[number]],compass[1])==0){
                choice[0]=1;
                choice[1]=box[1];
            }else if(strcmp(compass[mov[number]],compass[2])==0){
                choice[0]=2;
                choice[1]=box[2];
            }else if(strcmp(compass[mov[number]],compass[3])==0){
                choice[0]=3;
                choice[1]=box[3];
            }
            return choice;
        }
        printf("Your choice does not exist\n");
    } while (1);
}

