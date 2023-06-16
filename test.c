CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME	= server
NAME_C	= client
NAME_bs	= server_bonus
NAME_C_bs	= client_bonus
# ***
UTILs	= utils.c
OBJ_U = $(UTILs:.c=.o)

# ***
SRC_client  = client.c
SRC_server  = server.c
SRC_client_bs  = client_bonus.c
SRC_server_bs  = server_bonus.c

# ***
OBJ_client = $(SRC_client:.c=.o)
OBJ_server = $(SRC_server:.c=.o)

# ***
OBJ_server_bs = $(SRC_server_bs:.c=.o)
OBJ_client_bs = $(SRC_client_bs:.c=.o)

# ***
%.o:%.c Minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

# ***
all: $(NAME) $(NAME_C)

# ***
$(NAME) : $(OBJ_server) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_server) -o $(NAME)

$(NAME_C) : $(OBJ_client) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_client) -o $(NAME_C)

# ***
bonus: $(NAME_bs) $(NAME_C_bs)

# ***
$(NAME_bs) : $(OBJ_server_bs) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_server_bs) -o $(NAME_bs)

$(NAME_C_bs) : $(OBJ_client_bs) $(OBJ_U)
	$(CC) $(CFLAGS) $(OBJ_U) $(OBJ_client_bs) -o $(NAME_C_bs)

# ***
clean:
	rm -rf $(OBJ_client_bs) $(OBJ_server_bs)
	rm -rf $(OBJ_client) $(OBJ_server) $(OBJ_U)

fclean: clean
	rm -rf $(NAME) $(NAME_C) 
	rm -rf server_bonus client_bonus

re: fclean all

# ***# *** # ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***# ***


// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// int	trgb(double it)
// {
// 	int r;
// 	int g;
// 	int b;
	
// 	r = (1 - it) * it * 3555;
// 	g = (1 - it) * (1 - it)  * it * 1500;
// 	b = (1 - it) * (1 - it) * (1 - it)   * it * 3555;
// 	return (create_trgb(0, r, g, b));
// }


//cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit




void	mlx_functions(t_data x)
{
	mlx_put_image_to_window(x.mlx_ptr,
		x.win_ptr, x.img_ptr, 0, 0);
	mlx_mouse_hook(x.win_ptr, mouse_hook, &x);
	mlx_key_hook(x.win_ptr, key_hook, &x);
	mlx_hook(x.win_ptr, 17, 0, destroy, &x);
	mlx_hook(x.win_ptr, 2, 0, key_exit, &x);
	mlx_loop(x.mlx_ptr);
}

// # ************************************************************************

void    *mlx_new_image(void *mlx_ptr,int width,int height);
/*
**  return void *0 if failed
*/
char    *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
                           int *size_line, int *endian);
/*
**  endian : 0 = sever X is little endian, 1 = big endian
**  endian : useless on macos, client and graphical framework have the same endian
*/
int     mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
                                int x, int y);
unsigned int    mlx_get_color_value(void *mlx_ptr, int color);


/*
** dealing with Events
*/

int     mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int     mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int     mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int     mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int     mlx_loop (void *mlx_ptr);


/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/


/*
**  Usually asked...
*/

int     mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
                       char *string);
void    *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
                          int *width, int *height);
void    *mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
                               int *width, int *height);
int     mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int     mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int     mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param);

int     mlx_do_key_autorepeatoff(void *mlx_ptr);
int     mlx_do_key_autorepeaton(void *mlx_ptr);
int     mlx_do_sync(void *mlx_ptr);

#endif /* MLX_H */






// int Julia(double x, double y)
// {
//     double a;
//     double b;
    
//     double l;
//     double k;
    
//     double p;
    
//     double r;
//     double i;
//     // double sin(double angle);
//     // double cos(double angle);


//     a = ((x - (800 / 2)) / (800 / 4));
//     b = ((y - (800 / 2)) / (800 / 4));
//     k = a;
//     l = b;

//     p = 0.0;
//     while(p < ITR)
//     {
//         r = (a * a) - (b * b);
//         i = 2 * b * a;
           
//         a = r + -0.74543;
//         b = i + 0.11301;
//         // a = r + (0.7885*cos(0.4) + 0.7885 * sin(0.4));
//         // b = i + (0.7885*cos(0.6) + 0.7885 * sin(0.6));
//         if((a * a) + (b * b) > 4)
//             break;
//         p++;
//     }
//     return p;
// }




// #include <stdio.h>

// int     ft_strcmp(char *s1, char *s2)
// {
//         int                     i;

//         i = 0;
//         while (s1[i] && s2[i] && s1[i] == s2[i])
//         {
//                 i++;
//         }
//         return (s1[i] - s2[i]);
// }

// int main ()
// {
// 	printf("%d", ft_strcmp("hello world loop", "hello world loop"));
// }




     // a = r + -0.74543;
        // b = i + 0.11301;
        //printf("%f, %f\n", data->x_j, data->y_j);
        // data->x_j = -0.74543;
        // data->y_j = 0.11301;



		// mlx_hook(fractol.win_ptr, 2, 0, "function key_exit", &fractol);
		key for -> (X)  -->>>   17


	// param->width_zoom = width;
	// param->heigth_zoom = heigth;
	// if (button == 4)
	// {
	// 	x = param->width_zoom - (width / 10);
	// 	y = param->heigth_zoom - (heigth / 10);
	// }
	// else if (button == 5)
	// {
	// 	x = param->width_zoom - (width / 10);
	// 	y = param->heigth_zoom - (heigth / 10);
	// }
	// mlx_destroy_image(param->mlx_ptr, param->img);
	// param->img = mlx_new_image(param->mlx_ptr, width, heigth);
	// param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->line_length, &param->endian);
	// if (param->set == 0)
	// 	MNDLBRT_function_pixel_put(param);





// int	key_hook(int keycode, t_data *x)
// {
// 	help_key_hook(keycode, x);
// 	if (keycode == 123)
// 		x->x += 0.1;
// 	else if (keycode == 124)
// 		x->x -= 0.1;
// 	else if (keycode == 125)
// 		x->y -= 0.1;
// 	else if (keycode == 126)
// 		x->y += 0.1;
// 	else if (keycode == 53)
// 		destroy(x);
// 	mlx_clear_window(x->mlx_ptr, x->win_ptr);
// 	mandelbrot(x, x->c_real, x->c_img);
// 	mlx_put_image_to_window(x->mlx_ptr,
// 		x->win_ptr, x->img_ptr, 0, 0);
// 	return (0);
// }