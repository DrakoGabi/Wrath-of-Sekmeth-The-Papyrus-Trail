/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** save_in_menu
*/

#include "rpg.h"

void apply_save(base_t *b, ingame_t *m)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(b->win);
    sfFloatRect rect = get_sp_bounds(m->save.sp);

    if (!sfFloatRect_contains(&rect, mouse.x - 150, mouse.y + 275)) {
        m->save_state = 0;
        play_anime("no touch", &m->save);
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && m->state_inv != 2) {
        m->save_state = 2;
        play_anime("clicked", &m->save);
    } else {
        m->save_state = 1;
        play_anime("over", &m->save);
    }
    if (b->evt.type == sfEvtMouseButtonReleased)
        save(b);
}
