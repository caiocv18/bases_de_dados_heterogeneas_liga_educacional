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
        recursion/simple_sample.c
        recursion/fibonacci.c
        recursion/binary_tree.c
        recursion/graph.c
        recursion/linked_list.c
        pointers/understanding_pointers.c
        pointers/array_and_pointers_1.c
        pointers/array_and_pointers_2.c
        pointers/understanding_pointer_arithmetic.c
        pointers/increment_and_decrement_of_pointers.c
        pointers/addition_and_subtraction_with_pointers.c
        pointers/practical_effects_of_pointer_arithmetic.c
        pointers/manipulating_strings_with_pointers.c
        pointers/string_functions_using_pointers.c
        pointers/advantages_of_using_pointers_in_strings.c
        pointers/passing_pointers_to_functions.c
        pointers/advantages_of_the_ponteiros_pass.c
        pointers/considerations_about_passing_pointers.c
        pointers/concept_of_pointers_to_pointers.c
        pointers/uses_of_pointers_for_pointers.c
        pointers/benefits_of_pointers_for_pointers.c
        pointers/dynamic_allocation/learning_malloc.c
        pointers/dynamic_allocation/learning_calloc.c
)
