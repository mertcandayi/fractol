/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 06:50:06 by medayi            #+#    #+#             */
/*   Updated: 2025/04/16 08:59:02 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_usage(void)
{
	write(1, "Usage: ./fractol [fractal_type] [parameters]\n", 45);
	write(1, "Available fractal types:\n", 26);
	write(1, "  mandelbrot\n", 13);
	write(1, "  julia [real] [imaginary]\n", 27);
	write(1, "Example: ./fractol julia -0.7 0.27015\n", 38);
	exit(1);
}

static void	fractal_parse(t_fractol *f, int argc, char **argv)
{
	if (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 11) == 0))
		f->type = 0;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (!julia_checker(argv[2]) || !julia_checker(argv[3]))
			ft_usage();
		f->type = 1;
	}
	else
		ft_usage();
}

void	init_mlx(t_fractol *f)
{
	f->data.mlx = mlx_init();
	if (!f->data.mlx)
		exit(1);
	f->data.win = mlx_new_window(f->data.mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->data.win)
	{
		free(f->data.mlx);
		exit(1);
	}
	f->data.img = mlx_new_image(f->data.mlx, WIDTH, HEIGHT);
	if (!f->data.img)
	{
		mlx_destroy_window(f->data.mlx, f->data.win);
		free(f->data.mlx);
		exit(1);
	}
	f->data.addr = mlx_get_data_addr(f->data.img, &f->data.bits_per_pixel,
			&f->data.size_line, &f->data.endian);
}

void	setup_hooks(t_fractol *f)
{
	mlx_hook(f->data.win, 17, 0, (void *)free_resources, f);
	mlx_key_hook(f->data.win, key_press, f);
	mlx_mouse_hook(f->data.win, mouse_handle, f);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (!(ac == 2 || ac == 4))
	{
		ft_usage();
		return (-1);
	}
	fractal_parse(&f, ac, av);
	init_mlx(&f);
	init_fractal(&f, ac, av);
	draw_fractal(&f);
	setup_hooks(&f);
	mlx_loop(f.data.mlx);
	return (0);
}
