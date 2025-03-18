/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:36:34 by medayi            #+#    #+#             */
/*   Updated: 2025/03/14 14:36:34 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     pixel_size;
    int     size_line;
    int     endian;
}   t_data;

void free_resources(t_data *data);

#endif