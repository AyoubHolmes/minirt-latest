#include "miniRT.h"

void				ft_lstadd_back(t_objects **alst, t_objects *new)
{
	t_objects *p;

	if (*alst == NULL)
	{
		if (!(*alst = (t_objects*)malloc(sizeof(t_objects))))
			return ;
		(*alst)->id = new->id;
		(*alst)->content = new->content;
		(*alst)->next = NULL;
	}
	else
	{
		p = *alst;
		if (new)
		{
			while (p->next != NULL)
			{
				p = p->next;
			}
			if (!(p->next = (t_objects*)malloc(sizeof(t_objects))))
				return ;
			p->next->id = new->id;
			p->next->content = new->content;
			p->next->next = NULL;
		}
	}
}

t_objects			*ft_lstnew(void *content)
{
	t_objects *p;

	if (!(p = (t_objects*)malloc(sizeof(t_objects))))
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}

t_camlist	*ft_double_lst_cam_new(t_Cam_data cam)
{
	t_camlist *p;

	if (!(p = (t_camlist*)malloc(sizeof(t_camlist))))
		return (NULL);
	p->cam = cam;
	p->next = NULL;
	p->prev = NULL;
	return (p);
}

void				fcam_add(t_camlist **alst, t_camlist *new)
{
	t_camlist *p;

	if (*alst == NULL)
		*alst = new;
	else
	{
		p = *alst;
		if (new)
		{
			while (p->next != NULL)
				p = p->next;
			p->next = new;
			new->next = NULL;
			new->prev = p;
		}
	}
}

t_camlist			*fcam_last(t_camlist **alst)
{
	t_camlist *p;

	if (*alst == NULL)
		return (0);
	else
	{
		p = *alst;
		while (p->next != NULL)
			p = p->next;
		return (p);
	}
}

t_camlist		*get_cam_previous(t_camlist **alst)
{
	t_camlist *p;

	if (*alst == NULL)
		return (0);
	p = *alst;
	*alst = p->prev;
	return (*alst);
}

t_camlist		*get_cam_next(t_camlist **alst)
{
	t_camlist *p;

	if (*alst == NULL)
		return (0);
	p = *alst;
	*alst = p->next;
	return (*alst);
}
