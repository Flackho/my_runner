/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_menu
*/

#include "my_runner.h"

void para_menu(sfEvent event, int *count, sfRenderWindow *window)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
        *count = 1;
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
}

void my_menu(sfRenderWindow *window, sfEvent event)
{
    int count = 0;
    sfSprite *back = sfSprite_create();
    sfTexture *backy = sfTexture_createFromFile("src/files/start.png", NULL);
    sfSprite_setTexture(back, backy, sfTrue);
    sfMusic *music = sfMusic_createFromFile("src/files/menugame.ogg");

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    while (sfRenderWindow_isOpen(window) && count == 0) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            para_menu(event, &count, window);
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_drawSprite(window, back, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
}