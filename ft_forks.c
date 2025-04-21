/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:09:19 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/21 16:10:02 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

pthread_mutex_t	*ft_forks(int i)
{
	static pthread_mutex_t	fork[200];
	int			j;

	if (i == -1)
	{
		j = 0;
		while (j < ft_get_info(NULL, 2))
		{
			pthread_mutex_init(&fork[j], NULL);
			j++;
		}
		return (NULL);
	}
	return (&fork[i]);
}

