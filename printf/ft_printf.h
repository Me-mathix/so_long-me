#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>

int ft_printf(const char *, ...);
int	print_char(char c);
int	print_lhex(unsigned int nbr);
int	print_nbr(int nb);
int	print_pointer(void *ptr);
int	print_str(char *str);
int	print_uhex(unsigned int nbr);
int	ft_tree(const char *str, int i, va_list lst);
int	print_unbr(unsigned int nb);


#endif