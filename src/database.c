#include "game.h"
#include "database.h"
#include "sqlite3.h"
#include "knob.h"
#include "character_creator.h"

#define LOG_SQLITE3_ERROR(db) knob_log(KNOB_ERROR, "%s:%d: SQLITE3 ERROR: %s\n", __FILE__, __LINE__, sqlite3_errmsg(db))


void database_start(GameData* g){
    sqlite3_open("game.db", &g->db);
}

void database_end(GameData* g){
    sqlite3_close(g->db);
}

const char* create_customer_table =
"CREATE TABLE IF NOT EXISTS Customer ("
"   IdCustomer INT PRIMARY KEY,"
"   Name TEXT,"
"   Email TEXT," 
"   Adress TEXT,"
"   Username TEXT"
");";

//A noter: j'utilise aussi cette table comme table pour les produits vendus, vu la simplicite de mon store
const char* create_item_table =
"CREATE TABLE IF NOT EXISTS Item ("
"   IdItem INT PRIMARY KEY,"
"   Name TEXT,"
"   Value FLOAT,"
"   IsWeapon INTEGER,"
"   IsArmor INTEGER,"
"   IsEquipped INTEGER,"
"   IsSupplies INTEGER"
");";

const char* create_order_table =
"CREATE TABLE IF NOT EXISTS Client ("
"   IdOrder INT PRIMARY KEY,"
"   Adress TEXT,"
"   CardInformation TEXT"
");";

const char* create_character_table =
"CREATE TABLE IF NOT EXISTS Character ("
"   Name TEXT,"
"   Race TEXT,"
"   Faction TEXT,"
"   SocialStatus TEXT,"
"   Class TEXT,"
"   EquippedWeapon TEXT,"
"   EquippedArmor TEXT"
");";

char* races[Race_Max] = {
"Nord",
"Dark_Elf", 
"Redguard",
"Orc"
};

char* factions[Faction_Max] = {
"Dawnguard",
"Forsworm", 
"Brotherhood of Steel",
"Imperials"
};

char* socialstatus[SocialStatus_Max] = {
"Citizen",
"Merchant", 
"Soldier"
};

char* armors[Armors_Max] = {
"White Armor",
"Yellow Armor",
"Green Armor",
"Purple Armor",
"Red Armor",
"Beige Armor"
};

char* weapons[Weapons_Max] = {
"Bow",
"Small Axe",
"Sword",
"Elven Scimitar"
};

void database_init_tables(GameData *g){
    if (sqlite3_exec(g->db, create_customer_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, create_character_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, create_item_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, create_order_table, NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
}

void database_insert_character_options(GameData *g){
    sqlite3_stmt* stmt = NULL;
    char content[] =
    "INSERT INTO Character (Race, SocialStatus, Faction)"
    "VALUES (?,?,?);";
    int ret = sqlite3_prepare_v2(g->db,content,-1,&stmt,NULL);

    if(ret != SQLITE_OK){
        LOG_SQLITE3_ERROR(g->db);
    }
    
    if(sqlite3_bind_text(stmt,1,races[g->customer.curr_character.character_classe.race],-1,SQLITE_STATIC) != SQLITE_OK){
        LOG_SQLITE3_ERROR(g->db);
    }

    if(sqlite3_bind_text(stmt,2,socialstatus[g->customer.curr_character.character_classe.status],-1,SQLITE_STATIC) != SQLITE_OK){
        LOG_SQLITE3_ERROR(g->db);
    }

    if(sqlite3_bind_text(stmt,3,factions[g->customer.curr_character.character_classe.faction],-1,SQLITE_STATIC) != SQLITE_OK){
        LOG_SQLITE3_ERROR(g->db);
    }

    ret = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}

void database_insert_items_bought(GameData *g){
    sqlite3_stmt* stmt = NULL;
    char content[] =
    "INSERT INTO Character (EquippedWeapon, EquippedArmor)"
    "VALUES (?,?);";
    int ret = sqlite3_prepare_v2(g->db,content,-1,&stmt,NULL);

    if(ret != SQLITE_OK){
        LOG_SQLITE3_ERROR(g->db);
    }

    if(sqlite3_bind_text(stmt,1,weapons[g->customer.curr_character.character_classe.weapons],-1,SQLITE_STATIC) != SQLITE_OK){
        LOG_SQLITE3_ERROR(g->db);
    }
    
    if(sqlite3_bind_text(stmt,2,armors[g->customer.curr_character.character_classe.armors],-1,SQLITE_STATIC) != SQLITE_OK){
        LOG_SQLITE3_ERROR(g->db);
    }

    ret = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
}