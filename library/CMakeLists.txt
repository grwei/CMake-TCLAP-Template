# Find all source files in a directory.
aux_source_directory(. LIB_SRCS)

# add the library that runs
add_library(mylib ${LIB_SRCS})

# state that anybody linking to us needs to include the current source dir
# to find *.h, and we also need to.
target_include_directories(mylib
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                           )
