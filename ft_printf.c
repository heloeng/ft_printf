/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:48:45 by helde-so          #+#    #+#             */
/*   Updated: 2024/11/22 17:34:28 by helde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <stdarg.h>
# include <unistd.h>

int ft_printchar(char c);

int ft_printchar(char c){
	return write(1, &c, 1);
}


int ft_formats(char c, va_list args)
{
	int count;

	count =0;
	if(c == 'c')
	count += ft_printchar(va_arg(args, int));
	return count;
	
}


int ft_printf(const char *str, ...)
{
	va_list args;
	int count;
	int i;

	count = 0;
	i = 0;

	//if(str == NULL)
	//return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_formats(str[i], args);
		}
		else
		count += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
	

}

#include <stdio.h>


int main(void)
{
	char c;
	c = 'x';

	printf("\n%d", ft_printf("%c", c));
	return(0);
}