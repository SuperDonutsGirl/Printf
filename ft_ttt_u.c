/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttt_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:33:42 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/13 13:33:43 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_u(t_data *data, unsigned int nb)
{
	int	i;
	int nbz;

	i = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i += 1;
	}
	nbz = data->width - i;
	if (nb < 0)
		nbz -= 1;
	if (nbz > 0 && data->minus == 0 && data->zero == 1)
	{
		while (nbz-- > 0)
			data->int_rt += write(1, "0", 1);
	}
	if (nbz > 0 && data->minus == 0 && data->zero == 0)
	{
		while (nbz-- > 0)
			data->int_rt += write(1, " ", 1);
	}
}

void	ft_u_minus(t_data *data, unsigned int nb)
{
	int	i;
	int nbz;

	i = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i += 1;
	}
	nbz = data->width - i;
	if (nb < 0)
		nbz -= 1;
	//printf("le nb de zero : %i", nbz);
	if (nbz > 0 && data->minus == 1)
	{
		while (nbz-- > 0)
			data->int_rt += write(1, " ", 1);
	}
	
}

void	ttt_u(t_data *data)
{
	unsigned long long	nb;
	int i;

	nb = va_arg(data->params, unsigned long long int);
	
	i = 0;
	if (nb < 0 && data->width > 1)
		i++;
	if (nb > 0 && data->width > 1)
		ft_zero_u(data, nb);
	ft_print_unsigned_int(data, i, nb);
	ft_u_minus(data, nb);
	if ((long)nb <= LONG_MIN)
		ft_u_minus(data, 1);
}
