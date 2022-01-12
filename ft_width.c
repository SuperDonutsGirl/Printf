/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tttzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:26:13 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/10 08:26:15 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_datawidth(t_data *data, const char *str, int i)
{
	char	*nb;
	int		j;
	int		n;
	int		rt;
	int		size;

	j = 0;
	while (str[i++] >= '0' && str[i++] <= '9')
		j++;
	size = j;
	rt = i - 1;
	if (j == 0)
		size = 1;
	nb = (char *)malloc(sizeof(char) * size + 1);
	if (!nb)
		return (0);
	nb[j] = '\0';
	while (j--)
		nb[j] = str[--i];
	n = ft_atoi(nb);
	data->width = n;
	free(nb);
	return (rt);
}
