// Implementation of Map in Cpp
// Source: https://www.youtube.com/watch?v=7mwgA9XFIEQ&t=61s
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, int> mp = {
        {'T', 7},
        {'S', 8},
        {'a', 4}
    };
    mp['u'] = 9;
    mp.insert(pair<char, int>('j', 5));
    pair<char, int> p1('k', 11);
    mp.insert(p1);
    cout << mp['T'] << endl;
    cout << p1.first << endl;

    mp.erase(p1.first);
    cout << mp['k'] << endl;
    // cout << mp.size() << endl;
    // mp.clear();
    // cout << mp.empty() << endl;

    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first << ": " << itr->second << endl ;
    }

}