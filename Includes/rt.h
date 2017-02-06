/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:04:37 by jubarbie          #+#    #+#             */
/*   Updated: 2017/02/06 23:38:55 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "X.h"
# include <OpenCL/opencl.h>
# include <pthread.h>
# include <time.h>
# include "mlx.h"
# include "libft.h"
# include "libv3d.h"

# include "my_math.h"
# include "my_mlx.h"

# define PI 3.141592
# define NB_TH 50
# define DIST_MAX 1000.0
# define F_CLR 0x374355

# define OPT_REF "dh"
# define OPT e->opt

# define OPT_D (1 << 0)
# define OPT_H (1 << 1)

# define LIGHT (1 << 2)
# define SHADOW (1 << 3)
# define SHINE (1 << 4)
# define REFLX (1 << 5)
# define SEPIA (1 << 6)
# define GREY (1 << 7)
# define CRTN (1 << 8)
# define PHONG (1 << 9)
# define BPLANE (1 << 10)
# define GLOBQ (1 << 11)
# define OPT_I1 (1 << 12)
# define OPT_I2 (1 << 13)
# define MOTION_BLUR (1 << 14)
# define STEREO (1 << 15)
# define ANTI (1 << 16)

# define IS_OPT_D (OPT & OPT_D)
# define IS_OPT_H (OPT & OPT_H)

# define IS_LIGHT (OPT & LIGHT)
# define IS_SHADOW (OPT & SHADOW)
# define IS_SHINE (OPT & SHINE)
# define IS_REFLX (OPT & REFLX)
# define IS_SEPIA (OPT & SEPIA)
# define IS_GREY (OPT & GREY)
# define IS_CRTN (OPT & CRTN)
# define IS_PHONG (OPT & PHONG)
# define IS_BPLANE (OPT & BPLANE)
# define IS_GLOBQ (OPT & GLOBQ)
# define IS_OPT_I1 (OPT & OPT_I1)
# define IS_OPT_I2 (OPT & OPT_I2)
# define IS_MOTION_BLUR (OPT & MOTION_BLUR)
# define IS_STEREO (OPT & STEREO)
# define IS_ANTI (OPT & ANTI)

# define LUMI e->luminosite
# define AMBIANCE e->ambiance
# define SPEED e->speed
# define ALPHA_ROT e->alpha_rot
# define NB_REF e->nb_reflection

# define MOVES e->moves
# define ROT e->rotations
# define M_FORWARD (1 << 0)
# define M_BACKWARD (1 << 1)
# define M_LEFT (1 << 2)
# define M_RIGHT (1 << 3)
# define M_UP (1 << 4)
# define M_DOWN (1 << 5)

# define OBJ_ALLOWED "light plane sphere cylinder cone torus"
# define NB_OBJ_FCT 6

# define MLX e->mlx
# define WIN e->win
# define IMG_WIDTH e->img_width
# define IMG_HEIGHT e->img_height
# define WIN_WIDTH e->win_width
# define WIN_HEIGHT e->win_height
# define IMG_GAP_X e->img_gap_x
# define IMG_GAP_Y e->img_gap_y
# define IMG e->img.img
# define IMG_ADDR e->img.addr
# define ENDIAN e->endian
# define NB_ME 31
# define ME e->menu
# define COMMAND e->command

# define ENV param->e
# define TH param->index
# define X param->x
# define Y param->y
# define VW_RAY param->vw_ray
# define PHO_RAY param->light_ray
# define MOUS_RAY param->mouse_ray
# define SOL param->sol
# define COLOR param->color
# define F_COLOR param->final_color
# define REF_COEFF param->reflec_coeff

# define T sol->t
# define A sol->a
# define B sol->b
# define C sol->c
# define DET sol->det

# define O_POS obj->pos
# define O_DIR obj->dir
# define O_P1 obj->p1
# define O_P2 obj->p2
# define O_R1 obj->r1
# define O_R2 obj->r2
# define O_ANG obj->angle

# define VW_WIDTH e->scene->view_plane_width
# define VW_HEIGHT e->scene->view_plane_height
# define VW_DIST e->scene->view_plane_dist
# define VW_UP_LEFT e->scene->view_plane_up_left
# define CAM_POS e->scene->cam_pos
# define CAM_DIR e->scene->cam_dir
# define CAM_UP e->scene->cam_up
# define CAM_RIGHT e->scene->cam_right
# define GAP_X e->scene->gap_x
# define GAP_Y e->scene->gap_y

# define XX noise->x
# define YY noise->y
# define ZZ noise->z
# define U noise->u
# define V noise->v
# define W noise->w
# define A1 noise->a
# define B1 noise->b
# define AA1 noise->aa
# define AB1 noise->ab
# define BA1 noise->ba
# define BB1 noise->bb
# define PER noise->per

typedef	struct		s_pix
{
	int				x;
	int				y;
	unsigned int	color;
}					t_pix;

typedef struct		s_sol
{
	double			t[4];
	double			a;
	double			b;
	double			c;
	double			det;
}					t_sol;

typedef struct		s_sol_3
{
	t_sol			alpha;
	t_sol			beta;
	t_sol			delta;
}					t_sol_3;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				sizeline;
	int				bpp;
}					t_img;

typedef struct		s_texture
{
	void			*img;
	char			*addr;
	int				bpp;
	int				width;
	int				sizeline;
}					t_tex;

typedef struct		s_col_res
{
	t_rgb			rgb;
	t_hsv			hsv;
	t_hsv			tmp;
	double			angle_light;
	double			omega;
	double			intensite;
	double			vm;
	t_v3d			ref;
	t_v3d			test;
	t_v3d			r;
	struct s_object	*obj;
}					t_col_res;

typedef struct		s_menu
{
	char			*path;
	t_img			img;
	float			x;
	float			y;
}					t_menu;

typedef struct		s_noise
{
	int				per[512];
	int				x;
	int				y;
	int				z;
	double			u;
	double			v;
	double			w;
	int				a;
	int				b;
	int				aa;
	int				bb;
	int				ab;
	int				ba;
}					t_noise;

typedef struct		s_4d
{
	double			a;
	double			b;
	double			c;
	double			d;
}					t_4d;

typedef struct		s_mat
{
	char			*name;
	double			ambient;
	double			diffuse;
	double			specular;
	double			shine;
	double			density;
}					t_mat;

typedef struct		s_object
{
	int				type;
	char			*name;
	t_v3d			pos;
	t_v3d			dir;
	t_v3d			p1;
	t_v3d			p2;
	double			r1;
	double			r2;
	double			t1;
	double			t2;
	double			angle;
	int				color;
	t_mat			mat;
	char			*pro;
	double			coef;
	char			*asp;
	double			density;
}					t_object;

typedef struct		s_ray
{
	t_v3d			pos;
	t_v3d			dir;
	t_v3d			inter;
	t_v3d			norm;
	double			dist;
	double			det;
	t_object		*obj;
}					t_ray;

typedef struct		s_light
{
	t_object		*obj;
	t_rgb			rgb;
	t_hsv			hsv;
	unsigned int	color;
	double			angle_light;
	double			omega;
	double			shadow;
	double			ray;
}					t_light;

typedef struct		s_scene
{
	char			*name;
	t_v3d			cam_pos;
	t_v3d			cam_dir;
	t_v3d			cam_up;
	t_v3d			cam_right;
	t_list			*obj;
	t_list			*obj_trash;
	t_list			*light;
	t_list			*obj_focus;
	double			view_plane_width;
	double			view_plane_height;
	double			view_plane_dist;
	t_v3d			view_plane_up_left;
	double			gap_x;
	double			gap_y;
}					t_scene;

typedef struct		s_param
{
	struct s_env	*e;
	int				index;
	int				x;
	int				y;
	int				i_reflec;
	t_ray			vw_ray;
	t_ray			light_ray;
	t_ray			mouse_ray;
	t_sol			sol;
	int				color;
	t_v3d			norm;
	double			reflec_coeff;
	t_rgb			final_color;
}					t_param;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	double			luminosite;
	double			ambiance;
	double			speed;
	double			alpha_rot;
	int				img_width;
	int				img_height;
	int				win_width;
	int				win_height;
	int				img_gap_x;
	int				img_gap_y;
	int				endian;
	int				back_plane;
	int				nb_reflection;
	int				opt;
	char			moves;
	char			rotations;
	char			command;
	t_img			img;
	t_menu			menu[NB_ME];
	t_scene			*scene;
	t_v3d			parse_cam_pos;
	t_v3d			parse_cam_dir;
	char			**obj_allowed;
	void			(*obj_fct_obj[NB_OBJ_FCT])(struct s_env *, t_object *, \
			t_ray *, t_sol *sol);
	void			(*calc_obj_param[NB_OBJ_FCT])(t_object *);
	void			(*update_obj_pos[NB_OBJ_FCT])(t_object *);
	void			(*get_obj_param[NB_OBJ_FCT])(char *, t_object *, void *);
	t_param			*param[NB_TH];
}					t_env;

/*
** ENV
*/

