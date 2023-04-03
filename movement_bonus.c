/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:56:36 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 17:45:54 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_position_of_p_and_d(t_mx *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j++] != '\n')
		{
			if (m->map[i][j] == 'P')
			{
				m->x = j;
				m->y = i;
			}
			if (m->map[i][j] == 'E')
			{
				m->d_x = j;
				m->d_y = i;
			}
		}
		i++;
	}
}

void	move_left(t_mx *m)
{
	print_n_moves(m);
	if (m->map[m->y][m->x - 1] == 'C')
		m->n_c_token++;
	put_image_to_w(*m, m->image.b_g, m->x * m->w, m->y * m->h);
	m->map[m->y][m->x] = '0';
	m->x--;
	m->map[m->y][m->x] = 'P';
	put_image_to_w(*m, m->image.p_l, m->x * m->w, m->y * m->h);
}

void	move_right(t_mx *m)
{
	print_n_moves(m);
	if (m->map[m->y][m->x + 1] == 'C')
		m->n_c_token++;
	put_image_to_w(*m, m->image.b_g, m->x * m->w, m->y * m->h);
	m->map[m->y][m->x] = '0';
	m->map[m->y][++m->x] = 'P';
	put_image_to_w(*m, m->image.p_r, m->x * m->w, m->y * m->h);
}

void	move_down(t_mx *m)
{
	print_n_moves(m);
	if (m->map[m->y + 1][m->x] == 'C')
		m->n_c_token++;
	put_image_to_w(*m, m->image.b_g, m->x * m->w, m->y * m->h);
	m->map[m->y][m->x] = '0';
	m->map[++m->y][m->x] = 'P';
	put_image_to_w(*m, m->image.p_d, m->x * m->w, m->y * m->h);
}

void	move_up(t_mx *m)
{
	print_n_moves(m);
	if (m->map[m->y - 1][m->x] == 'C')
		m->n_c_token++;
	put_image_to_w(*m, m->image.b_g, m->x * m->w, m->y * m->h);
	m->map[m->y][m->x] = '0';
	m->y--;
	m->map[m->y][m->x] = 'P';
	put_image_to_w(*m, m->image.p_u, m->x * m->w, m->y * m->h);
}
