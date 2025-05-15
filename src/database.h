#pragma once

#include "game.h"

void database_start(GameData* g);

void database_end(GameData* g);

void database_init_tables(GameData *g);

void database_insert_character_options(GameData *g);

// void database_create_user(GameData *data);

// void database_save_character(GameData *data);
