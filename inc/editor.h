/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:38:40 by aziabkin          #+#    #+#             */
/*   Updated: 2018/09/20 17:38:43 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include <SDL.h>
# include <SDL_image.h>
# include "libft.h"
# include "stdbool.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define SCR_W 640
# define SCR_H 640
# define CHECK_RIGHT 0
# define CHECK_LEFT 1
# define CHECK_DIAG1 2
# define CHECK_DIAG2 3

typedef struct		s_points
{
	int				x;
	int				y;
	struct s_points	*right;
	struct s_points	*down;
	struct s_points	*diag1;
	struct s_points	*diag2;
	struct s_points	*end_right;
	struct s_points	*end_down;
	struct s_points	*end_diag1;
	struct s_points	*end_diag2;
	struct s_points	*next;
}					t_points;

typedef struct		s_all
{
	SDL_Window		*wind;
	SDL_Renderer	*rend;
	t_points		*points;
	t_points		*player;
	int				w;
	int				h;
	int				scale;
	int				half_step;
	double			zoom;
	double			move;

}					t_all;

void				f_close(t_all *all);
void				create_list_points(t_all *all);
void				neighbors(t_all *all);
void				diag_l_r(t_all *all);
void				diag_r_l(t_all *all, t_points *tmp);
void				draw(t_all *all, int x, int y);
int					check(int x_mouse, int y_mouse, t_all *all);
t_points			*new_elem(void);
void				exit_error(int n);
void				init_sdl(t_all *all);
void				general_draw(t_all *all, t_points *start);
void				set_render(t_all *all, t_points *start);
void				work(t_all *all, t_points *start);

#endif
