/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:36:17 by medayi            #+#    #+#             */
/*   Updated: 2025/03/14 14:36:17 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	*mlx_data;

	if (!(ac == 2 || ac == 4))
	{
		ft_printf("%s [fractol name] [julia parameter(optional)]", av[0]);
		return (-1);
	}
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
	{
		ft_printf("mlx init fail\n");
		return (-1);
	}
	mlx_data->win = mlx_new_window(mlx_data->mlx, 800, 600, "Fract-ol");
}
