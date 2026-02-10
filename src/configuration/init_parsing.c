#include "configuration.h"
void    init_config(t_config *id)
{
    id->no = NULL;
    id->so = NULL;
    id->ea = NULL;
    id->we = NULL;
    id->cc = NULL;
    id->cf = NULL;
}

void    init_ulines(t_ulines *list)
{
    list->line = NULL;
    list->type = 0;
    list->next = NULL;
    list->pad = 0;
    list->max = 0;
}

void    init_valid(t_valid *d)
{
    d->no = 0;
    d->so = 0;
    d->ea = 0;
    d->we = 0;
    d->cc = 0;
    d->cf = 0;
}

