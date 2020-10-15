/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:38:04 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_impression(t_conv *conv)
{
	if (conv->type == 'd' || conv->type == 'i')
	{
		conv->d = va_arg(*conv->ap, int);
		ft_imprime_d(conv);
	}
	if (conv->type == 's')
	{
		conv->s = (char*)(va_arg(*conv->ap, char*));
		if (!conv->s)
			conv->s = "(null)";
		ft_imprime_s(conv);
	}
	if (conv->type == 'c')
	{
		conv->intc = va_arg(*conv->ap, int);
		ft_imprime_c(conv);
	}
}

void	ft_impression2(t_conv *conv, char *str)
{
	if (conv->type == 'p')
	{
		conv->p = va_arg(*conv->ap, void*);
		conv->adr = (unsigned long)conv->p;
		conv->end = ft_nbx(conv->adr) + 1;
		ft_imprime_p(conv);
	}
	if (conv->type == 'u')
	{
		conv->u2 = va_arg(*conv->ap, int);
		ft_imprime_u(conv);
	}
	if (conv->type == 'x' || conv->type == 'X')
	{
		conv->x = va_arg(*conv->ap, int);
		ft_imprime_x(conv);
	}
	if (conv->type == 'r')
		ft_imprime_r(conv, str);
}

int		ft_parsing(char *str, int i, t_conv *conv)
{
	int j;

	conv->first = i;
	j = -1;
	while (((j = res("cspdiuxX", str[i], 0, 8)) < 0) && str[i])
		i++;
	if (j < 0)
		conv->type = 'r';
	else
		conv->type = str[i];
	conv->end = i;
	conv->m = ft_largeur_memory(str, conv->first, i);
	ft_recup_largeur(str, conv->first, i, conv);
	ft_recup_flag(str, conv);
	ft_recup_precision(str, 0, conv, ft_precision_memory(str, conv));
	if (conv->type == 'd' || conv->type == 'i' || conv->type == 's'\
			|| conv->type == 'c')
		ft_impression(conv);
	else
		ft_impression2(conv, str);
	return (i + 1);
}

int		ft_printf(char *str, ...)
{
	int		i;
	t_conv	conv;
	va_list	ap;

	i = 0;
	conv.ret = 0;
	va_start(ap, str);
	conv.ap = &ap;
	while (str[i] && i < ft_strlen(str))
	{
		while (str[i] != '%' && str[i])
			ft_putchar(str[i++], &conv);
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar(str[i], &conv);
			i = i + 2;
		}
		if (str[i] == '%' && str[i + 1] != '%')
			i = ft_parsing(str, i, &conv);
	}
	return (conv.ret);
}
