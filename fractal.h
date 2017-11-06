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

# define IM_X 600
# define WIN_X 600
# define WIN_Y 600

#include "libft.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_env
{
	int		r;
	int		g;
	int		b;
	void	*mlx;
	void	*win;
	void	*ima;
	float	zoom;
	float	zoomX;
	float	zoomY;
	int		x;
	int		y;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	tmpx;
	float	tmpy;
	float	tmpx2;
	float	tmpy2;
	int		bpp;
	int		sizel;
	int		endian;
	int		*data;
}				t_env;

int			colorConverter(t_env *z);
int 		colorConverterJ(t_env *z);
int			colorConverterT(t_env *z);
int			findMandelbrot(double cr, double ci, int max_iterations);
int			findJulia(double cr, double ci, int max_iterations);
double		mapToReal(int x, int imageWidth, double minR, double maxR);
double		mapToRealJ(int x, int imageWidth, double minR, double maxR);
double		mapToimaginary(int y, int imageHeight, double minI, double maxI);
double		mapToimaginaryJ(int y, int imageHeight, double minI, double maxI);
int			my_key_funct(int keycode, int x, int y, t_env *z);
int     	my_key_functJ(int keycode, int x, int y, t_env *z);
int			my_key_functT(int keycode, int x, int y, t_env *z);
void		mlx_put_pixel_imageT(int x, int y, t_env *z, int color);
void 	    drawJulia(t_env *z);
void 	    drawTricorn(t_env *z);
void 	    drawMandelbrot(t_env *z);
double		mapToRealT(int x, int imageWidth, double minR, double maxR);
int			findTricorn(double cr, double ci, int max_iterations);
double		mapToimaginaryT(int y, int imageHeight, double minI, double maxI);

#endif
