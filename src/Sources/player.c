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
    int stop = 0;
    displayArea(world->area[player->area]);
    do {

        if(stop==2){
            exit(1);
        }
        int *verif = verification(world->area[player->area], player->x, player->y);
        int compass = displayPosition(verif);
        world->area[player->area].chunk[player->y][player->x] = 0;
        switch (compass) {
            case 0:
                printf("Test  %d %d\n", player->y, player->x);
                high(world->area[player->area], player);
                displayArea(world->area[player->area]);
                break;
            case 1:
                right(world->area[player->area], player);
                displayArea(world->area[player->area]);
                break;
            case 2:
                bottom(world->area[player->area], player);
                displayArea(world->area[player->area]);
                break;
            case 3:
                left(world->area[player->area], player);
                displayArea(world->area[player->area]);
                break;
        }
        stop++;
    }while(1);
}

void left(Area area,Player *player ){
    if(player->x == 0){
        area.chunk[player->y][area.widthArea-1]=1;
        player->x=area.widthArea;
    }else{
        area.chunk[player->y][player->x--]=1;
        player->x--;
    }
}
void high(Area area, Player *player){
    printf("Test 1 %d %d\n", player->y, player->x);
    if(player->y == 0){
        area.chunk[area.heigthArea-1][player->x]=1;
        player->y=area.heigthArea;
    }else{
        area.chunk[player->y-1][player->x]=1;
        player->y--;
    }
    printf("Test 2 %d %d\n", player->y, player->x);
}
void right(Area area, Player* player){
    if(player->x == area.widthArea){
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
        if(area.chunk[0][x]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(area.chunk[y+1][x]==0){
            return 1;
        }else{
            return 0;
        }
    }
}

int moveLow(Area area, int y,int x){
    if(0==y){
        if(area.chunk[area.heigthArea-1][x]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(area.chunk[y-1][x]==0){
            return 1;
        }else{
            return 0;
        }
    }
}

int moveRight(Area area, int y, int x){
    if(x==area.widthArea-1){
        if(area.chunk[y][0]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(area.chunk[y][x+1]==0){
            return 1;
        }else{
            return 0;
        }
    }
}

int moveLeft(Area area, int y, int x){
    if(x==0){
        if(area.chunk[y][area.widthArea-1]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(area.chunk[y][x-1]==0){
            return 1;
        }else{
            return 0;
        }
    }
}

int displayPosition(int* position){
    char compass[4][6]={"High\0","Right\0","Low\0","Left\0"};
    int count=0;
    int mov[4]={0,0,0,0};
    int number;
    for(int i=0; i<4 ; i++){
        if(position[i]==1){
            printf("\n%d: You can go %s",count, compass[i]);
            mov[count]=i;
            count++;
        }
    }
    printf("\nChoose your number ?\n");
    do {
        scanf("%d",&number);
        if(number >=0 && number <count){
            if(strcmp(compass[mov[number]],compass[0])==0){
                return 0;
            }else if(strcmp(compass[mov[number]],compass[1])==0){
                return 1;
            }else if(strcmp(compass[mov[number]],compass[2])==0){
                return 2;
            }else if(strcmp(compass[mov[number]],compass[3])==0){
                return 3;
            }
        }
        printf("Your choice does not exist\n");
    } while (1);
}

