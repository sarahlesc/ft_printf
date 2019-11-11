/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:26:34 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/11 18:36:23 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_num(t_flag flag, char **str)
{
	int		j;
	int		p;
	int		a;
	char	*tmp;

	if (flag.prec > ft_strlen(*str))
	{
		a = 0;
		tmp = *str;
		p = flag.prec - 1;
		j = ft_strlen((*str)) - 1;
		if(!(*str = malloc(sizeof(char) * flag.prec + 1)))
			exit(0);
		while (a <= j)
		{
			(*str)[a] = tmp[a];
			a++;
		}
		free(tmp);
		while (j >= 0 && ((*str)[j]) != '-')
		{
			((*str)[p]) = ((*str)[j]);
			p--;
			j--;
		}
		while (p >= 0 && ((*str)[p]) != '-')
		{
			((*str)[p]) = '0';
			p--;
		}
		((*str)[flag.prec]) = '\0';
	}
}
