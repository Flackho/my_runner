/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** load_file_mem
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *load_file_in_mem(char const *filepath)
{
    int op = open(filepath, O_RDONLY);
    int i = 0;
    int size = 10000;
    int len;
    char *dest = malloc(sizeof(char) * (size + 1));

    if (op == -1)
        return (NULL);
    else
        while ((len = read(op, dest + i, size - i)) > 0) {
            i = i + len;
        }
    close(op);
    dest[i] = '\0';
    return (dest);
}