/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 06:51:11 by medayi            #+#    #+#             */
/*   Updated: 2025/04/16 08:59:01 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while ((zr * zr + zi * zi) < 4.0 && i < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	ft_julia(double zr, double zi, t_fractol *f, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while ((zr * zr + zi * zi) < 4.0 && i < max_iter)
	{
		tmp = zr * zr - zi * zi + f->real;
		zi = 2 * zr * zi + f->imaginary;
		zr = tmp;
		i++;
	}
	return (i);
}

void	draw_fractal(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		iterations;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pr = (x - WIDTH / 2.0) / (0.5 * WIDTH * f->zoom) + f->x_offset;
			pi = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * f->zoom) + f->y_offset;
			if (f->type == 0)
				iterations = ft_mandelbrot(pr, pi, f->max_iterations);
			else if (f->type == 1)
				iterations = ft_julia(pr, pi, f, f->max_iterations);
			ft_pixel_put(&f->data, x, y, ft_color(iterations));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->data.mlx, f->data.win, f->data.img, 0, 0);
}

void	init_fractal(t_fractol *f, int argc, char **argv)
{
	f->zoom = 0.65;
	f->x_offset = 0.0;
	f->y_offset = 0.0;
	f->max_iterations = MAX_ITERATIONS;
	if (f->type == 1 && argc == 4)
	{
		f->real = ft_atof(argv[2]);
		f->imaginary = ft_atof(argv[3]);
	}
	else if (f->type == 1)
	{
		f->real = -0.7;
		f->imaginary = 0.27015;
	}
}
