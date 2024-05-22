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
)
