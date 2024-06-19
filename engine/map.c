/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** map
*/

#include "../include/rpg.h"

map_t create_map(unsigned int h, unsigned int w, unsigned int t, char *path)
{
    map_t res = {0};

    res.height = h;
    res.width = w;
    res.square = t;
    res.sp = create_sprite(path);
    res.layers = create_layer("collision", 100, 100, 16);
    load(COLLISION, "assets/DesertTilemap16x16.png", &res.layers);
    return res;
}

void destroy_map(map_t map)
{
    destroy_layer(map.layers);
    destroy_sprite(map.sp);
}

bool add_layer(char *name, char *path, char *asset_path, map_t *map)
{
    layer_t layer = create_layer(name, map->height, map->width, map->square);
    int i = 0;

    if (!load(path, asset_path, &layer)) {
        destroy_layer(layer);
        return false;
    }
    map->layers = layer;
    return true;
}
