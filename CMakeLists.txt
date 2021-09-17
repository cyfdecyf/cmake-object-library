cmake_minimum_required(VERSION 3.0)

project(object-library-test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# Create Object Library，note the OBJECT keyword here.
add_library(obj OBJECT lib1.cc lib2.cc)
# This compile options only apply to source files of obj target.
# They are not propagated to targets that link to this target.
#target_compile_options(obj PUBLIC -fPIC)

add_executable(a a.cc $<TARGET_OBJECTS:obj>)
# This compile option only applies to a.cc
target_compile_options(a PUBLIC -O2)

add_executable(b b.cc $<TARGET_OBJECTS:obj>)
# This compile option only applies to b.cc
target_compile_options(b PUBLIC -O3 -ggdb)


# Compare with static library.
# If liblib1 and liblib2.a is not used for other projects, then these two lib is
# useless.
add_library(lib1 STATIC lib1.cc)
add_library(lib2 STATIC lib2.cc)

# lib1, lib2 has circular dependency. Correct ordering in link command is
# important for successful linking.
add_executable(a1 a.cc)
# Following order will fail, must switch the order of lib1 and lib2.
target_link_libraries(a1 lib2 lib1)
# Or specify lib2 multiple times. This is sometimes necessary.
#target_link_libraries(a1 lib2 lib1 lib2)

add_executable(b1 b.cc)
# Following order will fail, must switch the order of lib1 and lib2.
target_link_libraries(b1 lib1 lib2)
# Or specify lib1 multiple times. This is sometimes necessary.
#target_link_libraries(a1 lib2 lib1 lib2 lib1)
