/*
** EPITECH PROJECT, 2024
** pain
** File description:
** paint
*/

#pragma once
    #include "my.h"
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/Listener.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundRecorder.h>
    #include <SFML/Audio/SoundBufferRecorder.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/SoundStream.h>
    #include <SFML/Config.h>
    #include <time.h>

typedef struct save_s {
    int s_ring;
    int d_ring;
    int equip;
    int bandage;
    int player_lv;
    int exp;
    bool baboon;
    bool ibis;
} save_t;

typedef struct sprite_s {
    sfSprite *sp;
    sfTexture *tex;
    bool visible;
} sprite_t;

typedef struct animation_s {
    char *name;
    int *frames;
    int nb_frames;
    bool loop;
} anime_t;

typedef struct square_button_s {
    sfRectangleShape *square;
    bool state;
    bool visible;
} square_button_t;

typedef struct inv_button_s {
    square_button_t bdg;
    square_button_t dring;
    square_button_t sring;
    bool visible;
} inv_button_t;

typedef struct sprite_sheet_s {
    sprite_t sp;
    int frame;
    int width;
    anime_t *anime;
    char *current_ani;
    sfClock *clock;
} sprite_sheet_t;

typedef struct button_s {
    sprite_sheet_t icon;
    sfRectangleShape *base;
    int state;
    int value;
} button_t;

typedef struct menu_ingame_s {
    sprite_sheet_t save;
    sprite_sheet_t inv;
    sprite_sheet_t stats;
    int save_state;
    int state_inv;
    int states_state;
    sprite_t st;
    char def[60];
    sfText *txt;
    inv_button_t buttons;
} ingame_t;

typedef struct menu_s {
    sprite_t bg;
    sprite_t title;
    button_t start;
    button_t setting;
    button_t back;
    button_t control;
    sprite_t moves;
    sprite_t input;
    int playable;
    sfMusic *mus;
} menu_t;

typedef struct setting_s {
    button_t vol_up;
    button_t vol_down;
    button_t resize;
    button_t goback;
    sfText *desc_mv;
    sfText *desc_in;
} setting_t;

typedef struct stat_s {
    int lvl;
    int maxhp;
    int hp;
    int atk;
    int cl;
    int exp;
} stat_t;

typedef struct entry_s {
    char enter[9];
    char ref[9];
    sfText *ent;
    sfText *r;
} entry_t;

typedef struct item_s {
    int quantity;
    char name[17];
    char description[29];
} item_t;

typedef struct inventory_s {
    item_t bandages;
    item_t d_ring;
    item_t s_ring;
    int equip;
} inv_t;

typedef struct enti_s {
    char *name;
    sprite_sheet_t s;
    sprite_sheet_t map;
    stat_t stats;
    sfClock *cl;
    inv_t inv;
    int att;
    bool alive;
} enti_t;

typedef struct select_s {
    sfText *txt;
    sprite_t bg;
    bool activ;
    int len;
} select_t;

typedef struct victory_s {
    char e[10];
    char i[48];
    char s[43];
    sfText *ex;
    sfText *it;
    sfText *st;
    sprite_t bg;
} victory_t;

typedef struct fight_s {
    enti_t *player;
    enti_t *enemy;
    sprite_t bg;
    select_t spell[2];
    entry_t ent;
    entry_t hp_dis;
    bool start;
    bool turn;
    victory_t vic;
} fight_t;

typedef struct map_layer_s {
    char *name;
    sfVertexArray *vertices;
    unsigned int height;
    unsigned int width;
    int *indexes;
    sfTexture *tileset;
    int size;
    bool drawable;
} layer_t;

typedef struct map_s {
    unsigned int width;
    unsigned int height;
    unsigned int square;
    sprite_t sp;
    layer_t layers;
} map_t;

typedef struct npc_s {
    sprite_t self;
    sprite_t box;
    sfText *txt;
    bool alive;
} npc_t;

typedef enum equi_s {
    NOTHING,
    DEF_RING,
    ATT_RING
} equi_t;

typedef struct cutscene_s {
    char src[73];
    sfText *aff;
    sprite_t bg;
    sprite_t box;
    sprite_sheet_t p;
    sprite_sheet_t t;
    bool over;
} cutscene_t;

