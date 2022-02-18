/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:56:54 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 13:40:14 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ptr(unsigned long long int n, t_info *info)
{
	char	*min;

	min = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_ptr(n / 16, info);
	ft_putchar(min[n % 16]);
	return ;
}

int	ft_nbrlen_ptr(unsigned long long int n, t_info *info)
{
	int	len;

	len = 0;
	if (n == 0 && info->precision == 0 && info->point == 1)
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

int	ft_sign_ptr(t_info *info)
{
	if (info->plus == 1 || info->space == 1)
		return (1);
	return (0);
}

void	ft_print_sign_ptr(t_info *info)
{
	if (info->plus == 1)
		ft_putchar ('+');
	if (info->space == 1 && info->plus == 0)
		ft_putchar(' ');
	return ;
}
