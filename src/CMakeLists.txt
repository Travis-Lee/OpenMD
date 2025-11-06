set(SRC reverse_words.cpp
        linked_list.cpp
        power.cpp
        max_subarray.cpp
        two_sum.cpp
        interval_inserter.cpp
        queue_with_two_stacks.cpp
        ransom_note.cpp
        string_replacer.cpp)   # ✅ 删除 mat.cpp

add_library(algo STATIC ${SRC})

# 允许 mat.h 包含 Mat.tpp
target_include_directories(algo PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)
target_link_libraries(algo)

