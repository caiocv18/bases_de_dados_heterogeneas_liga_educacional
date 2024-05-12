cmake_minimum_required(VERSION 3.28)
project(bases_de_dados_heterogeneas_liga_educacional C)

set(CMAKE_C_STANDARD 23)

add_executable(bases_de_dados_heterogeneas_liga_educacional main.c
        sample_union.c
        data_types.c
        control_structures.c
)
