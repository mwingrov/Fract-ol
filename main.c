/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:01:33 by mwingrov          #+#    #+#             */
/*   Updated: 2017/10/16 16:01:38 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractal.h"

int     main(int ac, char **av)
{
    t_env z;

    z = *(t_env *)malloc(sizeof(t_env));
    z.mlx = mlx_init();
	z.win = mlx_new_window(z.mlx, 600, 600, "Fractal");
   if (ac < 2)
    {
        ft_putendl("Please Choose one of the following Fractals:\n- Mandelbrot\n- Julia\n- Tricorn");
        return (0);
    }
    else if (ac > 1)
    {
            if (!ft_strcmp("julia.c", av[1]))
            {
                drawJulia(&z);
                return(0);
            }
            if (!ft_strcmp("mandelbrot.c", av[1]))
            {
                drawMandelbrot(&z);
                return (0);
            }
            if (!ft_strcmp("tricorn.c", av[1]))
            {
                drawTricorn(&z);
                return (0);
            }
    }
    return (0);
}