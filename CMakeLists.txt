cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(main VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/CMakeInstall")
set(PROJECT_BINARY_DIR "${PROJECT_SOURCE_DIR}/build")

# Specify the build type on single-configuration generators.
set(CMAKE_BUILD_TYPE "Debug") 

# Specify flags used by the CXX compiler during all build types.
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -static-libgcc -fexec-charset=GBK")

# add include path
include_directories("${PROJECT_SOURCE_DIR}/include")

# add the mylib library
add_subdirectory(library)

# add the executable
add_executable(main main.cxx)
target_link_libraries(main PUBLIC mylib)

# add the binary tree to the search path for include files
# so that we will find mainConfig.h
target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

# enable testing
include(CTest)

# does the application run
add_test(NAME Runs COMMAND main --author)

# does the usage message work?
add_test(NAME Usage COMMAND main --help)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "[-h]"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# do a bunch of result based tests
do_test(main --version "version")
