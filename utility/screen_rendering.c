/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteofilibertosciacca <matteofiliberto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:14:25 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/22 23:48:52 by matteofilib      ###   ########.fr       */
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

static int rgb_to_int(double r, double g, double b)
{
	int color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	generate_new_frame(t_mlx_data *mlx_data)
{
	int				i;
	int				k;

	i = 0;
	while (i < mlx_data->h)
	{
		k = 0;
		while (k < mlx_data->w)
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
			else if (mlx_data->map[i][k] == 'P')
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
			k++;
		}
		i++;
	}
	mlx_string_put(mlx_data->mlx, mlx_data->window, mlx_data->w - 70, 24, rgb_to_int(250, 250, 250), "MOVES:");
	mlx_string_put(mlx_data->mlx, mlx_data->window, mlx_data->w - 26, 24, rgb_to_int(250, 250, 250), ft_itoa(mlx_data->movements));
	mlx_string_put(mlx_data->mlx, mlx_data->window, mlx_data->w - 70, 36, rgb_to_int(250, 250, 250), "APPLE:");
	mlx_string_put(mlx_data->mlx, mlx_data->window, mlx_data->w - 26, 36, rgb_to_int(250, 250, 250), ft_itoa(mlx_data->collectibles));
	ft_printf("Moves: %d\n", mlx_data->movements);
}

void	load_images(t_mlx_data *mlx_data)
{
	initialize_img_cache(&mlx_data->images);
	mlx_data->images.bck->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/screen.xpm",
			&mlx_data->images.bck->w, &mlx_data->images.bck->h);
	mlx_data->images.wall->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/wall.xpm",
			&mlx_data->images.wall->w, &mlx_data->images.wall->h);
	mlx_data->images.ply->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/CRFront.xpm",
			&mlx_data->images.ply->w, &mlx_data->images.ply->h);
	mlx_data->images.ply_bsk->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/CRFront3.xpm",
			&mlx_data->images.ply_bsk->w, &mlx_data->images.ply_bsk->h);
	mlx_data->images.ply_r->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/CPR.xpm",
			&mlx_data->images.ply_r->w, &mlx_data->images.ply_r->h);
	mlx_data->images.ply_r_bsk->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/CPR3.xpm",
			&mlx_data->images.ply_r_bsk->w, &mlx_data->images.ply_r_bsk->h);
	mlx_data->images.ply_l->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/CPL.xpm",
			&mlx_data->images.ply_l->w, &mlx_data->images.ply_l->h);
	mlx_data->images.ply_l_bsk->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/CPL3.xpm",
			&mlx_data->images.ply_l_bsk->w, &mlx_data->images.ply_l_bsk->h);
	mlx_data->images.ply_u->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/CRBack.xpm",
			&mlx_data->images.ply_u->w, &mlx_data->images.ply_u->h);
	mlx_data->images.ply_u_bsk->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/CRBack3.xpm",
			&mlx_data->images.ply_u_bsk->w, &mlx_data->images.ply_u_bsk->h);
	mlx_data->images.coll->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/mela.xpm",
			&mlx_data->images.coll->w, &mlx_data->images.coll->h);
	mlx_data->images.enemy->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/wolfdw.xpm",
			&mlx_data->images.enemy->w, &mlx_data->images.enemy->h);
	mlx_data->images.enemy_r->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/wolfdx.xpm",
			&mlx_data->images.enemy_r->w, &mlx_data->images.enemy_r->h);
	mlx_data->images.enemy_l->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/wolfsx.xpm",
			&mlx_data->images.enemy_l->w, &mlx_data->images.enemy_l->h);
	mlx_data->images.enemy_u->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/wolfup.xpm",
			&mlx_data->images.enemy_u->w, &mlx_data->images.enemy_u->h);
	mlx_data->images.exit->addr = mlx_xpm_file_to_image(mlx_data->mlx, "./img/exit.xpm",
			&mlx_data->images.exit->w, &mlx_data->images.exit->h);
	mlx_data->enemy_img = *mlx_data->images.enemy;
	mlx_data->ply_img = *mlx_data->images.ply;
}