include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/../src)

# 让 reverse_w 编译 main + uniTest + demo(如果 main 用到)
add_executable(reverse_w
    main.cpp
    uniTest.cpp
)

target_link_libraries(reverse_w algo)

# conv 还是保持原样
add_executable(conv demo.cpp)
target_link_libraries(conv algo)

