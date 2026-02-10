#include "parsing.h"
#include "configuration.h"

int validate_all(t_valid *d, t_ulines *head)
{
    if (!val_txt_count(head, d))
        return (0);
    if (!val_cc_count(head, d))
        return (0);
    if (!is_dig_cc(head))
        return (0);
    if (!val_mp_count(head))
        return (0);
    if (!is_first_val(head))
        return (0);
    if (!is_last_val(head))
        return (0);
    if (!is_fline_val(head))
        return (0);
    if (!is_first_last_mapline_val(head))
        return (0);
    return (1);
}

int caller_id(t_ulines *head, t_config *id)
{
    if (!no_config(head, id) || !so_config(head,id) || 
    !ea_config(head, id) || !we_config(head, id))
    {
        perror(": Texture error");
        return (0);
    }
    if (!cc_config(head, id) || !cf_config(head, id))
    {
        perror(": Color error");
        return (0);
    }
    return (1);
}

int list_to_struct(char *filename, t_data *game)
{
    t_ulines    *head;
    t_valid     d;

    ft_bzero(&d, sizeof(t_valid));
    init_config(game->id);
    head = parse_to_list(filename);
    if (!head)
        return (0);
    if (!validate_all(&d, head))
    {
        free_list(head);
        return (0);
    }
    if (!caller_id(head, game->id))
        return (0);//needs a free for all here?
    prep_pad(head);
    game->map = map_config(game, head);
    if (!game->map)
    {
        free_list(head);
        return (0);
    }
    free_list(head);
    return (1);
}


