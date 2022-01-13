/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:02:59 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/02 21:03:01 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_print_ptr(t_data *data, unsigned long adr)
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
