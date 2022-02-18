/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:05:03 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 15:43:29 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialise_all_info(t_info	*info)
{
	info->width = 0;
	info->precision = 0;
	info->zero = 0;
	info->point = 0;
	info->dash = 0;
	info->hash = 0;
	info->total_length = 0;
	info->plus = 0;
	info->percentage = 0;
	info->space = 0;
	info->type = 0;
	info->index = 0;
	info->count = 0;
}

void	ft_initialise_info(t_info	*info)
{
	info->width = 0;
	info->precision = 0;
	info->zero = 0;
	info->point = 0;
	info->dash = 0;
	info->hash = 0;
	info->total_length = 0;
	info->plus = 0;
	info->percentage = 0;
	info->space = 0;
	info->type = 0;
}

int	ft_print_arg(t_info *info)
{
	int	count;

	count = 0;
	if (info->type == 'c' || info->type == '%')
		count = ft_print_char(info);
	if (info->type == 's')
		count = ft_print_str(info);
	if (info->type == 'd' || info->type == 'i')
		count = ft_print_nbr(info);
	if (info->type == 'u')
		count = ft_print_unsigned(info);
	if (info->type == 'x' || info->type == 'X')
		count = ft_print_hex(info);
	if (info->type == 'p')
		count = ft_print_ptr(info);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	t_info	info;

	ft_initialise_all_info(&info);
	va_start(info.arg, format);
	if (!format)
		return (-1);
	while (info.index < (int)ft_strlen((char *)format))
	{
		if (format[info.index] == '%')
		{
			info.index = ft_get_format(&info, format, info.index + 1);
			info.count += ft_print_arg(&info);
			ft_initialise_info(&info);
		}
		else
		{
			write(1, &format[info.index], 1);
			info.count++;
		}
		info.index++;
	}
	va_end(info.arg);
	return (info.count);
}
