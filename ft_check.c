/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slescure <slescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:46:33 by slescure          #+#    #+#             */
/*   Updated: 2019/11/04 19:10:21 by slescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check(char *fmt, int *nb, va_list ap)
{
	t_flag	flag;
	char	*conv;

	conv = "cspduxX%";
	flag = check_ldc2(*fmt, flag);
	flag = check_ldc1(*fmt, flag, ap);
	flag = check_prec(*fmt, flag, ap);
	if (flag.prec == -1)
		return (-1);
	return (1);
}

t_flag		check_ldc2(char *fmt, t_flag flag)
{
	flag.ldc2 = 0;
	while (*fmt == '0' || *fmt == '-')
	{
		if (*fmt == '0')
		{
			if (flag.ldc2 != 1)
				flag.ldc2 = 2;
			fmt++;
		}
		else if (*fmt == '-')
		{
			flag.ldc2 = 1;
			fmt++;
		}
	}
	return (flag);
}

t_flag		check_ldc1(char *fmt, t_flag flag, va_list ap)
{
	if (ft_atoi(*fmt) != 0)
		flag.ldc1 = ft_atoi(*fmt);
	else if (*fmt == '*')
		flag.ldc1 = va_arg(ap, int);
	else
		flag.ldc1 = 0;
	while (*fmt >= '0' || *fmt <= '9')
		fmt++;
	return (flag);
}

t_flag		check_prec(char *fmt, t_flag flag, va_list ap)
{
	char *conv;

	conv = "cspduxX%";
	if (*fmt == '.')
	{
		fmt++;
		if (ft_atoi(*fmt) != 0)
			flag.prec = ft_atoi(*fmt);
		else if (*fmt == '*')
			flag.prec = va_arg(ap, int);
		else if (is_conv(*fmt, conv) == 0)
			flag.prec = -1;
		else
			flag.prec = 0;
	}
	return (flag);
}
