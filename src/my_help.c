/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my_help
*/

#include "my_runner.h"

void no_arg(void)
{
    my_putstr("./my_runner: bad arguments: 0 given but 1 is required");
    my_putstr("\nretry with -h\n");
}

void my_help(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_runner map.txt\n\n\nOPTIONS\n");
    my_putstr("\n -h\t\tprint");
    my_putstr(" the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n SPACE_KEY\t jump\n RIGHT_KEY\tmove to the");
    my_putstr(" right\n LEFT_KEY\tmove to the left\n\nIN THE START MENU\n");
    my_putstr(" SPACE_KEY\tto start the game\n ESCAPE_KEY\t to quit the game");
}