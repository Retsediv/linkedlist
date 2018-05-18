#include <iostream>
#include "Node.hpp"
#include "List.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    List<int> l{};
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    cout << distance(l.begin(), l.end()) << endl;

//    auto lend = remove_if(l.begin(), l.end(), [](Node<int> *n){ return n->getValue() % 2 == 0; });
//    auto lend = remove_if(l.begin(), l.end(), [](Node<int> *n){ return true; });
//    cout << distance(l.begin(), lend) << endl;

    return 0;
}