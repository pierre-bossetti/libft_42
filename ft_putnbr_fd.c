/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbossett <pbossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:36:41 by pbossett          #+#    #+#             */
/*   Updated: 2022/12/16 18:40:53 by pbossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* faire attention au int min max
** imprime le signe - pour int neg
** recursion pour imprimer > 9 
*/

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		ft_putchar_fd((char)(n + 48), fd);
}
