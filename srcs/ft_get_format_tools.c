/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:13:13 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 13:10:03 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(char c)
{
	if (c == 'u' || c == 'd' || c == 'i' || c == 's' || c == 'c'
		|| c == 'p' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_is_digit_zero(char c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}
