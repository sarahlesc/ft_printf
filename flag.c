/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:26:34 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/10 16:06:45 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_num(t_flag flag, char **str)
{
	int i;
	int j;
	char *tmp;

	if (flag.prec > ft_strlen(*str))
		{
			ft_putstr("puuuuuuuute");
			tmp = *str;
			if(!(*str = malloc(sizeof(char *) * flag.prec + 1)))
				exit(0);
			j = (tmp[0] == '-') ? 1 : 0;
			i = (tmp[0] == '-') ? 1 : 0;
			while (j < (flag.prec - ft_strlen(tmp)))
			{
				(*str)[j] = '0';
				j++;
			}
			while(tmp[i])
			{
				(*str)[j + i] = tmp[i];
				i++;
			}
		}
}
