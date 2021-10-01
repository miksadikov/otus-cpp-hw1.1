cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VESRION} LANGUAGES CXX)

configure_file(version.h.in version.h)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

file(GLOB SOURCES
    "main.cpp"
)

add_executable(ip_filter ${SOURCES})
add_library(filters filters.cpp)
add_library(ver ver.cpp)
add_executable(gtest_filters gtest_filters.cpp)

set_target_properties(ip_filter filters ver gtest_filters PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(filters
    PRIVATE "${CMAKE_BINARY_DIR}"
)
target_include_directories(ver
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(gtest_filters PROPERTIES
    INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(ip_filter PRIVATE
    filters
    ver
)
target_link_libraries(gtest_filters
    ${GTEST_LIBRARIES}
    Threads::Threads
    filters
)

target_compile_options(ip_filter PRIVATE
    -Wall -Wextra -pedantic -Werror
)
target_compile_options(ver PRIVATE
    -Wall -Wextra -pedantic -Werror
)
target_compile_options(filters PRIVATE
    -Wall -Wextra -pedantic -Werror
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
