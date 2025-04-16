/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 06:50:47 by medayi            #+#    #+#             */
/*   Updated: 2025/04/16 08:59:01 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
	{
		free_resources(f);
		exit(0);
	}
	draw_fractal(f);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		f->zoom *= 1.2;
	else if (button == SCROLL_DOWN)
		f->zoom /= 1.2;
	draw_fractal(f);
	return (0);
}

void	free_resources(t_fractol *f)
{
	if (f->data.img)
		mlx_destroy_image(f->data.mlx, f->data.img);
	if (f->data.win)
		mlx_destroy_window(f->data.mlx, f->data.win);
	if (f->data.mlx)
	{
		mlx_destroy_display(f->data.mlx);
		free(f->data.mlx);
	}
	exit(EXIT_SUCCESS);
}
