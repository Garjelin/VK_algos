#include <iostream>
#include <string>

std::string removeAdjacentDuplicates(const std::string& s) {
    std::string result;
    for (char ch : s) {
        if (result.empty() || ch != result.back()) {
            result.push_back(ch);
        } else {
            result.pop_back();
        }
    }
    return result;
}

int main() {
    std::string input;
    std::cin >> input;
    std::string result = removeAdjacentDuplicates(input);
    std::cout << result << std::endl;
    return 0;
}
