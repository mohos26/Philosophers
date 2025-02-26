/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:26:31 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/26 14:30:31 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	n = 0;

size_t	v_max = 10000;

void* ft_aid(void* arg) {

	int i = 0;
	while (i++ < v_max)
		n++;
	return NULL;
}

int main() {
	pthread_t thread_id;

	if (pthread_create(&thread_id, NULL, ft_aid, NULL) != 0)
	{
		perror("error to create Thread");
		return 1;
	}
	int i = 0;
	while (i++ < v_max)
		n++;
	pthread_join(thread_id, NULL);
	printf("%d\n", n);
	printf("the main Thead end\n");
	return 0;
}
