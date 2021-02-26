/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_texture
*/

#include "my_runner.h"

parallax_t *texture(void)
{
    parallax_t *par = malloc(sizeof(parallax_t));
    par->parallax = sfSprite_create();
    par->parallax2 = sfSprite_create();
    par->parallax3 = sfSprite_create();
    par->persoo = sfSprite_create();
    par->positions = (sfVector2f){30, 890};
    par->pos;
    par->re = re_place();
    par->perso = sfTexture_createFromFile("src/files/finaltry.png", NULL);
    par->text = sfTexture_createFromFile("src/files/groundy.png", NULL);
    par->text2 = sfTexture_createFromFile("src/files/middly.png", NULL);
    par->text3 = sfTexture_createFromFile("src/files/skyy.png", NULL);
    par->anim = sfClock_create();
    par->count = 0;
    sfSprite_setTexture(par->persoo, par->perso, sfTrue);
    sfSprite_setTexture(par->parallax, par->text, sfTrue);
    sfSprite_setTexture(par->parallax2, par->text2, sfTrue);
    sfSprite_setTexture(par->parallax3, par->text3, sfTrue);

    return (par);
}