/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbrinksm <jbrinksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 18:19:32 by jbrinksm       #+#    #+#                */
/*   Updated: 2019/03/14 18:16:37 by jbrinksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define MALLOC_CHECK(value) !value ? exit(0) : 0;

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_va_list
{
	unsigned long long	data_ptr;
	long double			data_double;
	char				data_type;
	int					flag_hash;
	int					flag_zero;
	int					flag_minus;
	int					flag_space;
	int					flag_plus;
	int					field_width;
	int					precision;
	int					length_mod;
	int					removed_minus;
	int					is_positive;
	int					null_chars;
	int					empty_char_index;
	int					is_empty;
	int					end_of_str;
	struct s_va_list	*next;
}				t_va_list;

void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putendl(const char *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_itoa(int n);
int				ft_intlen(int n);
char			*ft_revstr(char *str);
int				ft_atoi(const char *str);
int				ft_isspace(char c);
char			*ft_strstr(const char *haystack, const char *needle);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *str);

int				ft_unsintlen(unsigned int n);
char			*ft_uitoa(unsigned int n);
int				ft_longlonglen(long long n);
char			*ft_lltoa(long long n);
int				ft_unslonglonglen(unsigned long long n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_char_to_str(char c);
void			ft_putnstr(char *str, int n);

/*
**	ft_printf.c
*/

int				ft_printf(const char *format, ...);
int				handle_arguments(t_va_list *data_list, char **format_cpy,
va_list vl, int percentages);

/*
**	struct_handlers.c
*/

t_va_list		*make_va_item(void);
t_va_list		*add_item_va_list(t_va_list *data_list);
t_va_list		*last_item(t_va_list *data_list);
void			clear_list(t_va_list *data_list);

/*
**	read_conversion_specification.c
*/

int				read_conversion_specification(t_va_list *data_list,
char **format_cpy, int *i);
void			flag_type_checker(t_va_list *probe, char *format, int *i);
void			field_width_and_precision_checker(t_va_list *probe,
char *format, int *i);
void			length_mod_checker(t_va_list *probe, char *format, int *i);
int				conv_type_checker(t_va_list *probe, char *format, int *i);

/*
**	replace_conversion_specification.c
*/

void			replace_conversion_specification(t_va_list *data_lst,
char **format_cpy, va_list va, int *i);

/*
**	conversions_to_str_wrapper.c
*/

char			*conversions_to_str_wrapper(t_va_list *probe,
int loc_in_string);
char			*char_wrapper(t_va_list *probe);
char			*str_wrapper(t_va_list *probe);
char			*ptr_wrapper(t_va_list *probe);
char			*double_wrapper(t_va_list *probe);

/*
**	diouxx_to_str_wrapper.c
*/

char			*diouxx_to_str_wrapper(t_va_list *probe);

/*
**	poxf_converters.c
*/

char			*convert_p_to_str(unsigned long long data_ptr);
char			*convert_o_to_str(unsigned long long data_ptr);
char			*convert_hex_to_str(unsigned long long data_ptr, char c);
char			*convert_f_to_str(int hash_flag, long double data_double,
int precision);

/*
**	manipulate_converted_str.c
*/

void			manipulate_converted_str(t_va_list *probe, char **data_str,
int loc_in_string);
char			*add_hash_flag(t_va_list *probe, char **data_str);
void			add_space_flag(t_va_list *probe, char **data_str);
void			add_plus_flag(t_va_list *probe, char **data_str);

/*
**	add_precision.c
*/

void			add_precision(t_va_list *probe, char **data_str);

/*
**	add_field_width_and_flags.c
*/

void			check_field_width(t_va_list *probe, char **data_str);
void			add_field_width_and_flags(t_va_list *probe, char **data_str,
int chars_left);
char			*create_padding(int size, char c);

/*
**	extra_functions.c
*/

char			*get_hex_chars(char c);
long double		multiply_double(long double data_double, int precision);
int				find_null_char(char *data_str, int loc_in_string);
int				find_end_of_str(char *data_str, int loc_in_string);
char			*remove_minus(t_va_list *probe, char *str);

#endif
