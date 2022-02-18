/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:59:44 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 15:45:29 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr_left_justified(t_info *info, int nbr)
{
	if (info->dash == 1)
	{
		ft_print_sign(nbr, info);
		while (info->precision > ft_nbrlen(nbr, info))
		{
			ft_putchar('0');
			info->precision--;
			info->width--;
		}
		if (!(nbr == 0 && info->precision == 0 && info->point == 1))
			ft_putnbr(nbr);
		while ((info->width > (ft_nbrlen(nbr, info) + ft_sign(nbr, info)))
			&& (info->width > (info->precision + ft_sign(nbr, info))))
		{
			ft_putchar(' ');
			info->width--;
		}
	}
}

void	ft_print_nbr_right_justified_with_precision(t_info *info, int nbr)
{
	if (info->point == 1)
	{
		while ((info->width > (ft_nbrlen(nbr, info) + ft_sign(nbr, info)))
			&& (info->width > (info->precision + ft_sign(nbr, info))))
		{	
			ft_putchar(' ');
			info->width--;
		}
		ft_print_sign(nbr, info);
		while (info->precision > ft_nbrlen(nbr, info))
		{
			ft_putchar('0');
			info->precision--;
		}
	}
}

void	ft_print_nbr_right_justified_no_precision(t_info *info, int nbr)
{
	if (info->point == 0)
	{
		if (info->zero == 1)
		{
			ft_print_sign(nbr, info);
			while (info->width > (ft_nbrlen(nbr, info) + ft_sign(nbr, info)))
			{
				ft_putchar('0');
				info->width--;
			}
		}
		else
		{
			while (info->width > (ft_nbrlen(nbr, info) + ft_sign(nbr, info)))
			{
				ft_putchar(' ');
				info->width--;
			}
			ft_print_sign(nbr, info);
		}
	}
}

void	ft_print_nbr_right_justified(t_info *info, int nbr)
{
	if (info->dash == 0)
	{
		ft_print_nbr_right_justified_with_precision(info, nbr);
		ft_print_nbr_right_justified_no_precision(info, nbr);
		if (!(nbr == 0 && info->precision == 0 && info->point == 1))
			ft_putnbr(nbr);
	}
}

int	ft_print_nbr(t_info *info)
{
	int	nbr;
	int	len;
	int	count;

	nbr = va_arg(info->arg, int);
	len = ft_nbrlen(nbr, info);
	if (info->width > info->precision)
		count = info->width;
	else
		count = info->precision + ft_sign(nbr, info);
	ft_print_nbr_left_justified(info, nbr);
	ft_print_nbr_right_justified(info, nbr);
	len = ft_nbrlen(nbr, info);
	if (count > len)
		return (count);
	else
		return (len + ft_sign(nbr, info));
}
