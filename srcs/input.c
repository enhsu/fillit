/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:17:04 by llu               #+#    #+#             */
/*   Updated: 2018/12/05 21:50:43 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		basic_check(char *s)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (s[i * 5 + j] == '#')
				c++;
			if (s[i * 5 + j] != '.' && s[i * 5 + j] != '#')
				return (0);
			j++;
		}
		if (s[i * 5 + j] != '\n' && s[i * 5 + j] != '\0')
			return (0);
		i++;
	}
	if (c != 4)
		return (0);
	return (1);
}

int		is_format_tet(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#')
				c++;
			if (i > 0 && s[i - 1] == '#')
				c++;
			if (i > 4 && s[i - 5] == '#')
				c++;
			if (i < 14 && s[i + 5] == '#')
				c++;
		}
		i++;
	}
	if (c == 6 || c == 8)
		return (1);
	return (0);
}

int		is_valid_input(char *s, int input_tets)
{
	int		i;
	int		is_valid;
	char	*tmp;

	i = 0;
	is_valid = 1;
	tmp = (char*)malloc(sizeof(char) * 20);
	while (i < input_tets)
	{
		tmp = ft_strncpy(tmp, &s[i * 21], 20);
		tmp[19] = '\0';
		if (!(basic_check(tmp) && is_format_tet(tmp)))
			is_valid = 0;
		i++;
	}
	free(tmp);
	return (is_valid);
}

char	**save_input(char *s, int i)
{
	char	**map;
	int		c;
	int		j;
	int		k;

	map = (char**)malloc(sizeof(char*) * (i / 21 + 2));
	c = 0;
	while (c < (i / 21 + 1))
	{
		map[c] = ft_strnew(16);
		j = 0;
		k = 0;
		while (j < 16)
		{
			if (s[c * 21 + k] == '\n')
				k++;
			map[c][j] = s[c * 21 + k];
			j++;
			k++;
		}
		c++;
	}
	map[c] = NULL;
	return (map);
}
