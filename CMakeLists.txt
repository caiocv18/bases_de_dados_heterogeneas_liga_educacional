cmake_minimum_required(VERSION 3.28)
project(bases_de_dados_heterogeneas_liga_educacional C)

set(CMAKE_C_STANDARD 23)

add_executable(bases_de_dados_heterogeneas_liga_educacional syntax/main.c
        syntax/sample_union.c
        syntax/data_types.c
        syntax/control_structures.c
        syntax/functions_1.c
        syntax/functions_2.c
        syntax/scan_and_print.c
        syntax/arrays.c
        syntax/sample_struct.c
        phase_1/recursion/simple_sample.c
        phase_1/recursion/fibonacci.c
        phase_1/recursion/binary_tree.c
        phase_1/recursion/graph.c
        phase_1/recursion/linked_list.c
        phase_1/pointers/understanding_pointers.c
        phase_1/pointers/array_and_pointers_1.c
        phase_1/pointers/array_and_pointers_2.c
        phase_1/pointers/understanding_pointer_arithmetic.c
        phase_1/pointers/increment_and_decrement_of_pointers.c
        phase_1/pointers/addition_and_subtraction_with_pointers.c
        phase_1/pointers/practical_effects_of_pointer_arithmetic.c
        phase_1/pointers/manipulating_strings_with_pointers.c
        phase_1/pointers/string_functions_using_pointers.c
        phase_1/pointers/advantages_of_using_pointers_in_strings.c
        phase_1/pointers/passing_pointers_to_functions.c
        phase_1/pointers/advantages_of_the_ponteiros_pass.c
        phase_1/pointers/considerations_about_passing_pointers.c
        phase_1/pointers/concept_of_pointers_to_pointers.c
        phase_1/pointers/uses_of_pointers_for_pointers.c
        phase_1/pointers/benefits_of_pointers_for_pointers.c
        phase_1/pointers/dynamic_allocation/learning_malloc.c
        phase_1/pointers/dynamic_allocation/learning_calloc.c
        phase_1/pointers/dynamic_allocation/learning_realloc.c
        phase_1/pointers/dynamic_allocation/learning_free.c
        phase_1/pointers/dynamic_allocation/practical_examples_of_memory_allocation_and_release.c
        phase_1/study_case/study_case.c
        phase_2/list.c
        phase_2/stack.c
        phase_2/queue.c
        phase_2/linear_list.c
        phase_2/bubble_sort.c
        phase_2/bubble_sort_linked_list.c
        phase_2/bubble_sort_double_linked_list.c
        phase_2/selection_sort.c
        phase_2/insertion_sort.c
        phase_2/merge_sort.c
        phase_2/quick_sort.c
        phase_2/heap_sort.c
)
