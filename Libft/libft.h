/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:35:33 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/09 15:34:54 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdarg.h>
# include <stdint.h>

int				ft_atoi(const char *nptr);
int				ft_how_many_strings(char const *str, char ch);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				hex_counter(uintptr_t i);
int				hex_internal_conv_min(uintptr_t i, char *array, int max_a);
int				hex_internal_conv_ma(uintptr_t i, char *array, int max_array);
int				ft_percent_conversion(char per);
int				ft_char_conversion(char c);
int				ft_string_conversion(char *str);
int				ft_check(char check, va_list args);
int				ft_printf(const char *str, ...);
int				ft_print_count_str(char *str);
int				ft_printnbr(int n);
int				ft_split_count(char *str, char splitter);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putstr(char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *str, char *buff);
char			*ft_strjoin_free(char *str, char *buff);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*get_next_line(int fd);
char			*ft_uitoa(unsigned int n);
unsigned int	ft_hexa_min_conversion(uintptr_t i);
unsigned int	ft_hexa_maiusc_conversion(uintptr_t i);
unsigned int	ft_pt_conversion(void *ptr);
unsigned int	ft_unsigned_conversion(unsigned int i);
#endif
