#include <bits/stdc++.h>

using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
    ~MapNode()
    {
        delete next; // destroy recursively
    }
};

template <typename V>
class mymap
{
private:
    MapNode<V> **buckets;
    int count;
    int numbuckets;

    int getbucketindex(string key)
    { // HashFunction
        int hashcode = 0;
        int base = 1;
        int p = 11;
        for (i = key.size() - 1; i >= 0; i--)
        {
            hashcode += key[i] * base;
            base = base * p;
            hashcode = hashcode % numbuckets;
            base = base % numbuckets;
        }
        return hashcode % numbuckets;
    }

    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numbuckets];
        for(int i = 0;i<2*numbuckets; i++)
        {
            buckets[i] = nullptr;
        }
        int oldbucketsize = numbuckets;
        numbuckets*=2;
        count =0;
        for(int i o;i<oldbucketsize; i++){
            MapNode<V>* head = temp[i];
            while(!head){
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for(int i =0;i<oldbucketsize; i++)
        {
            delete temp[i];
        }
        delete[] temp; 
    }
public:
    mymap()
    {
        count = 0;
        numbuckets = 5;
        buckets = new MapNode<V> *[numbuckets];
        for (auto i = 0; i < numbuckets; i++)
            buckets[i] = NULL;
    }
    ~mymap()
    {
        for (int i = 0; i < numbuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }
    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketindex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketindex];
        while (!head)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    void insert(string key, V value)
    {
        int bucketindex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketindex];
        while (!head)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        MapNode<V> *newnode = new MapNode(key, value);
        newnode->next = buckets[bucketindex];
        buckets[bucketindex] = newnode;
        count++;
    }
    void remove(string key)
    {
        int bucketindex = getbucketindex(key);
        MapNode<V> *head = buckets[bucketindex];
        MapNode<V> *prev = nullptr;
        while (!head)
        {
            if (head->key == key)
            {
                if (prev == nullptr)
                {
                    buckets[bucketindex] = head->next;
                }
                else{
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = nullptr;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
    }
};

int main(){

    mymap<int> ourmap;
    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        ourmap.insert(key,value);
        cout<<ourmap.getLoadFactor()<<endl;
    }
    cout<<ourmap.size()<<endl;

    ourmap.remove("abc1");
    ourmap.remove("abc6");

    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout<<key<<" "<<ourmap.getValue(key)<<endl;
    }
     cout<<ourmap.size()<<endl;
  return 0;
}