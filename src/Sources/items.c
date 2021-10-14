/*
**  Filename : items.c
**
**  Made by : HAN Felix
**
**  Description : Initialisation of items default properties
*/

//  Includes library
#include "../headers/items.h"

//  Material
//  Wood Level
Material stone = {
    .itemId = STONE,
    .name = "Pierre",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0
};

Material spruce = {
    .itemId = SPRUCE,
    .name = "Sapin",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0
};

Material grass = {
    .itemId = GRASS,
    .name = "Herbe",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0,
};

//  Stone Level
Material iron = {
    .itemId = IRON,
    .name = "Fer",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0
};

Material beech = {
    .itemId = BEECH,
    .name = "Hetre",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0
};

Material lavender = {
    .itemId = LAVENDER,
    .name = "Lavande",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0
};

//  Iron level
Material diamond = {
    .itemId = DIAMOND,
    .name = "Diamant",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0
};

Material oak = {
    .itemId = OAK,
    .name = "Chene",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0
};

Material hemp = {
    .itemId = HEMP,
    .name = "Chanvre",
    .type = MATERIAL,
    .quantityMax = 20,
    .durabilityCurrent = 0
};

//  TOOL
//  Wood Level
Tool woodenPickaxe = {
    .itemId = WOODEN_PICKAXE,
    .name = "Pioche en bois",
    .type = TOOL,
    .toolType = PICKAXE,
    .miningLevel = MINING_WOOD,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Tool woodenBillhook = {
    .itemId = WOODEN_BILLHOOK,
    .name = "Serpe en bois",
    .type = TOOL,
    .toolType = BILLHOOK,
    .miningLevel = MINING_WOOD,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Tool woodenAxe = {
    .itemId = WOODEN_AXE,
    .name = "HAche en bois",
    .type = TOOL,
    .toolType = AXE,
    .miningLevel = MINING_WOOD,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

//  STONE
Tool stonePickaxe = {
    .itemId = STONE_PICKAXE,
    .name = "Pioche en pierre",
    .type = TOOL,
    .toolType = PICKAXE,
    .miningLevel = MINING_STONE,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Tool stoneBillhook = {
    .itemId = STONE_BILLHOOK,
    .name = "Serpe en pierre",
    .type = TOOL,
    .toolType = BILLHOOK,
    .miningLevel = MINING_STONE,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Tool stoneAxe = {
    .itemId = STONE_AXE,
    .name = "Hache en pierre",
    .type = TOOL,
    .toolType = AXE,
    .miningLevel = MINING_STONE,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

//  IRON
Tool ironPickaxe = {
    .itemId = IRON_PICKAXE,
    .name = "Pioche en fer",
    .type = TOOL,
    .toolType = PICKAXE,
    .miningLevel = MINING_IRON,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Tool ironBillhook = {
    .itemId = IRON_BILLHOOK,
    .name = "Serpe en fer",
    .type = TOOL,
    .toolType = BILLHOOK,
    .miningLevel = MINING_IRON,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Tool ironAxe = {
    .itemId = IRON_AXE,
    .name = "Hache en fer",
    .type = TOOL,
    .toolType = AXE,
    .miningLevel = MINING_IRON,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

//  WEAPON
//  Wood Level
Weapon woodenSword = {
    .itemId = WOODEN_SWORD,
    .name = "Epee en bois",
    .type = WEAPON,
    .attackDamage = 1,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

//  Stone Level
Weapon stoneSword = {
    .itemId = STONE_SWORD,
    .name = "Epee en pierre",
    .type = WEAPON,
    .attackDamage = 2,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Weapon stoneSpear = {
    .itemId = STONE_SPEAR,
    .name = "Lance en pierre",
    .type = WEAPON,
    .attackDamage = 3,
    .quantityMax = 1,
    .durabilityCurrent = 8,
    .durabilityMax = 8
};

Weapon stoneHammer = {
    .itemId = STONE_HAMMER,
    .name = "Marteau en pierre",
    .type = WEAPON,
    .attackDamage = 4,
    .quantityMax = 1,
    .durabilityCurrent = 5,
    .durabilityMax = 5
};

//  Iron Level
Weapon ironSword = {
    .itemId = IRON_SWORD,
    .name = "Epee en fer",
    .type = WEAPON,
    .attackDamage = 5,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Weapon ironSpear = {
    .itemId = IRON_SPEAR,
    .name = "Lance en fer",
    .type = WEAPON,
    .attackDamage = 7,
    .quantityMax = 1,
    .durabilityCurrent = 8,
    .durabilityMax = 8
};

Weapon ironHammer = {
    .itemId = IRON_HAMMER,
    .name = "Marteau en fer",
    .type = WEAPON,
    .attackDamage = 10,
    .quantityMax = 1,
    .durabilityCurrent = 5,
    .durabilityMax = 5
};

//  Diamond Level
Weapon diamondSword = {
    .itemId = DIAMOND_SWORD,
    .name = "Epee en diamant",
    .type = WEAPON,
    .attackDamage = 10,
    .quantityMax = 1,
    .durabilityCurrent = 10,
    .durabilityMax = 10
};

Weapon diamondSpear = {
    .itemId = DIAMOND_SPEAR,
    .name = "Lance en diamant",
    .type = WEAPON,
    .attackDamage = 15,
    .quantityMax = 1,
    .durabilityCurrent = 8,
    .durabilityMax = 8
};

Weapon diamondHammer = {
    .itemId = DIAMOND_HAMMER,
    .name = "Marteau en diamant",
    .type = WEAPON,
    .attackDamage = 20,
    .quantityMax = 1,
    .durabilityCurrent = 5,
    .durabilityMax = 5
};

//  ARMOR
//  Stone Level
Armor stoneChestplate = {
    .itemId = STONE_CHESTPLATE,
    .name = "Plastron en pierre",
    .type = ARMOR,
    .armorResistance = 0.1,
    .quantityMax = 1,
    .durabilityCurrent = 0
};

//  Iron Level
Armor ironChestplate = {
    .itemId = IRON_CHESTPLATE,
    .name = "Plastron en fer",
    .type = ARMOR,
    .armorResistance = 0.2,
    .quantityMax = 1,
    .durabilityCurrent = 0
};

//  Diamond Level
Armor diamondChestplate = {
    .itemId = DIAMOND_CHESTPLATE,
    .name = "Plastron en diamant",
    .type = ARMOR,
    .armorResistance = 0.4,
    .quantityMax = 1,
    .durabilityCurrent = 0
};

//  POTION
//  Level I
Potion lifePotionI = {
    .itemId = LIFE_POTION_I,
    .name = "Potion de vie I",
    .type = POTION,
    .restoreLife = 30,
    .quantityMax= 1,
    .durabilityCurrent = 0
};

//  Level II
Potion lifePotionII = {
    .itemId = LIFE_POTION_II,
    .name = "Potion de vie II",
    .type = POTION,
    .restoreLife = 80,
    .quantityMax= 1,
    .durabilityCurrent = 0
};

//  Level III
Potion lifePotionIII = {
    .itemId = LIFE_POTION_III,
    .name = "Potion de vie III",
    .type = POTION,
    .restoreLife = 200,
    .quantityMax= 1,
    .durabilityCurrent = 0
};
