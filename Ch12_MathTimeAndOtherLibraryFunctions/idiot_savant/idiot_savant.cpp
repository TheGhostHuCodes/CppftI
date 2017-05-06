#include <ctime>
#include <iostream>
#include <string>

std::string input_str;

int main() {
    int a_year = 0;
    int a_month = 0;
    int a_day = 1;

    do {
        std::cout << "Enter a year from 1900 onward: ";
        std::cin >> a_year;
        std::cout << "Enter a month from 1 to 12: ";
        std::cin >> a_month;
        std::cout << "Enter a day of the month, from 1 to 31: ";
        std::cin >> a_day;

        tm the_day;
        the_day.tm_mday = a_day;
        the_day.tm_mon = a_month - 1;
        the_day.tm_year = a_year - 1900;
        the_day.tm_hour = 12;
        the_day.tm_min = 0;
        the_day.tm_sec = 0;

        time_t this_time = mktime(&the_day);
        if (this_time != -1) {
            char date_str[256];
            char format_str[] = "The day is %A, %d %B, %Y.";
            strftime(date_str, 256, format_str, &the_day);
            std::cout << date_str << std::endl;
        } else {
            std::cout << "Sorry. Invalid date." << std::endl;
        }
        std::cout << "I'm an excellent driver...";
        std::cout << "Do again? (Enter Y or N.)";
        std::cin >> input_str;
        if (input_str[0] != 'Y' && input_str[0] != 'y') {
            break;
        }

    } while (true);
    return 0;
}