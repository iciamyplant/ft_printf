/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprime_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:39:18 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_imprime_d(t_conv *conv)
{
	long int	nbd;
	int			i;
	int			j;

	nbd = ft_nbd(conv->d, conv);
	i = conv->largeur - nbd;
	j = conv->precision - nbd;
	conv->moins = 'x';
	if (conv->largeur <= nbd || conv->precision < nbd)
		ft_cas1_d(nbd, i, j, conv);
	else
	{
		if (conv->largeur > conv->precision && conv->flag == '-')
			ft_cas2_d(i, j, conv);
		else if (conv->largeur > conv->precision && conv->flag != '-')
			ft_cas3_d(i, j, conv);
		else
			ft_cas4_d(j, conv);
	}
}

int		ft_cas1_d(long int nbd, int i, int j, t_conv *conv)
{
	if (conv->largeur > nbd && conv->flag == '-')
	{
		if (conv->precision == 0 && conv->d == 0)
			ft_putchar(' ', conv);
		else
			ft_putnbr(conv->d, conv);
		ft_putchar_ameliore(i, ' ', conv);
		return (0);
	}
	if ((conv->largeur > nbd && conv->flag == '0') && (conv->precision < 0))
	{
		if (conv->d < 0)
		{
			ft_putchar('-', conv);
			conv->moins = '-';
		}
		ft_putchar_ameliore(i, '0', conv);
	}
	else if (conv->largeur > nbd && conv->flag != '-')
		ft_putchar_ameliore(i, ' ', conv);
	ft_cas5_d(nbd, j, conv);
	return (0);
}

int		ft_cas5_d(long int nbd, int j, t_conv *conv)
{
	if (conv->precision >= nbd)
	{
		if (conv->d < 0)
		{
			ft_putchar('-', conv);
			ft_putchar('0', conv);
			conv->moins = '-';
		}
		ft_putchar_ameliore(j, '0', conv);
	}
	if (conv->precision == 0 && conv->d == 0 && conv->largeur > 0)
		ft_putchar(' ', conv);
	if (conv->precision == 0 && conv->d == 0)
		return (0);
	ft_putnbr(conv->d, conv);
	return (0);
}

int		ft_cas2_d(int i, int j, t_conv *conv)
{
	if (conv->d < 0)
	{
		ft_putchar('-', conv);
		ft_putchar('0', conv);
		conv->moins = '-';
	}
	ft_putchar_ameliore(j, '0', conv);
	ft_putnbr(conv->d, conv);
	if (conv->d < 0)
		j = j + 1;
	ft_putchar_ameliore(i - j, ' ', conv);
	return (0);
}

int		ft_cas3_d(int i, int j, t_conv *conv)
{
	if (conv->largeur > conv->precision && conv->flag != '-')
	{
		if (conv->d < 0)
			ft_putchar_ameliore(i - (j + 1), ' ', conv);
		else
			ft_putchar_ameliore(i - j, ' ', conv);
		if (conv->d < 0)
		{
			ft_putchar('-', conv);
			ft_putchar('0', conv);
			conv->moins = '-';
		}
		ft_putchar_ameliore(j, '0', conv);
	}
	ft_putnbr(conv->d, conv);
	return (0);
}
