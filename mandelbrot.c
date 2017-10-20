/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:59:21 by mwingrov          #+#    #+#             */
/*   Updated: 2017/10/20 04:00:11 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft/libft.h"
#include "fractal.h"

int 	colorConverter(t_color *color)
{
	int   hexValue;

	hexValue = color->r << 16;
	hexValue += color->g << 8;
	hexValue += color->b;
	return (hexValue); 
}

int		OnZoom(double ci)
{
	double	imaginaryR;
	double	newR;

	imaginaryR = maxI - minI;
	if (ci < 0)
		newR = imaginaryR * 0.95;
	else
		newR = imaginaryR * 1.05;
}

int		findMandelbrot(double cr, double ci, int max_iterations)
{
	int		i;
	double	zr;
	double	zi;
	double 	temp;

	i = 0;
	zr = 0.0;
	zi = 0.0;

	while (i < max_iterations && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

double		mapToReal(int x, int imageWidth, double minR, double maxR)
{
	double range;

	range = maxR - minR;
	return (x * (range / imageWidth) + minR);
}

double		mapToimaginary(int y, int imageHeight, double minI, double maxI)
{
	double range;

	range = maxI - minI;
	return (y * (range / imageHeight) + minI);
}

int     my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void 	    draw(t_color *color)
{
	int     imageWidth;
	int     imageHeight;
	double  minR;
	double  maxR;
	double  minI;
	double  maxI;
	int     maxN;
	double  cr;
	double  ci;
	int     col;
	int     x;
	int     y;
	int     n;

	imageHeight = 500;
	imageWidth  = 500;
	maxR = 0.7;
	minR = -1.5;
	maxI = 1.0;
	minI = -1.0;
	x = 0;
	y = 0;
	color->mlx = mlx_init();
	color->win = mlx_new_window(color->mlx, 500, 500, "Fractol");
	int cnt  = 50;
	while(y < imageHeight)
	{
		x = 0;
		while (x < imageWidth)
		{
			cr = mapToReal(x, imageWidth, minR, maxR);
			ci = mapToimaginary(y, imageHeight, minI, maxI);
			n = findMandelbrot(cr, ci, 255);
			if (n > 0 && n < 20)
			{
				color->r = (n * 3) % 1;
				color->g = (n * 3) % 1;
				color->b = (n * 11) % 255;
			}
			else if (n >= 20 && n <= 100)
			{
				color->r = (n * 7) % 255;
				color->g = (n * 7) % 255;
				color->b = (n * 7) % 255;
			}
			else if (n >= 100 && n <= 150)
			{
				color->r = (n * 7) % 255;
				color->g = (n * 7) % 255;
				color->b = (n * 7) % 255;
			}
			else if (n >= 150 && n <= 254)
			{
				color->r = (n * 7) % 255;
				color->g = (n * 7) % 255;
				color->b = (n * 7) % 255;
			}
			else
			{
				color->r = (n * 90) % 255;
				color->g = (n * 90) % 255;
				color->b = (n * 90) % 255;  
			}

			col = colorConverter(color);
			mlx_pixel_put(color->mlx, color->win, x, y, col);
			x++;
		}
		y++;
	}
	mlx_key_hook(color->win, my_key_funct, 0);
	mlx_loop(color->mlx);
}