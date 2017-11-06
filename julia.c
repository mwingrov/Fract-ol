/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 03:59:21 by mwingrov          #+#    #+#             */
/*   Updated: 2017/10/20 04:00:11 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractal.h"

int 	colorConverterJ(t_env *z)
{
	int   hexValue;

	hexValue = z->r << 16;
	hexValue += z->g << 8;
	hexValue += z->b;
	return (hexValue); 
}

int		findJulia(double cr, double ci, int max_iterations)
{
	int		i;
	double	zr;
	double	zi;
	double zrzr;
	double zizi;
	double 	temp;

	i = 0;
	zr = cr;
	zi = ci;
	while (i < max_iterations)
	{
		zrzr = zr * zr;
		zizi = zi * zi;
		temp = -2.0 * zr * zi;
		zr = zizi - zrzr + 0.835;
		zi = temp - 0.2321;
		if (zrzr * zrzr + zizi * zizi > 4.0)
			break;
		i++;
	}
	return (i);
}

double		mapToRealJ(int x, int imageWidth, double minR, double maxR)
{
	double range;

	range = maxR - minR;
	return (x * (range / imageWidth) + minR);
}

double		mapToimaginaryJ(int y, int imageHeight, double minI, double maxI)
{
	double range;

	range = maxI - minI;
	return (y * (range / imageHeight) + minI);
}

int     my_key_functJ(int keycode, int x, int y, t_env *z)
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
		drawJulia(z);
	return (0);
}

void 	    drawJulia(t_env *z)
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
	maxR = 1.9;
	minR = -1.9;
	maxI = 1.9;
	minI = -1.9;
	x = 0;
	y = 0;
	while(y < imageHeight)
	{
		x = 0;
		while (x < imageWidth)
		{
			cr = mapToRealJ(x, imageWidth, minR, maxR + z->zoom);
			ci = mapToimaginaryJ(y, imageHeight, minI, maxI + z->zoom);
			n = findJulia(cr, ci, 255);
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
			x++;
		}
		y++;
	}
	mlx_key_hook(z->win, my_key_functJ, &(*z));
	mlx_mouse_hook(z->win, my_key_functJ, &(*z));
	mlx_loop(z->mlx);
}