set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
set(PROJECT_ID helloworld)

project(${PROJECT_ID} VERSION ${PROJECT_VESRION})

add_subdirectory(bin)
add_subdirectory(lib)
add_subdirectory(boost_tests)
add_subdirectory(gtests)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/lib/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/lib/version.h)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
