/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 17:30:29 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/01/11 11:47:00 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// libraries
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// height & width of window and image
# define WIDTH 1920
# define HEIGHT 1920

// colors
# define BACKGROUND_COLOR 0x22222200
// plus
# define COLOR_ONE 0xFFFFEEFF
# define COLOR_TWO 0xFFE8E8FF
# define COLOR_THREE 0xFFCFCFFF
# define COLOR_FOUR 0xFFADADFF
# define COLOR_FIVE 0xFF7B7BFF
# define COLOR_SIX 0xFF4949FF
# define COLOR_SEVEN 0xFF2727FF
# define COLOR_EIGHT 0xFF0E0EFF
# define COLOR_NINE 0xFF2B2BFF
# define COLOR_TEN 0xFE0000FF

// minus
# define COLOR_MINONE 0xcad0dbFF
# define COLOR_MINTWO 0xb4c0d9FF
# define COLOR_MINTHREE 0xa3b4d6FF
# define COLOR_MINFOUR 0x758ebfFF
# define COLOR_MINFIVE 0x536994FF
# define COLOR_MINSIX 0x4a67a1FF
# define COLOR_MINSEVEN 0x3559a1FF
# define COLOR_MINEIGHT 0x224b9cFF
# define COLOR_MINNINE 0x124099FF
# define COLOR_MINTEN 0x000098FF

typedef struct t_data
{
	float		angle_cos;
	float		angle_y;
	int			angle_z;
	int			iso;
	float		move_z;
	int			pixel_pos_x;
	int			pixel_pos_y;
}				t_data;

typedef struct t_map
{
	int			height;
	int			width;
	char		*map;
	char		**map_formatted;
	int			del_count;
	int			**z_index;
	double		map_zoom;
	char		**color;
	t_data		*data;
}				t_map;

typedef struct s_point
{
	float		x;
	float		y;
	float		x1;
	float		y1;
}				t_point;

typedef struct t_fdf
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_fdf;

/**
 * creates a window, creates an image and puts the image inside this window.
 */
int				make_window(t_fdf *fdf);
/**
 * hook which refreshes every frame and checks if any key is pressed,
 *	if so changes the variable according to this keypress
 */
void			ft_hook(void *param);

// map -> parse map from fd
void			get_map(const char *argv[], t_fdf *fdf);
int				get_map_width(char *map, t_fdf *fdf);
int				get_map_height(char *map);
char			*read_map(const char *map, t_fdf *fdf);
void			malloc_map(t_fdf *fdf);
void			fill_map(t_map *map);
char			*replace_nl_w_space(char *str);
void			find_highest_and_lowest(t_map *map);
int				get_prev_count(char *map, int *i);
int				check_for_same_width(int i, char *map, int prev_count,
					t_fdf *fdf);

// draw -> draw map parsed from fd
void			draw_map(void *param);
void			bresenham(t_point *point, t_fdf *fdf);
void			iso_transform(float *x, float *y, int z, t_fdf *fdf);
void			reset_map(t_fdf *fdf);
int				color_plus(int z);
int				color_minus(int z);
int				get_color(int z);
void			map_zoom(t_point *point, t_fdf *fdf);
void			calculate_pos(t_point *point, t_fdf *fdf);
void			move_z(int *z, int *z1, t_fdf *fdf);

// move
void			ft_scrollhook(double xdelta, double ydelta, void *param);
void			move_keys(t_fdf *fdf);
void			move_angle(t_fdf *fdf);
void			move_iso(t_fdf *fdf);
void			move_z_index(t_fdf *fdf);

// fdf utils
char			**ft_split(char *s, char c);
void			*ft_memmove(void *dest, const void *src, size_t n);
int				ft_atoi(char *nptr);
int				count_delimiter(char const *s, char c);
void			ft_bzero(void *s, size_t n);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *s);
int				ft_strlen(char *str);
int				ft_isnum(int c);
int				ft_isalpha(int c);
int				num_or_alph(int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			get_z_index(int *z, int *z1, t_point *point, t_fdf *fdf);
void			print_error(char *msg);
char			*make_str(t_fdf *fdf);

// printing map -> for testing purposes
void			print_formatted(t_map *map);
void			free_map_formatted(t_fdf *fdf);

// memory and clean exits
void			free_all(t_fdf *fdf);
void			free_z_index(t_fdf *fdf);
void			free_z_index_i(t_fdf *fdf, int i);
void			free_map_formatted(t_fdf *fdf);
void			free_and_exit(t_fdf *fdf);
void			ft_free(char **buffer);
void			ft_free_multi(char **buffer, char **buffer2);
void			ft_free_and_exit(char **buffer, t_fdf *fdf);
void			print_free_exit(char *msg, t_fdf *fdf);
#endif