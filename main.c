/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:26:01 by hyejung           #+#    #+#             */
/*   Updated: 2021/10/07 15:02:21 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	mandel(int rn, int in, t_mlx mlx)
{
	t_comp	z;
	t_comp	c;
	int		i;
	double	new;

	c.rNum = mlx.fractol.zoom * (((rn - WIN_W / 2) * 3.0 / WIN_W) - 0.5);
	c.iNum = mlx.fractol.zoom * (((WIN_H / 2) - in) * 2.0 / WIN_H);
	z.rNum = 0;
	z.iNum = 0;
	i = 0;
	while ((((z.rNum * z.rNum) + (z.iNum * z.iNum)) < 4) && (i < MAX_I))
	{
		new = (z.rNum * z.rNum) - (z.iNum * z.iNum) + c.rNum;
		z.iNum = (2 * z.rNum * z.iNum) + c.iNum;
		z.rNum = new;
		i++;
	}
	return (i);
}

int	julia(int rn, int in, t_mlx mlx)
{
	t_comp	z;
	t_comp	c;
	double	new;
	int		i;

	z.rNum = mlx.fractol.zoom * (rn - WIN_W / 2) * 4.0 / WIN_W;
	z.iNum = mlx.fractol.zoom * ((WIN_H / 2) - in) * 4.0 / WIN_H;
	c.rNum = mlx.fractol.zoom * ((mlx.mx) - WIN_W / 2) * 4.0 / WIN_W;
	c.iNum = mlx.fractol.zoom * ((WIN_H / 2) - (mlx.my)) * 4.0 / WIN_H;
	i = 0;
	while ((((z.rNum * z.rNum) + (z.iNum * z.iNum)) < 4) && (i < MAX_I))
	{
		new = (z.rNum * z.rNum) - (z.iNum * z.iNum) + c.rNum;
		z.iNum = (2 * z.rNum * z.iNum) + c.iNum;
		z.rNum = new;
		i++;
	}
	return (i);
}

int	hyejung(int rn, int in, t_mlx mlx)
{
	t_comp	z;
	t_comp	c;
	double	new;
	int		i;

	z.rNum = mlx.fractol.zoom * (rn - WIN_W / 2) * 4.0 / WIN_W;
	z.iNum = mlx.fractol.zoom * ((WIN_H / 2) - in) * 4.0 / WIN_H;
	c.rNum = mlx.fractol.zoom * ((mlx.mx) - WIN_W / 2) * 4.0 / WIN_W;
	c.iNum = mlx.fractol.zoom * ((WIN_H / 2) - (mlx.my)) * 4.0 / WIN_H;
	i = 0;
	while ((((z.rNum * z.iNum) + (z.iNum * z.iNum)) < 4) && (i < MAX_I))
	{
		new = (z.rNum * z.rNum) - (z.iNum * z.iNum) + c.rNum;
		z.iNum = (2 * z.rNum * z.iNum) + c.iNum;
		z.rNum = new;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "mandel", 5) == 0)
		mlx.name = 'm';
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		mlx.name = 'j';
	else if (ft_strncmp(argv[1], "hyejung", 7) == 0)
		mlx.name = 'h';
	else
		return (0);
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "fract-ol");
	mlx_hook(mlx.win, 06, 0, &ft_mouse_get_pos, &mlx);
	mlx_hook(mlx.win, 04, 0, &mouse_sc, &mlx);
	mlx.fractol.zoom = 1;
	draw(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
