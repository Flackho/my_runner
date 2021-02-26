/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** my_music
*/

#include "my_runner.h"

music_t *musiccc(void)
{
    music_t *mu = malloc(sizeof(music_t));
    mu->clock = sfClock_create();
    mu->jump = sfClock_create();
    mu->i = 0;
    mu->j = 0;
    mu->h = 0;
    mu->jumpyy = 0;
}