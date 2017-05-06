cmake_minimum_required(VERSION 3.7)
project(CppftI)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Ch01_CppFundamentals/adding_machine/adding_machine.cpp
        Ch01_CppFundamentals/calculating_phi/calculating_phi.cpp
        Ch02_Data/type_promotion/type_promotion.cpp
        Ch03_Operators/binary_printout/binary_printout.cpp
        Ch03_Operators/integer_printout/integer_printout.cpp
        Ch03_Operators/reverse_binary_printout/reverse_binary_printout.cpp
        Ch04_ControlStructures/computer_guesses_the_number/computer_guesses_the_number.cpp
        Ch04_ControlStructures/guess_the_number_game/guess_the_number_game.cpp
        Ch05_Functions/odds_at_dice/odds_at_dice.cpp
        Ch05_Functions/print_ints/print_ints.cpp
        Ch06_PointersArraysAndReferences/sieve/sieve.cpp
        Ch07_ClassesAndObjects/packed_boolean/packed_boolean.cpp
        Ch09_CreatingAndUsingTemplates/type_promotion_2/type_promotion_2.cpp)

add_library(Pack_bool STATIC
        Ch07_ClassesAndObjects/packed_boolean/Pack_bool.cpp Ch07_ClassesAndObjects/packed_boolean/Pack_bool.hpp)

add_executable(adding_machine Ch01_CppFundamentals/adding_machine/adding_machine.cpp)
add_executable(calculating_phi Ch01_CppFundamentals/calculating_phi/calculating_phi.cpp)
add_executable(type_promotion Ch02_Data/type_promotion/type_promotion.cpp)
add_executable(binary_printout Ch03_Operators/binary_printout/binary_printout.cpp)
add_executable(integer_printout Ch03_Operators/integer_printout/integer_printout.cpp)
add_executable(reverse_binary_printout Ch03_Operators/reverse_binary_printout/reverse_binary_printout.cpp)
add_executable(computer_guesses_the_number
        Ch04_ControlStructures/computer_guesses_the_number/computer_guesses_the_number.cpp)
add_executable(guess_the_number_game Ch04_ControlStructures/guess_the_number_game/guess_the_number_game.cpp)
add_executable(odds_at_dice Ch05_Functions/odds_at_dice/odds_at_dice.cpp)
add_executable(print_ints Ch05_Functions/print_ints/print_ints.cpp)
add_executable(sieve Ch06_PointersArraysAndReferences/sieve/sieve.cpp)
add_executable(packed_boolean Ch07_ClassesAndObjects/packed_boolean/packed_boolean.cpp)
target_link_libraries(packed_boolean PRIVATE Pack_bool)
add_executable(bit_sieve Ch07_ClassesAndObjects/packed_boolean/bit_sieve.cpp)
target_link_libraries(bit_sieve PRIVATE Pack_bool)
add_executable(type_promotion_2 Ch09_CreatingAndUsingTemplates/type_promotion_2/type_promotion_2.cpp)
add_executable(idiot_savant Ch12_MathTimeAndOtherLibraryFunctions/idiot_savant/idiot_savant.cpp)
