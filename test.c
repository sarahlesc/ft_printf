/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:45:43 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/10 15:02:48 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    char  *str;

    str = "La pizza";
    
    ft_printf("%s coute %-0.d%c \n%% cad %x ou %X en Hexa %u\n",str, 123, '$',-123, 123, -1);
    printf("%s coute %d%c \n%% cad %x ou %X en Hexa %u\n", str, 123, '$',-123, 123,  -1);
}
