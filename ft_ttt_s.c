/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttt_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:57:43 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/13 13:57:44 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_space_s(t_data *data, char *str)
{
    int nbz;

    nbz = data->width - ft_strlen(str);
    while (nbz > 0 && data->minus == 0)
	    {
		    data->int_rt += write(1, " ", 1);
		    nbz--;
	    }
    
}

void	ft_space_s_minus(t_data *data, char *str)
{
    int nbz;

    nbz = data->width - ft_strlen(str);
    while (nbz > 0 && data->minus == 1)
	    {
		    data->int_rt += write(1, " ", 1);
		    nbz--;
	    }
    
}

void    ttt_s(t_data *data)
{
    char *str;

    str = va_arg(data->params, char *);
    
    ft_space_s(data, str);
    if (str == NULL)
        data->int_rt += write(1, "(null)", 6);
    else
        ft_print_str(data, str);
    ft_space_s_minus(data, str);
}