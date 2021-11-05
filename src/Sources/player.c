/*
**  Filename : player.c
**
**  Made by : HAN Felix
**
**  Description : Initialisation of player default properties
*/

//  Includes library
#include <stdlib.h>
#include <stdio.h>
#include "../headers/player.h"

//  Player's inventory default starter
/*Inventory inventory = {
    .armor[0].itemId = NONE,
    .armor[0].quantity = 0,
    .weapon[0].itemId = WOODEN_SWORD,
    .weapon[0].quantity = 1,
    .slot[0].itemId = WOODEN_PICKAXE,
    .slot[0].quantity = 1,
    .slot[1].itemId = WOODEN_AXE,
    .slot[1].quantity = 1,
    .slot[2].itemId = BILLHOOK,
    .slot[2].quantity = 1,
    .slot[3].itemId = NONE,
    .slot[3].quantity = 0,
    .slot[4].itemId = NONE,
    .slot[4].quantity = 0,
    .slot[5].itemId = NONE,
    .slot[5].quantity = 0,
    .slot[6].itemId = NONE,
    .slot[6].quantity = 0,
    .slot[7].itemId = NONE,
    .slot[7].quantity = 0,
    .slot[8].itemId = NONE,
    .slot[8].quantity = 0,
    .slot[9].itemId = NONE,
    .slot[9].quantity = 0
};*/

//  Player default properties at the start of the game


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
    return player;
}

void play(World* world, Player* player){
    move(world,player);
}

void move(World *world, Player* player){
    int choice[2];
    displayArea(world->area[player->area]);
    int *verif = verification(world->area[player->area], player->y, player->x);
    displayPosition(verif, player->area, choice);
    printf("%d %d", choice[0], choice[1]);
}

void left(Area area,Player *player ){
    if(player->x == 0){
        area.chunk[player->y][area.widthArea-1]=1;
        player->x=area.widthArea-1;
    }else{
        area.chunk[player->y][player->x-1]=1;
        player->x=player->x-1;
    }

}
void high(Area area, Player *player){
    if(player->y == 0){
        area.chunk[area.heigthArea-1][player->x]=1;
        player->y=area.heigthArea-1;
    }else{
        area.chunk[player->y-1][player->x]=1;
        player->y--;
    }
}
void right(Area area, Player* player){
    if(player->x == area.widthArea-1){
        area.chunk[player->y][0]=1;
        player->x=0;
    }else{
        area.chunk[player->y][player->x+1]=1;
        player->x++;
    }
}
void bottom(Area area, Player* player){
    if(player->y == area.heigthArea-1){
        area.chunk[0][player->x]=1;
        player->y=0;
    }else{
        area.chunk[player->y+1][player->x]=1;
        player->y++;
    }
}

int* verification(Area area, int y, int x){
    int *movePosition = malloc(sizeof(int)*4);
    movePosition[0]= moveHigh(area,y, x);
    movePosition[1]= moveRight(area,y,x);
    movePosition[2]= moveLow(area,y, x);
    movePosition[3]= moveLeft(area,y, x);
    return movePosition;
}

int moveHigh(Area area, int y,int x){
    if(y==area.heigthArea-1){
        return area.chunk[0][x];
    }else{
        return area.chunk[y+1][x];
    }
}

int moveLow(Area area, int y,int x){
    if(0==y){
        return area.chunk[area.heigthArea-1][x];
    }else{
        return area.chunk[y-1][x];
    }
}

int moveRight(Area area, int y, int x){
    if(x==area.widthArea-1){
        return area.chunk[y][0];
    }else{
        return area.chunk[y][x+1];
    }
}

int moveLeft(Area area, int y, int x){
    if(x==0){
        return area.chunk[y][area.widthArea-1];
    }else{
       return area.chunk[y][x-1];
    }
}

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
    }
    return choseNumber(count, mov, box, choice);
}

void displayMonster(int monster, char* compass, int count){
    if(monster==99){
        printf("\n%d: Face you the final boss  to %s",count, compass);
    } else{
        printf("\n%d: Face you against a level %d monster to %s",count,monster, compass);
    }
}

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

void displayResources(int position, char* compass, int count){
    if(position%3==0){
        displayPlant(position,  compass, count);
    }else if(position==5 || position==8 || position==11){
        displayWood(position, compass, count);
    }else if(position==4 || position==7 || position==10){
        displayMineral(position, compass, count);
    }
}

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

