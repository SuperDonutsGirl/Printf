/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:59:21 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/02 13:59:22 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(t_data *data, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		data->int_rt += write (1, &str[i], 1);
		i++;
	}
}
