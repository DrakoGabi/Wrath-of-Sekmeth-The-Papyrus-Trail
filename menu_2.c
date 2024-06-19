/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** menu_2
*/

#include "rpg.h"

void anime_button(button_t *but)
{
    if (!but->state)
        play_anime("no touch", &but->icon);
    else if (but->state == 1)
        play_anime("over", &but->icon);
    else
        play_anime("clicked", &but->icon);
}

void apply_button(base_t *b, button_t *but)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(b->win);
    sfFloatRect rect = get_sp_bounds(but->icon.sp);

    if (!sfFloatRect_contains(&rect, mouse.x, mouse .y)) {
        but->state = 0;
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && but->state != 2)
        but->state = 2;
    else
        but->state = 1;
    if (b->evt.type == sfEvtMouseButtonReleased)
        b->menu.playable = but->value;
}

void set_menu_ani(menu_t *r)
{
    int *framez = append_int(NULL, 0);
    button_t *s[] = {&r->start, &r->setting, &r->back, &r->control, NULL};

    for (int i = 0; s[i]; i++) {
        s[i]->value = i + 1;
        add_animation("no touch", framez, &s[i]->icon);
    }
    framez = append_int(can_free(framez), 1);
    for (int i = 0; s[i]; i++)
        add_animation("over", framez, &s[i]->icon);
    framez = append_int(can_free(framez), 2);
    for (int i = 0; s[i]; i++)
        add_animation("clicked", framez, &s[i]->icon);
    can_free(framez);
}
