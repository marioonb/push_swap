
#include "../include/checker.h"
#include "../include/all.h"


int			main(int ac, char **av)
{
	int		i;
	t_list	*lista;
	t_list	*listb;
	char	*buffer;

	(void)ac;
	i = 0;
	lista = NULL;
	listb = NULL;
	buffer = NULL;
	check_error(av);
	create_list(&lista, av);
	if (DEBUG == 1)
	{
		dprintf(1, "\nLISTE AVANT DE DEPART \nA = ");
		affiche_list(lista);
		dprintf(1, "\nB = ");
		affiche_list(listb);
		dprintf(1, "\n");
	}
	while (get_next_line(0, &buffer) > 0)
	{
		search_operation(buffer, &lista, &listb);
		if (DEBUG == 1)
		{
			dprintf(1, "A = ");
			affiche_list(lista);
			dprintf(1, "\nB = ");
			affiche_list(listb);
			dprintf(1, "\n");
		}
		free(buffer);
	}
	free(buffer);
	if (check_sort(lista, listb))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
}
