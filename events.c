/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboiraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:06:38 by iboiraza          #+#    #+#             */
/*   Updated: 2024/11/15 19:27:53 by iboiraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection,
		fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection,
		fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	if (keysym == XK_Left || keysym == XK_a)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Right || keysym == XK_d)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Up || keysym == XK_w)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == XK_Down || keysym == XK_s)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_plus)
		fractol->iterations_definition += 5;
	else if (keysym == XK_minus)
		fractol->iterations_definition -= 5;
	fractol_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == Button5)
	{
		fractol->zoom *= 1.05;
	}
	fractol_render(fractol);
	return (0);
}
