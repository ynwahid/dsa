// Learn vector/list in Cpp
// Source: https://www.youtube.com/watch?v=T9-agjKW4PQ&list=PLzMcBGfZo4-lmGC8VW0iu6qfMHjy7gLQ3&index=16 (Tech With Tim)
#include <iostream>
#include <tuple>

using namespace std;

int main() {
    // Declare and init
    tuple <int, string> person(23, "Yusuf");
    cout << get<1>(person) << endl;
    get<1>(person) = "Ucup";
    cout << get<1>(person) << endl;

    tuple <int, char, bool, float> thing;
    thing = make_tuple(23, 'Y', true, 23.0);
    cout << get<0>(thing) << endl;
    cout << get<1>(thing) << endl;
    cout << get<2>(thing) << endl;
    cout << get<3>(thing) << endl;

    cout << tuple_size<decltype(person)>::value << endl;

    tuple <int, int> t1 = make_tuple(1, 2);
    tuple <int, int> t2 = make_tuple(3, 4);
    
    // Swap value
    t2.swap(t1);

    cout << get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    cout << get<0>(t2) << endl;
    cout << get<1>(t2) << endl;

    int x, y;

    // Decompose tuple
    tie(x, y) = t1;
    cout << x << " " << y << endl;

    // Tuple concatenation
    tuple <int, char> t3(20, 'Y');
    tuple <char, string> t4('R', "Hello world!");

    auto t5 = tuple_cat(t3, t4);
    cout << get<0>(t5) << endl;
    cout << get<1>(t5) << endl;
    cout << get<2>(t5) << endl;
    cout << get<3>(t5) << endl;
}