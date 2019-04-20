cmake_minimum_required(VERSION 3.12)
project(AssemblyTesting)

set(CMAKE_CXX_STANDARD 14)

add_executable(AssemblyTesting main.cpp assembly.cpp assembly.h levenshtein.cpp levenshtein.h sequencing.cpp sequencing.h simulated_annealing.cpp simulated_annealing.h utility.cpp utility.h)