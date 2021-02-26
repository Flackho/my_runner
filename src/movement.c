/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** movement
*/

#include "my_runner.h"

void movement(sfVector2f *positions, sfEvent event, sfRenderWindow *window,
int *jumpyy)
{
    sfMusic *music = sfMusic_createFromFile("src/files/cutejump.ogg");
    sfMusic_setVolume(music, 20);

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        if (positions->x > 5)
            positions->x -= 8;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        if (positions->x < 1810)
            positions->x += 12;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
    *jumpyy == 0) {
        *jumpyy = 1;
        sfMusic_play(music);
    }
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
}

void jumpyyy(sfVector2f *positions, int *jumpyy)
{
    if (positions->y >= 520 && *jumpyy == 1)
        positions->y -= 12;
    if (positions->y <= 520)
        *jumpyy = 2;
    if (positions->y <= 890 && *jumpyy == 2){
        positions->y += 12;
        if (positions->y > 890) {
            positions->y = 890;
            *jumpyy = 0;
        }
    }
}