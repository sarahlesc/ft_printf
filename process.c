/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:16:11 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/08 13:55:52 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_process(t_flag flag, va_list ap)
{
    char* str;        

        ft_switch(flag, str, ap);
        if (flag.conv == 'd' || flag.conv == 'i' || flag.conv == 'u' || flag.conv
        == 'x'|| flag.conv ==  'X')
            ft_prec_num(flag, str);
        else if (flag.conv == 's')
            ft_prec_str(flag, str);
        ft_ldc(flag, str);
    return (ft_strlen(str));
}

int     ft_switch(t_flag flag, char *str, va_list ap)
{
    if (flag.conv == 'd ' || flag.conv == 'i')
        ft_conv_int();
    if (flag.conv == 'x' || flag.conv == 'X')
        ft_conv_hexa();
    if (flag.conv == 's' || flag.conv == 'c')
        ft_conv_str();
    if (flag.conv == 'p')
        ft_conv_point();
    if (flag.conv == 'u')
        ft_conv_unsint();
    if (flag.conv == '%')
    {
        if (!(str = malloc(sizeof(char))))
		exit (0);
        *str = '%';
    }   
}
