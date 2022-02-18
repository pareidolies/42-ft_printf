/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:11:16 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 14:56:43 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int n, t_info *info)
{
	char	*min;
	char	*maj;

	min = "0123456789abcdef";
	maj = "0123456789ABCDEF";
	if (n >= 16)
		ft_putnbr_hex(n / 16, info);
	if (info->type == 'x')
		ft_putchar(min[n % 16]);
	else if (info->type == 'X')
		ft_putchar(maj[n % 16]);
}

int	ft_nbrlen_hex(unsigned int n, t_info *info)
{
	int	len;

	len = 0;
	if (n == 0 && info->point == 1 && info->precision == 0)
		return (0);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_sign_hex(t_info *info)
{
	if (info->plus == 1 || info->space == 1)
		return (1);
	return (0);
}

void	ft_print_sign_hex(t_info *info)
{
	if (info->plus == 1)
		ft_putchar ('+');
	if (info->space == 1 && info->plus == 0)
		ft_putchar(' ');
	return ;
}
