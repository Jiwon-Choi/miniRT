/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:28:07 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/05/18 16:07:47 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINIRT_H
# define _MINIRT_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "structures.h"
# include "get_next_line.h"
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0
# define EPSILON 1e-6
# define LUMEN 1
# define RX_MAX 1920
# define RY_MAX 1080

double	degrees_to_radians(int a);
int		rt_atoi(char **str);
double	rt_atof(char **str);
t_p3	rt_ato3(char **str);
t_p3	rt_albedo(char **str);

void	error_check(t_flag flag, char *err_msg);
void	check_null(char **str);
void	check_values(double num, double min, double max, char *err_msg);

t_bool	hit_cylinder(t_fig *lst, t_ray *r, t_hit_record *rec);

t_bool	hit_plane(t_fig *lst, t_ray *r, t_hit_record *rec);

t_bool	hit_sphere(t_fig *lst, t_ray *r, t_hit_record *rec);

t_bool	hit_square(t_fig *lst, t_ray *r, t_hit_record *rec);

t_bool	hit_triangle(t_fig *lst, t_ray *r, t_hit_record *rec);

t_bool	hit_figures(t_fig *lst, t_ray *r, t_hit_record *rec);
t_bool	hit(t_fig *lst, t_ray *r, t_hit_record *rec);

void	ft_mlx_init(t_data *data);
void	data_init(t_data *data, char *rt_file);
void	scene_init(t_data *data);
void	view_init(t_data *data);

int		key_press (int key, t_data *data);

void	make_bmp(t_data *data);
void	make_image(t_data *data);

void	parse_sphere(t_fig **lst, char *str);
void	parse_plane(t_fig **lst, char *str);
void	parse_square(t_fig **lst, char *str);
void	parse_cylinder(t_fig **lst, char *str);
void	parse_triangle(t_fig **lst, char *str);

void	parse_resolution(t_scene *scene, char *str);
void	parse_ambient(t_scene *scene, char *str);
void	parse_camera(t_mlx *mlx, char *str);
void	parse_light(t_scene *scene, char *str);
void	parse(t_data *data, char *str);

t_bool	in_shadow(t_fig *lst, t_ray light_ray, double light_len);
t_p3	point_light_get(t_data *data, t_light *light, t_ray *r,
							t_hit_record *rec);
t_p3	phong_lighting(t_data *data, t_ray *r, t_hit_record *rec);

t_p3	diffuse(t_light *light, t_hit_record *rec);
t_p3	reflect(t_p3 v, t_p3 n);
t_p3	specular(t_light *light, t_ray *r, t_hit_record *rec);

t_ray	ray(t_p3 orig, t_p3 dir);
t_p3	ray_at(t_ray *r, double t);
t_p3	ray_color(t_data *data, t_ray *r);
t_ray	ray_primary(t_scene *scene, double u, double v);

void	save_image(t_data *data);

void	comma(char **str);
void	set_face_normal(t_ray *r, t_hit_record *rec);

t_p3	vdefine(double x, double y, double z);
t_p3	vadd(t_p3 a, t_p3 b);
t_p3	vsubstract(t_p3 a, t_p3 b);
double	vdot(t_p3 a, t_p3 b);
t_p3	vcross(t_p3 a, t_p3 b);

t_p3	vscalarmul(t_p3 a, double t);
t_p3	vscalardiv(t_p3 a, double t);

t_p3	vmul(t_p3 a, t_p3 b);
double	vlen(t_p3 a);
t_p3	vunit(t_p3 a);
t_p3	vmin(t_p3 a, t_p3 b);
double	vdist(t_p3 a, t_p3 b);

#endif
