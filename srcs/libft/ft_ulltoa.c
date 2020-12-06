/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulltoa.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 09:13:15 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/13 20:30:23 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_ulltoa(unsigned long long n)
{
	char	*strint;
	int		len;

	len = ft_unslonglonglen(n);
	strint = (char*)malloc(sizeof(char) * (len + 1));
	MALLOC_CHECK(strint);
	if (!strint)
		return (NULL);
	strint[len] = '\0';
	len--;
	if (n == 0)
		strint[len] = '0';
	while (n > 0)
	{
		strint[len] = n % 10 + '0';
		len--;
		n /= 10;
	}
	return (strint);
}
