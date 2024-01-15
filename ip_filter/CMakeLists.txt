option(LOCAL_INPUT "Enable local txt input" OFF)
if(LOCAL_INPUT)
    add_compile_definitions(LOCAL_INPUT)
endif()

add_subdirectory(bin)
