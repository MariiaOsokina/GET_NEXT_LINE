/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:36:44 by mosokina          #+#    #+#             */
/*   Updated: 2024/05/15 16:36:48 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	polish_list(t_list	**ptr_list)
{
	t_list	*saved_node;
	t_list	*last_node;
	int		i;
	int		k;
	char	*saved_str;

	saved_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!saved_str)
		return ;
	saved_node = malloc(sizeof(t_list));
	if (!saved_node)
		return ;
	last_node = find_last_node(*ptr_list);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		saved_str[k++] = last_node->content[i];
	saved_str[k] = '\0';
	saved_node->content = saved_str;
	saved_node->next = NULL;
	dealloc(saved_node, ptr_list, saved_str);
}

void	add_to_list(t_list **ptr_list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*ptr_list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*ptr_list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

int	create_list(t_list	**ptr_list, int fd)
{
	int		chars_read;
	char	*buf;

	while (!found_newline(*ptr_list))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (0);
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read < 0)
		{
			free(buf);
			return (-1);
		}
		if (chars_read == 0)
		{
			free(buf);
			return (0);
		}
		buf[chars_read] = '\0';
		add_to_list(ptr_list, buf);
	}
	return (0);
}

char	*get_line(t_list *list)
{
	char	*line_str;
	int		str_len;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	line_str = malloc((sizeof(char) * (str_len +1)));
	if (!line_str)
		return (NULL);
	cpystr_upto_newline(list, line_str);
	return (line_str);
}

char	*get_next_line(int fd)
{
	char				*line_str;
	static t_list		*list = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (create_list(&list, fd) < 0)
		return (NULL);
	if (!list)
		return (NULL);
	line_str = get_line(list);
	polish_list(&list);
	return (line_str);
}
