/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:08:00 by slescure          #+#    #+#             */
/*   Updated: 2019/11/19 12:40:58 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_flag	flag;
	va_list	ap;
	char	*str;
	int		nb;

	nb = 0;
	va_start(ap, fmt);
	while (*fmt)
		if (*fmt != '%')
		{
			write(1, fmt++, 1);
			nb++;
		}
		else
		{
			fmt++;
			flag = ft_process(ft_check((char *)fmt, ap, flag), ap, &str);
			fmt += flag.fmt;
			(flag.prblm == 0 || flag.ldc > 0) ? nb += ft_strlen(str) : 0;
			(flag.prblm == 0) ? nb += 1 : 0;
			(flag.prblm == 0 || flag.ldc > 0) ? ft_putstr(str) : 0;
			free(str);
		}
	va_end(ap);
	return (nb);
}
