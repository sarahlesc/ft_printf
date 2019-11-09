/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:46:33 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/09 18:23:19 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_check(char *fmt, va_list ap)
{
	t_flag	flag;
	char	*conv;

	conv = "cspduxX%";
	flag = check_vdc(fmt, flag);
	flag = check_ldc(fmt, flag, ap);
	flag = check_prec(fmt, flag, ap);
	if (flag.prec != 0)
		fmt++;
	if (is_conv(*fmt, conv) == 0 || flag.prec == -1)
		exit(0);
	else
		flag.conv = *fmt;
	return (flag);
}

t_flag		check_vdc(char *fmt, t_flag flag)
{
	flag.vdc = 0;
	while (*fmt == '0' || *fmt == '-')
	{
		if (*fmt == '0')
		{
			if (flag.vdc != 1)
				flag.vdc = 2;
			fmt++;
		}
		else if (*fmt == '-')
		{
			flag.vdc = 1;
			fmt++;
		}
	}
	return (flag);
}

t_flag		check_ldc(char *fmt, t_flag flag, va_list ap)
{
	if (ft_atoi(fmt) != 0)
		flag.ldc = ft_atoi(fmt);
	else if (*fmt == '*')
		flag.ldc = va_arg(ap, int);
	else
		flag.ldc = 0;
	while (*fmt >= '0' && *fmt <= '9')
		fmt++;
	return (flag);
}

t_flag		check_prec(char *fmt, t_flag flag, va_list ap)
{
	char	*conv;

	conv = "cspduxX%";
	if (*fmt == '.')
	{
		fmt++;
		if (ft_atoi(fmt) != 0)
			flag.prec = ft_atoi(fmt);
		else if (*fmt == '*')
			flag.prec = va_arg(ap, int);
		else if (is_conv(*fmt, conv) == 0)
			flag.prec = -1;
		else
			flag.prec = 0;
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	else
		flag.prec = 0;
	return (flag);
}
