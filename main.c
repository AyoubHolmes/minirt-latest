#include "miniRT.h"
#include <mlx.h>
//gcc -Wall -Werror -Wextra  -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGl -framework AppKit tracing_ray.c && ./a.out

int		file_checker(char *file)
{
    int		isChecked;
    char	**data;
    char	*line;
    int		fd;
    int		rest;

	d.obj = NULL;
    fd = open(file, O_RDONLY);
    rest = 1;
    while(rest == 1)
    {
        rest = get_next_line(fd, &line);
        if (line[0] == '\0')
            continue;
        data = ft_split_whitespaces(line);
		isChecked = data_checker(data);
		if (isChecked == -1)
			return (0);
    }
    close(fd);
    return (1);
}

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
        data = ft_split_whitespaces(line);
		data_insertion(&d, data);
    }
    close(fd);
    return (d);
}

/*void		graphicDrawer(t_data d,t_window w)
{
	int i;
	int j;
	double u;
	double v;
	double distance = INT_MAX;
	double d_shadow = INT_MAX;
	int k = 0;
	j = 0;
	while(j < d.R.y)
	{
		i = d.R.x - 1;
		while (i >= 0)
		{
			u = (double)i / (double)d.R.x;
			v = (double)j / (double)d.R.y;
			ray r = get_ray(d, u, v);
			w.img_data[k++] = getPixelColor(d.obj, r, &distance, &d_shadow, d.lights);
			i--;
		}
		j++;
	}
	mlx_put_image_to_window(w.mlx_ptr, w.win_ptr, w.img_ptr,0,0);
}

int key_press(int keycode, t_main *m)
{
	if(keycode == 53 || keycode == 12)
		exit(0);
	if (keycode == 123)
	{
		m->d.cameras = get_cam_previous(&m->d.cameras);
		graphicDrawer(m->d, m->w);
		printf("test here 1 \n");
	}
	if (keycode == 124)
	{
		m->d.cameras = get_cam_next(&m->d.cameras);
		printf("test here 2 \n");
		graphicDrawer(m->d, m->w);
	}
	return (0);
}*/

int			main()
{
	t_main	m;

	m.d = file_parser("test.rt");
	objectsDebugger(m.d);
	m.d.cameras = getCams(m.d);
	//cameraPrinter(&d.cameras->cam);
	m.d.lights = getLigths(m.d.obj);
	/*m.w.mlx_ptr = mlx_init();
	m.w.win_ptr = mlx_new_window(m.w.mlx_ptr,m.d.R.x,m.d.R.y,"miniRT");
	m.w.img_ptr = mlx_new_image(m.w.mlx_ptr,m.d.R.x,m.d.R.y);
	m.w.img_data = (int *)mlx_get_data_addr(m.w.img_ptr, &m.w.bpp, &m.w.size_l, &m.w.img_endian);
	if (m.d.lights == 0 || m.d.cameras == 0 || m.d.obj == 0)
		return (0);
	graphicDrawer(m.d, m.w);
	mlx_hook(m.w.win_ptr, 2, 0, key_press, &m);
	mlx_loop(m.w.mlx_ptr);*/
}
