#include "store.h"
#include "game.h"
#include "database.h"
#include "ui_style.h"

#include "raygui.h"

#define NUM_ELEMENTS 6

void ui_store(GameData* g){
    Vector2 cursor = {.x=g->win.w * 0.15f,.y = g->win.h * 0.3f - (TEXTBOX_HEIGHT + PADDING) * NUM_ELEMENTS};

    static bool y_armor = false;
    static bool w_armor = false;
    static bool g_armor = false;
    static bool p_armor = false;
    static bool r_armor = false;
    static bool b_armor = false;
    
    static bool bow = false;
    static bool small_axe = false;
    static bool sword = false;
    static bool elven_scimitar = false;

    Rectangle bounds = {
        .x=cursor.x - g->win.w * 0.25f * 0.5f,
        .y=cursor.y,
        .width=g->win.w * 0.25f, .height = TEXTBOX_HEIGHT
    };

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.height = TEXTBOX_HEIGHT;
    bounds.width = 1000;
    GuiLabel(bounds, "#191#Check a box to buy an object.");

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.height = TEXTBOX_HEIGHT;
    bounds.width = 1000;
    GuiLabel(bounds, "Armors: ");

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Yellow Armor", &y_armor));
    if(y_armor){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Elven armor made to fit elves.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "White Armor", &w_armor));
    if(w_armor){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Elven armor made to fit elves.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Green Armor", &g_armor));
    if(g_armor){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Orcish armor made to fit orcs.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Purple Armor", &p_armor));
    if(p_armor){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Armor for dawnguards.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Red Armor", &r_armor));
    if(r_armor){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Armor for imperials.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Beige Armor", &b_armor));
    if(b_armor){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Armor for forsworms.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.height = TEXTBOX_HEIGHT;
    bounds.width = 1000;
    GuiLabel(bounds, "Weapons: ");

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Bow", &bow));
    if(bow){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "For citizens.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Small Axe", &small_axe));
    if(small_axe){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "For citizens.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Sword", &sword));
    if(sword){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "For anybody.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Elven Scimitar", &elven_scimitar));
    if(elven_scimitar){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "For dark elves only.");
    }

    if(GuiButton((Rectangle){620, 430, 90, 30}, "Buy Selected")){
        if(y_armor){
            g->customer.curr_character.character_classe.armors = y_armor;
        }

        if(w_armor){
            g->customer.curr_character.character_classe.armors = w_armor;
        }

        if(g_armor){
            g->customer.curr_character.character_classe.armors = g_armor;
        }

        if(p_armor){
            g->customer.curr_character.character_classe.armors = p_armor;
        }

        if(r_armor){
            g->customer.curr_character.character_classe.armors = r_armor;
        }

        if(b_armor){
            g->customer.curr_character.character_classe.armors = b_armor;
        }

        if(bow){
            g->customer.curr_character.character_classe.weapons = bow;
        }

        if(small_axe){
            g->customer.curr_character.character_classe.weapons = small_axe;
        }

        if(sword){
            g->customer.curr_character.character_classe.weapons = sword;
            printf("Sword equipped");
        }

        if(elven_scimitar){
            g->customer.curr_character.character_classe.weapons = elven_scimitar;
        }
    }
}