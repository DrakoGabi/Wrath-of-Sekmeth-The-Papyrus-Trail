/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** map_layer
*/

#include "../include/rpg.h"

bool openfile(opn_t *opn, char *file)
{
    opn->fd = open(file, O_RDONLY);
    if (opn->fd == -1)
        return false;
    opn->arg = NULL;
    stat(file, &opn->s);
    opn->size = (sizeof(char) * opn->s.st_size);
    opn->buffer = malloc(sizeof(char) * (opn->size +1));
    if (!opn->buffer) {
        close(opn->fd);
        return false;
    }
    read(opn->fd, opn->buffer, opn->size -1);
    opn->buffer[opn->size -1] = '\0';
    opn->arg = my_str_to_word_array(opn->buffer, "\n,");
    can_free(opn->buffer);
    close(opn->fd);
    if (!opn->arg)
        return false;
    return true;
}

layer_t create_layer(char *n, unsigned int h, unsigned int w, int t)
{
    layer_t res = {0};

    res.name = my_strdup(n);
    res.height = h;
    res.width = w;
    res.vertices = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(res.vertices, sfQuads);
    sfVertexArray_resize(res.vertices, (res.width * res.height * 4));
    res.size = t;
    res.drawable = true;
    return res;
}

int myisnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_get_nbr(char const *str)
{
    int i = 0;
    int minus = 0;
    int nb = 0;

    for (; str[i] == '-' || str[i] == '+' || myisnum(str[i]);) {
        if (myisnum(str[i]))
            nb = nb * 10 + str[i] - 48;
        if (str[i] == '-')
            minus = minus + 1;
        if (myisnum(str[i]) == 1 && myisnum(str[i + 1] == 0))
            break;
        i = i + 1;
    }
    if (minus % 2 == 1)
        nb = -nb;
    return nb;
}

bool parse_csv(char *path, char *assets_path, layer_t *lay)
{
    opn_t content = {0};
    int i = 0;

    lay->tileset = sfTexture_createFromFile(assets_path, NULL);
    if (!openfile(&content, path))
        return false;
    lay->indexes = malloc(sizeof(int) * (my_tablen(content.arg) + 1));
    if (!lay->indexes || !lay->tileset) {
        can_free(lay->indexes);
        can_free(lay->tileset);
        return false;
    }
    for (i = 0; content.arg[i]; i++)
        lay->indexes[i] = my_get_nbr(content.arg[i]);
    lay->indexes[i] = -1;
    return true;
}
