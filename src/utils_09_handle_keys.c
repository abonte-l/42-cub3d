
// #include "../inc/cub3d.h"
#include "cub3d.h"
int		ft_handle_keypress(int keycode, t_info *info)
{
	if (keycode == MOVE_FORWARD)
		info->data.forward = 1;
	else if (keycode == MOVE_BACKWARD)
		info->data.back = 1;
	else if (keycode == MOVE_LEFT)
		info->data.left = 1;
	else if (keycode == MOVE_RIGHT)
		info->data.right = 1;
	else if (keycode == TURN_LEFT)
		info->data.rotate_left = 1;
	else if (keycode == TURN_RIGHT)
		info->data.rotate_right = 1;
	else if (keycode == ESCAPE)
	{
		info->escp_cl = 1;
		ft_free_var_1(info, EXIT_GAME);
	}
	return (1);
}

int		ft_handle_keyrelease(int keycode, t_info *info)
{
	if (keycode == MOVE_FORWARD)
		info->data.forward = 0;
	else if (keycode == MOVE_BACKWARD)
		info->data.back = 0;
	else if (keycode == MOVE_LEFT)
		info->data.left = 0;
	else if (keycode == MOVE_RIGHT)
		info->data.right = 0;
	else if (keycode == TURN_LEFT)
		info->data.rotate_left = 0;
	else if (keycode == TURN_RIGHT)
		info->data.rotate_right = 0;
	return (1);
}

