/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyulee <juhyulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:09:26 by juhyulee          #+#    #+#             */
/*   Updated: 2023/01/12 16:08:00 by juhyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long long	ans;
	long long	sign;

	ans = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ans *= 10;
		ans += (*str - '0');
		str++;
	}
	return ((int)(ans * sign));
}

void	send_signal(int pid, char *str)
{
	int	i;
	int	num;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			num = (int)*str >> i & 1;
			if (num == 1)
			{
				kill(pid, SIGUSR1);
			}
			else if (num == 0)
			{
				kill(pid, SIGUSR2);
			}
			usleep(300);
			i--;
		}
		str++;
	}
	exit(0);
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	send_signal(pid, argv[2]);
	return (0);
}
