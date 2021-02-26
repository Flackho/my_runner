/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** main
*/

#include "my_runner.h"

int main(int ac, char **av)
{
    if (ac < 2) {
        no_arg();
        return (84);
    } else if (ac > 3) {
        my_putstr("too much arguments\n");
        return (84);
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_help();
        return (0);
    }
    if (ac == 2)
        display(load_file_in_mem(av[1]));
    return (0);
}