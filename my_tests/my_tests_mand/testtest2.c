
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    char    *content;
    struct  s_list *next;
}   t_list;



int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

void	cpystr_upto_newline(t_list	*list, char *line_str)
{
	int	i;
	int	k;

	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				line_str[k++] = '\n';
				line_str[k] = '\0';
				return ;
			}
			line_str[k++] = list->content[i++];
		}
		list = list->next;
	}
	line_str[k] = '\0';
}


char	*get_line(t_list *list)
{
	char	*line_str;
	int		str_len;

	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	line_str = malloc((sizeof(char) * (str_len +1)));
	if (!line_str)
		return (NULL);
	cpystr_upto_newline(list, line_str);
	return (line_str);
}

//TEST1 without get_line()
// int	main(void)
// {
//     t_list  **ptr_to_list;
//     t_list  *test_list1;
//     t_list  *test_list2;
//     t_list  *test_list3;
//     char   *test_str;

//     test_list1 = malloc(sizeof(t_list));

//     test_list2 = malloc(sizeof(t_list));

//     test_list3 = malloc(sizeof(t_list));

//     test_list1->content = "123";
//     test_list1->next = test_list2;
//     test_list2->content = "4567\n89";
//     test_list2->next = test_list3;
//     test_list3->content = "\n";
//     test_list3->next = NULL;
//     test_str = malloc(sizeof(char)*50);

//     printf ("leght %d\n", len_to_newline(test_list1));
//     cpystr_upto_nextline(test_list1, test_str);
//     printf ("string %s\n", test_str);
//     free (test_list1);
//     free(test_list2);
//     free(test_list3);
//     free(test_str);
// 	return (0);
// }


// TEST2 with get_line()
int	main(void)
{
    t_list  **ptr_to_list;
    t_list  *test_list1;
    t_list  *test_list2;
    t_list  *test_list3;
    char   *test_str;

    test_list1 = malloc(sizeof(t_list));

    test_list2 = malloc(sizeof(t_list));

    test_list3 = malloc(sizeof(t_list));

    test_list1->content = "123";
    test_list1->next = test_list2;
    test_list2->content = "4567\n89";
    test_list2->next = test_list3;
    test_list3->content = "\n";
    test_list3->next = NULL;
    test_str = get_line(test_list1);
    // printf ("leght %d\n", len_to_newline(test_list1));
    // cpystr_upto_nextline(test_list1, test_str);
    printf ("string %s\n", test_str);
    free (test_list1);
    free(test_list2);
    free(test_list3);
    free(test_str);
	return (0);
}

//TEST3 with get_line() if list is NULL
// int	main(void)
// {
//     t_list  *test_list1;
//     char   *test_str;

//     test_list1 = NULL;
//     test_str = get_line(test_list1);
//     // printf ("leght %d\n", len_to_newline(test_list1));
//     // cpystr_upto_nextline(test_list1, test_str);
//     printf ("string %s\n", test_str);
//     // free(test_str);
// 	return (0);
// }