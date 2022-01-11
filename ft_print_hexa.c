/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:40:02 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/02 17:40:03 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_div_hexa(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb / 16 != 0)
	{
		i *= 16;
		nb = nb / 16;
	}
	return (i);
}

void	ft_print(unsigned int nb, char indicateur, t_data *data)
{
	char		*base_upp16;
	char		*base_low16;

	base_upp16 = "0123456789ABCDEF";
	base_low16 = "0123456789abcdef";
	if (indicateur == 'X')
		data->int_rt += write (1, &base_upp16[nb], 1);
	else if (indicateur == 'x')
		data->int_rt += write (1, &base_low16[nb], 1);
}

void	ft_print_int_hexa(t_data *data, char indicateur)
{
	int				i;
	long long		n;
	unsigned int	nb;

	nb = va_arg(data->params, unsigned int);
	i = ft_div_hexa(nb);
	while (i != 0)
	{
		n = nb / i;
		ft_print(n, indicateur, data);
		nb = nb % i;
		i = i / 16;
	}
}
