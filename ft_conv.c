/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:45:09 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/09 18:35:07 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_str(t_flag flag, char *str, va_list ap)
{
	if (flag.conv == 'c')
	{
		if (!(str = malloc(sizeof(char) * 2)))
			exit(0);
		str[0] = va_arg(ap, int);
		str[1] = '\0';
	}
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			str = "(null)";
	}
	return (str);
}

char	*ft_conv_int(t_flag flag, char *str, va_list ap)
{
	str = ft_itoa(va_arg(ap, long));
	return (str);
}

char	*ft_conv_unsint(t_flag flag, char *str, va_list ap)
{
	str = ft_itoa((long)va_arg(ap, unsigned int));
	return (str);
}

char	*ft_conv_point(t_flag flag, char *str, va_list ap)
{
	int		i;
	char	*tmp;

	i = 2;
	str = ft_conv_hexa(flag, str, ap);
	str = malloc(sizeof(char) * (strlen(str) + 2));
	tmp = str;
	while (i < (strlen(str)))
	{
		str[i] = tmp[i - 2];
		i++;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}
