/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:47:35 by mochan            #+#    #+#             */
/*   Updated: 2022/06/19 18:09:50 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	function(void *p, char flag)
{
	int	i;

	i = 0;
	if (flag == 'i' || flag == 'd')
		i = wint(*((int *)p), 10, "0123456789");
	if (flag == 'u')
		i = wuint(*((unsigned int *)p), 10, "0123456789");
	if (flag == 'c')
		i = write(1, p, 1);
	if (flag == 'x')
		i = dectohex(*((int *)p), 16, "0123456789abcdef");
	if (flag == 'X')
		i = dectohex(*((int *)p), 16, "0123456789ABCDEF");
	return (i);
}

int	numconversion(va_list ap, char flag)
{
	unsigned int	*value;
	int				j;

	j = 0;
	value = ft_pcalloc(1, sizeof(long int));
	*value = va_arg(ap, int);
	j = function(value, flag);
	free(value);
	return (j);
}

int	ft_flag(const char *fmt, va_list ap)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
		{
			if (*(fmt + ++i) == 'i' || *(fmt + i) == 'd' || *(fmt + i) == 'c')
				j += numconversion(ap, *(fmt + i));
			if (*(fmt + i) == 'u' || *(fmt + i) == 'x' || *(fmt + i) == 'X')
				j += numconversion(ap, *(fmt + i));
			if (*(fmt + i) == 'p')
				j += print_ptr_addr(ap);
			if (*(fmt + i) == 's')
				j += wstr(ap);
			if (*(fmt + i) == '%')
				j += ft_pputchar_fd('%', 1);
			i++;
		}
		if (*(fmt + i) && (*(fmt + i) != '%'))
			j += write(1, (fmt + i++), 1);
	}
	return (j);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			char_count;

	char_count = 0;
	va_start(ap, fmt);
	char_count += ft_flag(fmt, ap);
	va_end(ap);
	return (char_count);
}
