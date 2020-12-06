/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unslonglonglen.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 10:12:43 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/08 15:51:43 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_unslonglonglen(unsigned long long n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}
