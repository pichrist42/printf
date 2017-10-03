#include "../includes/ft_printf.h"

void	debug_int(char *msg, int var){
	ft_putstr(msg);
	ft_putnbr(var);
	ft_putendl("");
}

void	debug_char(char *msg, char c)
{
	ft_putstr(msg);
	ft_putchar(c);
	ft_putendl("]");
}

void	debug_str(char *msg, const char *str){
	ft_putstr(msg);
	ft_putstr(str);
	ft_putendl("]");
}