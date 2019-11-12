/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:26:34 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/12 18:39:29 by selgrabl         ###   ########.fr       */
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

	if (flag.prec > ft_strlen(*str))
	{
		i = ((*str)[0] == '-') ? 1 : 0;
		a = 0;
		tmp = *str;
		p = flag.prec - 1 + i;
		j = ft_strlen((*str)) - 1;
		if(!(*str = malloc(sizeof(char) * flag.prec + 1 + i)))
			exit(0);
		while (a <= j + i)
		{
			(*str)[a] = tmp[a];
			a++;
		}
		while (j >= i)
		{
			((*str)[p]) = ((*str)[j]);
			p--;
			j--;
		}
		while (p >= i)
		{
			((*str)[p]) = '0';
			p--;
		}
		((*str)[flag.prec + i]) = '\0';
		free(tmp);
	}
}
