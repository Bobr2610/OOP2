add_library(decimal_lib decimal.cpp)
set_property(TARGET decimal_lib PROPERTY CXX_STANDARD 17)

add_executable(OOP_LAB_2 main.cpp)
target_link_libraries(OOP_LAB_2 decimal_lib)
set_property(TARGET OOP_LAB_2 PROPERTY CXX_STANDARD 17)
