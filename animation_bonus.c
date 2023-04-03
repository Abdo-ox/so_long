/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:46:49 by ajari             #+#    #+#             */
/*   Updated: 2023/01/27 08:16:07 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemys(t_mx *m)
{
	t_enemy	*enemy;
	t_list	*head;
	int		x;
	int		y;

	y = 0;
	head = NULL;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x] != '\n')
		{
			if (m->map[y][x] == 'I')
			{
				enemy = malloc(sizeof(t_enemy));
				enemy->x = x;
				enemy->y = y;
				enemy->d = 1;
				ft_lstadd_back(&head, ft_lstnew(enemy));
			}
			x++;
		}
		y++;
	}
	m->i_data = head;
}

void	animate(t_mx *m, void *coin, void *eny)
{
	int	x;
	int	y;
	int	i;
	int	j;

	j = 0;
	m->im = mlx_xpm_file_to_image(m->mx, coin, &i, &i);
	m->inn = mlx_xpm_file_to_image(m->mx, eny, &i, &i);
	while (m->map[j])
	{
		i = 0;
		while (m->map[j][i])
		{
			x = i * m->w;
			y = j * m->h;
			if (m->map[j][i] == 'C')
				put_image_to_w(*m, m->im, x, y);
			if (m->map[j][i] == 'I')
				put_image_to_w(*m, m->inn, x, y);
			i++;
		}
		j++;
	}
}

int	animation(t_mx *m)
{
	static int	t;
	static int	n;
	static int	j;
	int			i;

	if (!m->stop && (t == 500 || t == 1000 || t == 1500 || t == 2000
			|| t == 2500 || t == 3000 || t == 3500))
	{
		(!m->imc[n]) && (n = 0);
		(!m->imi[j]) && (j = 0);
		animate(m, m->imc[n], m->imi[j]);
		n++;
		j++;
	}
	if (!m->stop && t == 4000)
	{
		(!m->imi[j]) && (j = 0);
		m->inn = mlx_xpm_file_to_image(m->mx, m->imi[j], &i, &i);
		move_i(m, m->inn, m->image.b_g);
		t = 0;
		j++;
	}
	t++;
	return (0);
}

void	move_i(t_mx *m, void *i, void *b)
{
	t_list	*t;

	t = m->i_data;
	while (m->i_data)
	{
		put_aminate_image(m, i, b, m->i_data);
		m->i_data = m->i_data->next;
	}
	m->i_data = t;
}
