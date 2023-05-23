#include "mlx.h"
#include <unistd.h>

// void ft_putchar(char c)
// {
//     write(1, &c, 1);
// }

// int deal_key(int key, void *param)
// {
//     void *mlx_ptr;
//     void *win_ptr;

//     ft_putchar('X');
//     mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
//     return (0);
// }

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int i = 0;
	int j;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 800, "mlx 42");

	while (i < 800){
        j = 0;
		while (j < 800) {
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FF00);
			if (j >= 100)
			{
				while (j < 800)
				{
					mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x87CEFA);
					mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x87CEFA);
					j++;
				}
				break;
			}
			j++;
		}
        i++;
	}
// mlx_key_hook (win_ptr, deal_key, (void *)0 );
    mlx_loop(mlx_ptr);
}





//cc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
