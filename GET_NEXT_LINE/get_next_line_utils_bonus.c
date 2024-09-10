/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:44:34 by mosokina          #+#    #+#             */
/*   Updated: 2024/05/26 19:44:37 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	found_newline(t_list	*list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

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
				len++;
				return (len);
			}
			i++;
			len++;
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

t_list	*find_last_node(t_list *list)
{
	t_list	*temp;

	if (!list)
		return (NULL);
	temp = list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	dealloc(t_list	*saved_node, t_list	**ptr_list, char *saved_str)
{
	t_list	*tmp;

	if (!(*ptr_list))
		return ;
	while (*ptr_list)
	{
		tmp = (*ptr_list)->next;
		free((*ptr_list)->content);
		free(*ptr_list);
		*ptr_list = tmp;
	}
	*ptr_list = NULL;
	if (saved_node->content[0])
		*ptr_list = saved_node;
	else
	{
		free(saved_str);
		free(saved_node);
	}
}
