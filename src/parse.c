/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:12:39 by pichrist          #+#    #+#             */
/*   Updated: 2017/10/03 19:30:20 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_static_str(t_mem *item, char *str){
	item->type = 's';
	item->val_str = str;
	item->next = alloc_item(0);
}

t_mem	*parse(const char *format)
{
	t_mem	*first;
	t_mem	*item;
	char	var_types[] = {'d', 'D', 's', 'S', 'c', 'C'};

	first = alloc_item(0);
	item = first;
	int length = 0;
	int begin = 0;
	// debug_str("format:[", format);
	while (format[begin + length])
	{
		// ft_putstr("char ");
		// ft_putnbr(begin + length);
		// ft_putstr(":");
		// ft_putchar(format[begin+length]);
		// ft_putendl("");
		if (format[begin + length] == '%')
		{
			if (length > 0){
				// debug_int("begin:", begin);
				// debug_int("length:", length);
				// debug_str("str before command:[", ft_strsub(format, begin, length));
				parse_static_str(item, ft_strsub(format, begin, length));
				item = item->next;
			}
			begin += length;
			length = 0;
			// debug_int("begin:", begin);
			while (format[begin + length] && !in_array(format[begin + length], var_types))
				++length;
			if (in_array(format[begin + length], var_types)){
				// ft_putendl("in array");
				if (length > 1)
					item->options = ft_strsub(format, begin, length);
				item->type = format[begin + length];
				// debug_str("options:[", item->options);
				// debug_char("type:[", item->type);
				item->next = alloc_item(0);
				item = item->next;
			}else{
				ft_putendl("format error");
				exit(1);
			}
			begin += length + 1;
			length = -1;
		}
		++length;
		// debug_int("begin:", begin);
		// debug_int("length", length);
	}
	if (length){
		// ft_putendl("default allocation : type s");
		parse_static_str(item, ft_strsub(format, begin, length));
		item = item->next;
	}
	return (first);
}
