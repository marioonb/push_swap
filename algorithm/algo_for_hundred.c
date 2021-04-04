#include "../include/push_swap.h"
#include "../include/all.h"

int *create_bloc(t_list *list, int nb, int *current)
{
	int *bloc;

	bloc = malloc(sizeof(int) * nb);

	//printf ("le premier element est %d\n", current);
	int i = 0;
	//bloc[i] = current;
	//i++;
	while (i < nb)
	{
		bloc[i] = search_next_min(list, *current);
		*current = bloc[i];
		//dprintf(1, "current dans la creation est passé a : %d", *current);
		i++;
	}
	return(bloc);
}

void affiche_bloc(int *bloc, int nb)
{
	int i;
	i = 0;
	dprintf(1, "le bloc est : \n");
	    for (i = 0 ; i < nb ; i++)
    {
        dprintf(1, "[%d], ", bloc[i]);
    }
	dprintf(1, "\n");

}

int find_element_bloc_in_head(t_list *a, int nb, int *bloc)
{
	int i;
	int compt;

	compt = 1;
	i = 0;
	while (a != NULL)
	{
		i = 0;
		while (i < nb)
		{
			//dprintf(1, "on compare %d et %d\n", a->nb, bloc[i]);
			if (a->nb == bloc[i])
				return(compt);
			i++;
		}
		a = a->next;
		compt++;
	}
	return (-1);
}

int		find_element_bloc_in_queue2(int *tab, int nb, int *bloc, int t)
{
	int i;
	int compt;
	int j = 0;
	//int size;

	compt = 1;
	while (j < t)
	{
		i = 0;
		while (i < nb)
		{
			//dprintf(1, "on compare %d et %d\n", tab[j], bloc[i]);
			if (tab[j] == bloc[i])
			{
				return(compt);
			}
			i++;
		}
		j++;
		compt++;
	}
	free(tab);
	return (-1);
}


int *copy_in_tab(t_list *a)
{

	int size = ft_lstsize(a);
	int *tab = malloc(sizeof(int) * size);
	int i;

	i = size - 1;
	while (i >= 0)
	{
		//dprintf(1, "size est a %d\n", size);
		//dprintf(1, "l element a mettre dans le tableau est %d\n", a->nb);
		tab[i] = a->nb;
		//dprintf(1, "tab de size est a %d\n", tab[i]);
		a = a->next;
		i--;
	}
	//affiche_bloc(tab, size);
	return(tab);
}

int     find_element_bloc_in_queue(t_list *a, int nb, int *bloc)
{
	int i;
	int compt;
	int size;
	int median;
	int *tab;
	//t_list **cpy;

	//cpy = &a;
	compt = 1;
	i = 0;
	size = ft_lstsize(a);
	median = size / 2;
	//dprintf(1, "median est a %d\n", median);
	while (median > i)
	{
			a = a->next;
			i++;
	}
	//affiche_list(a);
	tab = copy_in_tab(a);
	compt = find_element_bloc_in_queue2(tab, nb, bloc, size - median);
	return(compt);
}

void exec_algo_hundred(int *bloc, t_list **a, t_list **b, int nb)
{
	int head;
	int queue;

	int i = 0;
	while (i < nb)
	{
		head = find_element_bloc_in_head((*a), nb, bloc);
		//dprintf(1, "element de head est position %d\n", head);
		queue = find_element_bloc_in_queue((*a), nb, bloc);
		//dprintf(1, "element de queue est position %d\n", queue);
		if (head -1 > queue && queue != -1)
		{
			while (queue > 0)
			{
				execute("rra", a, b);
				queue--;
			}
		}
		else
		{
			while(head-1 > 0)
			{
				execute("ra", a, b);
				//affiche_list((*a));
				head--;
			}
		}
		//affiche_2((*a), (*b));
		execute("pb", a ,b);
		//affiche_2((*a), (*b));
		//affiche_list((*a));
		i++;
	}
	//affiche_2((*a), (*b));
}

int max_in_head(t_list *b)
{
	int i;
	int size;
	int max;
	int size2;

	max = b->nb;
	size = ft_lstsize(b);
	size2 = size / 2;
	if (size % 2 != 0)
		size2++;
	i = 0;
	if(DEBUG == 1)
		dprintf(1, "dans head, size est a %d\n", size2);
	while (i < size2 && b)
	{
		if (b->nb > max)
			max = b->nb;
		b = b->next;
		i++;
	}
	return (max);
}

int		max_in_queue2(int *tab, int t)
{
	int i;
	int max;
	int res;

	res = -1;
	i = 0;
	max = -2147483648;
	while (i < t)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	free(tab);
	return (max);
}

