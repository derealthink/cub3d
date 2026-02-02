#include "cub3d.h"

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

int caller_id(t_ulines *head, t_valid *d, t_config *id)
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


