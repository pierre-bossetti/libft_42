/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbossett <pbossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:06:29 by pbossett          #+#    #+#             */
/*   Updated: 2022/11/23 11:28:38 by pbossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_joined;
	size_t	i;
	size_t	j;
	size_t	s_len;

	i = 0;
	j = 0;
	s_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s_joined = malloc(sizeof(char) * s_len);
	if (s_joined == NULL)
		return (NULL);
	while (s1[i])
	{
		s_joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s_joined[i + j] = s2[j];
		j++;
	}
	s_joined[i + j] = '\0';
	return (s_joined);
}
