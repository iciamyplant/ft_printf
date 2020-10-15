/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprime_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:38:32 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_imprime_c(t_conv *conv)
{
	conv->c = (char)conv->intc;
	if (conv->largeur > 1)
		ft_cas1_c(conv);
	else
		ft_putchar(conv->c, conv);
}

int		ft_cas1_c(t_conv *conv)
{
	if (conv->largeur > 1 && conv->flag == '-')
	{
		ft_putchar(conv->c, conv);
		ft_putchar_ameliore((conv->largeur - 1), ' ', conv);
		return (0);
	}
	if ((conv->largeur > 1 && conv->flag == '0'))
		ft_putchar_ameliore((conv->largeur - 1), '0', conv);
	else if (conv->largeur > 1 && conv->flag != '-')
		ft_putchar_ameliore((conv->largeur - 1), ' ', conv);
	ft_putchar(conv->c, conv);
	return (0);
}

int		ft_cas4_d(int j, t_conv *conv)
{
	if (conv->d < 0)
	{
		ft_putchar('-', conv);
		ft_putchar('0', conv);
		conv->moins = '-';
	}
	ft_putchar_ameliore(j, '0', conv);
	ft_putnbr(conv->d, conv);
	return (0);
}
