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
	if (!(ac == 2 || ac == 4))
	{
		ft_printf("%s [fractol name] [julia parameter(optional)]", av[0]);
		return (-1);
	}
}
