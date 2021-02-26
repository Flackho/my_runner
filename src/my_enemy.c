/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-justine.trupheme
** File description:
** my_enemy
*/

#include "my_runner.h"

int my_counter(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '1')
            count += 1;
    }
    return (count);
}

sfSprite **create_enemy(char *file, parallax_t *par)
{
    sfSprite **present = malloc(sizeof(sfSprite *) * 100);
    sfTexture *enemy = sfTexture_createFromFile("src/files/obstacle.png", NULL);
    float pos = 1500.0;
    int h = 0;

    for (int i = 0; i < 100; i += 1) {
        present[i] = sfSprite_create();
        sfSprite_setTexture(present[i], enemy, sfTrue);
    }
    for (int j = 0; file[j] != '\0'; j += 1, pos += 200.0) {
        if (file[j] == '1') {
            sfSprite_setPosition(present[h], (sfVector2f){pos, 600});
            h += 1;
        }
    }
    par->goal = pos - 200;
    return (present);
}