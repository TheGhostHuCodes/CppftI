#include <iostream>

double calc_roll(int n);
double calc_roll_dont_pass(int n);

int dice_totals[11] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
// Ways of rolling:    2  3  4  5  6  7  8  9  10 11 12

int main() {
    double prob_total = 0.0;
    for (int i = 2; i <= 12; ++i) {
        prob_total += calc_roll(i);
    }
    double dont_pass_prob_total = 0.0;
    for (int i = 2; i <= 11; ++i) {
        dont_pass_prob_total += calc_roll_dont_pass(i);
    }
    std::cout << "Total probability of winning: ";
    std::cout << prob_total << std::endl;
    std::cout << "Total probability of don't pass winning: ";
    std::cout << dont_pass_prob_total << std::endl;
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

// Return the probability of rolling n AND winning on a don't pass bet.
double calc_roll_dont_pass(int n) {
    double d = dice_totals[n - 2];
    // bar 12 means we don't play on a 12 roll.
    double prob_roll = d / 35.0;

    switch (n) {
    case 2:
    case 3:
        // Win!
        return prob_roll;
        break;
    case 7:
    case 11:
        // Loose :(
        return 0;
        break;
    default:
        // Win if the shooter doesn't make point.
        // The probability of "don't pass" winning given a certain "point":
        // This is equal to 6/(d+6), where d = number of ways to roll the
        // point, and 6 = number of ways to roll 7.
        double prob_miss_point = 6.0 / (d + 6.0);
        return prob_roll * prob_miss_point;
        break;
    }
}
