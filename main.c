/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:26:31 by mhoussas          #+#    #+#             */
/*   Updated: 2025/02/25 15:39:21 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
	struct timeval	aid;

	printf("%d\n", gettimeofday(&aid, NULL));
	printf("%ld\n", aid.tv_sec);
	puts("True");
}
