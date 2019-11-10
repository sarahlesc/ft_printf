/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:22:36 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/10 13:48:49 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	unsigned int	i;
	int				signe;
	unsigned int	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == ' ' || str[i] == '\v')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = (resultat * 10) + (str[i] - 48);
		i++;
	}
	return (resultat * signe);
}

int		is_conv(char c, char *set)
{
	int			i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

char	*ft_toupper(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
