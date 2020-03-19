#ifndef CPCS_RUNTIME_H
# define CPCS_RUNTIME_H 1

typedef enum
{
    CPCS_STRING,
    CPCS_INTEGER
} cpcs_type_t;

typedef struct
{
    cpcs_type_t    type;
    union
    {
        char    *str;
        int     nb;
    }           val;
} cpcs_value_t;

typedef struct cpcs_variable_s
{
    char                    *identifier;
    cpcs_value_t           value;
    struct cpcs_variable_s *next;

} cpcs_variable_t;


int cpcs_init(int, char **);

void    cpcs_push_to_context(cpcs_variable_t *, cpcs_variable_t *);
void    cpcs_push_to_global_context(cpcs_variable_t *);
cpcs_variable_t *cpcs_get_from_context(cpcs_variable_t *, const char *);
cpcs_variable_t *cpcs_get_from_global(const char *);

void cpcs_cls(void);

#endif /* !CPCSC_RUNTIME_H */