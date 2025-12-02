set(SRC reverse_words.cpp
        linked_list.cpp
        binary_tree_level_order.cpp
        power.cpp
        points_k_closest.cpp
        max_subarray.cpp
        two_sum.cpp
        add_two_numbers.cpp
        lru_cache.cpp
        three_sum.cpp
        matrix01.cpp
        longest_substring.cpp
        kth_smallest_elements.cpp
        valid_parentheses.cpp
        interval_inserter.cpp
        queue_with_two_stacks.cpp
        merge_two_sorted_lists.cpp
        ransom_note.cpp
        string_replacer.cpp)   # ✅ 删除 mat.cpp

add_library(algo STATIC ${SRC})

# 允许 mat.h 包含 Mat.tpp
target_include_directories(algo PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
)
target_link_libraries(algo)

