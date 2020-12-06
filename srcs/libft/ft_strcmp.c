/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 14:16:24 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/11 18:47:01 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		u;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	if (s1[i] != s2[i])
	{
		u = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
		return ((int)u);
	}
	else
		return (0);
}
