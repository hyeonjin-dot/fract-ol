/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:23:34 by hyejung           #+#    #+#             */
/*   Updated: 2021/10/07 15:00:36 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	draw_pic(int wid, int hei, t_mlx mlx)
{
	if (mlx.name == 'm')
		return (mandel(wid, hei, mlx));
	else if (mlx.name == 'j')
		return (julia(wid, hei, mlx));
	else
		return (hyejung(wid, hei, mlx));
}

void	draw(t_mlx *mlx)
{
	int	wid;
	int	hei;
	int	count;

	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, \
			&mlx->img.size_l, &mlx->img.endian);
	wid = -1;
	while (++wid < WIN_W)
	{
		hei = -1;
		while (++hei < WIN_H)
		{
			count = draw_pic(wid, hei, *mlx);
			if (count < MAX_I)
				mlx->img.data[hei * WIN_W + wid] = makecolor(count);
			else
				mlx->img.data[hei * WIN_W + wid] = 0;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
}
