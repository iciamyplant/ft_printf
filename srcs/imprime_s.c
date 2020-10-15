/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprime_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:41:40 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_imprime_s(t_conv *conv)
{
	int nbc;
	int i;

	nbc = ft_strlen(conv->s);
	i = conv->largeur - nbc;
	if (conv->flag != '-')
	{
		if (conv->largeur <= nbc || (conv->precision >= nbc\
					|| conv->precision <= -1))
			ft_cas1_s(nbc, i, conv);
		else if (conv->largeur > nbc && conv->precision < nbc)
			ft_cas2_s(0, conv);
	}
	else
	{
		if (conv->largeur <= nbc || (conv->precision >= nbc\
					|| conv->precision <= -1))
			ft_cas3_s(nbc, i, conv);
		else if (conv->largeur > nbc && conv->precision < nbc)
			ft_cas4_s(0, conv);
	}
}

void	ft_cas1_s(int nbc, int i, t_conv *conv)
{
	if (conv->largeur > nbc)
	{
		ft_putchar_ameliore(i, ' ', conv);
		ft_putstr(conv->s, conv);
	}
	else if (conv->precision >= 0 && conv->precision < nbc)
	{
		ft_putchar_ameliore((conv->largeur - conv->precision), ' ', conv);
		i = 0;
		while (i < conv->precision)
		{
			ft_putchar(conv->s[i], conv);
			i++;
		}
	}
	else
		ft_putstr(conv->s, conv);
}

void	ft_cas2_s(int i, t_conv *conv)
{
	while (i < (conv->largeur - conv->precision))
	{
		ft_putchar(' ', conv);
		i++;
	}
	i = 0;
	while (i < conv->precision)
	{
		ft_putchar(conv->s[i], conv);
		i++;
	}
}

void	ft_cas3_s(int nbc, int i, t_conv *conv)
{
	if (conv->largeur > nbc)
	{
		ft_putstr(conv->s, conv);
		ft_putchar_ameliore(i, ' ', conv);
	}
	else if (conv->precision >= 0 && conv->precision < nbc)
	{
		i = 0;
		while (i < conv->precision)
		{
			ft_putchar(conv->s[i], conv);
			i++;
		}
		ft_putchar_ameliore((conv->largeur - conv->precision), ' ', conv);
	}
	else
		ft_putstr(conv->s, conv);
}

void	ft_cas4_s(int i, t_conv *conv)
{
	while (i < conv->precision)
	{
		ft_putchar(conv->s[i], conv);
		i++;
	}
	i = 0;
	while (i < (conv->largeur - conv->precision))
	{
		ft_putchar(' ', conv);
		i++;
	}
}
