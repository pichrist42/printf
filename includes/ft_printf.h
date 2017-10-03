/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 00:04:44 by pichrist          #+#    #+#             */
/*   Updated: 2017/10/03 19:05:00 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_mem
{
	char			type;
	char			*options;
	char			*val_str;
	double			val_dbl;
	int				val_int;
	struct s_mem	*next;
}					t_mem;

int		ft_printf(const char* format, ...);
t_mem	*parse(const char *format);
t_mem	*alloc_item(char c);
int		in_array(char a, char *array);
// char	*handle_list(const char *format, t_mem *first, va_list ap);
char	*handle_list(t_mem *first, va_list ap);
int		get_var(t_mem *item, va_list ap);
int		ft_tmemiter(t_mem *item, int (*f)(t_mem*, va_list), va_list ap);
void	display(char *output);
void	*ft_strtoupper(char *str);
void	parse_static_str(t_mem *item, char *str);
// debug
void	debug_int(char *msg, int var);
void	debug_str(char *msg, const char *str);
void	debug_char(char *msg, char c);

#endif
