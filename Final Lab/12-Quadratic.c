#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

struct HashNode
{
    int key;
    int value;
};

struct HashNode HashTable[TABLE_SIZE];

void InitializeTable()
{

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashTable[i].key = -1;
        HashTable[i].value = 0;
    }
}

void Insert(int key, int value,int c1,int c2)
{

    int hkey = key % TABLE_SIZE;

    int i = 0;

    while (i < TABLE_SIZE)
    {

        int index = (hkey + c1*i + c2*i*i)% TABLE_SIZE;


        if (HashTable[index].key == -1 || HashTable[index].key == key)
        {
            HashTable[index].key = key;
            HashTable[index].value = value;
            printf("Inserted key %d with value %d at index %d\n", key, value, index);

            return;
        }
        i++;
    }

    printf("Hash table is full.");
}

void SearchTable(int key, int c1, int c2)
{

    int hkey = key % TABLE_SIZE;
    int i = 0;

    while (i < TABLE_SIZE)
    {
        int index = (hkey + c1*i + c2*i*i)% TABLE_SIZE;
        if (HashTable[index].key == key)
        {
            printf("Element with key %d found at index %d with value %d\n", key, index,
                   HashTable[index].value);
            return;
        }
        if (HashTable[index].key == -1)
        {
            break;
        }
        i++;
    }

    printf("Element with key %d not found in the hash table\n", key);
}

int main()
{
    InitializeTable();
    int n, key, value;
    printf("Enter the number of key-value pairs to insert: ");
    scanf("%d", &n);
    printf("Enter the key-value pairs one by one:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &key, &value);
        Insert(key, value, 1,2);
    }
    printf("Enter the key to search in the HashTable: ");
    scanf("%d", &key);
    SearchTable(key,1,2);
    return 0;
}
