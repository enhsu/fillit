/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:24:32 by llu               #+#    #+#             */
/*   Updated: 2018/12/05 21:24:35 by llu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int		basic_check(char *s);
int		is_format_tet(char *s);
int		is_valid_input(char *s, int input_tets);
char	**save_input(char *s, int i);
void	empty_solve(char **arr);
void	transfer_input(char **arr);
char	**create_empty_arr(int i);
void	reset_try(char **solve, int c);
int		can_put(char **solve, int solve_p, char *tet);
void	act_put(char **solve, int solve_p, char *tet);
int		put_tet(char **solve, int solve_p, char *tet);
int		try_solve(char **input, char **solve, int cur, int input_num);
char	**solve(char **arr, int arr_rs);
void	display_square(char **arr);

#endif
