#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define NUMBER_PHILO 200
#define MAX_TIME 50

pthread_mutex_t *ft_forks(int i)
{
	static pthread_mutex_t fork[NUMBER_PHILO];
	int j;

	if (i == -1)
	{
		j = 0;
		while (j < NUMBER_PHILO)
			pthread_mutex_init(&fork[j++], NULL);
		return NULL;
	}
	return &fork[i];
}

long	ft_get_time(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return time.tv_sec;
}

long last_meal_time[NUMBER_PHILO];
pthread_mutex_t meal_lock = PTHREAD_MUTEX_INITIALIZER;

void	*ft_monitor(void *arg)
{
	while (1)
	{
		for (int i = 0; i < NUMBER_PHILO; i++)
		{
			pthread_mutex_lock(&meal_lock);
			long diff = ft_get_time() - last_meal_time[i];
			pthread_mutex_unlock(&meal_lock);
			if (diff >= MAX_TIME)
			{
				printf("Monitor: Philosopher %d died. Time without forks: %ld sec\n", i, diff);
				exit(1);
			}
		}
		usleep(100000); // Check every 0.1 seconds
	}
	return NULL;
}

void	*ft_aid(void *n)
{
	int	id = *(int *)n;
	int	left = id;
	int	rigth = (id + 1) % NUMBER_PHILO;

	while (1)
	{
		printf("philo: %d, Think.\n", id);

		pthread_mutex_lock(&meal_lock);
		last_meal_time[id] = ft_get_time();
		pthread_mutex_unlock(&meal_lock);

		if (id == NUMBER_PHILO - 1)
		{
			pthread_mutex_lock(ft_forks(rigth));
			printf("philo: %d, Take Right Fork '%d'.\n", id, rigth);
			pthread_mutex_lock(ft_forks(left));
			printf("philo: %d, Take Left Fork '%d'.\n", id, left);
		}
		else
		{
			pthread_mutex_lock(ft_forks(left));
			printf("philo: %d, Take Left Fork '%d'.\n", id, left);
			pthread_mutex_lock(ft_forks(rigth));
			printf("philo: %d, Take Right Fork '%d'.\n", id, rigth);
		}

		printf("philo: %d, Eating.\n", id);
		sleep(2);

		pthread_mutex_unlock(ft_forks(rigth));
		pthread_mutex_unlock(ft_forks(left));
		printf("philo: %d, Put Forks.\n", id);
		printf("philo: %d, Sleep.\n", id);
		sleep(5);
	}
	return NULL;
}

int main()
{
	pthread_t philo[NUMBER_PHILO];
	int ids[NUMBER_PHILO];
	pthread_t monitor;
	int i;

	ft_forks(-1);

	for (i = 0; i < NUMBER_PHILO; i++)
	{
		ids[i] = i;
		last_meal_time[i] = ft_get_time(); // Init time
		pthread_create(&philo[i], NULL, ft_aid, &ids[i]);
	}

	pthread_create(&monitor, NULL, ft_monitor, NULL);

	for (i = 0; i < NUMBER_PHILO; i++)
		pthread_join(philo[i], NULL);

	pthread_join(monitor, NULL);
	return 0;
}
