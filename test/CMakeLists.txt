include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/../src)

add_executable(reverse_w main.cpp)
target_link_libraries(reverse_w algo)

add_executable(conv demo.cpp)
target_link_libraries(conv algo)
