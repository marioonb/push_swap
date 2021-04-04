
#include "../include/push_swap.h"
#include "../include/all.h"

int search_next_min(t_list *list, int index)
{
	int i;
	int min;

	//if (list->nb == index)
	//	min = list->next->nb;
	//else
	//	min = list->nb;
	min = 2147483647;
	i = 0;

	while (list)
	{
		//dprintf(1, "l index est a %d", index);
		if (list->nb < min && list->nb > index)
			min = list->nb;
		list = list->next;
	}
	//printf("les next min trouvé est %d\n", min);
	return (min);
}

int is_min (int nb, t_list *list)
{
	while (list != NULL)
	{
		if (list->nb < nb)
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_max(int nb, t_list *list)
{
	while (list)
	{
		if (list->nb > nb)
			return (0);
		list = list->next;
	}
	return (1);

}

int search_min(t_list *list)
{
	int i;
	int min;

	min = list->nb;
	i = 0;

	//if (!list)
	//	return (0);
	while (list)
	{
		if (list->nb < min)
			min = list->nb;
		list = list->next;
	}
	//dprintf(1, "le nombre minimin cest %d ", min);
	return (min);

}
