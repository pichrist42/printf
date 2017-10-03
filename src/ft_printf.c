/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 00:04:39 by pichrist          #+#    #+#             */
/*   Updated: 2017/10/03 18:30:58 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
	parsing :
	OK parcourir chaine de format
	~ repérer var et leur type
	/ agencer dans l'ordre dans liste chainée
	~ extraire var

	traitement :
	parcourir chaine de format
	copier caractères dans chaine output
	si var, repérer celle-ci dans liste chainée
	faire traitements nécessaire et copier dans chaine output
	renvoyer
*/

void	debug_list(t_mem *first)
{
	t_mem *item = first;
	int i = 0;
	ft_putendl("debugging list:\n");
	while (item){
		ft_putstr("item ");
		ft_putnbr(i);
		ft_putstr("\ntype ");
		ft_putchar(item->type);
		ft_putstr("\nval_int ");
		ft_putnbr(item->val_int);
		if (item->val_str){
			ft_putstr("\nval_str ");
			ft_putstr(item->val_str);
		}
		else ft_putstr("\nno val_str");
		ft_putstr("\nval_dbl ");
		ft_putnbr(item->val_dbl);
		ft_putendl("");
		if (item->next)
			item = item->next;
		else{
			ft_putendl("no more item");
			break;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	char	*output;
	// int		length;
	t_mem	*first;
	va_list	ap;

	if (!ft_strlen(format))
		return (0);
	else
	{
		va_start(ap, format);
		first = parse(format);	// add later options for input array
		// debug_list(first);
		output = handle_list(first, ap);
		display(output);	// add later options for output fd
		va_end(ap);
		return (ft_strlen(output));
	}
}

/*

char* itoa(int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }
 
	char* ptr = result, *ptr1 = result, tmp_char;
	int tmp_value;
 
	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );
 
	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}
#include <stdio.h>
static char	*ftoa(float f, char *buffer, int nb_decimals)
{
	printf("float input:[%f]\n", f);
	char	*p_decimal;
	char	*result;
	float	power;
	int		decimal_val;
	int		integral_val;

	result = buffer;
	if (f < 0)
	{
		*buffer++ = '-';
		f = -f;
	}
	power = 1.0;
	integral_val = -1;
	while (++integral_val < nb_decimals)
		power *= 10;
	integral_val = (int)f;
	decimal_val = (int)((f - integral_val) * power);
	itoa(integral_val, buffer, 10);
	p_decimal = buffer + ft_strlen(buffer);
	*p_decimal++ = '.';
	itoa(decimal_val, p_decimal, 10);
	printf("string output:[%s]\n", result);
	return (result);
}

static int	nb_length(int x)
{
	int i;

	i = 0;
	while (x)
	{
		++i;
		x /= 10;
	}
	return (i);
}

static int	float_length(double x)
{
	while (!(x == (int)x))
		x *= 10;
	return (nb_length(x) + 1);
}

static int	print_nbr(va_list ap)
{
	int nb = va_arg(ap, int);
	ft_putnbr(nb);
	return (nb_length(nb));
}

static int	print_char(va_list ap)
{
	char c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

static int	print_str(va_list ap)
{
	char *str = va_arg(ap, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

static int	print_double(va_list ap)
{
	double d = va_arg(ap, double);
	char *buffer = ft_strnew(30);
	char *output = ftoa(d, buffer, 12);
	// ft_putstr(output);
	ft_strdel(&buffer);
	return (float_length(d));
}

// obligatoire : sSpdDioOuUxXcC %% #0-+ espace, taille min du champ, precision, hh h l ll j z
// bonus : eE, fF, gG, aA, n,  *, $, L, ’
// Gestion de ﬂags non existants : %b binaire, %r chaine ac char non-imprimables, %k date à un format ISO quelconque, etc
// Gestion de modiﬁeurs pour gérer lescouleurs,les fd ou des choses fun comme ça :)
// ex : printf("Le ﬁchier {cyan}%s{eoc} contient : {red}%s{eoc}", ﬁlename, str);

static int	parser(const char *format, va_list ap)
{
	// char	*output;
	int		i;
	int		macro;
	int		length;

	i = 0;
	macro = 0;
	length = 0;
	// output = ft_strnew(1);
	while (format[i])
	{
		if (format[i] == '%')
			macro = 1;
		// sSpdDioOuUxXcC
		if (macro && ft_strchr("sSpdDioOuUxXcC", format[i]))

		else
		{
			macro = 0;
			++length;
			ft_putchar(format[i]);
		}
		++i;
	}
	va_end(ap);
	return (length);
}

*/