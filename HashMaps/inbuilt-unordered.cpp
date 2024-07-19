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
}