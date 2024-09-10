#include<iostream>
using namespace std;
#include<list>
#include<vector>
class Hashing{
    vector<list<int>>hashTable;
    int buckets;
    public:
    Hashing(int x)
    {
        buckets=x;
        hashTable.resize(x);
    }
    int hashvalue(int hashKey)
    {
        return hashKey%buckets;
    }
    void addElement(int key)
    {
        int index=hashvalue(key);
        hashTable[index].push_back(key);
    }
    list<int>::iterator search(int key)
    {
        int index=hashvalue(key);
        return find(hashTable[index].begin(), hashTable[index].end(),key);
    }
    void Delete(int key)
    {
        int index=hashvalue(key);
        if(search(key)!=hashTable[index].end())
        hashTable[index].erase(search(key));
    }
};
int main()
{
    Hashing h(10);
    h.addElement(4);
    h.addElement(5);
    h.addElement(6);
    h.addElement(7);
    return 0;
}