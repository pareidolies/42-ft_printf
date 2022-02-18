NAME        = libftprintf.a

LIBFT		= libft

OBJS_DIR	= objs/

SRCS_DIR	= srcs/

LIB_DIR		= libft

INCS		= includes

SRCS		= ft_printf.c\
		      ft_get_format.c\
		      ft_get_format_tools.c\
		      ft_print_char.c\
		      ft_print_hex.c\
		      ft_print_hex_tools.c\
		      ft_print_nbr.c\
		      ft_print_nbr_tools.c\
		      ft_print_str.c\
		      ft_print_str_tools.c\
		      ft_print_unsigned.c\
		      ft_print_unsigned_tools.c\
		      ft_print_ptr.c\
		      ft_print_ptr_tools.c\

OBJS		= ${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}

RM			= rm -rf

all:		    ${NAME}

${NAME}:		${OBJS}
				make -C ${LIBFT}
				cp libft/libft.a .
				mv libft.a ${NAME}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
			    mkdir -p ${OBJS_DIR}
				gcc -Wall -Wextra -Werror -g -I ${INCS} -o $@ -c $<

clean:
			    ${RM} ${OBJS_DIR}
				make clean -C ${LIBFT}

fclean:		    clean
		        ${RM} ${NAME}
				${RM} ${LIBFT}/libft.a
				make fclean -C ${LIBFT}

re:		        fclean all

bonus:			fclean all

.PHONY:		    all clean fclean re bonus
