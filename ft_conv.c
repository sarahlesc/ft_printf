/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:38:52 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/12 18:49:47 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_switch(t_flag flag, char **str, va_list ap)
{
	char	*tmp;
	int		i;

	if (flag.conv == 'x' || flag.conv == 'X')
		ft_conv_hexa(flag, str, ap);
	if (flag.conv == 's' || flag.conv == 'c')
		ft_conv_str(flag, str, ap);
	if (flag.conv == 'p')
		ft_conv_point(flag, str, ap);
	if (flag.conv == 'u' || flag.conv == 'd' || flag.conv == 'i')
		ft_conv_int(flag, str, ap);
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
	unsigned long			i;
	int						x;
	int						j;
	int						len;
	char					*base;

	base = "0123456789abcdef";
	i = va_arg(ap, unsigned int);
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

void			ft_conv_str(t_flag flag, char **str, va_list ap)
{
	char	*tmp;
	int		i;

	if (flag.conv == 'c')
	{
		if (!(*str = malloc(sizeof(char *) * 2)))
			exit(0);
		(*str)[0] = va_arg(ap, int);
		(*str)[1] = '\0';
	}
	else
	{
		tmp = va_arg(ap, char *);
		if (!(*str = malloc(sizeof(char *) * ft_strlen(tmp))))
			exit(0);
		if (tmp == NULL)
			tmp = "(null)";
		while (i < ft_strlen(tmp))
		{
			(*str)[i] = tmp[i];
			i++;
		}
		(*str)[i] = '\0';
	}
}

void			ft_conv_point(t_flag flag, char **str, va_list ap)
{
	int		i;
	char	*tmp;

	i = 0;
	ft_conv_hexa(flag, str, ap);
	tmp = *str;
	if (!(*str = malloc(sizeof(char *) * (ft_strlen(*str) + 2))))
		exit(0);
	while (i <= (ft_strlen(tmp)))
	{
		(*str)[i + 2] = tmp[i];
		i++;
	}
	free(tmp);
	(*str)[0] = '0';
	(*str)[1] = 'x';
}

void			ft_conv_int(t_flag flag, char **str, va_list ap)
{
	int		i;
	char	*tmp;

	i = -1;
	if (flag.conv == 'd' || flag.conv == 'i')
	{
		tmp = ft_itoa((long)va_arg(ap, int));
		if (!(*str = malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
			exit(0);
		while (i++ < ft_strlen(tmp))
			(*str)[i] = tmp[i];
	}
	else
	{
		tmp = ft_itoa((long)va_arg(ap, unsigned int));
		if (!(*str = malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
			exit(0);
		while (i++ < ft_strlen(tmp))
			(*str)[i] = tmp[i];
	}
	free(tmp);
}
