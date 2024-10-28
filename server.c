/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhyulee <juhyulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:09:31 by juhyulee          #+#    #+#             */
/*   Updated: 2023/01/10 17:27:46 by juhyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	recur(int nb, int fd)
{
	char	mod;

	if (nb == 0)
		return ;
	recur(nb / 10, fd);
	mod = nb % 10 + 48;
	write(fd, &mod, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		recur(-n, fd);
	}
	else if (n > 0)
		recur(n, fd);
	else if (n == 0)
		write(fd, "0", 1);
}

void	sig_handler(int signo)
{
	static char	tmp;
	static int	bit;

	if (signo == SIGUSR1)
	{
		tmp |= 1;
		if (bit < 7)
			tmp <<= 1;
	}
	else if (signo == SIGUSR2)
	{
		tmp |= 0;
		if (bit < 7)
			tmp <<= 1;
	}
	bit++;
	if (bit == 8)
	{
		write(1, &tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
