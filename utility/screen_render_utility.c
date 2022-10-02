/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_render_utility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:48:55 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/02 02:56:52 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	rgb_to_int(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	screen_points(t_mlx_data *mlx_data)
{
	mlx_string_put(mlx_data->mlx, mlx_data->window,
		mlx_data->w - 70, 24, rgb_to_int(250, 250, 250), "MOVES:");
	mlx_string_put(mlx_data->mlx, mlx_data->window,
		mlx_data->w - 26, 24, rgb_to_int(250, 250, 250),
		ft_itoa(mlx_data->movements));
	mlx_string_put(mlx_data->mlx, mlx_data->window,
		mlx_data->w - 70, 36, rgb_to_int(250, 250, 250), "APPLE:");
	mlx_string_put(mlx_data->mlx, mlx_data->window,
		mlx_data->w - 26, 36, rgb_to_int(250, 250, 250),
		ft_itoa(mlx_data->collectibles));
	ft_printf("Moves: %d\n", mlx_data->movements);
}

void	load_images2(t_mlx_data *mlx_data)
{
	mlx_data->images.ply_u_bsk->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/CRBack3.xpm",
			&mlx_data->images.ply_u_bsk->w, &mlx_data->images.ply_u_bsk->h);
	mlx_data->images.coll->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/mela.xpm",
			&mlx_data->images.coll->w, &mlx_data->images.coll->h);
	mlx_data->images.enemy->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/wolfdw.xpm",
			&mlx_data->images.enemy->w, &mlx_data->images.enemy->h);
	mlx_data->images.enemy_r->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/wolfdx.xpm",
			&mlx_data->images.enemy_r->w, &mlx_data->images.enemy_r->h);
	mlx_data->images.enemy_l->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/wolfsx.xpm",
			&mlx_data->images.enemy_l->w, &mlx_data->images.enemy_l->h);
	mlx_data->images.enemy_u->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/wolfup.xpm",
			&mlx_data->images.enemy_u->w, &mlx_data->images.enemy_u->h);
	mlx_data->images.exit->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/exit.xpm",
			&mlx_data->images.exit->w, &mlx_data->images.exit->h);
	mlx_data->enemy_img = *mlx_data->images.enemy;
	mlx_data->ply_img = *mlx_data->images.ply;
}

void	load_images3(t_mlx_data *mlx_data)
{
	mlx_data->images.ply_l->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/CPL.xpm",
			&mlx_data->images.ply_l->w, &mlx_data->images.ply_l->h);
	mlx_data->images.ply_l_bsk->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/CPL3.xpm",
			&mlx_data->images.ply_l_bsk->w, &mlx_data->images.ply_l_bsk->h);
	mlx_data->images.ply_u->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/CRBack.xpm",
			&mlx_data->images.ply_u->w, &mlx_data->images.ply_u->h);
}