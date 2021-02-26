/*
** EPITECH PROJECT, 2020
** My_runner
** File description:
** teste
*/

#include "my_runner.h"

int my_verify(sfRenderWindow *window, parallax_t *par, sfSprite **present,
char *file)
{
    int i = 0;
    sfVector2f pos;

    for (int j = 0; file[i] != '\0'; i++)
        if (file[i] == '1') {
            pos = sfSprite_getPosition(present[j]);
            if (pos.x <= par->positions.x && pos.x + 159 >= par->positions.x &&
            par->positions.y + 180 >= pos.y)
                return (2);
            j++;
            }
    return (par->count);
}

void my_reach(parallax_t *par)
{
    par->goal -= 6.0;
    if (par->goal <= 0)
        par->count = 1;
}

sfRenderWindow *my_window_create(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080};

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "Snowy runner", sfResize | sfClose, 0);
    return (window);
}

void my_background(sfSprite *parallax, sfIntRect pos, int i)
{
    pos.top = 0;
    pos.height = 1076;
    pos.width = 1916;
    pos.left = i;
    sfSprite_setTextureRect(parallax, pos);
}

void display(char *file)
{
    parallax_t *par = texture();
    music_t *mu = musiccc();
    mu->score = my_manage();
    sfRenderWindow *window = my_window_create(1920, 1080);
    sfEvent event;
    sfMusic *mumu = sfMusic_createFromFile("src/files/game.ogg");
    sfFont *write = sfFont_createFromFile("src/files/SnowtopCaps.otf");
    par->score = sfText_create();
    sfSprite **present = create_enemy(file, par);

    music_update(window, event);
    sfText_setFont(par->score, write);
    sfText_setScale(par->score, (sfVector2f){2.3, 2.3});
    while (sfRenderWindow_isOpen(window) && par->count == 0) {
        while (sfRenderWindow_pollEvent(window, &event))
            movement(&par->positions, event, window, &mu->jumpyy);
        my_updaty(par, mu);
        my_update_draw(window, par, file, present);
    }
    my_win(window, par);
    sfRenderWindow_destroy(window);
}