/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selgrabl <selgrabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:08:00 by slescure          #+#    #+#             */
/*   Updated: 2019/11/10 15:03:16 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_flag	flag;
	va_list	ap;
	char	*str;

	str = NULL;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write(1, fmt, 1);
			fmt++;
		}
		else
		{
			fmt++;
			flag = ft_check((char *)fmt, ap, flag);
			fmt += ft_process(flag, ap, &str);
			ft_putstr(str);
		}
	}
	return (ft_strlen(str));
}
