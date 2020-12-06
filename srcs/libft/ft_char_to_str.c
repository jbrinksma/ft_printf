/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_to_str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/09 05:19:45 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/13 20:34:01 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_char_to_str(char c)
{
	char	*data_str;

	data_str = (char*)malloc(sizeof(char) * 2);
	MALLOC_CHECK(data_str);
	data_str[0] = c;
	data_str[1] = '\0';
	return (data_str);
}
