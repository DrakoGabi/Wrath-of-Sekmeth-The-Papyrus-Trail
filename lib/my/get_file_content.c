/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** get_file_content
*/

#include "../../include/my.h"

char **get_file_content(char *path)
{
    int op = open(path, O_RDONLY);
    char tmp[1] = {0};
    char *content = NULL;
    char **res = NULL;

    if (op == -1)
        return NULL;
    for (; read(op, tmp, 1);)
        content = my_append(content, tmp[0]);
    close(op);
    if (!content)
        return NULL;
    res = my_str_to_word_array(content, "\n\t,");
    can_free(content);
    return res;
}

bool open_file(opn_t *opn, char *file)
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
