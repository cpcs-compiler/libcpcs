#include <assert.h>
#include <cpcs/internal.h>

void    test_cpcs_strcasecmp_same_ptr(void)
{
    const char *str;
    int res;

    str = "Hello world";
    res = cpcs_strcasecmp(str, str);

    assert(res == 0);
}

void    test_cpcs_strcasecmp_case(void)
{
    const char *s1;
    const char *s2;
    int res;

    s1 = "HeLlO wOrLd";
    s2 = "hello world";
    res = cpcs_strcasecmp(s1, s2);
    
    assert(res == 0);
}

void    test_cpcs_strcasecmp_differ(void)
{
    const char *s1;
    const char *s2;
    int res;

    s1 = "Hello";
    s2 = "World";
    res = cpcs_strcasecmp(s1, s2);

    assert(res != 0);
}

int main(void)
{
    test_cpcs_strcasecmp_same_ptr();
    test_cpcs_strcasecmp_case();
    test_cpcs_strcasecmp_differ();

    return (0);
}