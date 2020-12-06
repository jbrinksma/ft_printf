/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_revstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 20:59:07 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/13 20:33:50 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_revstr(char *str)
{
	char	*result;
	int		end;
	int		i;

	end = ft_strlen(str);
	result = (char*)malloc(sizeof(char) * (end + 1));
	MALLOC_CHECK(result);
	i = 0;
	result[end] = '\0';
	end--;
	while (end >= 0)
	{
		result[i] = str[end];
		i++;
		end--;
	}
	free(str);
	return (result);
}
