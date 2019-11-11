/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:58:12 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/10 15:58:01 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long			ft_longueur(long n)
{
	long		l;

	if (n <= 0)
		l = 1;
	else
		l = 0;
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(long nb)
{
	long				sign;
	long				len;
	char				*str;

	sign = (nb < 0 ? 1 : 0);
	str = NULL;
	len = ft_longueur(nb);
	if (sign == 1)
		nb = -nb;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	if (sign == 1)
		str[0] = '-';
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
