/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:17:22 by llu               #+#    #+#             */
/*   Updated: 2018/12/06 00:15:02 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	display_square(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_putendl(arr[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		rd;
	char	buf[550];
	char	**input;

	if (ac != 2)
		ft_errexit("usage: fillit <file name>");
	if ((fd = open(av[1], O_RDONLY)) > 0)
	{
		rd = read(fd, buf, 550);
		if (is_valid_input(buf, rd / 21 + 1) && rd <= 545)
		{
			input = save_input(buf, rd);
			transfer_input(input);
			display_square(solve(input, rd / 21 + 1));
		}
		else
			ft_errexit("error");
	}
	else
		ft_errexit("error");
	return (0);
}
