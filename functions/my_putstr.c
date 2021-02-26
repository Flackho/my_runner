/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    int c = 0;

    while (str[c] != '\0') {
        my_putchar(str[c]);
        c = c + 1;
    }
    return (0);
}
