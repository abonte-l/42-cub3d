
// #include "../inc/cub3d.h"
#include "cub3d.h"


void	ft_get_texture_address(t_info *info)
{
	info->texture[0].addr = (int *)mlx_get_data_addr(info->texture[0].img,
			&info->texture[0].bits_per_pixel,
			&info->texture[0].line_length, &info->texture[0].endian);
	info->texture[1].addr = (int *)mlx_get_data_addr(info->texture[1].img,
			&info->texture[1].bits_per_pixel,
			&info->texture[1].line_length, &info->texture[1].endian);
	info->texture[2].addr = (int *)mlx_get_data_addr(info->texture[2].img,
			&info->texture[2].bits_per_pixel,
			&info->texture[2].line_length, &info->texture[2].endian);
	info->texture[3].addr = (int *)mlx_get_data_addr(info->texture[3].img,
			&info->texture[3].bits_per_pixel,
			&info->texture[3].line_length, &info->texture[3].endian);
	info->texture[4].addr = (int *)mlx_get_data_addr(info->texture[4].img,
			&info->texture[4].bits_per_pixel,
			&info->texture[4].line_length, &info->texture[4].endian);
}

void	ft_get_texture(t_info *info)
{
	if (!(info->texture[0].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
					info->no, &(info->texture[0].width),
					&(info->texture[0].height))))
		ft_error(TEXTURE_ERROR, info);
	if (!(info->texture[1].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
					info->so, &(info->texture[1].width),
					&(info->texture[1].height))))
		ft_error(TEXTURE_ERROR, info);
	if (!(info->texture[2].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
					info->we, &(info->texture[2].width),
					&(info->texture[2].height))))
		ft_error(TEXTURE_ERROR, info);
	if (!(info->texture[3].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
					info->ea, &(info->texture[3].width),
					&(info->texture[3].height))))
		ft_error(TEXTURE_ERROR, info);
	if (!(info->texture[4].img = mlx_xpm_file_to_image(info->data.mlx_ptr,
					info->sp, &(info->texture[4].width),
					&(info->texture[4].height))))
		ft_error(TEXTURE_ERROR, info);
	ft_get_texture_address(info);
}

int		ft_colcol(t_info *info)
{
	int j;
	int i;

	j = -1;
	info->ray.drawend = info->r_y - info->ray.drawstart;
	i = info->ray.drawend;
	while (++j < info->ray.drawstart)
		info->data.addr[j * info->data.line_length / 4 +
			info->ray.x] = info->color_c;
	if (j <= info->ray.drawend)
		ft_add_texture(info, info->ray.x, j);
	j = i;
	while (++j < info->r_y)
		info->data.addr[j * info->data.line_length / 4 +
			info->ray.x] = info->color_f;
	return (0);
}

void	ft_add_texture(t_info *info, int x, int y)
{
	y = info->ray.drawstart - 1;
	ft_init_texture(info);
	info->t.step = 1.0 * info->texture[0].height / info->ray.lineheight;
	info->t.texx = (int)(info->t.wallx * (double)info->texture
			[info->t.texdir].width);
	if (info->ray.side == 0 && info->ray.raydirx > 0)
		info->t.texx = info->texture[info->t.texdir].width -
			info->t.texx - 1;
	if (info->ray.side == 1 && info->ray.raydiry < 0)
		info->t.texx = info->texture[info->t.texdir].width -
			info->t.texx - 1;
	info->t.texpos = (info->ray.drawstart - info->r_y / 2 +
			info->ray.lineheight / 2) * info->t.step;
	while (++y <= info->ray.drawend)
	{
		info->t.texy = (int)info->t.texpos &
			(info->texture[info->t.texdir].height - 1);
		info->t.texpos += info->t.step;
		if (y < info->r_y && x < info->r_x)
			info->data.addr[y * info->data.line_length / 4 + x] =
				info->texture[info->t.texdir].addr[info->t.texy *
					info->texture[info->t.texdir].line_length /
					4 + info->t.texx];
	}
}
