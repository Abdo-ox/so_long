/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:46:21 by ajari             #+#    #+#             */
/*   Updated: 2023/01/23 19:28:01 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_im
{
	void	*i;
	void	*m;
	void	*p_l;
	void	*p_r;
	void	*p_d;
	void	*p_u;
	void	*d_o;
	void	*d_s;
	void	*nbr;
	void	*dlr;
	void	*b_g;
	void	*g_o;
	void	*g_w;
	void	*door;
	void	*wall;
	void	*black;
}			t_im;

typedef struct s_mx
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		in;
	int		d_x;
	int		d_y;
	int		w_w;
	int		h_w;
	void	*mx;
	void	*im;
	int		exit;
	void	*x_w;
	void	*inn;
	int		stop;
	int		timer;
	char	**map;
	char	**imc;
	char	**imi;
	int		n_of_c;
	int		n_moves;
	int		n_c_token;
	t_im	image;
	t_list	*i_data;
}			t_mx;

void		error(char *s, char *m);
void		image(t_mx *m);
void		move_up(t_mx *m);
int			animation(t_mx *m);
void		move_down(t_mx *m);
void		move_left(t_mx *m);
void		ft_freee(char **s);
void		check_c_i(char **s);
void		move_right(t_mx *m);
void		set_enemys(t_mx *m);
int			count_lines(int fd);
void		set_enemys(t_mx *m);
int			check_map(char **map);
void		check_wall(char **map);
void		check_path(char **map);
void		print_n_moves(t_mx *m);
void		check_elements(char **s);
int			count_number_of_c(t_mx m);
int			chek_more_i(int x, int y, char **s);
int			check_extention(char *name);
void		*xpm_file_to_img(void *m, char *s, int i, int j);
void		*choose_image(t_mx *m, char c);
char		**ft_strdup_double(char **map);
void		fill_im(t_mx *m, int x, int y);
int			is_allow(t_mx *m, int x, int y);
void		set_position_of_p_and_d(t_mx *m);
t_list		*ft_lstnew1(int x, int y, int d);
void		game_over_or_win(int k, t_mx *m);
int			check_m_i(int x, int y, char **s);
void		move_i(t_mx *m, void *i, void *b);
void		put_map_to_window(char **s, t_mx *m);
void		animate(t_mx *m, void *coin, void *eny);
void		put_image_to_w(t_mx m, void *im, int x, int y);
void		check_one_by_one(int x, int y, int *a, char **map);
void		put_aminate_image(t_mx *m, void *i, void *b, t_list *list);

#endif
