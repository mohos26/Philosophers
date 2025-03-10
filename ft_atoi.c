/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:17:40 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 14:49:30 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_is_number(char *s)
{
	long	n;

	while (*s == ' ')
		s++;
	if (*s == '+')
		s++;
	if (!s || !*s)
		return (0);
	n = 0;
	while (*s && ft_isdigit(*s))
	{
		n *= 10;
		n += (*s) - 48;
		if (n > (2147483647L))
			return (0);
		s++;
	}
	while (*s == ' ')
		s++;
	return (!*s);
}

int	ft_atoi(char *s)
{
	int	result;

	if (!ft_is_number(s))
	{
		ft_putendl_fd("!!! Invalive Number !!!", 2);
		ft_exit(1);
	}
	while (*s == 32)
		s++;
	result = 0;
	if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
		result = (result * 10) + (*s++ - '0');
	return (result);
}
