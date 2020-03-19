#include <stdlib.h>
#include <assert.h>
#include <cpcs/cpcs_runtime.h>

void test_cpcs_get_from_global_null(void)
{
    cpcs_variable_t *val;

    val = cpcs_get_from_global("test");
    assert(val == NULL);
}

void test_cpcs_get_from_context_null(void)
{
    cpcs_variable_t *val;

    val = cpcs_get_from_context(NULL, "test");
    assert(val == NULL);
}

void test_cpcs_get_from_context_with_data(void)
{
    cpcs_variable_t *val;
    cpcs_variable_t ctx;

    ctx.identifier = "test";
    ctx.next = NULL;

    val = cpcs_get_from_context(&ctx, "tEst");
    
    assert(val != NULL);
    assert(val == &ctx);
}

int main(void)
{
    test_cpcs_get_from_global_null();
    test_cpcs_get_from_context_null();
    test_cpcs_get_from_context_with_data();

    return (0);
}