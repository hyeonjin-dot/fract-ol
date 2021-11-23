/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:16:12 by hyejung           #+#    #+#             */
/*   Updated: 2021/10/07 15:02:12 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_mouse_get_pos(int x, int y, t_mlx *mlx)
{
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	mlx->mx = x;
	mlx->my = y;
	if (mlx->mx > WIN_W)
		mlx->mx = WIN_W;
	if (mlx->my > WIN_H)
		mlx->my = WIN_H;
	draw(mlx);
	return (0);
}

int	mouse_sc(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4 || button == 5)
	{
		if (button == 4)
			mlx->fractol.zoom = mlx->fractol.zoom * 0.8;
		else
			mlx->fractol.zoom = mlx->fractol.zoom * 1.2;
	}
	else
		return (0);
	mlx->mx = x;
	mlx->my = y;
	draw(mlx);
	return (0);
}

int	key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
		exit (0);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (-1);
	while (i < n - 1 && str1[k] && str2[k])
	{
		if ((unsigned char)str1[k] == (unsigned char)str2[k])
		{
			i++;
			k++;
		}
		else
			break ;
	}
	return ((unsigned char)str1[k] - (unsigned char)str2[k]);
}
