/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:06:31 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 19:08:37 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_flags(t_info *info, char *format, int i)
{
	while (format[i] && !ft_is_type(format[i]) && !ft_is_digit_zero(format[i]))
	{
		if (format[i] == '#')
			info->hash = 1;
		if (format[i] == '-')
			info->dash = 1;
		if (format[i] == '+')
			info->plus = 1;
		if (format[i] == ' ')
			info->space = 1;
		if (format[i] == '0')
			info->zero = 1;
		i++;
	}
}

void	ft_get_width_precision(t_info *info, char *format, int i)
{
	while (format[i] && !ft_is_type(format[i]))
	{
		while (format[i] >= '0' && format[i] <= '9')
		{
			info->width = info->width * 10 + format[i] - '0';
			i++;
		}
		if (format[i] && format[i] == '.')
		{
			info->point = 1;
			i++;
			while (format[i] && format[i] >= '0' && format[i] <= '9')
			{
				info->precision = info->precision * 10 + format[i] - '0';
				i++;
			}
		}
		i++;
	}
}

int	ft_get_type(t_info *info, char *format, int i)
{
	while (format[i] && !ft_is_type(format[i]))
	{
		i++;
	}
	if (format[i])
		info->type = format[i];
	return (i);
}

int	ft_get_format(t_info *info, const char *str, int i)
{
	int		ret;
	char	*format;

	format = (char *)str;
	ft_get_flags(info, format, i);
	ft_get_width_precision(info, format, i);
	ret = ft_get_type(info, format, i);
	return (ret);
}
