set(ProjectId helloworld_cli)
project(${ProjectId})

find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(${ProjectId} main.cpp)

install(TARGETS ${ProjectId} RUNTIME DESTINATION bin)

set_target_properties(${ProjectId} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(${ProjectId} PRIVATE
    Boost::program_options
    helloworld
)

target_compile_options(${ProjectId} PRIVATE
    -Wall -Wextra -pedantic -Werror
)
