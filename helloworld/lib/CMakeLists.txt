set(ProjectId helloworld)
project(${ProjectId})

add_library(${ProjectId} lib.cpp)

set_target_properties(${ProjectId} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${ProjectId}
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_compile_options(${ProjectId} PRIVATE
    -Wall -Wextra -pedantic -Werror
)
