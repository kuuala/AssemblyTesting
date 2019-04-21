cmake_minimum_required(VERSION 3.12)

project(AssemblyTesting)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

add_executable(tester tester/main.cpp tester/assembly.cpp tester/assembly.h tester/levenshtein.cpp tester/levenshtein.h tester/sequencing.cpp tester/sequencing.h tester/utility.cpp tester/utility.h)

add_executable(example commis_voyager/simulated_annealing.cpp commis_voyager/simulated_annealing.h commis_voyager/main.cpp)