typedef struct base_s {
    sfRenderWindow *win;
    sfEvent evt;
    sfFont *fight_font;
    sfFont *font;
    fight_t fstate;
    sprite_t input;
    int exp;
    enti_t player;
    enti_t scribs;
    enti_t ibis;
    enti_t baboon;
    enti_t thot;
    int key_states[75];
    npc_t npc[5];
    menu_t menu;
    map_t map;
    cutscene_t scene;
    sfView *pov;
    sfMusic *over_mus;
    sfMusic *en_mus;
    sfMusic *ib_mus;
    sfMusic *ba_mus;
    sfMusic *th_mus;
    sfMusic *vi_mus;
    sfMusic *go_mus;
    sfMusic *ge_mus;
    sfMusic *cu_mus;
    sprite_t press;
    ingame_t pause;
} base_t;

extern const stat_t bstats[];
extern const char *gen[];
extern const char *cin[];

#define OUSTIDE_BG "assets/outside_bg.png"
#define INSIDE_BG "assets/temple_bg.png"
#define THOT_BG "assets/thot_bg.png"
#define FIGHT_FONT "assets/Pegypta.ttf"
#define FONT "assets/CourierNewPSMT.ttf"
#define SELECT_BG "assets/att.png"
#define SCRIB "assets/scrib.png"
#define PLAYER "assets/player_combat.png"
#define BABOON "assets/baboon.png"
#define IBIS "assets/ibis.png"
#define THOT "assets/thot.png"
#define OVERWORLD "assets/overworld_map.png"
#define COLLISION "assets/overworld_map_collision.csv"
#define GAMEOVER "assets/gameover.png"
#define NPC "assets/npc.png"
#define BOX "assets/box.png"
#define VICTORY "assets/victory.png"
#define P_MAP "assets/player_map.png"
#define L_SIDE 14
#define L_FRONT 16
#define M_MUS "assets/menu.ogg"
#define O_MUS "assets/combat.ogg"
#define S_MUS "assets/enemy.ogg"
#define I_MUS "assets/ibis.ogg"
#define B_MUS "assets/baboon.ogg"
#define T_MUS "assets/thot.ogg"
#define INTERACT "assets/interact.png"
#define V_MUS "assets/victory.ogg"
#define S_MV "assets/move.png"
#define S_IN "assets/menu.png"
#define G_MUS "assets/gameover.ogg"
#define C_MUS "assets/cutscene.ogg"
#define SAVE "assets/save.png"
#define STATS "assets/stats.png"
#define INV "assets/inv.png"
#define ZONE "assets/txt_zone.png"
#define PRESS "assets/press.png"
#define GEN_BG "assets/credit.png"
#define GEN_MUS "assets/gen.ogg"
#define P_POR "assets/player_portrait.png"
#define T_POR "assets/thot_portrait.png"
#define M_BG "assets/bg.png"
#define START "assets/st.png"
#define SET "assets/set.png"
#define BACK "assets/back.png"
#define CONT "assets/controls.png"

//ENGINE
sprite_t create_sprite(char *pathname);
void destroy_sprite(sprite_t sp);
void draw_sprite(sfRenderWindow *win, sprite_t sp);
void set_sp_pos(sfVector2f pos, sprite_t *sp);
sfVector2f get_sp_pos(sprite_t sp);
void sp_move(sprite_t sp, float x, float y);
void set_sp_scale(sfVector2f scale, sprite_t *sp);
void replace_sp_tex(char *path, sprite_t *sp);
bool sp_collide(sprite_t sp, sprite_t ot);
sfFloatRect get_sp_bounds(sprite_t sp);
bool is_clicked(sfRenderWindow *win, sprite_t sp);
void set_sp_origin(sfVector2f ori, sprite_t *sp);
void sp_texture_rect(sfIntRect rekt, sprite_t *sp);
sprite_sheet_t create_sheets(char *path, int width);
void destroy_sheets(sprite_sheet_t sht);
int locate_animation(char *ani, sprite_sheet_t *sht);
void add_animation(char *new_ani, int *new_frames, sprite_sheet_t *sht);
void play_anime(char *ani, sprite_sheet_t *sht);
void set_loop(sprite_sheet_t *sht, char *ani, bool pool);
anime_t create_anime(char *name, int *frames);
void destroy_anime(anime_t ani);
int first_anime(anime_t ani);
int last_anime(anime_t ani);
void set_ani_name(char *new, anime_t *ani);
void set_ani_frames(int *new, anime_t *ani);
int anime_len(anime_t *src);
anime_t *ani_append(anime_t *src, char *add, int *frames);
map_t create_map(unsigned int h, unsigned int w, unsigned int t, char *path);
void destroy_map(map_t map);
bool add_layer(char *name, char *path, char *asset_path, map_t *map);
layer_t create_layer(char *n, unsigned int h, unsigned int w, int t);
void destroy_layer(layer_t layer);
bool parse_csv(char *path, char *assets_path, layer_t *lay);
void fill_vertex(unsigned int x, unsigned int y, layer_t *l);
void draw_layer(sfRenderWindow *win, layer_t lay);
bool load(char *path, char *asset_path, layer_t *lay);
int layers_len(layer_t *lay);
button_t create_button(char *path);
void destroy_button(button_t but);
menu_t create_menu(void);
void destroy_menu(menu_t menu);
void draw_menu(sfRenderWindow *win, menu_t menu);
void collide_npc_input(base_t *b);
void draw_square(sfRenderWindow *win, square_button_t res);

