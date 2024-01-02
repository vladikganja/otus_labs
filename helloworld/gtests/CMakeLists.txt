set(ProjectId gtests)
project(${ProjectId})

# GTEST #######################################################################

add_executable(${ProjectId}
    gtest.cpp
)
set_target_properties(${ProjectId} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
target_link_libraries(${ProjectId}
    gtest
    gtest_main
    helloworld
)
target_compile_options(${ProjectId} PRIVATE
    -Wall -Wextra -pedantic -Werror
)

include_directories("../../3rdparty/googletest/googletest/include")
