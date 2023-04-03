/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:56:36 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 15:42:08 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_position_of_p(t_mx *m)
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
		}
		i++;
	}
}

void	move_left(t_mx *m)
{
	print_n_moves(m);
	if (m->map[m->y][m->x - 1] == 'C')
		m->n_of_c--;
	put_image_to_w(*m, m->image.b_g, m->x * m->w, m->y * m->h);
	m->map[m->y][m->x] = '0';
	m->x--;
	m->map[m->y][m->x] = 'P';
	put_image_to_w(*m, m->image.p_d, m->x * m->w, m->y * m->h);
}

void	move_right(t_mx *m)
{
	print_n_moves(m);
	if (m->map[m->y][m->x + 1] == 'C')
		m->n_of_c--;
	put_image_to_w(*m, m->image.b_g, m->x * m->w, m->y * m->h);
	m->map[m->y][m->x] = '0';
	m->map[m->y][++m->x] = 'P';
	put_image_to_w(*m, m->image.p_d, m->x * m->w, m->y * m->h);
}

void	move_down(t_mx *m)
{
	print_n_moves(m);
	if (m->map[m->y + 1][m->x] == 'C')
		m->n_of_c--;
	put_image_to_w(*m, m->image.b_g, m->x * m->w, m->y * m->h);
	m->map[m->y][m->x] = '0';
	m->map[++m->y][m->x] = 'P';
	put_image_to_w(*m, m->image.p_d, m->x * m->w, m->y * m->h);
}

void	move_up(t_mx *m)
{
	print_n_moves(m);
	if (m->map[m->y - 1][m->x] == 'C')
		m->n_of_c--;
	put_image_to_w(*m, m->image.b_g, m->x * m->w, m->y * m->h);
	m->map[m->y][m->x] = '0';
	m->y--;
	m->map[m->y][m->x] = 'P';
	put_image_to_w(*m, m->image.p_d, m->x * m->w, m->y * m->h);
}
