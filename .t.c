#include <libc.h>
#include <pthread.h>

#define NUMBER_PHILO 5
#define MAX_WAIT_TIME 50

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

// دالة لحساب الوقت الحالي بالثواني
long current_time_sec()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec;
}

void *ft_aid(void *n)
{
	int id = *(int *)n;
	int left = id;
	int rigth = (id + 1) % NUMBER_PHILO;
	long start_wait;

	while (1)
	{
		printf("philo: %d, Think.\n", id);
		sleep(1);

		// بداية الانتظار
		start_wait = current_time_sec();

		// محاولة أخذ الشوك مع حساب الوقت
		if (id == NUMBER_PHILO - 1)
		{
			while (pthread_mutex_trylock(ft_forks(rigth)) != 0)
			{
				if (current_time_sec() - start_wait > MAX_WAIT_TIME)
				{
					printf("💀 philo: %d died waiting for right fork!\n", id);
					exit(1);
				}
				usleep(1000); // 1ms
			}
			printf("philo: %d, Took Right Fork %d.\n", id, rigth);

			while (pthread_mutex_trylock(ft_forks(left)) != 0)
			{
				if (current_time_sec() - start_wait > MAX_WAIT_TIME)
				{
					printf("💀 philo: %d died waiting for left fork!\n", id);
					exit(1);
				}
				usleep(1000);
			}
			printf("philo: %d, Took Left Fork %d.\n", id, left);
		}
		else
		{
			while (pthread_mutex_trylock(ft_forks(left)) != 0)
			{
				if (current_time_sec() - start_wait > MAX_WAIT_TIME)
				{
					printf("💀 philo: %d died waiting for left fork!\n", id);
					exit(1);
				}
				usleep(1000);
			}
			printf("philo: %d, Took Left Fork %d.\n", id, left);

			while (pthread_mutex_trylock(ft_forks(rigth)) != 0)
			{
				if (current_time_sec() - start_wait > MAX_WAIT_TIME)
				{
					printf("💀 philo: %d died waiting for right fork!\n", id);
					exit(1);
				}
				usleep(1000);
			}
			printf("philo: %d, Took Right Fork %d.\n", id, rigth);
		}

		printf("🍽️  philo: %d, Eating.\n", id);
		sleep(2);

		pthread_mutex_unlock(ft_forks(rigth));
		pthread_mutex_unlock(ft_forks(left));
		printf("philo: %d, Put Forks.\n", id);
		printf("philo: %d, Sleep.\n", id);
		sleep(3);
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
