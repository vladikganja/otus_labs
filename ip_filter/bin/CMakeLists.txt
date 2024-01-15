set(PROJECT_ID ip_filter)

project(${PROJECT_ID} VERSION ${PROJECT_VESRION})

add_executable(${PROJECT_ID} main.cpp)

configure_file(ip_filter.txt ip_filter.txt COPYONLY)

set_target_properties(${PROJECT_ID} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_compile_options(${PROJECT_ID} PRIVATE
    -Wall -Wextra -pedantic -Werror
)
