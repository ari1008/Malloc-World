#ifndef RECIPE_H_INCLUDED
#define RECIPE_H_INCLUDED

/*
**  Filename : recipe.h
**
**  Made by : HAN Felix
**
**  Description : Define recipes in the game
*/

//  Include library
#include "items.h"

// Give a alias to the level of a recipe
typedef enum  {
    RECIPE_EASY,
    RECIPE_MEDIUM,
    RECIPE_HARD
} RecipeLevel;

// Properties of a recipe
typedef struct  {
    Item product;
    Item needMaterial[2];
    RecipeLevel recipeLevel;
} Recipe;

#endif // RECIPE_H_INCLUDED
