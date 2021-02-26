/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_character
*/

#include "my_runner.h"

sfIntRect re_place(void)
{
    sfIntRect re;

    re.left = 0;
    re.height = 273;
    re.top = 0;
    re.width = 228;
    return (re);
}

void move_character(sfIntRect *re, int min, int max)
{
    if (re->left < max - 228 ) {
        re->left += 228;
    } else {
        re->left = min;
    }
}