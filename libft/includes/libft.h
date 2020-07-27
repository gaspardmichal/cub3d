/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamichal <gamichal@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 05:45:48 by gamichal          #+#    #+#             */
/*   Updated: 2020/03/07 14:07:19 by gamichal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>

# define FALSE 0
# define TRUE 1

# define SPEC	"cspdiuxX%"
# define FLAGS	"-0"
# define WIDTH	"*0123456789"
# define PREC	".*0123456789"

/*
**	########################################	CHAR
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
void				ft_putchar(char c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
**	########################################	FD
*/

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(long int n, int fd);
void				ft_putstr_fd(char *s, int fd);

/*
**	########################################	GNL
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef	struct		s_fd
{
	int				fd;
	char			*buffer;
	struct s_fd		*next;
}					t_fd;

int					endl(const char *s);
void				line_cat(char *dst, const char *src);
char				*line_join(char *line, char const *buffer);
char				*stringdup(const char *src);
int					get_next_line(int fd, char **line);

/*
**	########################################	INT
*/

char				*ft_itoa(long int n);
char				*ft_itoa_base(long int n, const char *base);
void				ft_putnbr(long int n);

/*
**	########################################	LST
*/

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),\
					void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

/*
**	########################################	MEM
*/

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_exit(void *ptr, int ret);
void				ft_free(void *ptr);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

/*
**	########################################	PRINTF
*/

int				ft_printf(const char *format, ...)
	 __attribute__((format(printf,1,2)));

typedef struct		s_dota
{
	va_list			ap;
	size_t			i;
	size_t			res;
	const char		*format;
	char			*spec;
	char			*base;
	char			minus;
	char			zero;
	char			w_star;
	char			p_star;
	char			w_read;
	char			p_read;
	int				width;
	int				prec;
	int				indx;
	void			(*arr[9]) (struct s_dota *);
}					t_dota;

int					ft_printf(const char *format, ...);
int					get_offset(int n);
void				get_modif(t_dota *dt);
int					get_pos(const char c, const char *s);
void				print_spaces(t_dota *dt, int c, int n);
void				print_s_spaces(t_dota *dt, int c, int offset);
void				print_zeros(t_dota *dt, int n);
void				reset_data(t_dota *dt);
void				parse_flags(const char *format, t_dota *dt);
void				parse_width(const char *format, t_dota *dt);
void				parse_prec(const char *format, t_dota *dt);
void				parse_modif(const char *format, t_dota *dt);
void				parse_spec(t_dota *dt, const char c);
void				print_c(t_dota *dt);
void				print_s(t_dota *dt);
void				print_s_w(t_dota *dt, const char *s, int offset);
void				print_s_p(t_dota *dt, const char *s, int offset);
void				print_s_wp(t_dota *dt, const char *s, int offset);
void				print_p(t_dota *dt);
void				print_p_minus(t_dota *dt, const char *p, int offset);
void				print_p_no_flag(t_dota *dt, const char *p, int offset);
void				print_p_w(t_dota *dt, const char *p, int offset);
void				print_p_p(t_dota *dt, const char *p, int offset);
void				print_p_wp(t_dota *dt, const char *p, int offset);
void				print_di(t_dota *dt);
void				print_di_w(t_dota *dt, const char *d, int offset);
void				print_di_p(t_dota *dt, const char *d, int offset);
void				print_di_wp(t_dota *dt, const char *d, int offset);
void				print_di_m_w(t_dota *dt, const char *d, int offset);
void				print_di_m_wp(t_dota *dt, const char *d, int offset);
void				print_di_z_w(t_dota *dt, const char *d, int offset);
void				print_di_z_wp(t_dota *dt, const char *d, int offset);
void				print_ux(t_dota *dt);
void				print_ux_w(t_dota *dt, const char *u, int offset);
void				print_ux_p(t_dota *dt, const char *u, int offset);
void				print_ux_wp(t_dota *dt, const char *u, int offset);
void				print_ux_m_w(t_dota *dt, const char *u, int offset);
void				print_ux_m_wp(t_dota *dt, const char *u, int offset);
void				print_ux_z_w(t_dota *dt, const char *u, int offset);
void				print_ux_z_wp(t_dota *dt, const char *u, int offset);
void				print_percent(t_dota *dt);
void				reset_data(t_dota *dt);

/*
**	########################################	STR
*/

int					ft_atoi(const char *str);
char				**ft_split(char const *s, char const *charset);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,\
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif
