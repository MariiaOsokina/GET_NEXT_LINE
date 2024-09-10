/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosokina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:36:17 by mosokina          #+#    #+#             */
/*   Updated: 2024/05/15 16:36:25 by mosokina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int		found_newline(t_list	*list);
int		len_to_newline(t_list *list);
void	cpystr_upto_newline(t_list	*list, char *line_str);
t_list	*find_last_node(t_list *list);
void	dealloc(t_list	*saved_node, t_list	**ptr_list, char *saved_str);
void	polish_list(t_list	**ptr_list);
void	add_to_list(t_list **ptr_list, char *buf);
int		create_list(t_list	**ptr_list, int fd);
char	*get_line(t_list *list);

#endif
