/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:06:05 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 15:21:46 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned_left_justified(t_info *info, unsigned int nbr)
{
	ft_print_sign_unsigned(info);
	while (info->precision > ft_nbrlen_uns(nbr, info))
	{
		ft_putchar('0');
		info->precision--;
		info->width--;
	}
	if (!(nbr == 0 && info->precision == 0 && info->point == 1))
		ft_putnbr_unsigned(nbr);
	while ((info->width > (ft_nbrlen_uns(nbr, info) + ft_sign_uns(info)))
		&& (info->width > (info->precision + ft_sign_uns(info))))
	{
		ft_putchar(' ');
		info->width--;
	}
}

void	ft_print_unsigned_right_j_with_p(t_info *info, unsigned int nbr)
{
	if (info->point == 1)
	{
		while ((info->width > (ft_nbrlen_uns(nbr, info) + ft_sign_uns(info)))
			&& (info->width > (info->precision + ft_sign_uns(info))))
		{
			ft_putchar(' ');
			info->width--;
		}
		ft_print_sign_unsigned(info);
		while (info->precision > ft_nbrlen_uns(nbr, info))
		{
			ft_putchar('0');
			info->precision--;
		}
	}
}

void	ft_print_unsigned_right_j_no_p(t_info *info, unsigned int nbr)
{
	if (info->point == 0)
	{
		if (info->zero == 1)
		{
			ft_print_sign_unsigned(info);
			while (info->width > (ft_nbrlen_uns(nbr, info) + ft_sign_uns(info)))
			{
				ft_putchar('0');
				info->width--;
			}
		}
		else
		{
			while (info->width > (ft_nbrlen_uns(nbr, info) + ft_sign_uns(info)))
			{
				ft_putchar(' ');
				info->width--;
			}
			ft_print_sign_unsigned(info);
		}
	}
	if (!(nbr == 0 && info->precision == 0 && info->point == 1))
		ft_putnbr_unsigned(nbr);
}

int	ft_print_unsigned(t_info *info)
{
	unsigned int	nbr;
	int				len;
	int				count;

	nbr = va_arg(info->arg, unsigned int);
	if (info->width >= info->precision)
		count = info->width;
	else
		count = info->precision;
	if (info->dash == 1)
		ft_print_unsigned_left_justified(info, nbr);
	if (info->dash == 0)
	{
		ft_print_unsigned_right_j_with_p(info, nbr);
		ft_print_unsigned_right_j_no_p(info, nbr);
	}
	len = ft_nbrlen_uns(nbr, info) + ft_sign_uns(info);
	if (count > len)
		return (count);
	else
		return (len);
}
