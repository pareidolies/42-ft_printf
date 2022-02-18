/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:13:35 by smostefa          #+#    #+#             */
/*   Updated: 2022/02/10 19:07:31 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_info
{
	int		width;
	int		precision;
	int		zero;
	int		point;
	int		dash;
	int		hash;
	int		total_length;
	int		plus;
	int		percentage;
	int		space;
	char	type;
	va_list	arg;
	int		index;
	int		count;
}	t_info;

//ft_printf.c
void	ft_initialise_all_info(t_info *info);
void	ft_initialise_info(t_info *info);
int		ft_print_arg(t_info *info);
int		ft_printf(const char *format, ...);

//ft_get_format.c
void	ft_get_flags(t_info *info, char *format, int i);
void	ft_get_width_precision(t_info *info, char *format, int i);
int		ft_get_type(t_info *info, char *format, int i);
int		ft_get_format(t_info *info, const char *str, int i);

//ft_get_format_tools.c
int		ft_is_type(char c);
int		ft_is_digit_zero(char c);

//ft_print_char.c
void	ft_putchar(char c);
void	ft_print_char_left_justified(t_info *info, char c);
void	ft_print_char_right_justified(t_info *info, char c);
int		ft_print_char(t_info *info);

//ft_print_hex.c
int		ft_print_hex_left_justified(t_info *info, unsigned int nbr, int two);
void	ft_print_hex_right_justified_with_p(t_info *info, unsigned int nbr);
void	ft_print_hex_right_justified_no_p(t_info *info, unsigned int nbr);
int		ft_print_hex_right_justified(t_info *info, unsigned int nbr, int two);
int		ft_print_hex(t_info *info);

//ft_print_hex_tools.c
void	ft_putnbr_hex(unsigned int n, t_info *info);
int		ft_nbrlen_hex(unsigned int n, t_info *info);
int		ft_sign_hex(t_info *info);
void	ft_print_sign_hex(t_info *info);

//ft_print_nbr.c
void	ft_print_nbr_left_justified(t_info *info, int nbr);
void	ft_print_nbr_right_justified_with_precision(t_info *info, int nbr);
void	ft_print_nbr_right_justified_no_precision(t_info *info, int nbr);
void	ft_print_nbr_right_justified(t_info *info, int nbr);
int		ft_print_nbr(t_info *info);

//ft_print_nbr_tools.c
void	ft_putnbr(int n);
int		ft_nbrlen(int n, t_info *info);
int		ft_sign(int nbr, t_info *info);
void	ft_print_sign(int nbr, t_info *info);

//ft_print_unsigned.c
void	ft_print_unsigned_left_justified(t_info *info, unsigned int nbr);
void	ft_print_unsigned_right_j_with_p(t_info *info, unsigned int nbr);
void	ft_print_unsigned_right_j_no_p(t_info *info, unsigned int nbr);
int		ft_print_unsigned(t_info *info);

//ft_print_unsigned_tools.c
void	ft_putnbr_unsigned(unsigned int n);
int		ft_nbrlen_uns(unsigned int n, t_info *info);
int		ft_sign_uns(t_info *info);
void	ft_print_sign_unsigned(t_info *info);

//ft_print_str.c
void	ft_print_str_left_justified(t_info *info, char *str, int len);
void	ft_print_str_right_justified(t_info *info, char *str, int len);
int		ft_print_str(t_info *info);

//ft_print_str_tools.c
void	ft_putstr(char *str);
void	ft_putstr_precision(char *str, int precision);

//ft_printf_ptr.c
void	ft_print_ptr_left_justified(t_info *info, unsigned long long int nbr);
void	ft_print_ptr_right_j_with_p(t_info *info, unsigned long long int nbr);
void	ft_print_ptr_right_j_no_p(t_info *info, unsigned long long int nbr);
void	ft_print_ptr_right_justified(t_info *info, unsigned long long int nbr);
int		ft_print_ptr(t_info *info);

//ft_print_ptr_tools.c
void	ft_putnbr_ptr(unsigned long long int n, t_info *info);
int		ft_nbrlen_ptr(unsigned long long int n, t_info *info);
int		ft_sign_ptr(t_info *info);
void	ft_print_sign_ptr(t_info *info);

#endif
