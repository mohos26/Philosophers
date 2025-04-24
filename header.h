/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:29:25 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/24 18:26:00 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# include <libc.h>
# include <pthread.h>

/* aid files*/
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);

/* src */
int				ft_get_info(char **av, int i);
int				ft_atoi(char *s);
pthread_mutex_t	*ft_forks(int i);
void			*ft_philosopher(void *n);
long			ft_get_time(void);
long			ft_start(int flag);
void			*ft_monitor(void *arg);
pthread_mutex_t	*ft_meal_lock(int flag);
int				ft_last_meal(int id, int n, int flag);

#endif
