/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:14:04 by rbejot            #+#    #+#             */
/*   Updated: 2016/06/09 18:45:02 by rbejot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include "color.h"

# define ESC 53
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define Z 6
# define X 7
# define W 13
# define S 1
# define A 0
# define D 2
# define E 14
# define Q 12
# define SPACE 49
# define RETURN 36
# define C 8
# define V 9
# define N1 18
# define N2 19
# define N3 20
# define N4 21
# define N5 23

# define ZOOM 4
# define DEZOOM 5
# define L_CLIC 1
# define R_CLIC 2

# define HEIGHT 1000
# define WIDTH 1000

typedef struct		s_liste
{
	int				*tab;
	int				length;
	struct s_liste	*next;
}					t_liste;

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_vert
{
	int				start;
	int				end;
}					t_vert;

typedef struct		s_im
{
	char			*imag;
	int				size_line;
	int				bpp;
	int				endian;
	void			*img_ptr;
	int				width;
	int				height;
}					t_im;

typedef struct		s_info
{
	t_pos			player;
	t_pos			direction;
	t_pos			plane;
	t_pos			raypos;
	t_pos			raydir;
	t_pos			map;
	t_pos			sidedist;
	t_pos			deltadist;
	t_pos			step;
	int				color;
	t_im			image;
	int				orientation;
}					t_info;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	t_info			data;
	int				view;
	double			perpwalldist;
	double			camerax;
	int				side;
	int				size;
	t_liste			*begin_list;
	char			*line;
	int				fd;
	int				x;
	int				y;
	t_liste			*tmp;
	int				wl_map[25][25];
}					t_env;

t_info				lateral_orientation(t_info *d);
t_info				front_orientation(t_info *d);
void				window(t_env *e);
void				new_image(t_env *e);
t_vert				init_draw(int side, t_info *data, t_env *e);
void				ft_draw(t_im im, int x, int y, int color);
t_info				ft_hit(int *side, t_info *d, int worldmap[25][25]);
int					color(t_info *d);
int					calc(t_info data, t_env *e);
int					expose_hook(t_env *e);
t_env				init_player(t_env *e);
void				move(t_env *e, int keycode);
void				rotate(t_env *e, int keycode);
t_env				read_map(char **av, t_env *env);
t_env				stock_map(t_env *env);
void				usage(int condition);
#endif
