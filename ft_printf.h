/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:44:29 by pamartin          #+#    #+#             */
/*   Updated: 2022/01/02 02:44:30 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	va_list	params;
	size_t	int_rt;
	size_t	minus;
	size_t	zero;
	size_t	pr;
	size_t	sp;
	size_t	plus;
	size_t	hashtag;
	size_t	width;
}	t_data;

t_data	*ft_initialize_data(t_data *data);

int		ft_printf(const char *str, ...);
void	ft_print_char(t_data *data, size_t int_rt);
void	ft_print_str(t_data *data, size_t int_rt);
void	ft_print_int(t_data *data, size_t int_rt);
void	ft_print_unsigned_int(t_data *data, size_t int_rt);
void	ft_print_int_hexa(t_data *data, char indicateur, size_t int_rt);
void	ft_print_ptr(t_data *data, size_t int_rt);
char	*ft_itoa(int n);
void	ft_ttt_conversion(t_data *data, char indicateur, size_t int_rt);
int		ft_atoi(char *str);
//bonus
int		ft_datawidth(t_data *data, const char *str, int i);

#endif
