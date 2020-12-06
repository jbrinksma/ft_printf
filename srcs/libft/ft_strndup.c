/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:26:21 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/13 20:30:05 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char*)malloc(sizeof(char) * (n + 1));
	MALLOC_CHECK(cpy);
	if (cpy == 0)
		return (NULL);
	while (i < n && s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
