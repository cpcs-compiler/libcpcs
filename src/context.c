#include <stdlib.h>
#include <string.h>
#include <cpcs/cpcs_runtime.h>
#include <cpcs/internal.h>

static cpcs_variable_t *global_context = NULL;

void    cpcs_push_to_context(cpcs_variable_t *ctx, cpcs_variable_t *var)
{
    cpcs_variable_t *tmp;

    if (ctx == NULL) return;
    for (tmp = ctx; tmp->next != NULL; tmp = tmp->next);
    tmp->next = var;
}

void    cpcs_push_to_global_context(cpcs_variable_t *var)
{
    if (global_context == NULL)
    {
        global_context = var;
        return;
    }
    cpcs_push_to_context(global_context, var);
}

cpcs_variable_t *cpcs_get_from_context(cpcs_variable_t *ctx, const char *indent)
{
    cpcs_variable_t *tmp;

    for (tmp = ctx; tmp != NULL; tmp = tmp->next)
    {
        if (cpcs_strcasecmp(indent, tmp->identifier) == 0)
            return (tmp);
    }
    return (NULL);
}

cpcs_variable_t *cpcs_get_from_global(const char *indent)
{
    return (cpcs_get_from_context(global_context, indent));
}