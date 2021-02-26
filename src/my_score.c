/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** my_score
*/

#include "my_runner.h"

void my_score(char *score)
{
    int i = 4;

    score[i] += 1;
    for (; i >= 1; i -= 1) {
        if (score[i] == 58) {
            score[i] = '0';
            score[i - 1] += 1;
        }
    }
}

char *my_manage(void)
{
    char *manage = malloc(sizeof(char) * 6);

    manage[0] = 48;
    manage[1] = 48;
    manage[2] = 48;
    manage[3] = 48;
    manage[4] = 48;
    manage[5] = '\0';
    return (manage);
}