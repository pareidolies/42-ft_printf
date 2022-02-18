/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:02:32 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 15:19:59 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str_left_justified(t_info *info, char *str, int len)
{
	if (info->dash == 1)
	{
		if (info->point == 1)
			ft_putstr_precision(str, info->precision);
		else
			ft_putstr(str);
		while (info->width > len)
		{
			ft_putchar(' ');
			info->width--;
		}
	}
}

void	ft_print_str_right_justified(t_info *info, char *str, int len)
{
	if (info->dash == 0)
	{
		if (info->zero == 1)
		{
			while (info->width > len)
			{
				ft_putchar('0');
				info->width--;
			}
		}
		else
		{
			while (info->width > len)
			{
				ft_putchar(' ');
				info->width--;
			}
		}
		if (info->point == 1)
			ft_putstr_precision(str, info->precision);
		else
			ft_putstr(str);
	}
}

int	ft_print_str(t_info *info)
{
	int		len;
	char	*str;
	int		count;

	str = va_arg(info->arg, char *);
	if (!str)
		str = "(null)";
	if ((info->precision < (int)ft_strlen(str)) && info->point == 1)
		len = info->precision;
	else
		len = ft_strlen(str);
	count = info->width;
	ft_print_str_left_justified(info, str, len);
	ft_print_str_right_justified(info, str, len);
	if (count < len)
		return (len);
	else
		return (count);
}
