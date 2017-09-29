/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:07:35 by pichrist          #+#    #+#             */
/*   Updated: 2017/09/24 19:37:15 by pichrist         ###   ########.fr       */
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
	return (item);
}
