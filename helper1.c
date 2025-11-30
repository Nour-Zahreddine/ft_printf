/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzahredd <nzahredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:12 by nzahredd          #+#    #+#             */
/*   Updated: 2025/11/20 10:17:03 by nzahredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlower_fd(unsigned long n, int fd)
{
	char	*hex;
	size_t	count;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthexlower_fd(n / 16, fd);
	count += ftputchar(hex[(n % 16)]);
	return (count);
}

int	ft_puthexupper_fd(unsigned int n, int fd)
{
	char	*hex;
	size_t	count;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthexupper_fd(n / 16, fd);
	count += ftputchar(hex[(n % 16)]);
	return (count);
}

int	ftputchar(char c)
{
	return (write(1, &c, 1));
}

int	ftputstr(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		count += write(1, &s[i++], 1);
	}
	return (count);
}

int	ftputnbr_fd(int n, int fd)
{	
	long	num;
	int		count;

	count = 0;
	num = n;
	if (num < 0)
	{
		count += ftputchar('-');
		num = -num;
	}
	if (num >= 10)
		count += ftputnbr_fd(num / 10, fd);
	count += ftputchar((num % 10) + '0');
	return (count);
}
