/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:57:55 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 19:09:16 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_char_left_justified(t_info *info, char c)
{
	if (info->dash == 1)
	{
		ft_putchar(c);
		while (info->width > 1)
		{
			ft_putchar(' ');
			info->width--;
		}
	}
}

void	ft_print_char_right_justified(t_info *info, char c)
{
	if (info->dash == 0)
	{
		if (info->zero == 1)
		{
			while (info->width > 1)
			{
				ft_putchar('0');
				info->width--;
			}
		}
		else
		{
			while (info->width > 1)
			{
				ft_putchar(' ');
				info->width--;
			}
		}
		ft_putchar(c);
	}
}

int	ft_print_char(t_info *info)
{
	char	c;
	int		count;

	count = info->width;
	if (info->type == 'c')
		c = va_arg(info->arg, int);
	else
		c = '%';
	ft_print_char_left_justified(info, c);
	ft_print_char_right_justified(info, c);
	if (count == 0)
		return (1);
	else
		return (count);
}
