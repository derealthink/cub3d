#include "cub3d.h"

t_list	*create_node(char *line, t_line type)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->line = ft_strdup(line);
	if (!node->line)
	{
		free(node);
		return (NULL);
	}
	node->type = type;
    node->len = ft_strlen(line);
    node->valid = 0;
	node->next = NULL;
	return (node);
}

void	add_to_list(t_list **head, t_list *new_node)
{
	t_list	*tmp;

	if (!head || !new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

t_line	line_type(char *line)
{
	if (!line)
		return (MAP_LINE);
	if (ft_strncmp(line, "NO ", 3) == 0 ||
		ft_strncmp(line, "SO ", 3) == 0 ||
		ft_strncmp(line, "EA ", 3) == 0 ||
		ft_strncmp(line, "WE ", 3) == 0)
		return (ID_LINE);
	if (ft_strncmp(line, "C ", 2) == 0 ||
		ft_strncmp(line, "F ", 2) == 0)
		return (C_LINE);
	return (MAP_LINE);
}

t_list	*parse_to_list(char *file)
{
	char	**map;
	t_list	*head;
	t_list	*node;
	int		i;
	t_line	type;

	map = call_map(file);
	if (!map)
		return (NULL);
	map = prep_id(map);
	if (!map)
		return (NULL);
	head = NULL;
	i = 0;
	while (map[i])
	{
		type = line_type(map[i]);
		node = create_node(map[i], type);
		if (!node)
		{
			free_map(map);
            free_list(head);
			return (NULL);
		}
		add_to_list(&head, node);
		i++;
	}
	free_map(map);
	return (head);
}



