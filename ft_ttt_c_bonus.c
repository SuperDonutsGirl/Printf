/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttt_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:46:37 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/15 22:46:38 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(t_data *data)
{
	size_t	nbsp;

	nbsp = data->width - 1;
	while (nbsp-- > 0)
		data->int_rt += write(1, " ", 1);
}

void	ttt_c(t_data *data)
{
	char	c;

	c = va_arg(data->params, int);
	if (data->width > 1 && data->minus == 0)
	{
		ft_width(data);
		data->int_rt += write (1, &c, 1);
	}
	else if (data->width > 1 && data->minus == 1)
	{
		data->int_rt += write (1, &c, 1);
		ft_width(data);
	}
	else
		data->int_rt += write (1, &c, 1);
}
