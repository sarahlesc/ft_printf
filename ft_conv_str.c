/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:45:09 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/09 13:06:15 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_conv_str(t_flag flag, char *str, va_list ap)
{
	if (flag.conv == 'c')
	{
		if (!(str = malloc(sizeof(char) * 2)))
			exit(0);
		str[0] = va_arg(ap, char);
		str[1] = '\0';
	}
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
	}
}
