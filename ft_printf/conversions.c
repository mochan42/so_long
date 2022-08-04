/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:52:45 by mochan            #+#    #+#             */
/*   Updated: 2022/06/23 11:20:57 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long int n)
{
	int	i;

	i = 0;
	if (n < i)
	{
		i++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_pitoa(long long int n)
{
	int			x;
	long int	num;
	char		*numbr1;

	num = n;
	x = ft_count(num);
	numbr1 = ft_pcalloc(1, ft_count(num) + 2);
	if (!numbr1)
		return (NULL);
	if (num < 0)
	{
		*numbr1 = '-';
		num = num * -1;
	}
	while (num >= 10)
	{
		*(numbr1 + x--) = (num % 10) + '0';
		num = num / 10;
	}
	*(numbr1 + x) = num + '0';
	return (numbr1);
}

char	*ft_uitoa(unsigned int n)
{
	int			x;
	long int	num;
	char		*numbr1;

	num = n;
	x = ft_count(num);
	numbr1 = ft_pcalloc(1, ft_count(num) + 2);
	if (!numbr1)
		return (NULL);
	while (num >= 10)
	{
		*(numbr1 + x--) = (num % 10) + '0';
		num = num / 10;
	}
	*(numbr1 + x) = num + '0';
	return (numbr1);
}

void	ft_pputstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_pputchar_fd(*s++, fd);
}

int	wint(int n, int base, char *base_str)
{
	int			index;
	static int	ilen;
	int			num;
	int			sign;

	num = n;
	sign = 0;
	ilen = 0;
	if (n == -2147483648)
	{
		ft_pputstr_fd("-2147483648", 1);
		return (11);
	}
	if (num < 0)
	{
		ft_pputchar_fd('-', 1);
		num = -num;
		sign = 1;
	}
	if (num / base)
		wint(num / base, base, base_str);
	index = num % base;
	ilen += write(1, &base_str[index], 1);
	ilen += sign;
	return (ilen);
}
