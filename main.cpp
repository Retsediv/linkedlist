#include <iostream>
#include "Node.hpp"
#include "List.hpp"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
//    List<int> l{};
//    l.push_back(5);

    vector<int> a{1, 2, 3};
    std::cout << distance(a.begin(), a.end()) << std::endl;
    std::cout << distance(a.end(), a.begin()) << std::endl;
    return 0;
}