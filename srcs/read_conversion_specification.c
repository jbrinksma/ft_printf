/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_conversion_specification.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/06 16:33:45 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/14 17:17:54 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	Reads and saves all data that is needed for the replacement part
**	of ft_printf.
*/

int		read_conversion_specification(t_va_list *data_list, char **format_cpy, \
int *i)
{
	t_va_list	*probe;
	int			read_i;

	if (data_list->next == NULL && data_list->is_empty)
		probe = data_list;
	else
		probe = add_item_va_list(data_list);
	probe->is_empty = 0;
	while ((*format_cpy)[*i] != '%' && (*format_cpy)[*i] != '\0')
		(*i)++;
	read_i = *i;
	read_i++;
	flag_type_checker(probe, *format_cpy, &read_i);
	field_width_and_precision_checker(probe, *format_cpy, &read_i);
	length_mod_checker(probe, *format_cpy, &read_i);
	if (conv_type_checker(probe, *format_cpy, &read_i))
		return (1);
	return (0);
}

void	flag_type_checker(t_va_list *probe, char *format, int *i)
{
	if (\
	format[*i] == '#' || format[*i] == '0' || \
	format[*i] == '-' || format[*i] == ' ' || \
	format[*i] == '+')
	{
		while (\
		format[*i] == '#' || format[*i] == '0' || \
		format[*i] == '-' || format[*i] == ' ' || \
		format[*i] == '+')
		{
			if (format[*i] == '#')
				probe->flag_hash = 1;
			else if (format[*i] == '0')
				probe->flag_zero = 1;
			else if (format[*i] == '-')
				probe->flag_minus = 1;
			else if (format[*i] == ' ')
				probe->flag_space = 1;
			else if (format[*i] == '+')
				probe->flag_plus = 1;
			(*i)++;
		}
	}
	else
		return ;
}

void	field_width_and_precision_checker(t_va_list *probe, char *format, \
int *i)
{
	int		counter;

	if (format[*i] >= '0' && format[*i] <= '9')
	{
		counter = 0;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			counter = (counter * 10) + (format[*i] - '0');
			(*i)++;
		}
		probe->field_width = counter;
	}
	if (format[*i] == '.')
	{
		counter = 0;
		(*i)++;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			counter = (counter * 10) + (format[*i] - '0');
			(*i)++;
		}
		probe->precision = counter;
	}
}

/*
**	length mode values are saved as followed:
**	0 = hh
**	1 = h
**	2 = l
**	3 = ll
**	4 = L
*/

void	length_mod_checker(t_va_list *probe, char *format, int *i)
{
	if (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'L')
	{
		(*i)++;
		if (format[*i] == 'h')
		{
			probe->length_mod = 0;
			(*i)++;
		}
		else if (format[*i] == 'l')
		{
			probe->length_mod = 3;
			(*i)++;
		}
		else
		{
			if (format[*i - 1] == 'h')
				probe->length_mod = 1;
			else if (format[*i - 1] == 'l')
				probe->length_mod = 2;
			else if (format[*i - 1] == 'L')
				probe->length_mod = 4;
		}
	}
}

/*
**	Returns 1 if dealing with unsupported or invalid
**	conversion specification.
*/

int		conv_type_checker(t_va_list *probe, char *format, int *i)
{
	if (format[*i] == 'c')
		probe->data_type = 'c';
	else if (format[*i] == 's')
		probe->data_type = 's';
	else if (format[*i] == 'p')
		probe->data_type = 'p';
	else if (format[*i] == 'd' || format[*i] == 'i')
		probe->data_type = 'd';
	else if (format[*i] == 'o')
		probe->data_type = 'o';
	else if (format[*i] == 'u')
		probe->data_type = 'u';
	else if (format[*i] == 'x')
		probe->data_type = 'x';
	else if (format[*i] == 'X')
		probe->data_type = 'X';
	else if (format[*i] == 'f')
		probe->data_type = 'f';
	else if (format[*i] == '%')
		probe->data_type = '%';
	else
		return (1);
	(*i)++;
	return (0);
}
