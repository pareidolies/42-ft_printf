/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:27:24 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 15:20:18 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr_left_justified(t_info *info, unsigned long long int nbr)
{
	ft_print_sign_ptr(info);
	while (info->precision > ft_nbrlen_ptr(nbr, info))
	{
		ft_putchar('0');
		info->precision--;
	}
	if (info->type == 'p' || info->hash == 1)
	{
		if (info->type == 'X')
			ft_putstr("0X");
		else
			ft_putstr("0x");
		info->width -= 2;
	}
	if (!(nbr == 0 && info->precision == 0 && info->point == 1))
		ft_putnbr_ptr(nbr, info);
	while ((info->width > (ft_nbrlen_ptr(nbr, info) + ft_sign_ptr(info)))
		&& (info->width > (info->precision + ft_sign_ptr(info))))
	{
		ft_putchar(' ');
		info->width--;
	}
}

void	ft_print_ptr_right_j_with_p(t_info *info, unsigned long long int nbr)
{
	if (info->point == 1)
	{
		if (info->type == 'p' || info->hash == 1)
			info->width -= 2;
		while ((info->width > (ft_nbrlen_ptr(nbr, info) + ft_sign_ptr(info)))
			&& (info->width > (info->precision + ft_sign_ptr(info))))
		{
			ft_putchar(' ');
			info->width--;
		}
		ft_print_sign_ptr(info);
		while (info->precision > ft_nbrlen_ptr(nbr, info))
		{	
			ft_putchar('0');
			info->precision--;
		}
	}
}

void	ft_print_ptr_right_j_no_p(t_info *info, unsigned long long int nbr)
{
	if (info->point == 0)
	{
		if (info->type == 'p' || info->hash == 1)
			info->width -= 2;
		if (info->zero == 1)
		{
			ft_print_sign_ptr(info);
			while (info->width > (ft_nbrlen_ptr(nbr, info) + ft_sign_ptr(info)))
			{
				ft_putchar('0');
				info->width--;
			}
		}
		else
		{
			while (info->width > (ft_nbrlen_ptr(nbr, info) + ft_sign_ptr(info)))
			{
				ft_putchar(' ');
				info->width--;
			}
			ft_print_sign_ptr(info);
		}	
	}
}

void	ft_print_ptr_right_justified(t_info *info, unsigned long long int nbr)
{
	if (info->type == 'p' || info->hash == 1)
	{
		if (info->type == 'X')
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	if (!(nbr == 0 && info->precision == 0 && info->point == 1))
		ft_putnbr_ptr(nbr, info);
}

int	ft_print_ptr(t_info *info)
{
	unsigned long long int	nbr;
	int						count;

	nbr = va_arg(info->arg, unsigned long long int);
	if (info->width >= info->precision)
		count = info->width;
	else
		count = info->precision;
	if (info->dash == 1)
		ft_print_ptr_left_justified(info, nbr);
	if (info->dash == 0)
	{
		ft_print_ptr_right_j_with_p(info, nbr);
		ft_print_ptr_right_j_no_p(info, nbr);
		ft_print_ptr_right_justified(info, nbr);
	}
	if (count > (ft_nbrlen_ptr(nbr, info) + 2))
		return (count);
	else
		return (ft_nbrlen_ptr(nbr, info) + 2);
}
