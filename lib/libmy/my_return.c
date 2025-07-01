/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myhunter-philibert.gentien
** File description:
** my_return
*/

#include "includes/my.h"

int my_return(char *msg, int status)
{
    write(2, msg, my_strlen(msg));
    return status;
}
