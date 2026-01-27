#include "parsing.h"

t_ulines	*create_node(char *line, t_tline type)
{
	t_ulines	*node;

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

void	add_to_list(t_ulines **head, t_ulines *new_node)
{
	t_ulines	*tmp;

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

t_tline	line_type(char *line)
{
	if (!line)
		return (MAP_LINE);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (NO_LINE);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (SO_LINE);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (EA_LINE);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (WE_LINE);
	if (ft_strncmp(line, "CC", 2) == 0)
		return (CC_LINE);
	if (ft_strncmp(line, "CF", 2) == 0)
		return (CF_LINE);
	return (MAP_LINE);
}

t_ulines	*parse_to_list(char *file)
{
	char	**map;
	t_ulines	*head;
	t_ulines	*node;
	int		i;
	t_tline	type;

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