//PROJECT
base_t create_base(char *title);
void destroy_base(base_t base);
entry_t create_ent(sfFont *font);
fight_t create_fight(sfFont *font);
void set_level(int lvl, stat_t *stats, int indstat);
enti_t create_entity(char *name, int indstat, int lvl);
void get_entity(base_t *base);
void destroy_entity(enti_t ent);
int fight(base_t *b);
void activate_fight(base_t *base, enti_t *en, char *bg_path, sfMusic *mus);
void takes_hit(base_t *b, enti_t *ent, int hit);
int damage(enti_t *ent, base_t *b);
void apply_button(base_t *b, button_t *but);
void set_menu_ani(menu_t *res);
void set_answer(char src[9], int len);
void handle_event(base_t *base);
bool just_pressed(base_t *states, int key);
int player_attack(base_t *b);
void overworld(base_t *base);
void draw_fstate(fight_t *f, sfRenderWindow *win);
void destroy_fight(fight_t f);
void add_char(char str[9], char c, int len);
void set_hp(fight_t *f);
bool player_wait(base_t *b, int len);
bool player_choice(base_t *b);
bool play_fight(base_t *b);
void redirect_fight(base_t *b);
void reset_fight(base_t *b);
void get_enemy(enti_t *e);
int *frame_getter(int start, int size);
anime_t find_anim(char *name, sprite_sheet_t s);
sfView *create_view(void);
void destroy_view(sfView *res);
void handle_move(base_t *base);
void get_baboon(enti_t *e);
void get_ibis(enti_t *e);
void get_thot(enti_t *e);
void get_player(enti_t *e);
void are_you_fighting(base_t *base);
void level_up(base_t *b);
void die(base_t *b);
bool coll(base_t *b, int i);
void activate_bosses(base_t *b);
void get_npc(base_t *b);
void destroy_npc(npc_t n);
void draw_npc(sfRenderWindow *win, npc_t npc);
void collide_npc(base_t *b, int i);
void draw_all_npc(base_t *b);
void collide_all_npc(base_t *b);
void get_inventory(base_t *b);
void animation_manager(fight_t *f);
bool is_playing(char *name, enti_t *ent);
bool window_fight_con(base_t *b);
char *my_strnb_cpy(int nbr, char *dest);
sfText *set_text(char *str, sfFont *font, sfColor col);
victory_t create_victory(sfFont *f);
void victory_loop(base_t *b);
void add_inventory(base_t *b);
void flip(sfVector2f f, int r, sprite_sheet_t *s);
sfVector2f get_pos(int direction, sprite_t pl);
sfMusic *get_music(char *src);
void stop_combat_music(base_t *b);
void destroy_all_npc(base_t *b);
void menu_loop(base_t *base);
void get_all_music(base_t *b);
void destroy_all_music(base_t *b);
void check_pause(base_t *base);
ingame_t create_pause(sfFont *font);
void destroy_pause(ingame_t pause);
void draw_overworld(base_t *base);
void return_to_menu(base_t *b);
void win(base_t *b);
void set_pause_ani(ingame_t *res);
void apply_stats(base_t *b, ingame_t *menu);
void handle_event_pause(base_t *base);
void apply_inv(base_t *b, ingame_t *m);
inv_button_t create_inv_button(void);
void destroy_inv_button(inv_button_t res);
cutscene_t create_cutcsecne(sfFont *f);
void destroy_cutscene(cutscene_t s);
void cutscene(base_t *b);
bool change_rec_state_1(sfRectangleShape *rec, base_t *b, bool sta);
bool change_rec_state_2(sfRectangleShape *rec, base_t *b, bool sta);
bool change_rec_state_3(sfRectangleShape *rec, base_t *b, bool sta);
void equip_defring(enti_t *player, square_button_t *s);
void equip_attring(enti_t *player, square_button_t *s);
void anime_button(button_t *but);
void setting_loop(base_t *b);
void handleset_event(base_t *base);
void control_loop(base_t *b);
void save_recup(base_t *base);
void save(base_t *base);
void link_game(base_t *b);
void apply_save(base_t *b, ingame_t *m);
