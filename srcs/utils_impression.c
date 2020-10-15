/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_impression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:43:46 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_nbd(long int nb, t_conv *conv)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		if (conv->type != 'u')
			i = i + 1;
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int		ft_nbx(unsigned long i)
{
	int j;

	j = 0;
	while ((i = i / 16) > 0)
		j++;
	return (j);
}

void	ft_putnbr(long int nb, t_conv *conv)
{
	if (nb < 0)
	{
		if (conv->type != 'u' && conv->moins == 'x')
			ft_putchar('-', conv);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, conv);
		ft_putnbr(nb % 10, conv);
	}
	else
		ft_putchar(nb + '0', conv);
}

void	ft_putnbr_unsigned(unsigned int nb, t_conv *conv)
{
	if (nb == 0 && conv->precision == 0)
	{
		if (conv->largeur > 0)
			ft_putchar(' ', conv);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, conv);
		ft_putnbr(nb % 10, conv);
	}
	else
		ft_putchar(nb + '0', conv);
}

void	ft_putchar_ameliore(int end, char c, t_conv *conv)
{
	int i;

	i = 0;
	if (end < 0)
		return ;
	while (i < end)
	{
		conv->ret = conv->ret + 1;
		write(1, &c, 1);
		i++;
	}
}
