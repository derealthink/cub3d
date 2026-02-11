#include "parsing.h"
#include "configuration.h"

int validate_all(t_valid *d, t_ulines *head)
{
    printf("entered val_txt_count\n");
    if (!val_txt_count(head, d))
        return (0);
    printf("entered val_cc_count\n");
    if (!val_cc_count(head, d))
        return (0);
    printf("entered is_dig_cc\n");
    if (!is_dig_cc(head))
        return (0);
    printf("enetred val_mp_count\n");
    if (!val_mp_count(head))
        return (0);
    printf("entered is_first_val\n");
    if (!is_first_val(head))
        return (0);
    printf(" entered is_last_val\n");
    if (!is_last_val(head))
        return (0);
    printf("entered is_fline_val\n");
    if (!is_fline_val(head))
        return (0);
    printf("entered is first_last_mapline_val\n");
    if (!is_first_last_mapline_val(head))
        return (0);
    return (1);
}

int caller_id(t_ulines *head, t_config *id)
{
    printf("entered caller_i\n");
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
    printf("exiting caller_id safely\n");
    return (1);
}

int list_to_struct(char *filename, t_data *game)
{
    t_ulines    *head;
    t_valid     d;

    printf("entered list to struct\n");
    init_valid(&d);
    head = parse_to_list(filename);
    if (!head)
        return (0);
    if (!validate_all(&d, head))
    {
        free_list(head);
        printf("not validated\n");
        return (0);
    }
    printf("validated parsing\n");
    if (!caller_id(head, &game->id))
        return (0);//needs a free for all here?
    prep_pad(head);
    game->map = map_config(game, head);
    printf("padded and map array created from list\n");
    if (!game->map)
    {
        free_list(head);
        return (0);
    }
    free_list(head);
    printf("lsit freed and now exiting list_to_struct\n");
    return (1);
}


