/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:38:04 by joao-alm          #+#    #+#             */
/*   Updated: 2024/10/30 11:38:07 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

int	ft_get_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

int	ft_check_flags(const char **str, t_flags *flags)
{
	while (**str == '-' || **str == '0' || **str == '#' || **str == ' '
		|| **str == '+')
	{
		if (**str == '-')
			flags->minus = 1;
		else if (**str == '0' && !flags->minus)
			flags->zero = 1;
		else if (**str == '#')
			flags->cardinal = 1;
		else if (**str == '+')
			flags->plus = 1;
		else if (**str == ' ' && !flags->plus && !flags->minus)
			flags->space = 1;
		else
			return (0);
		(*str)++;
	}
	return (1);
}

int	ft_valid_flags(int c, t_flags *flags)
{
	if (!ft_get_type(c))
		return (0);
	if (c == 'c' && (flags->zero || flags->cardinal || flags->plus
			|| flags->space || flags->precision != -1))
		return (0);
	if (c == 's' && (flags->zero || flags->cardinal || flags->plus
			|| flags->space))
		return (0);
	if (c == 'p' && (flags->zero || flags->cardinal || flags->plus
			|| flags->space || flags->precision != -1))
		return (0);
	if ((c == 'd' || c == 'i') && flags->cardinal)
		return (0);
	if (c == 'u' && (flags->cardinal || flags->plus || flags->space))
		return (0);
	if ((c == 'x' || c == 'X') && (flags->plus || flags->space))
		return (0);
	if (c == '%' && (flags->zero || flags->cardinal || flags->plus
			|| flags->space || flags->width || flags->precision != -1))
		return (0);
	return (1);
}

char	*ft_handle_type_input(const char *str, t_flags *flags)
{
	if (!ft_check_flags(&str, flags))
		return ("Error: Invalid or Duplicate flag.\n");
	if (!(*str >= '0' && *str <= '9') && *str != '.' && !ft_get_type(*str))
		return ("Error: Invalid input.\n");
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '.' && !ft_get_type(*str))
		return ("Error: Invalid input.\n");
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (!ft_valid_flags(*str, flags))
		return ("Error: Invalid flag for given type.\n");
	return (NULL);
}

char	*ft_valid_input(const char *str, t_flags *flags)
{
	while (*str)
	{
		while (*str == '%' && *(str + 1))
		{
			str++;
			if (*str == '%')
			{
				str++;
				continue ;
			}
			if (ft_handle_type_input(str, flags))
				return (ft_handle_type_input(str, flags));
		}
		str++;
	}
	return (NULL);
}
