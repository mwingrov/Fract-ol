/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:59:21 by mwingrov          #+#    #+#             */
/*   Updated: 2017/10/20 04:00:11 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int 	colorConverterT(t_env *z)
{
	int   hexValue;

	hexValue = z->r << 16;
	hexValue += z->g << 8;
	hexValue += z->b;
	return (hexValue); 
}

int		findTricorn(double cr, double ci, int max_iterations)
{
	int		i;
	double	zr;
	double	zi;
	double zrzr;
	double zizi;
	double 	temp;

	zr = cr;
	zi = ci;
	i = 0;
	while (i < max_iterations)
	{
		zrzr = zr * zr;
		zizi = zi * zi;
		temp = 2.0 * zr * zi;
		zr = zizi - zrzr - cr;
		zi = temp - ci;
		if (zrzr * zrzr + zizi * zizi > 4.0)
			break;
		i++;
	}
	return (i);
}

double		mapToRealT(int x, int imageWidth, double minR, double maxR)
{
	double range;

	range = maxR - minR;
	return (x * (range / imageWidth) + minR);
}

double		mapToimaginaryT(int y, int imageHeight, double minI, double maxI)
{
	double range;

	range = maxI - minI;
	return (y * (range / imageHeight) + minI);
}

void    mlx_put_pixel_imageT(int x, int y, t_env *z, int color)
{
	int pos;

	pos = (y * IM_X) + x;
	z->data[pos] = color;
}

int		my_key_functT(int	keycode, int x, int y, t_env *z)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 1 || (keycode == 5 && x <= WIN_X))
	{
		z->zoom += 0.2;
	}
	if (keycode == 2 || (keycode == 4 && y <= WIN_Y))
	{
		z->zoom -= 0.2;
	}
	drawTricorn(z);
	return(0);
}

void 	    drawTricorn(t_env *z)
{
	int     imageWidth;
	int     imageHeight;
	double  minR;
	double  maxR;
	double  minI;
	double  maxI;
	double  cr;
	double  ci;
	int     col;
	int     x;
	int     y;
	int     n;

	imageHeight = 600;
	imageWidth  = 600;
	maxR = 1.2;
	minR = -1.5;
	maxI = 1.5;
	minI = -1.5;
	x = 0;
	y = 0;
	while(y < imageHeight)
	{
		x = 0;
		while (x < imageWidth)
		{
			cr = mapToRealT(x, imageWidth, minR, maxR + z->zoom);
			ci = mapToimaginaryT(y, imageHeight, minI, maxI + z->zoom);
			n = findTricorn(cr, ci, 255);
			if (n > 0 && n < 25)
			{
				z->r = (n * 4) % 150;
				z->g = (n * 2) % 50;
				z->b = (n * 4) % 1;
			}
			else if (n >= 25 && n <= 100)
			{
				z->r = (n * 4) % 255;
				z->g = (n * 4) % 255;
				z->b = (n * 4) % 1;
			}
			else if (n >= 100 && n <= 150)
			{
				z->r = (n * 4) % 255;
				z->g = (n * 4) % 255;
				z->b = (n * 4) % 1;
			}
			else if (n >= 150 && n <= 255)
			{
				z->r = n % 255;
				z->g = n % 255;
				z->b = n % 1;
			}
			else
			{
				z->r = (n * 90) % 255;
				z->g = (n * 90) % 255;
				z->b = (n * 90) % 255;  
			}
			col = colorConverter(z);
			mlx_pixel_put(z->mlx, z->win, x, y, col);
//			mlx_put_pixel_image(x, y, z, n);
			x++;
		}
		y++;
	}
//	z->ima = mlx_new_image(z->mlx, WIN_X, WIN_Y);
//	mlx_destroy_image(z->mlx, z->ima);
//	mlx_clear_window(z->mlx, z->win);
//	z->data = (int *)mlx_get_data_addr(&z->ima, &z->bpp, &z->sizel, &z->endian);
	mlx_key_hook(z->win, my_key_funct, &z);
	mlx_mouse_hook(z->win, my_key_functT, &(*z));
//	mlx_put_image_to_window(z->mlx, z->win, z->ima, 0, 0);
//	mlx_key_hook(color->win, my_key_funct, 0);
	mlx_loop(z->mlx);
}