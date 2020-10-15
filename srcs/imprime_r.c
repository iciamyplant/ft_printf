/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprime_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:41:00 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_imprime_r(t_conv *conv, char *str)
{
	int i;

	i = conv->first + 1;
	if (conv->flag == '-')
	{
		ft_cas1_r(conv, i, str);
		return ;
	}
	if (conv->flag == 'x' && conv->largeur > 0)
		ft_putchar_ameliore((conv->largeur - 1), ' ', conv);
	if (conv->flag == '0' && conv->largeur > 0)
		ft_putchar_ameliore((conv->largeur - 1), '0', conv);
	while (str[i] != '%' && i < conv->end)
		i++;
	while (i < conv->end)
	{
		ft_putchar(str[i], conv);
		i++;
	}
}

void	ft_cas1_r(t_conv *conv, int i, char *str)
{
	ft_putchar('%', conv);
	ft_putchar_ameliore((conv->largeur - 1), ' ', conv);
	while (str[i] != '%' && i < conv->end)
		i++;
	i = i + 1;
	while (i < conv->end)
	{
		ft_putchar(str[i], conv);
		i++;
	}
}
