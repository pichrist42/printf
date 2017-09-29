/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:12:39 by pichrist          #+#    #+#             */
/*   Updated: 2017/09/24 19:37:11 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_mem	*parse(const char *format)
{
	t_mem	*first;
	t_mem	*item;
	int		macro;
	char	var_types[] = {'d', 'D', 's', 'S', 'c', 'C'};

	first = alloc_item(1);
	item = first;
	macro = 0;
	int i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			macro = 1;
		else if (macro && in_array(format[i], var_types))
		{
			item->next = alloc_item(format[i]);
			item = item->next;
			macro = 0;
		}
	}
	return (first);
}
