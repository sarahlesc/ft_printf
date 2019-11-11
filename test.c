/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:45:43 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/11 18:48:30 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    long i = -123;
    char  *str;

    str = "La pizza";
    
   ft_printf("%s coute %.*d %c\n%% cad %x ou %X en Hexa %u\n addr : %p\n",str,10, -123, '$',-123, 123, -1, str);
   printf("%s coute %.*d %c\n%% cad %x ou %X en Hexa %u\n addr : %p\n", str, 10, -123, '$',-123, 123,  -1, str);
    //printf("%.8d\n",-45);
}
