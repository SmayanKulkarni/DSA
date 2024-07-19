#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> my_map;
    pair<string, int> p("abc", 1);
    my_map.insert(p);
    my_map["def"] = 2; // like array
    cout << my_map["def"] << endl;
    cout << my_map.at("abc") << endl;

    // check presence of a key
    if (my_map.count("ghi") > 0)
        cout << "Key is present" << endl;
    else
        cout << "not Present" < endl;

    // updating value
    my_map["def"] = 3;
    cout << my_map["def"] << endl;

    // size

    cout << my_map.size() << endl;
}