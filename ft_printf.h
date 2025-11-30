/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzahredd <nzahredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:20:19 by nzahredd          #+#    #+#             */
/*   Updated: 2025/11/20 10:17:18 by nzahredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	"libft/libft.h"
# include	<stdarg.h>
# include	<unistd.h>

int	ft_puthexlower_fd(unsigned long n, int fd);
int	ft_puthexupper_fd(unsigned int n, int fd);
int	ftputchar(char c);
int	ftputstr(char *s);
int	ftputnbr_fd(int n, int fd);
int	ftputnbrunsigned_fd(unsigned int n, int fd);
int	ft_printf(const char *format, ...);

#endif