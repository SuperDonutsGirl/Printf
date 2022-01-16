/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttt_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:55:07 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/15 22:55:08 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero_hex(t_data *data, unsigned int nb)
{
	int	i;
	int nbz;

	i = 1;
	nbz = 0;
	if (nb > 9 && nb <= 16)
		nbz += 1;
	if (nb >= 2147483647)
		i -= 2;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i += 1;
	}
	nbz = data->width - i ;
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

void	ft_minus_hex(t_data *data, unsigned int nb)
{
	int	i;
	int nbz;

	i = 1;
	nbz = 0;
	if (nb > 9 && nb <= 16)
		nbz += 1;
	if (nb >= 2147483647)
		i -= 2;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i += 1;
	}
	nbz += data->width - i;
	if (nb > 9 && nb <= 16)
		nbz -= 1;
	while (nbz-- > 0)
		data->int_rt += write(1, " ", 1);
}

void	ttt_x(t_data *data, char indicateur)
{
	unsigned int	nb;

	nb = va_arg(data->params, unsigned int);
	if (data->hashtag == 1 && indicateur == 'x' && nb > 0)
		data->int_rt += write(1, "0x", 2);
	if (data->hashtag == 1 && indicateur == 'X' && nb > 0)
		data->int_rt += write(1, "0X", 2);
	if (nb > 0 && data->width > 0 && data->minus == 0)
		ft_zero_hex(data, nb);
	ft_printb_int_hexa(data, indicateur, nb);
	if (nb > 0 && data->width > 0 && data->minus == 1)
		ft_minus_hex(data, nb);
}
