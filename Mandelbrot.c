#include "mlx.h"
#include <unistd.h>

void    ft_Mandelbrot(void *mlx_ptr, void *win_ptr)
{
    int         x;
    int         y;
    int         i;
    int         j;

    // x = 500;
    // y = 500;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "the greate window in mlx");
    // i = x * (500 / 2);
    // j = y * (500 / 2);
    x = 250;
    y = 0;
    if  (x < 500)
    {
        while (y < 500)
        {
            madelbrot(cwf(x), cws(y))
            y++;
        }
        x++;
    }
    mlx_loop(mlx_ptr);
}

int main ()
{
    void    *mlx_ptr;
    void    *win_ptr;

    ft_Mandelbrot(mlx_ptr, win_ptr);
}