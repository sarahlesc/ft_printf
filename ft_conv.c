/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:38:52 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/10 15:13:02 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_switch(t_flag flag, char **str, va_list ap)
{
	if (flag.conv == 'd' || flag.conv == 'i')
		*str = ft_itoa(va_arg(ap, long));
	if (flag.conv == 'x' || flag.conv == 'X')
		ft_conv_hexa(flag, str, ap);
	if (flag.conv == 's' || flag.conv == 'c')
		ft_conv_str(flag, str, ap);
	if (flag.conv == 'p')
		ft_conv_point(flag, str, ap);
	if (flag.conv == 'u')
		*str = ft_itoa((long)va_arg(ap, unsigned int));
	if (flag.conv == '%')
	{
		if (!(*str = malloc(sizeof(char) * 2)))
			exit(0);
		(*str)[0] = '%';
		(*str)[1] = '\0';
	}
}

void			ft_conv_hexa(t_flag flag, char **str, va_list ap)
{
	unsigned long	i;
	int				x;
	int				j;
	int				len;
	char			*base;

	base = "0123456789abcdef";
	i = va_arg(ap, unsigned long);
	len = 1;
	j = -1;
	while (i / ft_recursive_power(16, len) > 0)
		len++;
	if (!(*str = malloc(sizeof(char) * len + 1)))
		exit(0);
	x = --len;
	while (++j <= x)
	{
		(*str)[j] = base[(i / ft_recursive_power(16, len))];
		i = i % ft_recursive_power(16, len);
		len--;
	}
	(*str)[j] = '\0';
	if (flag.conv == 'X')
		*str = ft_toupper(*str);
}

unsigned long	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		exit(0);
	else if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
}

void			ft_conv_str(t_flag flag, char **str, va_list ap)
{
	if (flag.conv == 'c')
	{
		if (!(*str = malloc(sizeof(char) * 2)))
			exit(0);
		(*str)[0] = va_arg(ap, int);
		(*str)[1] = '\0';
	}
	else
	{
		*str = va_arg(ap, char *);
		if (*str == NULL)
			*str = "(null)";
	}
}

void			ft_conv_point(t_flag flag, char **str, va_list ap)
{
	int		i;
	char	*tmp;

	i = 2;
	ft_conv_hexa(flag, str, ap);
	*str = malloc(sizeof(char) * (strlen(*str) + 2));
	tmp = *str;
	while (i < (strlen(*str)))
	{
		(*str)[i] = tmp[i - 2];
		i++;
	}
	(*str)[0] = '0';
	(*str)[1] = 'x';
}
