/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:26:31 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/03 14:39:53 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	n = 0;

size_t	v_max = 100;

void	*ft_aid(void* arg) {

	int i = 0;
	while (i++ < v_max)
		n++;
	return NULL;
}

int main() {
	pthread_t thread_id;
	pthread_t thread_id2;

	if (pthread_create(&thread_id, NULL, ft_aid, NULL))
	{
		perror("error to create Thread");
		return 1;
	}
	if (pthread_create(&thread_id2, NULL, ft_aid, NULL))
	{
		perror("error to create Thread");
		return 1;
	}
	int i = 0;
	while (i++ < v_max)
		n++;
	pthread_join(thread_id, NULL);
	pthread_join(thread_id2, NULL);
	printf("%d\n", n);
	printf("the main Thead end\n");
	return 0;
}