t_env				*init_env(char *file_name, char opt);
void				free_env(t_env *e);
void				free_obj(void *content, size_t size);
void				init_opt(t_env *e, int opt);
int					get_options(int ac, char **av, int *opt);

/*
** MENU
*/

void				init_menu(t_env *e);
void				change_btn_light(t_env *e);
void				menu_object(t_env *e);
void				print_mat(t_env *e, t_object *o);
void				menu_image(t_env *e);
void				menu_image_filter(t_env *e);
void				back_menu(t_env *e);
void				top_menu_event(t_env *e, int x, int y);
void				right_menu_event(t_env *e, int x, int y);
void				bottom_menu_event(t_env *e, int x, int y);
void				deform_menu_event(t_env *e, int x, int y, t_object *obj);
void				text_menu_event(t_env *e, int x, int y, t_object *obj);

/*
** PARSING
*/

void				parse_rt(t_env *e, char *file_name);
void				build_object(t_env *e, char *str);
void				check_acc(t_env *e, char *str);
char				*get_in_acc(char *str, char *acc);
char				*go_to_next_acc(char *str, int n);
char				*find_param(char *small, char *big);
t_v3d				get_v3d(char *str, char *name, t_env *e);
double				get_double(char *str, char *name, t_env *e);
int					size_to_end_acc(char *str);
void				init_obj_param(t_env *e);
void				get_light_param(char *str, t_object *obj, void *e);
void				get_plane_param(char *str, t_object *obj, void *e);
void				get_sphere_param(char *str, t_object *obj, void *e);
void				get_cylinder_param(char *str, t_object *obj, void *e);
void				get_cone_torus_param(char *str, t_object *obj, void *e);

