/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:38:52 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/09 18:44:01 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_conv_hexa(t_flag flag, char *str, va_list ap)
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
	if (!(str = malloc(sizeof(char) * len + 1)))
		exit(0);
	x = --len;
	while (++j <= x)
	{
		str[j] = base[(i / ft_recursive_power(16, len))];
		i = i % ft_recursive_power(16, len);
		len--;
	}
	str[j] = '\0';
	if (flag.conv == 'X')
		str = ft_toupper(str);
	return (str);
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
