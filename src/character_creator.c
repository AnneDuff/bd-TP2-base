#include "character_creator.h"
#include "game.h"
#include "database.h"
#include "ui_style.h"

#include "raygui.h"

#define NUM_ELEMENTS 6


void ui_character_creator(GameData* g){
    Vector2 cursor = {.x=g->win.w * 0.15f,.y = g->win.h * 0.3f - (TEXTBOX_HEIGHT + PADDING) * NUM_ELEMENTS};

    static bool is_nord = false;
    static bool is_dark_elf = false;
    static bool is_redguard = false;
    static bool is_orc = false;

    static bool is_dawnguard = false;
    static bool is_forsworm = false;
    static bool is_b_o_s = false;
    static bool is_imperials = false;

    static bool is_citizen = false;
    static bool is_merchant = false;
    static bool is_soldier = false;

    bool show_error_box = false;

    Rectangle bounds = {
        .x=cursor.x - g->win.w * 0.25f * 0.5f,
        .y=cursor.y,
        .width=g->win.w * 0.25f, .height = TEXTBOX_HEIGHT
    };

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.height = TEXTBOX_HEIGHT;
    bounds.width = 1000;
    GuiLabel(bounds, "#191#Check the boxes to see restrictions.");
    
    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.height = TEXTBOX_HEIGHT;
    bounds.width = 1000;
    GuiLabel(bounds, "Choose a race.");

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Nord", &is_nord));
    if(is_nord){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Nords have no clothing or weapon restrictions.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    GuiCheckBox(bounds,"Dark Elf",&is_dark_elf);
    if(is_dark_elf){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Dark Elves can only wear yellow or white and wield elven weapons.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    GuiCheckBox(bounds,"Redguard",&is_redguard);
    if(is_redguard){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Redguards have no clothing or weapon restrictions.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    GuiCheckBox(bounds,"Orc",&is_orc);
    if(is_orc){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Orcs can only wear orcish armor. They have no weapon restrictions.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.height = TEXTBOX_HEIGHT;
    bounds.width = 1000;
    GuiLabel(bounds, "Choose a faction.");

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Dawnguard", &is_dawnguard));
    if(is_dawnguard){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Dawnguards wear only purple.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Forsworm", &is_forsworm));
    if(is_forsworm){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Forsworm only wear light armor. They cannot be citizens. They can only wear beige.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Brotherhood of Steel", &is_b_o_s));
    if(is_b_o_s){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "The Brotherhood of Steel only wears heavy armor. They cannot be citizens and colors don't matter.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Imperials", &is_imperials));
    if(is_imperials){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Imperials can mix armor. They only wear red.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.height = TEXTBOX_HEIGHT;
    bounds.width = 1000;
    GuiLabel(bounds, "Choose a social status.");

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Citizen", &is_citizen));
    if(is_citizen){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Citizens can only wield small axes and bows.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Merchant", &is_merchant));
    if(is_merchant){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Merchants are pacifists. They cannot wield weapons.");
    }

    bounds.y += TEXTBOX_HEIGHT + PADDING;
    bounds.width = bounds.height = TEXTBOX_HEIGHT;
    if(GuiCheckBox(bounds, "Soldier", &is_soldier));
    if(is_soldier){
        bounds.y += TEXTBOX_HEIGHT + PADDING;
        bounds.height = TEXTBOX_HEIGHT;
        bounds.width = 1000;
        GuiLabel(bounds, "Soldiers can wield any weapon.");
    }

    //Quoi passer???
    //game_preview_player(, g);

    // g->img = allocate(sizeof(Texture));
    // Texture2D character = LoadTexture("caracteres.png");
    // memcpy(g->img, &character, sizeof(Texture));

    // int stats = 0;
    int* strength = &g->customer.curr_character.strength;
    int* stamina = &g->customer.curr_character.stamina;
    int* stealth = &g->customer.curr_character.stealth;
    int* charisma = &g->customer.curr_character.charisma;
    static bool strength_spin = false;
    static bool stamina_spin = false;
    static bool stealth_spin = false;
    static bool charisma_spin = false;

    bounds.x += (TEXTBOX_HEIGHT + PADDING) * 20;
    bounds.y -= (TEXTBOX_HEIGHT + PADDING) * 10;
    bounds.width = 100;
    if(GuiSpinner(bounds, "Strength ", strength, 1, 20, strength_spin)){
        int res  = *strength + *stamina + *stealth + *charisma;
        if(res > 20){
            *strength-=1;
        }
        strength_spin = !strength_spin;
    }
    bounds.y -= TEXTBOX_HEIGHT + PADDING;
    if(GuiSpinner(bounds, "Stamina ", stamina, 1, 20, stamina_spin)){
        int res  = *strength + *stamina + *stealth + *charisma;
        if(res > 20){
            *stamina-=1;
        }
        stamina_spin = !stamina_spin;
    }
    bounds.y -= TEXTBOX_HEIGHT + PADDING;
    if(GuiSpinner(bounds, "Stealth ", stealth, 1, 20, stealth_spin)){
        int res  = *strength + *stamina + *stealth + *charisma;
        if(res > 20){
            *stealth-=1;
        }
        stealth_spin = !stealth_spin;
    }
    bounds.y -= TEXTBOX_HEIGHT + PADDING;
    if(GuiSpinner(bounds, "Charisma ", charisma, 1, 20, charisma_spin)){
        int res  = *strength + *stamina + *stealth + *charisma;
        if(res > 20){
            *charisma-=1;
        }
        charisma_spin = !charisma_spin;
    }

    

    if(GuiButton((Rectangle){620, 430, 90, 30}, "Save choices")){
        if(is_dark_elf && is_imperials || is_dark_elf && is_dawnguard || is_dark_elf && is_forsworm || is_orc && is_imperials || is_orc && is_dawnguard || is_orc && is_forsworm){
            if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Error Message")){
                show_error_box = true;   
            }
            if (show_error_box)
            {
                int result = GuiMessageBox((Rectangle){ 85, 70, 2500, 1000 }, "#191#Error!", "Your choices are incompatible! Please mind the descriptions and make approppriate choices.", "Sorry");

                if (result >= 0) show_error_box = false;
            }
        }
        else {
            //insert race
            if(is_nord){
                g->customer.curr_character.character_classe.race = is_nord;
            }
            if(is_dark_elf){
                g->customer.curr_character.character_classe.race = is_dark_elf;
            }
            if(is_redguard){
                g->customer.curr_character.character_classe.race = is_redguard;
            }
            if(is_orc){
                g->customer.curr_character.character_classe.race = is_orc;
            }

            //insert faction
            if(is_dawnguard){
                g->customer.curr_character.character_classe.faction = is_dawnguard;
            }
            if(is_forsworm){
                g->customer.curr_character.character_classe.faction = is_forsworm;
            }
            if(is_b_o_s){
                g->customer.curr_character.character_classe.faction = is_b_o_s;
            }
            if(is_imperials){
                g->customer.curr_character.character_classe.faction = is_imperials;
            }

            //insert social status
            if(is_citizen){
                g->customer.curr_character.character_classe.faction = is_citizen;
            }
            if(is_merchant){
                g->customer.curr_character.character_classe.faction = is_merchant;
            }
            if(is_soldier){
                g->customer.curr_character.character_classe.faction = is_soldier;
            }
        }
    }
}