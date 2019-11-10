/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:46:33 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/10 15:02:42 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_check(char *fmt, va_list ap, t_flag flag)
{
	int tmpf;

	tmpf = 0;
	flag.fmt = 0;
	flag = check_vdc(fmt, flag);
	fmt += flag.fmt - tmpf;
	tmpf = flag.fmt;
	flag = check_ldc(fmt, flag, ap);
	fmt += flag.fmt - tmpf;
	tmpf = flag.fmt;
	flag = check_prec(fmt, flag, ap);
	fmt += flag.fmt - tmpf;
	if (flag.prec != 0)
	{
		fmt++;
		flag.fmt++;
	}
	if (is_conv(*fmt, "cspduxX%") == 0 || flag.prec == -1)
		exit(0);
	else
		flag.conv = *fmt;
	flag.fmt++;
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
			flag.fmt++;
		}
		else if (*fmt == '-')
		{
			flag.vdc = 1;
			fmt++;
			flag.fmt++;
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
	while ((*fmt >= '0' && *fmt <= '9') || *fmt == '*')
	{
		fmt++;
		flag.fmt++;
	}
	return (flag);
}

t_flag		check_prec(char *fmt, t_flag flag, va_list ap)
{
	if (*fmt == '.')
	{
		fmt++;
		flag.fmt++;
		if (ft_atoi(fmt) != 0)
			flag.prec = ft_atoi(fmt);
		else if (*fmt == '*')
			flag.prec = va_arg(ap, int);
		else if (is_conv(*fmt, "cspduxX%") == 0)
			flag.prec = -1;
		else
			flag.prec = 0;
		while ((*fmt >= '0' && *fmt <= '9') || *fmt == '*')
		{
			fmt++;
			flag.fmt++;
		}
	}
	else
		flag.prec = 0;
	return (flag);
}
