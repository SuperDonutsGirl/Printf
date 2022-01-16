/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:56:40 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/15 22:56:40 by pamartin         ###   ########.fr       */
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

void	ft_printb(unsigned int nb, char indicateur, t_data *data)
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

void	ft_printb_int_hexa(t_data *data, char indicateur, unsigned int nb)
{
	int				i;
	long long		n;
	
	i = ft_div_hexa(nb);
	while (i != 0)
	{
		n = nb / i;
		ft_printb(n, indicateur, data);
		nb = nb % i;
		i = i / 16;
	}
}

unsigned long	ft_div_hexa_ptr(unsigned long adr)
{
	unsigned long	i;

	i = 1;
	while (adr / 16 != 0)
	{
		i *= 16;
		adr = adr / 16;
	}
	return (i);
}

void	ft_printb_ptr(t_data *data, unsigned long adr)
{
	char				*base16;
	unsigned long		ptr;
	unsigned long		i;

	base16 = "0123456789abcdef";
	data->int_rt += write(1, "0x", 2);
	i = ft_div_hexa_ptr(adr);
	while (i != 0)
	{
		ptr = adr / i;
		data->int_rt += write (1, &base16[ptr], 1);
		adr = adr % i;
		i = i / 16;
	}
}