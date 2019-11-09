/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:08:00 by slescure          #+#    #+#             */
/*   Updated: 2019/11/09 18:51:09 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	t_flag	flag;
    int nb; // nombre de caractères qu'on écrit
    va_list ap; // permet de lire les arguments
    char *str;
    
    va_start(ap, fmt); // on lit les arguments de la liste ap
    nb = 0;
    while (*fmt)
    {
        if (*fmt != '%')
        {
            write(1, fmt, 1);
            nb++;
            fmt++;
        }
        else
        {
            fmt++;
            flag = ft_check((char *)fmt, ap);
			str = ft_process(flag, ap, str);
            ft_putstr(str);
            nb += strlen(str);
        }
    }
    return (nb);
}
