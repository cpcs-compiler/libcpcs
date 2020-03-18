set (SRCS
    init.c
)

add_library (objlib OBJECT ${SRCS})
set_property (TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE ON)

if (BUILD_SHARED)
    add_library(libcpcs_runtime SHARED $<TARGET_OBJECTS:objlib>)
endif (BUILD_SHARED)

if (BUILD_STATIC)
    add_library (libcpcs_runtime-static STATIC $<TARGET_OBJECTS:objlib>)
endif (BUILD_STATIC)