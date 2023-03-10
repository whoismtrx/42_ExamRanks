/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:00:49 by orekabe           #+#    #+#             */
/*   Updated: 2023/03/10 05:03:57 by orekabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	int	size = 0;
	size += write(1, &c, 1);
	return (size);
}

int	ft_putstr(char *str)
{
	int	i = 0, size = 0;
	if (!str)
		size += write(1, "(null)", 6);
	else
	{
		while (str[i])
		{
			size += ft_putchar(str[i]);
			i++;
		}
	}
	return (size);
}

int	ft_putnbr(long long nbr)
{
	int size = 0;
	if (nbr < 0)
	{
		size += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		size += ft_putnbr(nbr / 10);
		size += ft_putnbr(nbr % 10);
	}
	else
		size += ft_putchar(nbr + 48);
	return (size);
}

int	ft_puthex(unsigned int nbr)
{
	int	size = 0;
	char *hex = "0123456789abcdef";

	if (nbr > 15)
	{
		size += ft_puthex(nbr / 16);
		size += ft_puthex(nbr % 16);
	}
	else
		size += ft_putchar(hex[nbr]);
	return (size);
}

int	ft_convertion(char *format, va_list ptr)
{
	int i = 0, size = 0;
	if (format[i] == 'd')
		size += ft_putnbr(va_arg(ptr, int));
	else if (format[i] == 's')
		size += ft_putstr(va_arg(ptr, char*));
	else if (format[i] == 'x')
		size += ft_puthex(va_arg(ptr, unsigned int));
	return (size);	
}

int	ft_printf(char *format, ...)
{
	int i = 0, size = 0;
	va_list ptr;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break;
		if (format[i] == '%')
		{
			i++;
			size += ft_convertion(&format[i], ptr);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	return (size);
}

int main()
{
	ft_printf("%x\n", 16);
}
