#include <iostream>
#include <string>

int main() {
    int lower_bound;
    int upper_bound;
    int n = 1;
    int cmd = 1;
    bool play_again = false;

    do {
        lower_bound = 1;
        upper_bound = 50;
        std::cout << "Think of a number from 1 to 50." << std::endl;
        std::cout << "Then press ENTER.";
        std::cin.ignore();
        bool guess_again = true;
        do {
            n = static_cast<int>((lower_bound + upper_bound) / 2.0);
            std::cout << "I guess " << n << "." << std::endl;
            std::cout
                << "Respond: 1=Correct! 2=Guess was too low! 3=Guess was too "
                   "high! ENTER =>";
            std::cin >> cmd;
            if (cmd == 1) {
                std::cout << "Yay! I got it right!" << std::endl;
                guess_again = false;
            } else if (cmd == 3) {
                upper_bound = n - 1;
            } else {
                lower_bound = n + 1;
            }
        } while (guess_again);
        std::cout << "Play again? 1=Yes 2=No. ENTER:";
        std::cin >> cmd;
        if (cmd == 1) {
            play_again = true;
        }
    } while (play_again);
    return 0;
}
