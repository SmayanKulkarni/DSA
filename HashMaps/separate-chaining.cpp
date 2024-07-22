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

 template <typename V>
  class mymap{
    private:
        MapNode<V>** buckets;
        int count;
        int numbuckets;

        int getbucketindex(string key){  //HashFunction
            int hashcode = 0;
            int base = 1;
            int p=11;
            for(i = key.size()-1; i>=0; i--){
                hashcode += key[i] * base;
                base = base*p;
                hashcode = hashcode % numbuckets;
                base = base % numbuckets;
            }
            return hashcode%numbuckets;
        }
    public:
        mymap(){
            count = 0;
            numbuckets =5;
            buckets = new MapNode<V>*[numbuckets];
            for(auto i = 0;i<numbuckets;i++) buckets[i] =NULL;
        }
        ~mymap(){
            for(int i = 0; i<numbuckets;i++)
            {
                delete buckets[i];
            }
            delete[] buckets;
        }
        int size()
        {
            return count;
        }
        
        V getValue(string key){

        }
        void insert(string key, V value){

        }
        void remove(string key){

        }

  }