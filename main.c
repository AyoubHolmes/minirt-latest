#include "miniRT.h"
#include <mlx.h>
//gcc -Wall -Werror -Wextra  -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit tracing_ray.c && ./a.out

t_data		file_parser(char *file)
{
    t_data d;
    char **data;
    char *line;
    int fd;
    int rest;

	d.obj = NULL;
    fd = open(file, O_RDONLY);
    rest = 1;
    while(rest == 1)
    {
        rest = get_next_line(fd, &line);
        if (line[0] == '\0')
            continue;
        data = ft_split(line, ' ');
		data_insertion(&d, data);
    }
    close(fd);
    return (d);
}


void		graphicDrawer(t_data d,t_window w)
{
	int i;
	int j;
	double u;
	double v;
	double distance = INT_MAX;
	int k = 0;
	j = 0;
	while(j < d.R.y)
	{
		i = 0;
		while (i < d.R.x)
		{
			u = (double)i / (double)d.R.x;
			v = (double)j / (double)d.R.y;
			ray r = get_ray(d, u, v);
			w.img_data[k++] = getPixelColor(d.obj, r, &distance, d.lights);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img_ptr,0,0);
}

int			main()
{
	t_data				d;
	t_window			w;

	d = file_parser("test.rt");
	//objectsDebugger(d);
	d.cameras = getCams(d);
	d.cameras = get_cam_next(&d.cameras);
	d.cameras = get_cam_next(&d.cameras);
	cameraPrinter(&d.cameras->cam);
	d.lights = getLigths(d.obj);
	w.mlx_ptr = mlx_init();
	w.win_ptr = mlx_new_window(w.mlx_ptr,d.R.x,d.R.y,"miniRT");
	w.img_ptr = mlx_new_image(w.mlx_ptr,d.R.x,d.R.y);
	w.img_data = (int *)mlx_get_data_addr(w.img_ptr, &w.bpp, &w.size_l, &w.img_endian);
	if (d.lights == 0 || d.cameras == 0 || d.obj == 0)
		return (0);
	graphicDrawer(d, w);
	mlx_loop(w.mlx_ptr);
}
