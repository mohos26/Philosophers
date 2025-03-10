/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:38:16 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 14:47:39 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_free(void *ptr, int flag)
{
	static void	*lst[INT_MAX];
	static int	i;
	int			j;

	if (flag)
	{
		j = 0;
		while (lst[j])
			free(lst[j++]);
	}
	else
		lst[i++] = ptr;
}

void	ft_exit(int status)
{
	ft_free(NULL, 1);
	exit(status);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_exit(1);
	ft_free(ptr, 0);
	return (ptr);
}
