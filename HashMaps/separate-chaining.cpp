#include <bits/stdc++.h>

using namespace std;

 template <typename V>
 class MapNode{
    public:
        string key;
        V value;
        MapNode* next;

        MapNode(string key, V value){
            this->key = key;
            this->value = value;
            next = nullptr;
        }
        ~MapNode(){
            delete next; //destroy recursively
        }
 }