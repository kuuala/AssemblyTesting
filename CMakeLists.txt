cmake_minimum_required(VERSION 3.12)
project(AssemblyTesting)

set(CMAKE_CXX_STANDARD 14)

add_executable(AssemblyTesting main.cpp assembly.cpp assembly.hpp levenshtein.cpp levenshtein.hpp sequencing.cpp sequencing.hpp simulated_annealing.cpp simulated_annealing.hpp)