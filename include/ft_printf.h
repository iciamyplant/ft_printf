/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:49:24 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 14:29:01 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_conv
{
	char			flag;
	int				largeur;
	int				precision;
	char			type;
	int				first;
	int				end;
	va_list			*ap;
	int				d;
	int				u2;
	char			*s;
	int				intc;
	char			c;
	void			*p;
	char			charp[9];
	int				x;
	int				intx;
	int				ret;
	char			moins;
	char			rien;
	int				i;
	int				m;
	unsigned long	adr;
}					t_conv;

int					ft_printf(char *str, ...);
int					ft_parsing(char *str, int i, t_conv *conv);
void				ft_impression(t_conv *conv);
void				ft_impression2(t_conv *conv, char *str);
void				ft_putchar(char c, t_conv *conv);
int					res(char *str, char c, int first, int end);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					ft_putstr(char *s, t_conv *conv);
int					ft_precision_memory(char *str, t_conv *conv);
int					ft_recup_precision(char *str, int j, t_conv *conv,\
							int malloc);
int					ft_largeur_memory(char *str, int first, int end);
int					ft_recup_largeur(char *str, int first, int end,\
							t_conv *conv);
int					ft_recup_flag(char *str, t_conv *conv);
int					ft_nbd(long int nb, t_conv *conv);
void				ft_putnbr(long int nb, t_conv *conv);
void				ft_putnbr_unsigned(unsigned int nb, t_conv *conv);
void				ft_putchar_ameliore(int end, char c, t_conv *conv);
int					ft_nbx(unsigned long i);
void				ft_imprime_d(t_conv *conv);
int					ft_cas1_d(long int nbd, int i, int j, t_conv *conv);
int					ft_cas2_d(int i, int j, t_conv *conv);
int					ft_cas3_d(int i, int j, t_conv *conv);
int					ft_cas4_d(int j, t_conv *conv);
int					ft_cas5_d(long int nbd, int j, t_conv *conv);
void				ft_imprime_s(t_conv *conv);
void				ft_cas1_s(int nbc, int i, t_conv *conv);
void				ft_cas2_s (int i, t_conv *conv);
void				ft_cas3_s(int nbc, int i, t_conv *conv);
void				ft_cas4_s(int i, t_conv *conv);
void				ft_imprime_c(t_conv *conv);
int					ft_cas1_c(t_conv *conv);
void				ft_imprime_p(t_conv *conv);
void				ft_cas1_p(t_conv *conv, char *charp);
void				ft_cas2_p(t_conv *conv, char *charp);
int					ft_imprime_u(t_conv *conv);
int					ft_cas1_u(int nbd, int i, int j, t_conv *conv);
int					ft_cas2_u(int i, int j, t_conv *conv);
int					ft_unsigned_nbd(unsigned long int nb);
void				ft_imprime_x(t_conv *conv);
void				ft_positive_x(t_conv *conv, char *base);
void				ft_negative_x(t_conv *conv, unsigned int ux, char *base);
int					ft_cas1_x(int nbd, int j, t_conv *conv, char *charx);
int					ft_cas2_x(int i, int j, t_conv *conv, char *charx);
void				ft_imprime_r(t_conv *conv, char *str);
void				ft_cas1_r(t_conv *conv, int i, char *str);

#endif
