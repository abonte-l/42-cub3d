#ifndef _CUB3D_H
# define _CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"


/*
** Define below are used in GNL
*/

# define ERROR -1
# define END_OF_FILE 0
# define ONE_LINE_READ 1
# define BUFFER_SIZE 32

/*
** Define below are used in CUB3D
*/
# define ARG_ERROR		"<< ARG ERROR || invalid arguments please check and try again >>"
# define FILE_ERROR		"<< FILE ERROR || please check you are using a valid *.cub map file and try again >>"
# define DATA_ERROR		"<< DATA ERROR || datas in your *.cub map file are incorrect please check and try again >>"
# define NO_MAP_ERROR	"<< NO MAP ERROR || there is no map in your *.cub map file please check and try again >>"
# define MEMORY_ERROR	"<< MEMORY ERROR || malloc() error >>"
# define MAP_ERROR		"<< MAP ERROR || you are using an invalid map please check and try again >>"
# define TEXTURE_ERROR	"<< TEXTURE ERROR || function to get textures encountered a problem >>"
# define MLX_ERROR		"<< MLX ERROR || mlx encountered a problem >>"
# define BMP_ERROR		"<< BMP ERROR || impossible to create the .bmp >>"
# define SAVE_OK		"<< --SAVE || image.bmp has been successfully created >>"
# define EXIT_GAME		"<< EXIT GAME || game was close with success >>"

/*
** GENERAL (in order) **escape key **left arrow **right arrow **w **s **a **d 
*/
# define ESCAPE			0xff1b
# define TURN_LEFT		0xff51
# define TURN_RIGHT		0xff53
# define MOVE_FORWARD	0x0077
# define MOVE_BACKWARD	0x0073
# define MOVE_LEFT		0x0061
# define MOVE_RIGHT		0x0064


typedef struct		s_sprxy
{
	double			x;
	double			y;
}					t_sprxy;

typedef struct		s_sprite
{
	int				nbspr;
	int				*order;
	double			*dist;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstartx;
	int				drawstarty;
	int				drawendy;
	int				drawendx;
	int				spritewidth;
	double			*zbuffer;
}					t_sprite;

typedef struct		s_texture
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_texture;

typedef struct		s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			raydirx;
	double			raydiry;
	double			camerax;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				x;
	int				texture;
}					t_ray;


typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				minimapechelle;
	int				width;
	int				height;
	void			*img2;
	int				*addr2;
}					t_data;

typedef struct	s_check_data
{
	int		resolution;
	int		color_floor;
	int		color_ceiling;;
	int		text_north;
	int		text_south;
	int		text_east;
	int		text_west;
	int		text_sprite;
}				t_check_data;

typedef struct	s_info
{

	char			**map;
	char			start;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*sp;
	int				r_x;
	int				r_y;
	int				r_verif;
	int				i;
	int				color_f;
	int				color_c;
	int				color_tmp;
	int				color_result;
	int				count_color;
	int				nb_line;
	int				len_line;
	int				start_x;
	int				start_y;
	int				count_tex;
	int				save_enbld;
	int				error;
	int				count_lines;
	int				inside_map;
	int				empty_line;
	int				wrg_char_map;
	int				count_player;
	int				check_line_map;
	int				check_col_map;
	int				screenx;
	int				screeny;
	int				cross_cl;
	int				escp_cl;
	int				map_ex;
	t_check_data	check_data;
	t_data			texture[5];
	t_data			data;
	t_ray			ray;
	t_texture		t;
	t_sprite		s;
	t_sprxy			*sxy;
	

}				t_info;

/*
** GNL
*/
int		get_next_line(int fd, char **line);
int		ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);

/*
** ERROR
*/
int		ft_exit(t_info *info);
void 	ft_error(char *str, t_info *info);
void	ft_free_var_1(t_info *info, char *str);
void	ft_free_var_2(t_info *info);

/*
**	main
*/
int		ft_check_save_enabled(char *str);
int		ft_check_dot_cub(char *str, t_info *info);

/*
** parsing general
*/
int		ft_str_s_char(const char *str, char c);
void	ft_check_data(t_info *info);
void	ft_collect_data(char *str, t_info *info);
void	ft_parsing(char *fichier, t_info *info);

/*
** parsing color / resolution
*/
int		ft_atoi_r(char *str, t_info *info);
int		ft_atoi_c(char *str, t_info *info);
int		ft_check_wrg_char_r(char *str);
int		ft_check_wrg_char_c(char *str);
void	ft_res_color_parsing(char **str, t_info *info);

/*
** parsing map
*/
int		ft_parsing_map(char *fichier, t_info *info);
int		ft_fill_in_map(char *str, t_info *info);
int		ft_is_map(char *str, t_info *info);
int		ft_check_empty_line(char *str);
int		ft_start(char c, t_info *info, int i, int j);
void	ft_get_map_data(char *str, t_info *info);
void	ft_check_edges(t_info *info);
void	ft_check_inside(t_info *info);
void	ft_put_zero(t_info *info);

/*
** parsing textures
*/
int		ft_strlen2(char *str);
int		ft_get_texture_path(char *str, char **path, t_info *info, int j);
char	*ft_strcpy_texture(char *dest, const char *src, t_info *info, int j);
void	ft_texture_alloc(char *str, t_info *info);

/*
** mlx and raycasting
*/
int		ft_raycasting(t_info *info);
int		ft_mlx(t_info *info);

/*
** print and textures
*/
int		ft_colcol(t_info *info);
void	ft_add_texture(t_info *info, int x, int y);
void	ft_get_texture(t_info *info);
void	ft_get_texture_address(t_info *info);

/*
** movements
*/
void	ft_forward_backward(t_info *info);
void	ft_left_right(t_info *info);
void	ft_turn_right_left(t_info *info);
void	ft_turn_left(t_info *info, double olddirx);

/*
** save to bmp
*/
void	ft_header(t_info *info, int fd);
void	ft_save_to_bmp(t_info *info);


int		ft_handle_keypress(int keycode, t_info *info);
int		ft_handle_keyrelease(int keycode, t_info *info);

/*
** calc raycasting
*/
void	ft_dispatch_calc(t_info *info);
void	ft_step_side_dist(t_info *info);
void	ft_increment_ray(t_info *info);
void	ft_draw_start_end(t_info *info);
void	ft_swap(t_info *info);

/*
** all init
*/
void	ft_init_info_1(t_info *info);
void	ft_init_info_2(t_info *info);
void	ft_calc_delta_dist(t_info *info);
void	ft_init_dir(t_info *info);
void	ft_init_in_ftmlx(t_info *info);
void	ft_init_in_rcstng(t_info *info);
void	ft_init_texture(t_info *info);
void	ft_init_sprite(t_info *info);
void	ft_init_sprite2(t_info *info, int i, int j, int v);

/*
** sprites
*/
void	ft_sprite(t_info *info);
void	ft_draw_sprites(t_info *info, int y, int texx, int stripe);
void	ft_calc(t_info *info, int i);
void	ft_dist_n_order(t_info *info);
void	ft_dist_n_order2(t_info *info);

#endif