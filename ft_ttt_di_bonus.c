/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttt_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:48:12 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/15 22:48:13 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_space_di(t_data *data, int nb)
{
	if (data->sp == 1 && nb >= 0)
		data->int_rt += write(1, " ", 1);
}

void	ft_zero_width_di(t_data *data, int nb)
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
	if (nb < 0 && data->width > 1)
	{
		data->int_rt += write(1, "-", 1);
		nbz--;
	}
	while (nbz > 0)
	{
		if (data->zero == 1 && data->minus == 0)
			data->int_rt += write(1, "0", 1);
		else if (data->zero == 0 && data->minus == 0)
			data->int_rt += write(1, " ", 1);
		nbz--;
	}
}

void	ft_zero_width_di_minus(t_data *data, int nb)
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
	if (nb < 0 && data->width > 1 && data->minus == 1)
		nbz--;
	while (nbz > 0)
	{
		if (data->zero == 1 && data->minus == 1)
			data->int_rt += write(1, "0", 1);
		else if (data->zero == 0 && data->minus == 1)
			data->int_rt += write(1, " ", 1);
		nbz--;
	}
}

void	ft_plus(t_data *data, int nb)
{
	if (data->plus == 1 && nb >= 0)
		data->int_rt += write (1, "+", 1);
}

void	ttt_di(t_data *data)
{
	int		nb;
	int		i;
	char	*nbr;

	nb = va_arg(data->params, int);
	i = 0;
	if (nb < 0 && data->width > 1)
		i = 1;
	nbr = ft_itoa(nb);
	ft_space_di(data, nb);
	ft_zero_width_di(data, nb);
	ft_plus(data, nb);
	ft_printb_str(data, nbr + i);
	ft_zero_width_di_minus(data, nb);
	free(nbr);
}