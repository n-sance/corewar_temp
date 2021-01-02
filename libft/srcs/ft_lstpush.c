#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			elem = *alst;
			while (elem->next != NULL)
				elem = elem->next;
			elem->next = new;
		}
	}
}
