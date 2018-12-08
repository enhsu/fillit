/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:32:35 by chsu              #+#    #+#             */
/*   Updated: 2018/12/05 21:10:14 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		can_put(char **solve, int solve_p, char *tet)
{
	int	solve_w;
	int	ft;
	int	i;
	int	tet_r;
	int	tet_c;

	solve_w = ft_strlen(solve[0]);
	ft = 0;
	while (tet[ft] == '.')
		ft++;
	i = 0;
	while (tet[i])
	{
		if (tet[i] != '.')
		{
			tet_r = solve_p / solve_w + i / 4 - ft / 4;
			tet_c = solve_p % solve_w + i % 4 - ft % 4;
			if (tet_r >= solve_w ||
					tet_c >= solve_w ||
					solve[tet_r][tet_c] != '.')
				return (0);
		}
		i++;
	}
	return (1);
}

void	act_put(char **solve, int solve_p, char *tet)
{
	int	solve_w;
	int	ft;
	int	i;
	int	tet_r;
	int	tet_c;

	solve_w = ft_strlen(solve[0]);
	ft = 0;
	while (tet[ft] == '.')
		ft++;
	i = 0;
	while (tet[i])
	{
		if (tet[i] != '.')
		{
			tet_r = solve_p / solve_w + i / 4 - ft / 4;
			tet_c = solve_p % solve_w + i % 4 - ft % 4;
			solve[tet_r][tet_c] = tet[i];
		}
		i++;
	}
}

int		put_tet(char **solve, int solve_p, char *tet)
{
	if (can_put(solve, solve_p, tet))
	{
		act_put(solve, solve_p, tet);
		return (1);
	}
	else
		return (0);
}

int		try_solve(char **input, char **solve, int cur, int input_num)
{
	int	solve_p;
	int	solve_w;

	solve_p = 0;
	solve_w = ft_strlen(solve[0]);
	while (solve_p < solve_w * solve_w)
	{
		if (put_tet(solve, solve_p, input[cur]) == 1)
		{
			if (cur == input_num - 1 ||
					try_solve(input, solve, cur + 1, input_num))
				return (1);
			reset_try(solve, cur);
		}
		solve_p++;
	}
	return (0);
}

char	**solve(char **arr, int arr_rs)
{
	char	**ret;
	int		ret_w;

	ret_w = 2;
	while (ret_w * ret_w < arr_rs * 4)
		ret_w++;
	while (1)
	{
		ret = create_empty_arr(ret_w);
		if (try_solve(arr, ret, 0, arr_rs))
			break ;
		empty_solve(ret);
		ret_w++;
	}
	return (ret);
}
