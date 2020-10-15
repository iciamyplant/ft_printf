/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:43:10 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_precision_memory(char *str, t_conv *conv)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if ((i = res(str, '.', conv->first, conv->end)) >= 0)
	{
		i = i + 1;
		while ((res("0123456789", str[i + j], 0, 10)) >= 0)
			j++;
		return (j);
	}
	return (0);
}

int		ft_recup_precision(char *str, int j, t_conv *conv, int memory)
{
	int		i;
	char	precision[memory + 1];

	i = -1;
	precision[0] = '\0';
	if ((i = res(str, '.', conv->first, conv->end)) >= 0)
	{
		i = i + 1;
		while ((str[i] >= '0' && str[i] <= '9') && i < conv->end)
		{
			precision[j] = str[i];
			j++;
			i++;
		}
		if (str[i] == '*')
		{
			conv->precision = va_arg(*conv->ap, int);
			return (0);
		}
		precision[j] = '\0';
		conv->precision = ft_atoi(precision);
	}
	else
		conv->precision = -1;
	return (0);
}

int		ft_largeur_memory(char *str, int first, int end)
{
	int i;

	i = 0;
	while (first <= end && str[first] != '.')
	{
		if ((res("123456789", str[first], 0, 9)) >= 0)
		{
			while ((res("0123456789", str[first], 0, 10)) >= 0)
			{
				i++;
				first++;
			}
			break ;
		}
		first++;
	}
	return (i);
}

int		ft_recup_largeur(char *str, int first, int end, t_conv *conv)
{
	char	largeur[conv->m + 1];

	conv->m = 0;
	largeur[0] = '\0';
	while (first <= end && str[first] != '.')
	{
		if ((res("123456789", str[first], 0, 9)) >= 0)
		{
			while ((res("0123456789", str[first + conv->m], 0, 10)) >= 0)
			{
				largeur[conv->m] = str[first + conv->m];
				conv->m++;
			}
			largeur[conv->m] = '\0';
			break ;
		}
		if (str[first] == '*')
		{
			conv->largeur = va_arg(*conv->ap, int);
			return (0);
		}
		first++;
	}
	conv->largeur = ft_atoi(largeur);
	return (0);
}

int		ft_recup_flag(char *str, t_conv *conv)
{
	int i;

	i = conv->first;
	while ((str[i] < '1' || str[i] > '9') && i < conv->end)
		i++;
	if ((res(str, '0', conv->first, i)) >= 0)
		conv->flag = '0';
	else
		conv->flag = 'x';
	if ((res(str, '-', conv->first, i)) >= 0)
		conv->flag = '-';
	if (conv->largeur < 0)
	{
		conv->largeur = conv->largeur * -1;
		conv->flag = '-';
	}
	return (0);
}
