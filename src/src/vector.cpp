// Implementation Vector in Cpp
// Source: https://www.youtube.com/watch?v=RXzzE2wnnlo
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3, 4};
    cout << v1.front() << endl;
    cout << v1.size() << endl;
    v1.push_back(9);
    v1.push_back(9);
    v1.push_back(9);
    v1.push_back(9);
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    v1.push_back(9);
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    v1.shrink_to_fit();
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
}