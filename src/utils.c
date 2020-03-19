#include <ctype.h>

int cpcs_strcasecmp(const char *s1, const char *s2)
{
    register char c1;
    register char c2;

    while (1)
    {
        c1 = *s1++;
        c2 = *s2++;
        if (tolower(c1) != tolower(c2))
            return (c1 - c2);
        if (c1 == '\0')
            return (0);
    }
}