#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>

std::string input_str;

int main() {
    int a_year = 0;
    std::string a_month = "";
    int month_number = 0;
    int a_day = 1;

    std::unordered_map<std::string, int> month_dict{
        {"january", 1},   {"february", 2}, {"march", 3},     {"april", 4},
        {"may", 5},       {"june", 6},     {"july", 7},      {"august", 8},
        {"september", 9}, {"october", 10}, {"november", 11}, {"december", 12}};

    do {
        std::cout << "Enter a year from 1900 onward: ";
        std::cin >> a_year;
        std::cout << "Enter a month from \"January\" to \"December\": ";
        std::cin >> a_month;
        std::transform(a_month.begin(), a_month.end(), a_month.begin(),
                       ::tolower);
        auto got = month_dict.find(a_month);
        if (got != month_dict.end()) {
            month_number = got->second;
        } else {
            std::cout << "\"" << a_month
                      << "\" is not a valid month. Try again." << std::endl;
            continue;
        }
        std::cout << "Enter a day of the month, from 1 to 31: ";
        std::cin >> a_day;

        tm the_day;
        the_day.tm_mday = a_day;
        the_day.tm_mon = month_number - 1;
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