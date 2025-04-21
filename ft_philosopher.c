/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:17:21 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/21 16:29:27 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	*ft_philosopher(void *n)
{
	int		id;
	int		left;
	int		rigth;
	long	start;

	id = *(int *)n;
	left = id;
	rigth = (id + 1) % ft_get_info(NULL, 2);
	ft_printf("%ld %d is thinking\n", )
}
