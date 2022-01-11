/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:59:21 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/02 13:59:22 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_data *data)
{
	char	c;

	c = va_arg(data->params, int);
	data->int_rt += write (1, &c, 1);
}

void	ft_print_str(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(data->params, char *);
	if (str == NULL)
		data->int_rt += write(1, "(null)", 6);
	else
	{	while (str[i])
		{
			data->int_rt += write (1, &str[i], 1);
			i++;
		}
	}
}

void	ft_print_int(t_data *data)
{
	int		nb;
	char	*nbr;
	int		i;

	i = 0;
	nb = va_arg(data->params, int);
	nbr = ft_itoa(nb);
	while (nbr[i])
	{
		data->int_rt += write (1, &nbr[i], 1);
		i++;
	}
	free (nbr);
}
