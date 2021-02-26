/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Audio.h>
#include <math.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <unistd.h>

typedef struct parallax {
    sfIntRect pos;
    sfIntRect re;
    sfVector2f positions;
    sfSprite *parallax;
    sfSprite *parallax2;
    sfSprite *parallax3;
    sfSprite *persoo;
    sfTexture *perso;
    sfTexture *text;
    sfTexture *text2;
    sfTexture *text3;
    sfText *score;
    sfClock *anim;
    sfSprite *win;
    sfSprite *over;
    sfTexture *winn;
    sfTexture *gameover;
    int count;
    float goal;
}parallax_t;

typedef struct music {
    sfClock *clock;
    sfClock *jump;
    int i;
    int j;
    int h;
    int jumpyy;
    sfMusic *mumu;
    char *score;
}music_t;
music_t *musiccc(void);
char *load_file_in_mem(char const *filepath);
int my_counter(char *str);
sfSprite **create_enemy(char *file, parallax_t *par);
void my_update_draw(sfRenderWindow *window, parallax_t *par, char *file,
sfSprite **present);
void my_updaty(parallax_t *par, music_t *mu);
void music_update(sfRenderWindow *window, sfEvent event);
void my_score(char *score);
char *my_manage(void);
int my_putstr(char const *str);
void my_putchar(char c);
void move_character(sfIntRect *re, int min, int max);
sfRenderWindow *my_window_create(int width, int height);
void my_background(sfSprite *parallax, sfIntRect pos, int i);
sfIntRect re_place(void);
void movement(sfVector2f *positions, sfEvent event, sfRenderWindow *window,
int *jumpyy);
int main(int ac, char **av);
parallax_t *texture(void);
void no_arg(void);
void move_character(sfIntRect *re, int min, int max);
void display(char *file);
void my_help(void);
void jumpyyy(sfVector2f *positions, int *jumpyy);
void my_menu(sfRenderWindow *window, sfEvent event);
void para_menu(sfEvent event, int *count, sfRenderWindow *window);
void my_reach(parallax_t *par);
int my_verify(sfRenderWindow *window, parallax_t *par, sfSprite **present,
char *file);
void win(sfRenderWindow *window, parallax_t *par);
void my_win(sfRenderWindow *window, parallax_t *par);

#endif /* !MY_RUNNER_H_ */
