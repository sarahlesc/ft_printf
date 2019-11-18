/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:47:05 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/18 17:58:42 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libc.h>

typedef struct		s_flag
{
	int		ldc;
	int		vdc;
	int		prec;
	int		conv;
	int		fmt;
	int		prblm;
}					t_flag;

int					ft_printf(const char *fmt, ...);
t_flag				ft_check(char *fmt, va_list ap, t_flag flag);
t_flag				check_vdc(char *fmt, t_flag flag);
t_flag				check_ldc(char *fmt, t_flag flag, va_list ap);
t_flag				check_prec(char *fmt, t_flag flag, va_list ap);
int					ft_atoi(const char *str);
char				*ft_itoa(long n);
int					is_conv(char c, char *set);
void				ft_switch(t_flag flag, char **str, va_list ap);
t_flag				ft_process(t_flag flag, va_list ap, char **str);
void				ft_prec_num(t_flag flag, char **str);
void				ft_prec_str(t_flag flag, char **str);
void				ft_ldc(t_flag flag, char **str);
void				ft_ldcg(t_flag flag, char **str);
void				ft_ldc0(t_flag flag, char **str);
void				ft_conv_hexa(t_flag flag, char **str, va_list ap);
void				ft_conv_str(t_flag flag, char **str, va_list ap);
void				ft_conv_point(t_flag flag, char **str, va_list ap);
void				ft_conv_int(t_flag flag, char **str, va_list ap);
unsigned long		ft_recursive_power(int nb, int power);
int					ft_strlen(char *str);
void				ft_putstr(char *str);
char				*ft_toupper(char *str);

#endif
