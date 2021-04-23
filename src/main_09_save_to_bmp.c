
// #include "../inc/cub3d.h"
#include "cub3d.h"
void	ft_header(t_info *info, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * info->r_x * info->r_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &info->r_x, 4);
	write(fd, &info->r_y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &info->data.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	ft_save_to_bmp(t_info *info)
{
	int	fd;
	int	x;
	int	y;

	y = info->r_y;
	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		ft_error(BMP_ERROR, info);
	ft_header(info, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < info->r_x)
		{
			write(fd, &info->data.addr[y * info->data.line_length / 4 + x],
				4);
			x++;
		}
		y--;
	}
	system("chmod 777 image.bmp");
	ft_free_var_1(info, SAVE_OK);
}

