/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:47:05 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/07 17:17:07 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <libc.h>

typedef struct s_flag
{
    int ldc; //longueur de champs 1
	int vdc;; //prend 0 si rien, 1 si -, 2 si 0
    int prec; //precision
    int conv; //convertisseur
}               t_flag;

int     ft_printf(const char *, ...);
t_flag  ft_check(char *fmt, va_list ap);
int     ft_atoi(const char *str);
int     is_conv(char c, char *set);
int     ft_switch(t_flag flag, int nb, va_list ap);

#endif