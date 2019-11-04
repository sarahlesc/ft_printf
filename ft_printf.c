/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:08:00 by slescure          #+#    #+#             */
/*   Updated: 2019/11/04 16:54:56 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int ft_printf(const char *fmt, ...)
{
    int nb; // nombre de caractères qu'on écrit
    va_list ap; // permet de lire les arguments

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
            ft_check((char *)fmt, &nb, ap);
        }
    }
    return (nb);
}
