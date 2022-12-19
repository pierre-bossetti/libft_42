/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbossett <pbossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:17:51 by pbossett          #+#    #+#             */
/*   Updated: 2022/12/18 13:09:36 by pbossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* returns amount of 
** splits required
*/
static int	fn_wordcount(char const *s, char c)
{
	int		i;
	int		splits;
	char	prevchar;

	prevchar = c;
	i = 0;
	splits = 0;
	while (s[i])
	{
		if (prevchar == c && s[i] != c)
			splits++;
		prevchar = s[i];
		i++;
	}
	return (splits);
}

/* counts length of characters between delimiter and
** returns int length of split strings
*/
static int	fn_wordlen(char const *s, char c, int pos)
{
	int	len;

	len = 0;
	while (s[pos] == c && s[pos])
		pos++;
	while (s[pos] != c && s[pos])
	{
		pos++;
		len++;
	}
	return (len);
}

/* free memory in case 
** array[row] == NULL
*/
static void	fn_freestuff(int row, char **array)
{
	while (row > 0)
	{
		free(array[row]);
		row--;
	}
	free(array);
}

/* splits string into substrings and returns char wrd
** which are seperate strings after the split
*/
static char	*fn_strreturn(char const *s, char c, int *posinstring)
{
	int		i;
	int		si;
	char	*wrd;

	i = 0;
	si = *posinstring;
	wrd = (char *)malloc(sizeof(char) * (fn_wordlen(s, c, *posinstring) + 1));
	if (!wrd)
		return (NULL);
	while (s[si] == c)
		si++;
	while (s[si])
	{
		if (s[si] != c)
		{
			wrd[i] = s[si];
			i++;
		}
		if (s[si] == c)
			break ;
		si++;
	}
	wrd[i] = '\0';
	*posinstring = si;
	return (wrd);
}

/* final function which puts split strings
** into main array
*/
char	**ft_split(char const *s, char c)
{
	int		row;
	char	**array;
	int		posinstring;
	int		wc;

	if (s == 0)
		return (NULL);
	wc = fn_wordcount(s, c);
	posinstring = 0;
	array = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!array)
		return (NULL);
	row = 0;
	while (row < wc)
	{
		array[row] = fn_strreturn(s, c, &posinstring);
		if (array[row] == NULL)
			fn_freestuff(row, array);
		row++;
	}
	array[row] = NULL;
	return (array);
}
