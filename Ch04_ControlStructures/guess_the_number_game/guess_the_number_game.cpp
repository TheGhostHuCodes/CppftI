#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

int main() {
    srand(time(nullptr));
    bool play_more = true;
    int target = 0;
    int guess = 0;
    int N = 0;
    int attempts = 0;

    do {
        std::cout
            << "Please enter a positive value of N to play the game with. "
               "Numbers will be chosen between 1 and N: "
            << std::endl;
        std::cin >> N;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (N <= 0);
    std::cout << "You should be able to guess the answer in "
              << static_cast<int>(log(N) / log(2)) + 1 << " guesses or less."
              << std::endl;

    while (play_more) {
        target = 1 + rand() % N;
        while (true) {
            std::cout << "Guess the number, or 0 to quit: ";
            std::cin >> guess;
            if (guess == 0) {
                play_more = false;
                break;
            }

            ++attempts;
            if (guess == target) {
                std::cout << "CORRECT!!! Number is " << target << "!"
                          << std::endl;
                std::cout << "It only took you " << attempts << " guesses."
                          << std::endl;
                std::cout << "Let's play again!" << std::endl;
                attempts = 0;
                break;
            } else if (guess < target) {
                std::cout << "Too low! Try again!" << std::endl;
            } else {
                std::cout << "Too high! Try again!" << std::endl;
            }
        }
    }
    return 0;
}
