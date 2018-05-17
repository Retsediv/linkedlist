#include <iostream>
#include "Node.hpp"
#include "List.hpp"
#include <vector>
#include <iterator>

using namespace std;

int main() {
    vector<int> v{1, 2, 3};
    List<int> l{};
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

//    cout << l.begin().getPointer() << endl;
//    cout << l.end().getPointer() << endl;
//    cout << l.end().getPointer() - l.begin().getPointer() << endl;
//    cout << l.begin().getPointer() - l.end().getPointer() << endl;
//    cout << l.end().getPointer() - l.end().getPointer() << endl;

//    cout << l.begin().getPointer() << endl;
//    cout << l.end().getPointer() << endl;
//
//    cout << (++l.begin()).getPointer() << endl;
//    cout << (l.begin()).getPointer()->getRight() << endl;
//
//    cout << (++(++l.begin())).getPointer() << endl;
//    cout << (l.begin()).getPointer()->getRight()->getRight() << endl;
//
//    cout << (++(++(++l.begin()))).getPointer() << endl;
//    cout << (l.begin()).getPointer()->getRight()->getRight()->getRight() << endl;


    cout << distance(l.begin(), l.end()) << endl;
//    cout << distance(v.begin(), v.end()) << endl;
    return 0;
}