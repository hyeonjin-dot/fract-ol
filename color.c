/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejung <hyejung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:56:07 by hyejung           #+#    #+#             */
/*   Updated: 2021/10/07 14:09:13 by hyejung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	makecolor(int i)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin((double)i * 0.3);
	g = sin((double)i * 0.3 + 0.5);
	b = sin((double)i * 0.3 * 9);
	color = ((int)(r * 255.99) << 16);
	color = color + ((int)(g * 255.99) << 8) + (int)(b * 259.99);
	return (color);
}
