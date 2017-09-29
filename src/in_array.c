/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 15:42:09 by pichrist          #+#    #+#             */
/*   Updated: 2017/09/24 18:33:56 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		in_array(char a, char *array)
{
	int i;

	i = -1;
	while (array[++i])
		if (a == array[i])
			return (1);
	return (0);
}