int max_in_queue(t_list *b)
{
	int i;
	int size;
	int *tab;
	int size2;

	i = 0;
	size = ft_lstsize(b);
	size2 = size / 2;
	while (size - size2 > i)
	{
			b = b->next;
			i++;
	}
	tab = copy_in_tab(b);
	if(DEBUG == 1)
	{dprintf(1, "size2 est a %d\n", size2);
	affiche_bloc(tab, size2);}
	size = max_in_queue2(tab, size2);
	return(size);
}

int max_in_head_index(t_list *b)
{
	int i;
	int size;
	int max;
	int res;
	int size2;

	res = -1;
	size = ft_lstsize(b);
	size2 = size / 2;
	if (size % 2 != 0)
		size2++;
	max = b->nb;
	i = 0;
	while (i < size2 && b)
	{
		if (b->nb >= max)
			{
				max = b->nb;
				res = i;
			}
		b = b->next;
		i++;
	}
	return (res);
}

int		max_in_queue_index2(int *tab, int t)
{
	int i;
	int max;
	int res;

	res = -1;
	i = 0;
	max = tab[i];
	while (i < t)
	{
		if (tab[i] >= max)
			{
				res = i;
				max = tab[i];
			}
		i++;
	}
	free(tab);
	return (res);
}

int max_in_queue_index(t_list *b)
{
	int i;
	int size;
	int *tab;
	int size2;

	i = 0;
	size = ft_lstsize(b);
	size2 = size / 2;
	while (size - size2 > i)
	{
			b = b->next;
			i++;
	}
	tab = copy_in_tab(b);
	//affiche_bloc(tab, size2);
	size = max_in_queue_index2(tab, size2);
	return(size);
}


void sort_b_for_end(t_list **a, t_list **b)
{
	int head;
	int queue;
	int head_index;
	int queue_index;

	while ((*b) != NULL)
	{
		head = max_in_head((*b));
		if(DEBUG == 1)
		dprintf(1, "element de head le plus grand est  %d\n", head);
		queue = max_in_queue((*b));
		if(DEBUG == 1)
		dprintf(1, "element de queue le plus grand est %d\n", queue);
		if (head < queue)
		{
			queue_index = max_in_queue_index((*b));
			if(DEBUG == 1)
			dprintf(1, "le plus grand elememt est dans queue, position %d\n", queue_index);
			while (queue_index + 1 > 0)
			{
				execute("rrb", a, b);
				//affiche_2((*a), (*b));
				queue_index--;
			}
		}
		else
		{
			head_index = max_in_head_index((*b));
			if(DEBUG == 1)
			dprintf(1, "le plus grand elememt est dans tete, position %d\n", head_index);
			while(head_index > 0)
			{
				execute("rb", a, b);
				//affiche_list((*a));
				head_index--;
			}
		}
		if(DEBUG == 1)
		affiche_2((*a), (*b));
		execute("pa", a ,b);
		if(DEBUG == 1)
		affiche_2((*a), (*b));
	}
}

void algo_for_hundred(t_list **a, t_list **b)
{
	int size = ft_lstsize((*a));
	int nb = size / 5;
	int *bloc;
	int current;
	int i = 0;
	int end = size%5;

	if (size %5)
		nb += 1;
	current = -2147483648;
	//printf("la taille de la chaine est %d\nla taille du bloc est %d\n", size, nb);
	while (i < 5)
	{
		//bloc = malloc(sizeof(int) * nb);
		if (i == 5 && end != 0)
			nb = end;
		bloc = create_bloc((*a), nb, &current);
		//dprintf(1, "current a apres le premier tableau est :  %d/n", current);
		//affiche_bloc(bloc, nb);
		exec_algo_hundred(bloc, a, b, nb);
		free(bloc);
		i++;
	}
	if(DEBUG == 1)
		dprintf(1, "--------------------------------------\n               |TRIE B|\n--------------------------------------\n");
	sort_b_for_end(a, b);
}


void algo_for_more(t_list **a, t_list **b)
{
	int size = ft_lstsize((*a));
	int nb = size / 11;
	int *bloc;
	int current;
	int i = 0;
	int end = size % 11;
	if (size % 11)
		nb += 1;
	current = -2147483648;
	//printf("la taille de la chaine est %d\nla taille du bloc est %d\n", size, nb);
	while (i < 11)
	{
		if (i == 11 && end != 0)
			nb = end;
		//bloc = malloc(sizeof(int) * nb);
		bloc = create_bloc((*a), nb, &current);
		//dprintf(1, "current a apres le premier tableau est :  %d/n", current);
		//affiche_bloc(bloc, nb);
		exec_algo_hundred(bloc, a, b, nb);
		free(bloc);
		i++;
	}
	//dprintf(1, "--------------------------------------\n               |TRIE B|\n--------------------------------------\n");
	sort_b_for_end(a, b);
}
