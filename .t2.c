#include <libc.h>
#include <pthread.h>

#define NUMBER_PHILO 200
#define MAX_TIME 50

pthread_mutex_t	*ft_forks(int i)
{
	static pthread_mutex_t	fork[NUMBER_PHILO];
	int			j;

	if (i == -1)
	{
		j = 0;
		while (j < NUMBER_PHILO)
		{
			pthread_mutex_init(&fork[j], NULL);
			j++;
		}
		return (NULL);
	}
	return (&fork[i]);
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec);
}

void	*ft_aid(void *n)
{
	int	id;
	int	left;
	int	rigth;
	long	start_wait;

	id = *(int *)n;
	left = id;
	rigth = (id + 1) % NUMBER_PHILO;
	while (1)
	{
		printf("philo: %d, Think.\n", id);
		start_wait = ft_get_time();
		if (id == NUMBER_PHILO - 1)
		{
			pthread_mutex_lock(ft_forks(rigth));
			if (ft_get_time() - start_wait >= MAX_TIME)
			{
				printf("philo: %d, Kill.\n", id);
				exit(1);
			}
			printf("philo: %d, Take Rigth Fork '%d'.\n", id, rigth);
			pthread_mutex_lock(ft_forks(left));
			if (ft_get_time() - start_wait >= MAX_TIME)
			{
				printf("philo: %d, Kill.\n", id);
				exit(1);
			}
			printf("philo: %d, Take Left Fork '%d'.\n", id, left);
		}
		else
		{
			pthread_mutex_lock(ft_forks(left));
			if (ft_get_time() - start_wait >= MAX_TIME)
			{
				printf("philo: %d, Kill.\n", id);
				exit(1);
			}
			printf("philo: %d, Take Left Fork '%d'.\n", id, left);
			pthread_mutex_lock(ft_forks(rigth));
			if (ft_get_time() - start_wait >= MAX_TIME)
			{
				printf("philo: %d, Kill.\n", id);
				exit(1);
			}
			printf("philo: %d, Take Rigth Fork '%d'.\n", id, rigth);
		}
		printf("philo: %d, Eating.\n", id);
		sleep(2);

		pthread_mutex_unlock(ft_forks(rigth));
		pthread_mutex_unlock(ft_forks(left));
		printf("philo: %d, Put Forks.\n", id);
		printf("philo: %d, Sleep.\n", id);
		sleep(5);
	}
}

int main()
{
	pthread_t	philo[NUMBER_PHILO];
	int			ids[NUMBER_PHILO];
	int			i;

	ft_forks(-1);
	i = 0;
	while (i < NUMBER_PHILO)
	{
		ids[i] = i;
		pthread_create(&philo[i], NULL, ft_aid, &ids[i]);
		i++;
	}
	i = 0;
	while (i < NUMBER_PHILO)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
}
