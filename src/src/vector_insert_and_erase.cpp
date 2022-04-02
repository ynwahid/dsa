// Implementation Vector in Cpp
// Source: https://www.youtube.com/watch?v=RXzzE2wnnlo
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1 = {1, 2, 3, 4};
    v1.insert(v1.begin(), 5);
    v1.insert(v1.begin(), 7);
    v1.insert(v1.begin() + 3, 9);
    cout << v1[3] << endl;

    cout << "Vector:" << endl;
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }

    cout << endl;
    
    cout << "Vector:" << endl;
    for (auto itr = v1.begin(); itr != v1.end(); ++itr) {
        cout << *itr << " ";
    }

    cout << endl;
    
    cout << "Vector:" << endl;
    for (auto const& itr : v1) {
        cout << itr << " ";
    }
}