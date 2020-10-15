/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprime_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:39:52 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_imprime_p(t_conv *conv)
{
	char			*base;
	char			charp[conv->end];

	base = "0123456789abcdef";
	charp[conv->end] = '\0';
	conv->end = conv->end - 1;
	while (conv->end >= 0)
	{
		charp[conv->end] = base[(conv->adr % 16)];
		conv->adr = conv->adr / 16;
		conv->end--;
	}
	if (conv->largeur > ft_strlen(charp))
		ft_cas1_p(conv, charp);
	else
		ft_cas2_p(conv, charp);
}

void	ft_cas1_p(t_conv *conv, char *charp)
{
	if (conv->flag == '-')
	{
		ft_cas2_p(conv, charp);
		ft_putchar_ameliore((conv->largeur - (ft_strlen(charp) + 2)),\
				' ', conv);
	}
	if (conv->flag != '-')
	{
		ft_putchar_ameliore((conv->largeur - (ft_strlen(charp) + 2)),\
				' ', conv);
		ft_cas2_p(conv, charp);
	}
}

void	ft_cas2_p(t_conv *conv, char *charp)
{
	int i;

	i = 0;
	if ((conv->p == NULL && conv->precision == 0) && conv->largeur > 2)
		ft_putchar(' ', conv);
	ft_putchar('0', conv);
	ft_putchar('x', conv);
	if (conv->p == NULL && conv->precision == 0)
		return ;
	while (i < ft_strlen(charp))
	{
		ft_putchar(charp[i], conv);
		i++;
	}
}
