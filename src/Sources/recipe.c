/*
**  Filename : recipe.c
**
**  Made by : HAN Felix
**
**  Description : Initialisation of default recipes
*/

//  Includes library
#include <stdlib.h>
#include "../headers/recipe.h"

//  TOOL
//  WOOD
Recipe woodenPickaxeRecipe = {
    .product.itemId = WOODEN_PICKAXE,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 3,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_EASY
};

Recipe woodenBillhookRecipe = {
    .product.itemId = WOODEN_BILLHOOK,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 3,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_EASY
};

Recipe woodenAxeRecipe = {
    .product.itemId = WOODEN_AXE,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 3,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_EASY
};

//  STONE
Recipe stonePickaxeRecipe = {
    .product.itemId = STONE_PICKAXE,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = STONE,
    .needMaterial[1].quantity = 3,
    .recipeLevel = RECIPE_EASY
};

Recipe stoneBillhookRecipe = {
    .product.itemId = STONE_BILLHOOK,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = STONE,
    .needMaterial[1].quantity = 3,
    .recipeLevel = RECIPE_EASY
};

Recipe stoneAxeRecipe = {
    .product.itemId = STONE_AXE,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = STONE,
    .needMaterial[1].quantity = 3,
    .recipeLevel = RECIPE_EASY
};

//  IRON
Recipe ironPickaxeRecipe = {
    .product.itemId = IRON_PICKAXE,
    .product.quantity = 1,
    .needMaterial[0].itemId = BEECH,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = IRON,
    .needMaterial[1].quantity = 4,
    .recipeLevel = RECIPE_MEDIUM
};

Recipe ironBillhookRecipe = {
    .product.itemId = IRON_BILLHOOK,
    .product.quantity = 1,
    .needMaterial[0].itemId = BEECH,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = IRON,
    .needMaterial[1].quantity = 4,
    .recipeLevel = RECIPE_MEDIUM
};

Recipe ironAxeRecipe = {
    .product.itemId = IRON_AXE,
    .product.quantity = 1,
    .needMaterial[0].itemId = BEECH,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = IRON,
    .needMaterial[1].quantity = 4,
    .recipeLevel = RECIPE_MEDIUM
};

//  WEAPON
//  WOOD
Recipe woodenSwordRecipe = {
    .product.itemId = WOODEN_SWORD,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 3,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_EASY
};

//  STONE
Recipe stoneSwordRecipe = {
    .product.itemId = STONE_SWORD,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = STONE,
    .needMaterial[1].quantity = 3,
    .recipeLevel = RECIPE_EASY
};

Recipe stoneSpearRecipe = {
    .product.itemId = STONE_SPEAR,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 3,
    .needMaterial[1].itemId = STONE,
    .needMaterial[1].quantity = 4,
    .recipeLevel = RECIPE_EASY
};

Recipe stoneHammerRecipe = {
    .product.itemId = STONE_HAMMER,
    .product.quantity = 1,
    .needMaterial[0].itemId = SPRUCE,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = STONE,
    .needMaterial[1].quantity = 6,
    .recipeLevel = RECIPE_EASY
};

//  IRON
Recipe ironSwordRecipe = {
    .product.itemId = IRON_SWORD,
    .product.quantity = 1,
    .needMaterial[0].itemId = BEECH,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = IRON,
    .needMaterial[1].quantity = 4,
    .recipeLevel = RECIPE_MEDIUM
};

Recipe ironSpearRecipe = {
    .product.itemId = IRON_SPEAR,
    .product.quantity = 1,
    .needMaterial[0].itemId = BEECH,
    .needMaterial[0].quantity = 3,
    .needMaterial[1].itemId = IRON,
    .needMaterial[1].quantity = 5,
    .recipeLevel = RECIPE_MEDIUM
};

Recipe ironHammerRecipe = {
    .product.itemId = IRON_HAMMER,
    .product.quantity = 1,
    .needMaterial[0].itemId = BEECH,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = IRON,
    .needMaterial[1].quantity = 7,
    .recipeLevel = RECIPE_MEDIUM
};

//  DIAMOND
Recipe diamondSwordRecipe = {
    .product.itemId = DIAMOND_SWORD,
    .product.quantity = 1,
    .needMaterial[0].itemId = OAK,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = DIAMOND,
    .needMaterial[1].quantity = 5,
    .recipeLevel = RECIPE_HARD
};

Recipe diamondSpearRecipe = {
    .product.itemId = DIAMOND_SPEAR,
    .product.quantity = 1,
    .needMaterial[0].itemId = OAK,
    .needMaterial[0].quantity = 3,
    .needMaterial[1].itemId = DIAMOND,
    .needMaterial[1].quantity = 6,
    .recipeLevel = RECIPE_HARD
};

Recipe diamondHammerRecipe = {
    .product.itemId = DIAMOND_HAMMER,
    .product.quantity = 1,
    .needMaterial[0].itemId = OAK,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = DIAMOND,
    .needMaterial[1].quantity = 8,
    .recipeLevel = RECIPE_HARD
};

//  ARMOR
//  STONE
Recipe stoneChestplateRecipe = {
    .product.itemId = STONE_CHESTPLATE,
    .product.quantity = 1,
    .needMaterial[0].itemId = STONE,
    .needMaterial[0].quantity = 10,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_EASY
};

//  IRON
Recipe ironChestplateRecipe = {
    .product.itemId = IRON_CHESTPLATE,
    .product.quantity = 1,
    .needMaterial[0].itemId = IRON,
    .needMaterial[0].quantity = 12,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_MEDIUM
};

//  DIAMOND
Recipe diamondChestplateRecipe = {
    .product.itemId = DIAMOND_CHESTPLATE,
    .product.quantity = 1,
    .needMaterial[0].itemId = DIAMOND,
    .needMaterial[0].quantity = 16,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_HARD
};

//  POTION
// Level I
Recipe potionIRecipe = {
    .product.itemId = LIFE_POTION_I,
    .product.quantity = 1,
    .needMaterial[0].itemId = GRASS,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_EASY
};

// Level II
Recipe potionIIRecipe = {
    .product.itemId = LIFE_POTION_II,
    .product.quantity = 1,
    .needMaterial[0].itemId = LAVENDER,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_MEDIUM
};

// Level III
Recipe potionIIIRecipe = {
    .product.itemId = LIFE_POTION_III,
    .product.quantity = 1,
    .needMaterial[0].itemId = HEMP,
    .needMaterial[0].quantity = 2,
    .needMaterial[1].itemId = NONE,
    .needMaterial[1].quantity = 0,
    .recipeLevel = RECIPE_HARD
};
