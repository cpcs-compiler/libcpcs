add_executable(test_context test_context.c)
target_link_libraries(test_context PRIVATE libcpcs_runtime-static)
add_test(NAME test_context COMMAND test_context) 

add_executable(test_utils test_utils.c)
target_link_libraries(test_utils PRIVATE libcpcs_runtime-static)
add_test(NAME test_utils COMMAND test_utils) 