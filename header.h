/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:28:10 by hyejung           #+#    #+#             */
/*   Updated: 2021/10/14 11:42:00 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

typedef struct s_comp{
	double		rNum;
	double		iNum;
}				t_comp;

typedef struct s_fractol
{
	double		zoom;
}				t_fractol;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
	char		name;
	t_fractol	fractol;
	int			mx;
	int			my;
}				t_mlx;

# define WIN_W   800
# define WIN_H   600
# define MAX_I   100

void	draw(t_mlx *mlx);
int		makecolor(int i);
int		ft_mouse_get_pos(int x, int y, t_mlx *mlx);
int		mouse_sc(int button, int x, int y, t_mlx *mlx);
int		key_hook(int key, t_mlx *mlx);
int		mandel(int rn, int in, t_mlx mlx);
int		julia(int rn, int in, t_mlx mlx);
int		hyejung(int	rn, int in, t_mlx mlx);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlen(const char *str);

#endif
