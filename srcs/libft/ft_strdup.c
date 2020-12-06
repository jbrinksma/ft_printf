/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:31:42 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/13 20:29:44 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	cpy = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	MALLOC_CHECK(cpy);
	if (cpy == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
