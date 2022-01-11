/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:17:19 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/02 14:17:23 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*itoa;
	int			i;
	long long	nb;

	nb = n;
	i = ft_intlen(nb);
	itoa = (char *)malloc(sizeof(char) * i + 1);
	if (!itoa)
		return (0);
	itoa[i] = '\0';
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		itoa[0] = '0';
	while (nb > 0)
	{
		i--;
		itoa[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (itoa);
}
