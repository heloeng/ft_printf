/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:56:18 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/26 18:27:23 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_print_string("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		ft_printchar('-');
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count = count + ft_print_dec_int(n / 10);
		count = count + ft_print_dec_int(n % 10);
		return (count);
	}
	count += ft_printchar("0123456789"[n]);
	return (count);
}
