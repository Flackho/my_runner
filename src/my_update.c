/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** my_update
*/

#include "my_runner.h"

void my_before_update(parallax_t *par, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, par->parallax3, NULL);
    sfRenderWindow_drawSprite(window, par->parallax2, NULL);
    sfRenderWindow_drawSprite(window, par->parallax, NULL);
    sfRenderWindow_drawSprite(window, par->persoo, NULL);
    my_reach(par);
}

void my_update_draw(sfRenderWindow *window, parallax_t *par, char *file,
sfSprite **present)
{
    int i = 0;
    sfVector2f pos;
    if (sfClock_getElapsedTime(par->anim).microseconds >= 10000) {
        sfSprite_setScale(par->persoo, (sfVector2f){0.47, 0.47});
        sfSprite_setTextureRect(par->persoo, par->re);
        sfSprite_setPosition(par->persoo, par->positions);
        sfRenderWindow_clear(window, sfBlack);
        my_before_update(par, window);
        sfRenderWindow_drawText(window, par->score, NULL);
        for (int j = 0; file[i] != '\0'; i++)
            if (file[i] == '1') {
                pos.x = sfSprite_getPosition(present[j]).x;
                pos.x -= 6;
                sfSprite_setPosition(present[j], (sfVector2f){pos.x, 890});
                sfRenderWindow_drawSprite(window, present[j], NULL);
                par->count = my_verify(window, par, present, file);
                j++;
            }
        sfRenderWindow_display(window);
        sfClock_restart(par->anim);
    }
}

void my_updaty(parallax_t *par, music_t *mu)
{
    if (sfClock_getElapsedTime(mu->clock).microseconds > 60000) {
        mu->i += mu->i < 1920 ? 7 : -1920;
        mu->j += mu->j < 1920 ? 5 : -1920;
        mu->h += mu->h < 1920 ? 3 : - 1920;
        my_background(par->parallax, par->pos, mu->i);
        my_background(par->parallax2, par->pos, mu->j);
        my_background(par->parallax3, par->pos, mu->h);
        move_character(&par->re, 0, 912 - 228);
        my_score(mu->score);
        sfClock_restart(mu->clock);
    }
    if (sfClock_getElapsedTime(mu->jump).microseconds > 12500) {
        jumpyyy(&par->positions, &mu->jumpyy);
        sfClock_restart(mu->jump);
    }
    sfText_setString(par->score, mu->score);
    sfText_setColor(par->score, sfColor_fromRGB(0, 150, 100));
}

void music_update(sfRenderWindow *window, sfEvent event)
{
    sfMusic *mumu = sfMusic_createFromFile("src/files/game.ogg");

    my_menu(window, event);
    sfMusic_play(mumu);
    sfMusic_setLoop(mumu, sfTrue);
}