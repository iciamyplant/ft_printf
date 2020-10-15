/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprime_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:40:37 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_imprime_x(t_conv *conv)
{
	unsigned int	ux;
	char			*base;

	ux = (unsigned)conv->x;
	if (conv->type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (conv->x >= 0)
	{
		conv->end = ft_nbx((unsigned)conv->x) + 1;
		ft_positive_x(conv, base);
	}
	else
	{
		conv->end = ft_nbx(ux) + 1;
		ft_negative_x(conv, ux, base);
	}
}

void	ft_positive_x(t_conv *conv, char *base)
{
	int		x;
	char	charx[conv->end];

	x = conv->x;
	charx[conv->end] = '\0';
	conv->end = conv->end - 1;
	while (conv->end >= 0)
	{
		charx[conv->end] = (base[(x % 16)]);
		x = x / 16;
		conv->end--;
	}
	x = ft_strlen(charx);
	conv->i = conv->largeur - x;
	if (conv->largeur < x || conv->precision < x)
		ft_cas1_x(x, (conv->precision - x), conv, charx);
	else
		ft_cas2_x((conv->largeur - x), (conv->precision - x), conv, charx);
}

void	ft_negative_x(t_conv *conv, unsigned int ux, char *base)
{
	char	charx[conv->end];
	int		x;

	charx[conv->end] = '\0';
	conv->end = conv->end - 1;
	while (conv->end >= 0)
	{
		charx[conv->end] = (base[(ux % 16)]);
		ux = ux / 16;
		conv->end--;
	}
	x = ft_strlen(charx);
	conv->i = conv->largeur - x;
	if (conv->largeur < x || conv->precision < x)
		ft_cas1_x(x, (conv->precision - x), conv, charx);
	else
		ft_cas2_x((conv->largeur - x), (conv->precision - x), conv, charx);
}

int		ft_cas1_x(int nbd, int j, t_conv *conv, char *charx)
{
	if (conv->largeur > nbd && conv->flag == '-')
	{
		if (conv->precision == 0 && conv->x == 0)
			ft_putchar(' ', conv);
		else
			ft_putstr(charx, conv);
		ft_putchar_ameliore(conv->i, ' ', conv);
		return (0);
	}
	if ((conv->largeur > nbd && conv->flag == '0') && (conv->precision < 0))
		ft_putchar_ameliore(conv->i, '0', conv);
	else if (conv->largeur > nbd && conv->flag != '-')
		ft_putchar_ameliore(conv->i, ' ', conv);
	if (conv->precision > nbd)
		ft_putchar_ameliore(j, '0', conv);
	if (conv->precision == 0 && conv->x == 0 && conv->largeur > 0)
		ft_putchar(' ', conv);
	if (conv->precision == 0 && conv->x == 0)
		return (0);
	ft_putstr(charx, conv);
	return (0);
}

int		ft_cas2_x(int i, int j, t_conv *conv, char *charx)
{
	if (conv->largeur > conv->precision && conv->flag == '-')
	{
		ft_putchar_ameliore(j, '0', conv);
		ft_putstr(charx, conv);
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
	ft_putstr(charx, conv);
	return (0);
}
