/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:55:30 by mochan            #+#    #+#             */
/*   Updated: 2022/06/19 18:09:59 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dectohex_ptr(unsigned long n, int base, char *base_str)
{
	int			index;
	static int	hexlen_ptr;

	hexlen_ptr = 0;
	if (n / base)
		dectohex_ptr(n / base, base, base_str);
	hexlen_ptr++;
	index = n % base;
	write(1, &base_str[index], 1);
	return (hexlen_ptr);
}

int	print_ptr_addr(va_list ap)
{
	int				i;
	unsigned long	value;

	i = 2;
	value = va_arg(ap, unsigned long);
	ft_pputchar_fd('0', 1);
	ft_pputchar_fd('x', 1);
	i += dectohex_ptr((unsigned long)value, 16, "0123456789abcdef");
	return (i);
}

int	dectohex(unsigned int n, int base, char *base_str)
{
	int			index;
	static int	hexlen;

	hexlen = 0;
	if (n / base)
		dectohex(n / base, base, base_str);
	hexlen++;
	index = n % base;
	write(1, &base_str[index], 1);
	return (hexlen);
}

int	wstr(va_list ap)
{
	int		i;
	char	*string;

	i = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	while (*(string + i))
		write(1, (string + i++), 1);
	return (i);
}

int	wuint(unsigned int n, int base, char *base_str)
{
	int			index;
	static int	uilen;

	uilen = 0;
	if (n / base)
		wuint(n / base, base, base_str);
	index = n % base;
	uilen += write(1, &base_str[index], 1);
	return (uilen);
}
