/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:26:34 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/19 16:03:00 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_num(t_flag flag, char **str)
{
	int		j;
	int		p;
	int		i;
	int		a;
	char	*tmp;

	if (flag.prec >= ft_strlen(*str))
	{
		i = ((*str)[0] == '-') ? 1 : 0;
		a = -1;
		tmp = *str;
		p = flag.prec - 1 + i;
		j = ft_strlen((*str)) - 1;
		if (!(*str = malloc(sizeof(char) * flag.prec + 1 + i)))
			exit(0);
		while (a++ <= j + i)
			(*str)[a] = tmp[a];
		while (j >= i)
			((*str)[p--]) = ((*str)[j--]);
		while (p >= i)
			((*str)[p--]) = '0';
		((*str)[flag.prec + i]) = '\0';
		free(tmp);
	}
}

void	ft_prec_str(t_flag flag, char **str)
{
	int i;

	if (flag.prec < ft_strlen(*str))
	{
		i = flag.prec;
		while (i < ft_strlen(*str))
		{
			(*str)[i] = '\0';
			i++;
		}
	}
}

void	ft_ldc(t_flag flag, char **str)
{
	int		j;
	int		p;
	int		a;
	char	*tmp;

	(flag.prblm == 2) ? flag.ldc -= 1 : 0;
	if (flag.ldc > ft_strlen(*str))
	{
		a = -1;
		tmp = *str;
		p = flag.ldc - 1;
		j = ft_strlen((*str)) - 1;
		if (!(*str = malloc(sizeof(char) * flag.ldc + 1)))
			exit(0);
		while (a++ <= j)
			(*str)[a] = tmp[a];
		while (j >= 0)
			((*str)[p--]) = ((*str)[j--]);
		while (p >= 0)
			((*str)[p--]) = ' ';
		(*str)[p + 1] = (flag.prblm == 2) ? ' ' : ' ';
		((*str)[flag.ldc]) = '\0';
		free(tmp);
	}
}

void	ft_ldc0(t_flag flag, char **str)
{
	int		j;
	int		p;
	int		i;
	int		a;
	char	*tmp;

	if (flag.ldc > ft_strlen(*str))
	{
		i = ((*str)[0] == '-') ? 1 : 0;
		a = -1;
		tmp = *str;
		p = flag.ldc - 1;
		j = ft_strlen((*str)) - 1;
		if (!(*str = malloc(sizeof(char) * flag.ldc + 1)))
			exit(0);
		while (a++ <= j + i)
			(*str)[a] = tmp[a];
		while (j >= i)
			((*str)[p--]) = ((*str)[j--]);
		while (p >= i)
			((*str)[p--]) = '0';
		((*str)[flag.ldc]) = '\0';
		free(tmp);
	}
}

void	ft_ldcg(t_flag flag, char **str)
{
	int		j;
	int		p;
	int		a;
	char	*tmp;

	(flag.prblm == 2) ? flag.ldc -= 1 : 0;
	if (flag.ldc > ft_strlen(*str))
	{
		a = -1;
		tmp = *str;
		p = flag.ldc - 1;
		j = ft_strlen((*str)) - 1;
		if (!(*str = malloc(sizeof(char) * flag.ldc + 1)))
			exit(0);
		while (a++ <= j)
			(*str)[a] = tmp[a];
		while (p > j)
		{
			((*str)[p]) = ' ';
			p--;
		}
		((*str)[flag.ldc]) = '\0';
		free(tmp);
	}
}
