/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzahredd <nzahredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:21:57 by nzahredd          #+#    #+#             */
/*   Updated: 2025/11/20 10:22:02 by nzahredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftputnbrunsigned_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ftputnbrunsigned_fd(n / 10, fd);
	count += ftputchar((n % 10) + '0');
	return (count);
}

int	handle_null_ptr(void *ptr)
{
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
		return (ftputstr("0x") + ft_puthexlower_fd((unsigned long)ptr, 1));
}

static int	arg_checker(char specifier, va_list args)
{
	int				count;
	void			*ptr;

	count = 0;
	if (specifier == 'c')
		count += ftputchar((char)va_arg(args, int));
	else if (specifier == 's')
		count += ftputstr(va_arg(args, char *));
	else if (specifier == 'x')
		count += ft_puthexlower_fd((unsigned int)va_arg(args, unsigned int), 1);
	else if (specifier == 'X')
		count += ft_puthexupper_fd(va_arg(args, unsigned int), 1);
	else if (specifier == 'i' || specifier == 'd')
		count += ftputnbr_fd(va_arg(args, int), 1);
	else if (specifier == '%')
		count += ftputchar('%');
	else if (specifier == 'u')
		count += ftputnbrunsigned_fd(va_arg(args, unsigned int), 1);
	else if (specifier == 'p')
	{
		ptr = va_arg(args, void *);
		count += handle_null_ptr(ptr);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += arg_checker(format[i], args);
		}
		else
			count += ftputchar(format[i]);
		i++;
	}
	return (count);
}
int main()
{
	int i = printf(" %c %p ", 0, 0);
	int j = ft_printf(" %p %p ", 0, 0);;
	printf("%i\n", i);
	printf("%i\n", j);
}