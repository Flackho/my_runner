/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-justine.trupheme
** File description:
** my_win
*/

#include "../include/my_runner.h"

void win(sfRenderWindow *window, parallax_t *par)
{
    sfEvent event;
    par->win = sfSprite_create();
    par->winn = sfTexture_createFromFile("src/files/winmenu.jpg", NULL);
    sfSprite_setTexture(par->win, par->winn, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, par->win, NULL);
        sfRenderWindow_display(window);
    }
}

void lose(sfRenderWindow *window, parallax_t *par)
{
    sfEvent event;
    par->over = sfSprite_create();
    par->gameover = sfTexture_createFromFile("src/files/gameover.png", NULL);
    sfSprite_setTexture(par->over, par->gameover, sfTrue);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, par->over, NULL);
        sfRenderWindow_display(window);
    }
}

void my_win(sfRenderWindow *window, parallax_t *par)
{
    if (par->count == 2)
        lose(window, par);
    else
        win(window, par);
}