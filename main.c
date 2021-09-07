/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:26:01 by hyejung           #+#    #+#             */
/*   Updated: 2021/09/07 15:52:06 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*mlx_ptr;
void	*win_ptr;

/*int	press_esc_key(int key, void *p)
{
	if (key == 0xFF1B)
		exit(0);
	return (1);
}*/

int	main()
{
//	void	*mlx;
//	void	*win;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "hj");
//	mlx_key_hook(win_ptr, press_esc_key, mlx_ptr);
	mlx_loop(mlx_ptr);
}//
