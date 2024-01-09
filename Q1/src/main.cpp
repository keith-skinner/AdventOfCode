#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <algorithm>

using namespace std;

int main()
{
    uint64_t line_num = 1;
    uint64_t total = {};
    std::ifstream input("input.txt");
    std::string line;
    while (std::getline(input, line))
    {
        constexpr auto isdigit = [](const char c) {return '0' <= c && c <= '9'; };
        auto tens = find_if(begin(line), end(line), isdigit);
        auto ones = find_if(rbegin(line), rend(line), isdigit);
        if (tens != end(line) && ones != rend(line))
        {
            auto value = 10 * (*tens - '0') + (*ones - '0');
            cout << line_num << ": " << value << endl;
            total += value;
        }
        else cout << line_num << " no number" << endl;
        ++line_num;
    }

    cout << total << endl;
}