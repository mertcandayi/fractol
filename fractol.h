/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 06:49:58 by medayi            #+#    #+#             */
/*   Updated: 2025/04/16 08:59:01 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITERATIONS 100

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_data;

typedef struct s_fractol
{
	int		type;
	double	real;
	double	imaginary;
	double	zoom;
	double	x_offset;
	double	y_offset;
	int		max_iterations;
	t_data	data;
}			t_fractol;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atof(const char *str);
int			julia_checker(char *str);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_color(int iterations);
void		setup_hooks(t_fractol *f);
void		free_resources(t_fractol *f);
void		draw_fractal(t_fractol *f);
void		init_fractal(t_fractol *f, int argc, char **argv);
int			key_press(int keycode, t_fractol *f);
int			mouse_handle(int button, int x, int y, t_fractol *f);
void		ft_pixel_put(t_data *data, int x, int y, int color);

#endif