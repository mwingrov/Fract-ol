/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 04:00:24 by mwingrov          #+#    #+#             */
/*   Updated: 2017/10/20 04:06:16 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

#include "Libft/libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
	void	*mlx;
	void	*win;
}				t_color;

int			colorConverter(t_color *color);
int			findMandelbrot(double cr, double ci, int max_iterations);
double		mapToReal(int x, int imageWidth, double minR, double maxR);
double		mapToimaginary(int y, int imageHeight, double minI, double maxI);
int			my_key_funct(int keycode, void *param);
void 	    draw(t_color *color);

#endif
