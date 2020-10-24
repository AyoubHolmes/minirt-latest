#include "miniRT.h"

t_camlist	*getCams(t_data d)
{
	t_objects	*obj;
	t_camlist	*liste;
	t_camlist	*q;

	liste = (t_camlist*)malloc(sizeof(t_camlist));
	obj = d.obj;
	while (obj != NULL)
	{
		if (obj->id == 2)
			break;
		obj = obj->next;	
	}
	liste = ft_double_lst_cam_new(*(t_Cam_data*)obj->content);
	obj = obj->next;
	while (obj != NULL)
	{
		if (obj->id == 2)
		{
			q = ft_double_lst_cam_new(*(t_Cam_data*)obj->content);
			fcam_add(&liste, q);
		}
		obj = obj->next;
	}
	q = fcam_last(&liste);
	q->next = liste;
	liste->prev = q; 
	return (liste);
}