/*
** DISPLAY
*/

unsigned int		hsv_to_rgb(unsigned int h, double s, double v);
void				img_put_pixel(t_img *img, int x, int y, t_param *param);
void				rgb_to_hsv(unsigned int rgb, int *h, double *s, double *v);
int					add_color(int c1, int c2, double i);
int					create_img(t_env *e);

int					moves(t_env *e);
void				change_global_quality(void *arg);
void				change_luminosite(t_env *e, int keycode);
void				change_ambiance(t_env *e, int keycode);
void				change_speed_rotation(t_env *e, int keycode);
void				change_luminosite_mouse(t_env *e, int y);
void				change_indice_reflection(t_env *e, int keycode);
void				change_option(t_env *e, int opt);
void				antialiasing(t_env *e);
void				init_params_for_al(t_env *e, t_img *tmp);
void				del_focus_object(t_env *e);
void				undo_del_object(t_env *e);
void				color_selector(t_env *e, int x, int y);
void				add_sphere(void *arg);
void				add_cylinder(void *arg);
void				add_cone(void *arg);
void				add_plane(void *arg);
void				add_torus(void *arg);
void				add_lampe(void *arg);
void				screenshot(void *arg);
void				reset_cam(void *arg);
void				back_plane(void *arg);
void				active_motion_blur(void *arg);
void				active_sepia(void *arg);
void				active_grey(void *arg);
void				active_cartoon(void *arg);

