/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:47:05 by slescure          #+#    #+#             */
/*   Updated: 2019/11/04 19:07:31 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_flag
{
    int ldc1; //longueur de champs 1
	int ldc2;; //prend 0 si rien, 1 si -, 2 si 0
    int prec; //precision
    int conv; //convertisseur
}               t_flag;

int ft_printf(const char *, ...);
int	ft_check(char *fmt, int *nb, va_list ap);
int	ft_atoi(const char *str);
int	is_conv(char c, char *set);


#endif