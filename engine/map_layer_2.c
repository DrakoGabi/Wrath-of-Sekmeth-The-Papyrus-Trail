/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** map_layer_2
*/

#include "../include/rpg.h"

bool load(char *path, char *asset_path, layer_t *lay)
{
    if (!parse_csv(path, asset_path, lay))
        return false;
    for (unsigned int i = 0; i < lay->width; i++)
        for (unsigned int j = 0; j < lay->height; j++)
            fill_vertex(i, j, lay);
    return true;
}

int layers_len(layer_t *lay)
{
    int i = 0;

    for (i = 0; lay[i].name; i++);
    return i;
}

void draw_layer(sfRenderWindow *win, layer_t lay)
{
    sfRenderStates stats = {0};

    if (!lay.drawable)
        return;
    stats.blendMode = sfBlendAlpha;
    stats.transform = sfTransform_Identity;
    stats.texture = lay.tileset;
    sfRenderWindow_drawVertexArray(win, lay.vertices, &stats);
}

void destroy_layer(layer_t layer)
{
    can_free(layer.name);
    can_free(layer.indexes);
    if (layer.vertices)
        sfVertexArray_destroy(layer.vertices);
}

void fill_vertex(unsigned int x, unsigned int y, layer_t *l)
{
    int tile_number = l->indexes[x + y * l->width];
    sfVector2u size = sfTexture_getSize(l->tileset);
    int tu = tile_number % (size.x / l->size);
    int tv = 0;
    sfVertex *q;
    float s = l->size;

    if (l->indexes[x + y * l->width] == -1)
        return;
    q = sfVertexArray_getVertex(l->vertices, (x + y * l->width) * 4);
    q[0].position = (sfVector2f){x * s, y * s};
    q[1].position = (sfVector2f){(x + 1) * s, y * s};
    q[2].position = (sfVector2f){(x + 1) * s, (y + 1) * s};
    q[3].position = (sfVector2f){x * s, (y + 1) * s};
    q[0].texCoords = (sfVector2f){tu * s, tv * s };
    q[1].texCoords = (sfVector2f){(tu + 1) * s, tv * s};
    q[2].texCoords = (sfVector2f){(tu + 1) * s, (tv + 1) * s};
    q[3].texCoords = (sfVector2f){tu * s, (tv + 1) * s};
}
