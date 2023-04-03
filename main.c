/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:19:42 by ajari             #+#    #+#             */
/*   Updated: 2023/01/27 08:15:53 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**put_map_to_str(char *s)
{
	char	**lines;
	int		fd;
	int		i;
	int		j;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		error("'Error\n\t|--------------->❌\n\t",
			"->the is no file in this name 😎");
	i = count_lines(fd);
	close(fd);
	lines = malloc((i + 1) * sizeof(char *));
	fd = open(s, O_RDONLY);
	j = 0;
	while (j < i)
	{
		lines[j] = get_next_line(fd);
		j++;
	}
	lines[i - 1] = ft_strjoin(lines[i - 1], ft_strdup("\n"));
	return (lines[i] = 0, lines);
}

int	key_hook(int k, t_mx *m)
{
	game_win(k, m);
	if (!m->stop)
	{
		if ((k == 123 || k == 0) && is_allow(m, m->x - 1, m->y))
			move_left(m);
		if ((k == 124 || k == 2) && is_allow(m, m->x + 1, m->y))
			move_right(m);
		if ((k == 125 || k == 1) && is_allow(m, m->x, m->y + 1))
			move_down(m);
		if ((k == 126 || k == 13) && is_allow(m, m->x, m->y - 1))
			move_up(m);
	}
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}

void	make_window(t_mx *m)
{
	int	i;
	int	x;

	i = 0;
	while (m->map[i])
		i++;
	m->mx = mlx_init();
	if (!m->mx)
		error("Error\n\t|--------------->❌\n\t", "->In mlx 😎\n");
	x = ft_strlen(m->map[0]) - 1;
	m->x_w = mlx_new_window(m->mx, x * 60, i * 60, "<< My game >>");
	m->w_w = (x * 30 - 300);
	m->h_w = (i * 30 - 75);
	fill_im(m, 0, 0);
	put_map_to_window(m->map, m);
	mlx_hook(m->x_w, 2, 1L << 0, key_hook, m);
	mlx_hook(m->x_w, 17, 0, ft_exit, 0);
	mlx_loop(m->mx);
}

int	main(int c, char **v)
{
	t_mx	m;

	if (c == 2)
	{
		m.h = 60;
		m.w = 60;
		m.in = 0;
		m.stop = 0;
		m.map = put_map_to_str(v[1]);
		if (check_map(m.map) == 1 && check_extention(v[1]))
		{
			m.exit = 0;
			m.n_moves = 0;
			m.n_of_c = count_number_of_c(m);
			set_position_of_p(&m);
			make_window(&m);
		}
	}
}
