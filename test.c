/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:45:43 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/13 16:02:53 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    long i = -123;
    char  *str;

    str = "La pizza";
    
    //ft_printf("%.*s coute %.*d%c\n%% cad %x ou %X en Hexa %u\n addr : %p\n", -4, str, -8, -123, '$', -1234, 123, -1, str);
    printf("%0*d coute %.*d%c\n%% cad %x ou %X en Hexa %u\n addr : %p\n",10, -6, -8, -123, '$', -1234, 123, -1, str);
    //printf("%0*.5d\n",10,6);
    //while (1)
    //;
}
