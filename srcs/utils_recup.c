/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_recup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebourdit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2020/05/11 13:44:12 by ebourdit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar(char c, t_conv *conv)
{
	conv->ret = conv->ret + 1;
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		res(char *str, char c, int first, int end)
{
	int i;

	i = first;
	while (i <= end && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi(char *str)
{
	int i;
	int sum;

	sum = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - 48);
		i++;
	}
	return (sum);
}

int		ft_putstr(char *s, t_conv *conv)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		conv->ret = conv->ret + 1;
		write(1, &s[i], 1);
		i++;
	}
	return (0);
}
