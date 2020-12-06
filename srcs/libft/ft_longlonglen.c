/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_longlonglen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 10:12:43 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/08 13:36:54 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_longlonglen(long long n)
{
	long long	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return ((int)i);
}
