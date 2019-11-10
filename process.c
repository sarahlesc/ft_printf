/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:16:11 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/10 14:23:14 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_process(t_flag flag, va_list ap, char **str)
{

	ft_switch(flag, str, ap);
	/*if (is_conv(flag.conv, "diuxX") == 1)
			ft_prec_num(flag, *str);
		else if (flag.conv == 's')
			ft_prec_*str(flag, *str);
		ft_ldc(flag, *str);*/
	return	(flag.fmt);
}

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
