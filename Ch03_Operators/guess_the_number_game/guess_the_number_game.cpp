#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    srand(time(nullptr));
    bool play_more = true;
    int target = 0;
    int guess = 0;

    while (play_more) {
        target = 1 + rand() % 50;
        while (true) {
            std::cout << "Guess the number, or 0 to quit: ";
            std::cin >> guess;
            if (guess == 0) {
                play_more = false;
                break;
            } else if (guess == target) {
                std::cout << "CORRECT!!! Number is " << target << "!"
                          << std::endl;
                std::cout << "Let's play again!" << std::endl;
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
