/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:51:57 by mochan            #+#    #+#             */
/*   Updated: 2022/06/23 11:19:34 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		dectohex_ptr(unsigned long n, int base, char *base_str);
int		dectohex(unsigned int n, int base, char *base_str);
void	*ft_pcalloc(size_t count, size_t size);
int		ft_flag(const char *fmt, va_list ap);
char	*ft_pitoa(long long int n);
int		ft_printf(const char *fmt, ...);
char	*ft_uitoa(unsigned int n);
int		function(void *p, char flag);
int		numconversion(va_list ap, char flag);
int		print_ptr_addr(va_list ap);
int		ft_pputchar_fd(char c, int fd);
void	ft_pputstr_fd(char *s, int fd);
int		wint(int n, int base, char *base_str);
int		wstr(va_list ap);
int		wuint(unsigned int n, int base, char *base_str);
void	*zeromem(void *str, size_t n);

#endif
