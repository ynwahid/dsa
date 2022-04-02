// Implementation of Map in Cpp
// Source: https://www.youtube.com/watch?v=7mwgA9XFIEQ&t=61s
#include <iostream>
#include <map>

using namespace std;

int main(){
    string test = "Hello world my name is tim! ttthhaaa";
    char letter;
    char max_key;
    int max_val = 0;
    map<char, int> freq;

    for (int i = 0; i < test.size(); ++i) {
        letter = test[i];
        
        if (freq.find(letter) == freq.end()) {
            freq[letter] = 0;
        }

        freq[letter]++;
    }

    for (auto const& itr : freq) {
        cout << itr.first << ": " << itr.second << endl;

        if (itr.first != ' ' && itr.second > max_val) {
            max_key = itr.first;
            max_val = itr.second;
        }
    }

    cout << "Max is char " << max_key << ": " << max_val << endl;

    return 0;
}