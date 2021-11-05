#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/*
**  Filename : main.h
**
**  Made by : HAN Felix
**
**  Description : Start the Game Malloc World
*/
#include "allstructure.h"
//  Save the game in a file
void SaveGame ();
//  Load a Game from an file
void LoadGame ();
int randomWorld();
char* readLine(char* filename, int type, int number);
char* information(char* line, int number);
#endif // MAIN_H_INCLUDED
