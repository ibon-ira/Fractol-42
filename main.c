/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboiraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:37:52 by iboiraza          #+#    #+#             */
/*   Updated: 2024/11/15 19:20:47 by iboiraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot"))
		|| (argc == 4 && !ft_strncmp(argv[1], "Julia")))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(fractol.name, "Julia"))
		{
			fractol.julia_x = atoi_plus(argv[2]);
			fractol.julia_y = atoi_plus(argv[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		write (1, "Please enter: \n\t\"./fractol Mandelbrot\"", 39);
		write (1, "\n\t or\n\t", 7);
		write (1, "\"./fractol Julia <value_1> <value_2>\"\n", 39);
		exit(EXIT_FAILURE);
	}
}
