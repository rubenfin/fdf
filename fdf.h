/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/27 17:30:29 by rfinneru      #+#    #+#                 */
/*   Updated: 2023/12/22 12:07:57 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// libraries
# include </home/rfinneru/Codam/rank 02/MLX42/include/MLX42/MLX42.h>
# include <fcntl.h>
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
# define COLOR_MINTEN 0x00308fFF

typedef struct t_data
{
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			z;
	int			z1;
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
	int			pixel_pos_x;
	int			pixel_pos_y;
	t_data		*data;
}				t_map;

typedef struct t_fdf
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_fdf;

// window -> creating window and adding controls to move the image
int				make_window(t_fdf *fdf);
void			ft_hook(void *param);

// map -> parse map from fd
void			get_map(const char *argv[], t_fdf *fdf);
int				get_map_width(char *map);
int				get_map_height(char *map);

// draw -> draw map parsed from fd
void			draw_map(void *param);
void			bresenham(float x, float y, float x1, float y1, t_fdf *fdf);
void			iso_transform(float *x, float *y, int z);
void			reset_map(t_fdf *fdf);

// move
void			ft_scrollhook(double xdelta, double ydelta, void *param);

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

// printing map -> for testing purposes
void			print_formatted(t_map *map);
void			free_map_formatted(t_fdf *fdf);

// memory and clean exits
int				free_all(t_fdf *fdf);
void			free_z_index(t_fdf *fdf);
void			free_z_index_i(t_fdf *fdf, int i);
void			free_map_formatted(t_fdf *fdf);
char			exit_and_close(t_fdf *fdf);

#endif