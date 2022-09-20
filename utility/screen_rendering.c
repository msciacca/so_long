/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msciacca <msciacca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:14:25 by msciacca          #+#    #+#             */
/*   Updated: 2022/09/20 19:44:21 by msciacca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	initialize_img_cache(t_img_cache *images)
{
	images->bck = malloc(sizeof(t_img_struct));
	images->wall = malloc(sizeof(t_img_struct));
	images->ply = malloc(sizeof(t_img_struct));
	images->ply_bsk = malloc(sizeof(t_img_struct));
	images->coll = malloc(sizeof(t_img_struct));
	images->enemy = malloc(sizeof(t_img_struct));
	images->exit = malloc(sizeof(t_img_struct));
}

void	generate_new_frame(t_mlx_data *mlx_data)
{
	int				i;
	int				k;
	t_img_struct	*ply;

	if (mlx_data->collectibles > 0)
		ply = mlx_data->images.ply_bsk->addr;
	else
		ply = mlx_data->images.ply->addr;
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
					ply, k * 64, i * 64);
			}
			k++;
		}
		i++;
	}
}

void	load_images(void *mlx, t_img_cache *images)
{
	initialize_img_cache(images);
	images->bck->addr = mlx_xpm_file_to_image(mlx, "./img/screen.xpm",
			&images->bck->w, &images->bck->h);
	images->wall->addr = mlx_xpm_file_to_image(mlx, "./img/wall.xpm",
			&images->wall->w, &images->wall->h);
	images->ply->addr = mlx_xpm_file_to_image(mlx, "./img/CRFront.xpm",
			&images->ply->w, &images->ply->h);
	images->ply_bsk->addr = mlx_xpm_file_to_image(mlx, "./img/CRFront3.xpm",
			&images->ply_bsk->w, &images->ply_bsk->h);
	images->coll->addr = mlx_xpm_file_to_image(mlx, "./img/mela.xpm",
			&images->coll->w, &images->coll->h);
	images->enemy->addr = mlx_xpm_file_to_image(mlx, "./img/wolfdw.xpm",
			&images->enemy->w, &images->enemy->h);
	images->exit->addr = mlx_xpm_file_to_image(mlx, "./img/exit.xpm",
			&images->exit->w, &images->exit->h);
}