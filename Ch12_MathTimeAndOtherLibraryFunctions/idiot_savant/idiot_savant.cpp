#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>

std::string input_str;

int prompt_month() {
    const static std::unordered_map<std::string, int> month_dict{
        {"january", 1},   {"jan", 1},       {"1", 1},        {"february", 2},
        {"feb", 2},       {"2", 2},         {"march", 3},    {"mar", 3},
        {"3", 3},         {"april", 4},     {"apr", 4},      {"4", 4},
        {"may", 5},       {"5", 5},         {"june", 6},     {"jun", 6},
        {"6", 6},         {"july", 7},      {"jul", 7},      {"7", 7},
        {"august", 8},    {"aug", 8},       {"8", 8},        {"september", 9},
        {"sep", 9},       {"9", 9},         {"october", 10}, {"oct", 10},
        {"10", 10},       {"november", 11}, {"nov", 11},     {"11", 11},
        {"december", 12}, {"dec", 12},      {"12", 12}};

    std::string a_month = "";
    std::cout << "Enter a month from 1 - 12, \"Jan\" to \"Dec\", or "
              << std::endl
              << "\"January\" to \"December\": ";
    std::cin >> a_month;
    std::transform(a_month.begin(), a_month.end(), a_month.begin(), ::tolower);
    auto got = month_dict.find(a_month);
    if (got != month_dict.end()) {
        return got->second;
    } else {
        std::cout << "\"" << a_month << "\" is not a valid month. Try again."
                  << std::endl;
        return -1;
    }
}

int main() {
    int a_year = 0;
    int month_number = 0;
    int a_day = 1;

    do {
        std::cout << "Enter a year from 1900 onward: ";
        std::cin >> a_year;
        month_number = prompt_month();
        if (month_number == -1) {
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