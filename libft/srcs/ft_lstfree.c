/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:40:53 by rciera            #+#    #+#             */
/*   Updated: 2020/12/08 14:09:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	free_elem(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void		*ft_lstfree(t_list **alst)
{
	return (ft_lstdel(alst, &free_elem));
}
