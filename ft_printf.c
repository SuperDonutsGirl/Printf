/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:12:22 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/02 02:19:44 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

t_data	*ft_initialize_data(t_data *data)
{
	data -> int_rt = 0;
	data -> minus = 0;
	data -> zero = 0;
	data -> pr = 0;
	data -> sp = 0;
	data -> plus = 0;
	data -> hashtag = 0;
	data -> width = 0;
	return (data);
}

t_data	*ft_reset_data(t_data *data)
{
	data -> minus = 0;
	data -> zero = 0;
	data -> pr = 0;
	data -> sp = 0;
	data -> plus = 0;
	data -> hashtag = 0;
	data -> width = 0;
	return (data);
}

int	ft_is_indicateur(char c)
{
	char *type;
	int	i;

	type = "cspiduxX";
	i = 0;
	while (type[i])
	{
		if (type[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_flag(t_data *data, const char *str, int i)
{
	ft_reset_data(data);
	while (ft_is_indicateur(str[i]) == 0 && str[i] != '%')
	{
		if (str[i] == '-')
			data -> minus = 1;
		else if (str[i] == '0')
			data -> zero = 1;
		else if (str[i] == '.')
			data -> pr = 1;
		else if (str[i] == '#')
			data -> hashtag = 1;
		else if (str[i] == ' ')
			data -> sp = 1;
		else if (str[i] == '+')
			data -> plus = 1;
		else if (str[i] > '0' && str[i] <= '9')
			i = ft_datawidth(data, str, i);
		i++;
	}
	return (i);
}

void	ft_ttt_conversion(t_data *data, char indicateur)
{
	if (indicateur == 'c')
		ft_print_char(data);
	else if (indicateur == 's')
		ft_print_str(data);
	else if (indicateur == 'p')
		ft_print_ptr(data);
	else if (indicateur == 'd' || indicateur == 'i')
		ft_print_int(data);
	else if (indicateur == 'u')
		ft_print_unsigned_int(data);
	else if (indicateur == 'x' || indicateur == 'X')
		ft_print_int_hexa(data, indicateur);
	else if (indicateur == '%')
		data->int_rt += write (1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		echo;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	ft_initialize_data(data);
	va_start(data->params, str);
	echo = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i = ft_check_flag(data, str, i + 1);
			ft_ttt_conversion(data, str[i]);
		}
		else
			echo += write (1, &str[i], 1);
	}
	echo += data->int_rt;
	va_end(data->params);
	free(data);
	return (echo);
}

/*
 #include <stdio.h>
 #include <stdlib.h>

 int main(void)
 {
 	int				c = 77;
 	char			*s = "";
 	int				i = 55;
 	int				d =	2147486;
 	unsigned int	u = 101;
 	void			*ptr = "vbcv";

 	printf("\n");
	int	rslt = ft_printf("Printf mien : lettre %c, string %s, chiffres %d et %i, unsigned %u, caractère %%, l'hexadecimale maj min %X %x, le pointeur %p", c, s, d, i, (int)u, (int)d, (int)d, (void*)ptr);
 	printf("\n\n");
	int	realrslr = printf("Printf real : lettre %c, string %s, chiffres %d et %i, unsigned %u, caractère %%, l'hexadecimale maj min %X %x, le pointeur %p", c, s, d, i, (int)u, (int)d, (int)d, (void*)ptr);
 	printf("\n\n");
 	printf("my int printf   : %i \n" , rslt);
 	printf("real int printf : %i \n" , realrslr);
 }*/


/*
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int rslt = ft_printf(" %04x ", 9);
 	int real =    printf(" %04x ", 9);

	printf("\nmy    : %i \n" , rslt);
 	printf("\nreal  : %i \n" , real);

}*/