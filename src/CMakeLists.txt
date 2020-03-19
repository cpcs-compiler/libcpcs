set (SRCS
    init.c
    context.c
    utils.c
)

add_library (objlib OBJECT ${SRCS})
set_property (TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE ON)

if ("${CMAKE_C_COMPILER}" MATCHES "cl")
    target_compile_options (objlib PRIVATE /WX /W3)
else ("${CMAKE_C_COMPILER}" MATCHES "cl")
    target_compile_options (objlib PRIVATE -Werror -Wall -Wextra)
endif ("${CMAKE_C_COMPILER}" MATCHES "cl")

if (BUILD_SHARED)
    add_library(libcpcs_runtime SHARED $<TARGET_OBJECTS:objlib>)
endif (BUILD_SHARED)

if (BUILD_STATIC)
    add_library (libcpcs_runtime-static STATIC $<TARGET_OBJECTS:objlib>)
endif (BUILD_STATIC)