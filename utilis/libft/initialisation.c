/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:55:16 by ajafy             #+#    #+#             */
/*   Updated: 2023/05/09 16:57:50 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube.h"

t_player	init_player(void)
{
	t_player	newlst;

	newlst.x = 0;
	newlst.y = 0;
	newlst.x_screen = 0;
	newlst.y_screen = 0;
	newlst.rotation_direction = 0;
	newlst.deplacement_directionx = 0;
	newlst.deplacement_directiony = 0;
	newlst.move_speed = 10.0;
	newlst.rotation_angle = M_PI / 2;
	newlst.rotation_speed = (3 * M_PI / 180);
	newlst.vue_angle = 60 * (M_PI / 180);
	return (newlst);
}

t_ray_info	*ft_lstlast(t_ray_info *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_ray_info **alst, t_ray_info *new)
{
	t_ray_info	*lst;

	if (!*alst)
		*alst = new;
	else
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
	}
}

int	ft_lstsize(t_ray_info *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = (t_ray_info *) lst->next;
		i++;
	}
	return (i);
}

t_ray_info	*ft_lstmid(t_ray_info *lst)
{
	int	i;
	int	len;

	i = 1;
	len = ft_lstsize(lst);
	if (len <= 0)
		return (NULL);
	while (i <= len / 2)
	{
		lst = (t_ray_info *) lst->next;
		i++;
	}
	return (lst);
}
