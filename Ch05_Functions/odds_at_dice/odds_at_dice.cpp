#include <iostream>

double calc_roll(int n);

int dice_totals[11] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
// Ways of rolling:    2  3  4  5  6  7  8  9  10 11 12

int main() {
    double prob_total = 0.0;
    for (int i = 2; i <= 12; ++i) {
        prob_total += calc_roll(i);
    }
    std::cout << "Total probability of winning: ";
    std::cout << prob_total;
    return 0;
}

// Return the probability of rolling n AND going on to win the game. In the
// case of 7 and 11, this is just the probability of rolling the number.
double calc_roll(int n) {
    double d = dice_totals[n - 2];
    double prob_roll = d / 36.0;

    switch (n) {
    case 2:
    case 3:
    case 12:
        // Loose :(
        return 0;
        break;
    case 7:
    case 11:
        // Win!
        return prob_roll;
        break;
    default:
        // Win if you make point.
        // The probability of winning given a certain "point": This is equal to
        // d/(d+6), where d = number of ways to roll the point, and 6 = number
        // of ways to roll 7.
        double prob_make_point = d / (d + 6.0);
        return prob_roll * prob_make_point;
        break;
    }
}
