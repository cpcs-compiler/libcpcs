#include <assert.h>
#include <cpcs/cpcs_runtime.h>

void test_cpcs_get_from_global_null(void)
{
    cpcs_variable_t *val;

    val = cpcs_get_from_global("test");
    assert(val == NULL);
}

int main(void)
{
    test_cpcs_get_from_global_null();
    return (0);
}