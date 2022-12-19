/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbossett <pbossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:21:22 by pbossett          #+#    #+#             */
/*   Updated: 2022/12/16 18:39:58 by pbossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_char_counter(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count++;
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			count++;
		}
	}
	if (n < 0)
	{
		while (n < 0)
		{
			n = n / 10;
			count++;
		}
		count++;
	}
	return (count);
}

char	*ft_nb_is_negative(int n, char *itoa_str, size_t nb_char)
{
	int		result;

	result = 0;
	if (n == -2147483648)
	{
		n = -214748364;
		itoa_str[nb_char - 1] = (char)(8 + 48);
		nb_char--;
	}
	n *= (-1);
	while (n > 0)
	{
		result = (n % 10);
		itoa_str[nb_char - 1] = (char)(result + 48);
		n = n / 10;
		nb_char--;
	}
	itoa_str[--nb_char] = '-';
	return (itoa_str);
}

char	*ft_nb_is_positive(int n, char *itoa_str, size_t nb_char)
{
	int		result;

	result = 0;
	while (n > 0)
	{
		result = n % 10;
		itoa_str[nb_char - 1] = (char)(result + 48);
		n = n / 10;
		nb_char--;
	}
	return (itoa_str);
}

char	*ft_itoa(int n)
{
	size_t	nb_char;
	size_t	buff;
	char	*itoa_str;

	buff = 0;
	nb_char = ft_char_counter(n);
	itoa_str = (char *)ft_calloc((nb_char + 1), sizeof(char));
	if (!itoa_str)
		return (NULL);
	while (buff < nb_char)
	{
		itoa_str[buff] = '0';
		buff++;
	}
	if (n == 0)
		itoa_str[0] = (char)(0 + 48);
	else if (n < 0)
		itoa_str = ft_nb_is_negative(n, itoa_str, nb_char);
	else if (n > 0)
		itoa_str = ft_nb_is_positive(n, itoa_str, nb_char);
	return (itoa_str);
}
