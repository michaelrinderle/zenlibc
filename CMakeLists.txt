cmake_minimum_required (VERSION 3.8)

project (zenlibc)

if (WIN32)
    # ignore cross platform code
    add_definitions("-D_CRT_SECURE_NO_WARNINGS")
    add_definitions("-D_CRT_SCL_SECURE_NO_WARNINGS")
    add_definitions("-D_CRT_SECURE_NO_DEPRECATE")
    add_definitions("-D_CRT_NONSTDC_NO_DEPRECATE")
endif(WIN32)

# Include sub-projects.
add_subdirectory("src")
add_subdirectory("test")

# add external dependecies
add_subdirectory("external/gtest")