/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 22:21:29 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/13 20:29:55 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		i2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	i2 = 0;
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	MALLOC_CHECK(ft_strjoin);
	if (join == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		join[i] = s2[i2];
		i++;
		i2++;
	}
	join[i] = '\0';
	return (join);
}
