cmake_minimum_required(VERSION 4.0.0)
project(OOP_LAB_2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(code)
add_subdirectory(tests)

