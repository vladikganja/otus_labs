set(ProjectId boost_tests)
project(${ProjectId})

# BOOST #######################################################################

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(${ProjectId}
    boost_test.cpp
)
set_target_properties(${ProjectId} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
set_target_properties(${ProjectId} PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)
target_link_libraries(${ProjectId}
    Boost::unit_test_framework
    helloworld
)
target_compile_options(${ProjectId} PRIVATE
    -Wall -Wextra -pedantic -Werror
)

enable_testing()
add_test(NAME boostTest COMMAND boost_tests)
