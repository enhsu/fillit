/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:58:17 by chsu              #+#    #+#             */
/*   Updated: 2018/12/05 21:03:32 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	empty_solve(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	transfer_input(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '#')
				arr[i][j] = 'A' + i;
			j++;
		}
		i++;
	}
}

char	**create_empty_arr(int i)
{
	char	**ret;
	int		c;
	int		m;

	ret = (char**)malloc(sizeof(char*) * (i + 1));
	c = 0;
	while (c < i)
	{
		ret[c] = (char*)malloc(sizeof(char) * (i + 1));
		m = 0;
		while (m < i)
		{
			ret[c][m] = '.';
			m++;
		}
		ret[c][m] = '\0';
		c++;
	}
	ret[c] = NULL;
	return (ret);
}

void	reset_try(char **solve, int c)
{
	int	i;
	int	j;

	i = 0;
	while (solve[i])
	{
		j = 0;
		while (solve[i][j])
		{
			if (solve[i][j] == ('A' + c))
				solve[i][j] = '.';
			j++;
		}
		i++;
	}
}
