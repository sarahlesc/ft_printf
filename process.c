/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:16:11 by selgrabl          #+#    #+#             */
/*   Updated: 2019/11/18 17:38:59 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag			ft_process(t_flag flag, va_list ap, char **str)
{
	flag.prblm = 0;
	ft_switch(flag, str, ap);
	if (flag.prec >= 0)
	{
		if (is_conv(flag.conv, "diuxX") == 1 && flag.prec > 0)
			ft_prec_num(flag, str);
		if (flag.conv == 's')
			ft_prec_str(flag, str);
	}
	if (flag.prec == 0 && is_conv(flag.conv, "diuxX") == 1)
		if((*str)[0] == '0' && ft_strlen(*str) == 1)
		{
			flag.prblm = 1;
			*str[0] = ' ';
		}
	if (flag.ldc > 0)
			{
				if (flag.vdc == 0)
					ft_ldc(flag, str);
				else
				(flag.vdc == 1) ?  (ft_ldcG(flag, str)) : ft_ldc0(flag, str);
			}
	return	(flag);
}

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

	if (is_conv(*fmt, "cspdiuxX%") == 0)
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
	if (ft_atoi(fmt) > 0)
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
	if (flag.ldc < 0)
	{
		flag.vdc = 1;
		flag.ldc *= -1;
	}
	return (flag);
}

t_flag		check_prec(char *fmt, t_flag flag, va_list ap)
{
	if (*fmt == '.')
	{
		fmt++;
		flag.fmt++;
		if (ft_atoi(fmt) >= 0)
			flag.prec = ft_atoi(fmt);
		else if (*fmt == '*')
			flag.prec = va_arg(ap, int);
		else if (is_conv(*fmt, "cspdiuxX%") == 0)
			exit(0);
		else
			flag.prec = 0;
		while ((*fmt >= '0' && *fmt <= '9') || *fmt == '*')
		{
			fmt++;
			flag.fmt++;
		}
	}
	else
	{
		flag.prec = -1;
	}
	if (flag.prec >= 0 && flag.vdc == 2)
		flag.vdc = 0;
	return (flag);
}
