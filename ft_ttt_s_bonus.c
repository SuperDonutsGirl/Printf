/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttt_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:50:27 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/15 22:50:28 by pamartin         ###   ########.fr       */
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
    while (nbz > 0 && data->minus == 0 && data->pr == 0)
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

void    ft_pr_s(t_data *data, char *str)
{
   
    size_t i;

    i = 0;
	if (ft_strcmp(str, "") == 0)
		return ;
    while (str[i] && i < data->width)
    {
		data->int_rt += write (1, &str[i], 1);
		i++;
	}
}

void    ttt_s(t_data *data)
{
    char *str;

    str = va_arg(data->params, char *);
    
    ft_space_s(data, str);
    if (str == NULL)
        data->int_rt += write(1, "(null)", 6);
    else if (data->pr == 1)
        ft_pr_s(data, str);
    else
        ft_printb_str(data, str);
    ft_space_s_minus(data, str);
}