/*
** RAYTRACING
*/

void				*raytracer(void *arg);
void				apply_light(t_env *e, t_param *param);
void				do_shininess(t_param *param, t_object *light, t_hsv *hsv, \
		t_v3d ref);
void				apply_color(t_env *e, t_param *param, t_object *l, \
		t_light *datas);
void				apply_cartoon_color(t_env *e, t_param *param, t_object \
		*light, t_light *datas);
void				plane(t_env *e, t_object *obj, t_ray *ray, t_sol *sol);
void				sphere(t_env *e, t_object *obj, t_ray *ray, t_sol *sol);
void				cylinder(t_env *e, t_object *obj, t_ray *ray, t_sol *sol);
void				cone(t_env *e, t_object *obj, t_ray *ray, t_sol *sol);
void				torus(t_env *e, t_object *obj, t_ray *ray, t_sol *sol);
void				calc_cylinder_param(t_object *obj);
void				update_cylinder_pos(t_object *obj);
void				calc_cone_param(t_object *obj);
void				update_cone_pos(t_object *obj);
t_v3d				get_torus_normal(t_object *o, t_v3d cam, t_v3d ray, \
		double ret);
void				update_torus_pos(t_object *obj);
double				caps_up(t_object *obj, t_ray *ray);
double				caps_bottom(t_object *obj, t_ray *ray);
double				caps(t_ray *ray, double r, t_v3d n, t_v3d p);

/*
** ERROR AND DEBUG
*/

void				error_usage(void);
void				error_file(t_env *e);
void				error_opt(char opt);
void				error_perso(t_env *e, char *str);
int					quit_rt(t_env *e);
void				debug(t_env *e);
void				print_help();

/*
** EVENT
*/

int					ft_key_press(int keycode, t_env *e);
int					ft_key_release(int keycode, t_env *e);
int					ft_key_command(int keycode, t_env *e);
int					ft_mouse_click(int button, int x, int y, t_env *e);
void				top_menu_event(t_env *e, int x, int y);
void				bottom_menu_event(t_env *e, int x, int y);
void				right_menu_event(t_env *e, int x, int y);
void				save_scene(t_env *e);
void				screenshot(void *arg);

/*
** Perlin
*/

void				fill_matiere_in_case(t_mat *mat);
void				modif_normale(double d, double alpha, t_v3d *norm, \
		t_v3d inter);
double				noise(double x, double y, double z);
void				fill_xyz(t_noise *noise, double x, double y, double z);
void				fill_uvw(t_noise *noise, double x, double y, double z);
void				fill_baba(t_noise *a);
double				noise_to_ret(t_noise *a, double b, double c, double d);
double				fade(double a);
double				lerp(double x, double y, double z);
double				grad(int a, double x, double y, double z);
int					modify_color_for_tex(char *tex, t_v3d vec, t_light *datas, \
		double c);
t_rgb				wood(t_v3d inter, double coef);
t_rgb				marbre(t_v3d inter, double mult);
t_rgb				damier(double l, t_v3d i, t_rgb col);
void				normal_water(double d, t_v3d *n, t_v3d inter, t_v3d dir);
t_rgb				random_noise(double coef, t_v3d vec, t_rgb rgb);

/*
** Reflection
*/

void				init_reflect(t_param *param);
void				add_reflected_color(t_param *param);
void				sepia_filter(t_param *param);
void				grey_filter(t_param *param);

int					stereo(t_env *e);
void				change_stereo(t_env *e);

#endif
