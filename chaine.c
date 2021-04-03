#include "include/checker.h"

void		search_operation(char *buffer, t_list **lista, t_list **listb)
{
	char **tab;

	tab = ft_split(buffer, ' ');
	while (*tab)
	{
		appli_instruct(*tab, lista, listb);
		tab++;
	}
}
