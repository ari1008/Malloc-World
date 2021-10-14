#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED

/*
**  Filename : items.h
**
**  Made by : HAN Felix
**
**  Description : Define the properties of items in the game
*/

//  Include library
#include <string.h>

//  Give alias to items
typedef enum {
    NONE,
    WOODEN_SWORD,
    WOODEN_PICKAXE,
    WOODEN_BILLHOOK,
    WOODEN_AXE,
    SPRUCE,
    STONE,
    GRASS,
    STONE_SWORD,
    STONE_SPEAR,
    STONE_HAMMER,
    STONE_CHESTPLATE,
    STONE_PICKAXE,
    STONE_BILLHOOK,
    STONE_AXE,
    LIFE_POTION_I,
    BEECH,
    IRON,
    LAVENDER,
    IRON_SWORD,
    IRON_SPEAR,
    IRON_HAMMER,
    IRON_CHESTPLATE,
    IRON_PICKAXE,
    IRON_BILLHOOK,
    IRON_AXE,
    LIFE_POTION_II,
    OAK,
    DIAMOND,
    HEMP,
    DIAMOND_SWORD,
    DIAMOND_SPEAR,
    DIAMOND_HAMMER,
    DIAMOND_CHESTPLATE,
    LIFE_POTION_III
} Item_ID;

//   Give alias to type of item
typedef enum  {
    MATERIAL,
    TOOL,
    WEAPON,
    ARMOR,
    POTION
} Type;

// Give alias to different type tool
typedef enum  {
    PICKAXE,
    BILLHOOK,
    AXE
} ToolType;

//  Give alias to the mining level of resources
typedef enum {
    MINING_WOOD,
    MINING_STONE,
    MINING_IRON
} MiningLevel;

// Properties of a items
typedef struct {
    const Item_ID itemId;
    short quantity;
} Item;

// Properties of material
typedef struct {
    const Item_ID itemId;
    const char name[20];
    const Type type;
    const short quantityMax;
    const short durabilityCurrent;
} Material;

//  Properties of a tool
typedef struct {
    const Item_ID itemId;
    const char name[20];
    const ToolType toolType;
    const Type type;
    const MiningLevel miningLevel;
    const short quantityMax;
    short durabilityCurrent;
    const short durabilityMax;
} Tool;

// Properties of a weapon
typedef struct {
    const Item_ID itemId;
    const char name[20];
    const Type type;
    const short attackDamage;
    const short quantityMax;
    short durabilityCurrent;
    const short durabilityMax;
} Weapon;

//  Properties of an armor
typedef struct  {
    const Item_ID itemId;
    const char name[20];
    const Type type;
    const float armorResistance;
    const short quantityMax;
    const short durabilityCurrent;
} Armor;

//  Properties of a health potion
typedef struct {
    const Item_ID itemId;
    const char name[20];
    const Type type;
    const short restoreLife;
    const short quantityMax;
    const short durabilityCurrent;
} Potion;


#endif // ITEMS_H_INCLUDED
