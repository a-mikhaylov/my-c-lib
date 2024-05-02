cmake_minimum_required(VERSION 3.0.0)
project(mycpplibtest VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_library(mycpplibtest SHARED shapes_lib1.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


install(
    TARGETS mycpplibtest DESTINATION bin
)
    
install(
    FILES shapes.h DESTINATION include 
)

# file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
