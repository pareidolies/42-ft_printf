/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:08:37 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 15:21:00 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_left_justified(t_info *info, unsigned int nbr, int two)
{
	ft_print_sign_hex(info);
	while (info->precision > ft_nbrlen_hex(nbr, info))
	{
		ft_putchar('0');
		info->precision--;
		info->width--;
	}
	if (nbr != 0 && info->hash == 1)
	{
		if (info->type == 'X')
			ft_putstr("0X");
		else
			ft_putstr("0x");
		info->width -= 2;
		two = 2;
	}
	if (!(nbr == 0 && info->precision == 0 && info->point == 1))
		ft_putnbr_hex(nbr, info);
	while ((info->width > (ft_nbrlen_hex(nbr, info) + ft_sign_hex(info)))
		&& (info->width > (info->precision + ft_sign_hex(info))))
	{
		ft_putchar(' ');
		info->width--;
	}
	return (two);
}

void	ft_print_hex_right_justified_with_p(t_info *info, unsigned int nbr)
{
	if (info->point == 1)
	{
		if (info->hash == 1)
			info->width -= 2;
		while ((info->width > (ft_nbrlen_hex(nbr, info) + ft_sign_hex(info)))
			&& (info->width > (info->precision + ft_sign_hex(info))))
		{
			ft_putchar(' ');
			info->width--;
		}
		ft_print_sign_hex(info);
		while (info->precision > ft_nbrlen_hex(nbr, info))
		{
			ft_putchar('0');
			info->precision--;
		}
	}
}

void	ft_print_hex_right_justified_no_p(t_info *info, unsigned int nbr)
{
	if (info->point == 0)
	{
		if (info->hash == 1)
			info->width -= 2;
		if (info->zero == 1)
		{
			ft_print_sign_hex(info);
			while (info->width > (ft_nbrlen_hex(nbr, info) + ft_sign_hex(info)))
			{
				ft_putchar('0');
				info->width--;
			}
		}
		else
		{
			while (info->width > (ft_nbrlen_hex(nbr, info) + ft_sign_hex(info)))
			{
				ft_putchar(' ');
				info->width--;
			}
			ft_print_sign_hex(info);
		}
	}
}

int	ft_print_hex_right_justified(t_info *info, unsigned int nbr, int two)
{
	if (nbr != 0 && info->hash == 1)
	{
		if (info->type == 'X')
			ft_putstr("0X");
		else
			ft_putstr("0x");
		two = 2;
	}
	if (!(nbr == 0 && info->precision == 0 && info->point == 1))
		ft_putnbr_hex(nbr, info);
	return (two);
}

int	ft_print_hex(t_info *info)
{
	unsigned int	nbr;
	int				count;
	int				two;

	two = 0;
	nbr = va_arg(info->arg, unsigned int);
	if (info->width >= info->precision)
		count = info->width;
	else
		count = info->precision;
	if (info->dash == 1)
		two = ft_print_hex_left_justified(info, nbr, two);
	if (info->dash == 0)
	{
		ft_print_hex_right_justified_with_p(info, nbr);
		ft_print_hex_right_justified_no_p(info, nbr);
		two = ft_print_hex_right_justified(info, nbr, two);
	}
	if (count > ft_nbrlen_hex(nbr, info))
		return (count + two);
	else
		return (ft_nbrlen_hex(nbr, info) + two);
}
