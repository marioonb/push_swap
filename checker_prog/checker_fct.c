
#include "../include/checker.h"
#include "../include/all.h"

static void	search_operation(char *buffer, t_list **lista, t_list **listb)
{
	char	**tab;

	tab = ft_split(buffer, ' ');
	while (*tab)
	{
		appli_instruct(*tab, lista, listb);
		if (g_debug_bonus == 1 || DEBUG == 1)
			affiche_2((*lista), (*listb));
		tab++;
	}
}

void		read_instruct(t_list **a, t_list **b)
{
	char	*buffer;

	buffer = NULL;
	while (get_next_line(0, &buffer) > 0)
	{
		search_operation(buffer, a, b);
		free(buffer);
	}
	free(buffer);
}
