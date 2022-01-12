/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:26:37 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/02 14:26:38 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsintlen(unsigned int nb)
{
	int			i;
	long long	n;

	n = nb;
	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_unsitoa(unsigned int n)
{
	char		*unsitoa;
	int			i;
	long long	nb;

	nb = n;
	i = ft_unsintlen(nb);
	unsitoa = (char *)malloc(sizeof(char) * i + 1);
	if (!unsitoa)
		return (0);
	unsitoa[i] = '\0';
	if (nb == 0)
		unsitoa[0] = '0';
	while (nb > 0)
	{
		i--;
		unsitoa[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (unsitoa);
}

void	ft_print_unsigned_int(t_data *data, size_t int_rt)
{
	char			*unsitoa;
	unsigned int	nb;
	int				i;

	i = 0;
	nb = va_arg(data->params, unsigned long long int);
	unsitoa = ft_unsitoa(nb);
	while (unsitoa[i])
	{
		int_rt += write (1, &unsitoa[i], 1);
		i++;
	}
	free (unsitoa);
}
