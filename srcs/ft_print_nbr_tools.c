/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:45:02 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 13:35:35 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("2147483648");
	else
	{
		if (n < 0)
			n = (-1) * n;
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

int	ft_nbrlen(int n, t_info *info)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0 && info->precision == 0 && info->point == 1)
		return (0);
	if (n == 0)
		return (1);
	else
	{
		if (n < 0)
			n = (-1) * n;
		while (n > 0)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

int	ft_sign(int nbr, t_info *info)
{
	if (nbr < 0 || info->plus == 1 || info->space == 1)
		return (1);
	return (0);
}

void	ft_print_sign(int nbr, t_info *info)
{
	if (nbr < 0)
		ft_putchar('-');
	if (info->plus == 1 && nbr >= 0)
		ft_putchar ('+');
	if (info->space == 1 && info->plus == 0 && nbr >= 0)
		ft_putchar(' ');
}
