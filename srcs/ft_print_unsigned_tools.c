/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:45:57 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 13:54:37 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10);
	ft_putchar((n % 10) + '0');
}

int	ft_nbrlen_uns(unsigned int n, t_info *info)
{
	int	len;

	len = 0;
	if (n == 0 && info->precision == 0 && info->point == 1)
		return (0);
	if (n == 0)
		return (1);
	else
	{
		while (n > 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

int	ft_sign_uns(t_info *info)
{
	if (info->plus == 1 || info->space == 1)
		return (1);
	return (0);
}

void	ft_print_sign_unsigned(t_info *info)
{
	if (info->plus == 1)
		ft_putchar ('+');
	if (info->space == 1 && info->plus == 0)
		ft_putchar(' ');
}
