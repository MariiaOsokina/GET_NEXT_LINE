
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    char    *content;
    struct  s_list *next;
}   t_list;

void	clean_list(t_list	**list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list) == NULL)
			return ;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	free (*list);
	*list = NULL;
}


int	found_newline(t_list	*list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		//???
		while (list->content[i] && i < 10)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	main(void)
{
    t_list  **ptr_to_list;
    t_list  *test_list1;
    t_list  *test_list2;
    int i;

    test_list1 = malloc(sizeof(t_list));
    test_list2 = malloc(sizeof(t_list));
    test_list1->next = test_list2;
    test_list2->next = NULL;


    test_list1->content = malloc((sizeof(char)*4) + 1);
    i = 0;
    while (i < 3)
    {
        test_list1->content[i] = '1';
        i++;
    }
    test_list1->content[i] = '\0';

    test_list2->content = malloc((sizeof(char)*4) + 1);
    i = 0;
    while (i < 3)
    {
        test_list2->content[i] = '2';
        i++;
    }
    test_list2->content[i] = '\0';

	printf ("result of finding the new line %d\n", found_newline(test_list1));

    printf ("string %s\n", test_list1->content);
    printf ("string %s\n", test_list2->content);

    clean_list(&test_list1);
    // free(test_list1);
    // free(test_list2);
    // // free(test_list1->content);
    // // free(test_list2->content);

	return (0);
}
