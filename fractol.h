/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboiraza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:31:07 by iboiraza          #+#    #+#             */
/*   Updated: 2024/11/15 19:33:34 by iboiraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH	2000
# define HEIGHT	1500

# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define PSYCHEDELIC_RED     0xFF0044  // Bright red with a purple tint
# define PSYCHEDELIC_GREEN   0x00FF33  // Bright green
# define PSYCHEDELIC_BLUE    0x0033FF  // Bright blue
# define PSYCHEDELIC_YELLOW  0xFFFF00  // Bright yellow
# define PSYCHEDELIC_CYAN    0x00FFFF  // Neon cyan
# define PSYCHEDELIC_MAGENTA 0xFF00FF  // Bright magenta
# define PSYCHEDELIC_ORANGE  0xFF7F00  // Neon orange
# define PSYCHEDELIC_PURPLE  0x9B00FF  // Deep purple
# define PSYCHEDELIC_PINK    0xFF1493  // Hot pink
# define PSYCHEDELIC_LIME    0x00FF00  // Neon lim
# define PSYCHEDELIC_TURQUOISE 0x40E0D0  // Turquoise
# define PSYCHEDELIC_PASTEL_PURPLE 0xB23E91  // Pastel purple
# define PSYCHEDELIC_TURQUOISE_BLUE 0x30D5C8  // Turquoise blue
# define PSYCHEDELIC_CORAL 0xFF7F50  // Coral*/
# define PSYCHEDELIC_LAVENDER 0xE6E6FA  // Lavender
# define PSYCHEDELIC_MINT 0x98FF98  // Mint green

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractol;

int			ft_strncmp(char *s1, char *s2);
double		atoi_plus(char *s);
int			julia_track(int x, int y, t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			key_handler(int keysym, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
t_complex	sqare_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
void		fractol_init(t_fractol *fractol);
void		data_init(t_fractol *fractol);
void		fractol_render(t_fractol *fractol);
void		handle_pixel(int x, int y, t_fractol *fractol);

#endif
