/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteofilibertosciacca <matteofiliberto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:14:25 by msciacca          #+#    #+#             */
/*   Updated: 2022/10/16 19:06:52 by matteofilib      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	initialize_img_cache(t_img_cache *images)
{
	images->bck = malloc(sizeof(t_img_struct));
	images->wall = malloc(sizeof(t_img_struct));
	images->ply = malloc(sizeof(t_img_struct));
	images->ply_bsk = malloc(sizeof(t_img_struct));
	images->ply_r = malloc(sizeof(t_img_struct));
	images->ply_r_bsk = malloc(sizeof(t_img_struct));
	images->ply_l = malloc(sizeof(t_img_struct));
	images->ply_l_bsk = malloc(sizeof(t_img_struct));
	images->ply_u = malloc(sizeof(t_img_struct));
	images->ply_u_bsk = malloc(sizeof(t_img_struct));
	images->coll = malloc(sizeof(t_img_struct));
	images->enemy = malloc(sizeof(t_img_struct));
	images->enemy_r = malloc(sizeof(t_img_struct));
	images->enemy_l = malloc(sizeof(t_img_struct));
	images->enemy_u = malloc(sizeof(t_img_struct));
	images->exit = malloc(sizeof(t_img_struct));
}

static void	generate_new_frame_conditions2(t_mlx_data *mlx_data, int i, int k)
{
	if (mlx_data->map[i][k] == 'P')
	{
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->images.bck->addr, k * 64, i * 64);
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->ply_img.addr, k * 64, i * 64);
	}
	else if (mlx_data->map[i][k] == 'N')
	{
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->images.bck->addr, k * 64, i * 64);
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->enemy_img.addr, k * 64, i * 64);
	}
}

static void	generate_new_frame_conditions(t_mlx_data *mlx_data, int i, int k)
{
	if (mlx_data->map[i][k] == '0')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->images.bck->addr, k * 64, i * 64);
	else if (mlx_data->map[i][k] == '1')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->images.wall->addr, k * 64, i * 64);
	else if (mlx_data->map[i][k] == 'C')
	{
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->images.bck->addr, k * 64, i * 64);
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->images.coll->addr, k * 64, i * 64);
	}
	else if (mlx_data->map[i][k] == 'E')
	{
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->images.bck->addr, k * 64, i * 64);
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
			mlx_data->images.exit->addr, k * 64, i * 64);
	}
	else
		generate_new_frame_conditions2(mlx_data, i, k);
}

void	generate_new_frame(t_mlx_data *mlx_data)
{
	int	i;
	int	k;

	i = 0;
	while (i < (mlx_data->h / 64))
	{
		k = 0;
		while (k < (mlx_data->w / 64))
		{
			generate_new_frame_conditions(mlx_data, i, k);
			k++;
		}
		i++;
	}
	//screen_points(mlx_data);
}

void	load_images(t_mlx_data *mlx_data)
{
	initialize_img_cache(&mlx_data->images);
	mlx_data->images.bck->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/screen.xpm",
			&mlx_data->images.bck->w, &mlx_data->images.bck->h);
	mlx_data->images.wall->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/wall.xpm",
			&mlx_data->images.wall->w, &mlx_data->images.wall->h);
	mlx_data->images.ply->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/CRFront.xpm",
			&mlx_data->images.ply->w, &mlx_data->images.ply->h);
	mlx_data->images.ply_bsk->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/CRFront3.xpm",
			&mlx_data->images.ply_bsk->w, &mlx_data->images.ply_bsk->h);
	mlx_data->images.ply_r->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/CPR.xpm",
			&mlx_data->images.ply_r->w, &mlx_data->images.ply_r->h);
	mlx_data->images.ply_r_bsk->addr = mlx_xpm_file_to_image(
			mlx_data->mlx, "./img/CPR3.xpm",
			&mlx_data->images.ply_r_bsk->w, &mlx_data->images.ply_r_bsk->h);
	load_images3(mlx_data);
	load_images2(mlx_data);
}
