/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 18:18:03 by pichrist          #+#    #+#             */
/*   Updated: 2017/10/08 16:52:59 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_list(t_mem *item, va_list ap){
	char *output = ft_strnew(0);
	char *tmp;

	while(item->type){
		// debug_char("following item -> type:", item->type);
		if (item->type == 's' || item->type == 'S'){
			if (!(item->val_str))
				item->val_str = va_arg(ap, char*);
			if (item->type == 'S')
				ft_strtoupper(item->val_str);
			output = ft_strjoin(output, item->val_str);
		}
		else if (item->type == 'd' || item->type == 'D')
			output = ft_strjoin(output, ft_itoa(va_arg(ap, int)));
		else if (item->type == 'c' || item->type == 'C'){
			tmp = ft_strnew(1);
			tmp[0] = va_arg(ap, int);
			if (item->type == 'C')
				ft_toupper(tmp[0]);
			output = ft_strjoin(output, tmp);
		}
		item = item->next;
	}
	return (output);
}

/*
int		get_var(t_mem *item, va_list ap)
{
	// if (item->type == 'd' || item->type == 'D')
	// 	item->int_value = va_arg(ap, int);
	// else 
	if (item->type == 'c' || item->type == 'C')
		item->val_int = va_arg(ap, int);
	else if (item->type == 's' || item->type == 'S')
		item->val_str = va_arg(ap, char*);
	else if (item->type == 'f' || item->type == 'd' || item->type == 'd' || item->type == 'D')
		item->val_dbl = va_arg(ap, double);
	else if (item->type != 1)
	{
		ft_putendl("ft_printf error : wrong type of arguments.");
		return (1);
	}
	return (0);
}

int		ft_tmemiter(t_mem *item, int (*f)(t_mem *item, va_list ap), va_list ap)
{
	int i;

	i = 0;
	if (item && f && ap)
		while (item)
		{
			if (f(item, ap))
				i = 1;
			item = item->next;
		}
	return (i);
}

char	*handle_list(const char *format, t_mem *first, va_list ap)
{
	char	*output;
	char	var_types[] = {'d', 'D', 's', 'S', 'c', 'C'};
	int		begin;
	int		count_var;
	int		length;
	int		macro;
	t_mem	*item;

	if (first->next)
	{
		item = first;
		if (ft_tmemiter(item, get_var, ap))
		{
			ft_putendl("exec stopped bc var");
			exit(1);
		}
		begin = 0;
		length = 0;
		macro = 0;
		count_var = 0;
		output = ft_strnew(0);
		while (format[begin + length])
		{
			if (format[begin + length] == '%')
			{
				macro = 1;
				output = ft_strjoin(output, ft_strsub(format, begin, length));
				begin += length;
				length = 0;
			}
			else if (macro && in_array(format[begin + length], var_types))
			{
				macro = 0;
				begin += length;
				length = 0;
				if (format[begin + length] == 'd' || format[begin + length] == 'D')
				{
					item = item->next;
					if (item->type == 'd' || item->type == 'D')
						output = ft_strjoin(output, ft_itoa(item->val_dbl));
					else
						ft_putendl("error type d");
				}
				else if (format[begin + length] == 'c' || format[begin + length] == 'C')
				{
					item = item->next;
					if (item->type == 'c' || item->type == 'C')
					{
						char *tmp = ft_strnew(1);
						tmp[0] = item->val_int;
						output = ft_strjoin(output, tmp);
					}
					else
						ft_putendl("error type c");
				}
				else if (format[begin + length] == 's' || format[begin + length] == 'S')
				{
					item = item->next;
					if (item->type == 's' || item->type == 'S')
						output = ft_strjoin(output, item->val_str);
					else
						ft_putendl("error type s");
				}
				else if (format[begin + length] == 'f' || format[begin + length] == 'F')
				{
					item = item->next;
					if (item->type == 'f' || item->type == 'F')
						output = ft_strjoin(output, ft_itoa(item->val_dbl));
					else
						ft_putendl("error type f");
				}
			}
			++length;
		}
		if (!count_var)
			output = ft_strjoin(output, ft_strsub(format, begin, length));
	}else
		output = ft_strdup(format);
	return (output);
}
*/