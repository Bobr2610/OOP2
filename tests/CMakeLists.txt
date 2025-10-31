add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests decimal_lib gtest_main)
set_property(TARGET unit_tests PROPERTY CXX_STANDARD 17)

include(GoogleTest)
gtest_discover_tests(unit_tests)
