/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprime_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:42:14 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_imprime_u(t_conv *conv)
{
	int nbd;
	int i;
	int j;

	if (conv->u2 >= 0)
		nbd = ft_nbd(conv->u2, conv);
	else
		nbd = ft_unsigned_nbd((unsigned)conv->u2);
	i = conv->largeur - nbd;
	j = conv->precision - nbd;
	if (conv->largeur < nbd || conv->precision < nbd)
		ft_cas1_u(nbd, i, j, conv);
	else
		ft_cas2_u(i, j, conv);
	return (0);
}

int		ft_cas1_u(int nbd, int i, int j, t_conv *conv)
{
	if (conv->largeur > nbd && conv->flag == '-')
	{
		ft_putnbr_unsigned(conv->u2, conv);
		ft_putchar_ameliore(i, ' ', conv);
		return (0);
	}
	if ((conv->largeur > nbd && conv->flag == '0') && (conv->precision < 0))
		ft_putchar_ameliore(i, '0', conv);
	else if (conv->largeur > nbd && conv->flag != '-')
		ft_putchar_ameliore(i, ' ', conv);
	if (conv->precision > nbd)
		ft_putchar_ameliore(j, '0', conv);
	ft_putnbr_unsigned((unsigned)conv->u2, conv);
	return (0);
}

int		ft_cas2_u(int i, int j, t_conv *conv)
{
	if (conv->largeur > conv->precision && conv->flag == '-')
	{
		ft_putchar_ameliore(j, '0', conv);
		ft_putnbr_unsigned(conv->u2, conv);
		ft_putchar_ameliore(i - j, ' ', conv);
		return (0);
	}
	if (conv->largeur > conv->precision && conv->flag != '-')
	{
		ft_putchar_ameliore(i - j, ' ', conv);
		ft_putchar_ameliore(j, '0', conv);
	}
	else
		ft_putchar_ameliore(j, '0', conv);
	ft_putnbr_unsigned(conv->u2, conv);
	return (0);
}

int		ft_unsigned_nbd(unsigned long int nb)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}
