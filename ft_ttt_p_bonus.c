/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttt_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:48:40 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/15 22:48:41 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_minus(t_data *data, unsigned long long adr)
{
	int	i;
	int nbz;

	i = 1;
	
	while (adr / 10 != 0)
	{
		adr = adr / 10;
		i += 1;
	}
	nbz = data->width - i;
	if (adr <= -ULONG_MAX)
		nbz -= 2;
	if (nbz > 0 && data->minus == 1)
	{
		while (nbz > 0)
		{
			data->int_rt += write(1, " ", 1);
			nbz--;
		}
	}
}

void	ttt_p(t_data *data)
{
	unsigned long long	adr;

	adr = va_arg(data->params, unsigned long long);
	ft_printb_ptr(data, adr);
	if (adr <= (unsigned long long)INT_MIN || adr >= (unsigned long long)INT_MAX)
		ft_s_minus(data, adr);
}
