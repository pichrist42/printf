/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:07:35 by pichrist          #+#    #+#             */
/*   Updated: 2017/10/03 19:19:16 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_mem	*alloc_item(char c)
{
	t_mem *item;
	item = (t_mem*)malloc(sizeof(t_mem));
	if (item == NULL)
		exit(1);
	item->type = c;
	item->options = ft_strnew(0);
	return (item);
}
