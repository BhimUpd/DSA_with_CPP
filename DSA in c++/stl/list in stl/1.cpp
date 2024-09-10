#include<iostream>
using namespace std;
#include<list>
int main()
{
list <int> l1{1,2,3,4,5,6,7,8,9,0};
l1.sort();
l1.reverse();
l1.remove(4);
l1.clear();
cout<<l1.size();
for(auto i=l1.begin(); i!=l1.end(); i++)
    cout<<*i<<endl;

cout<<endl<<endl;

return 0;
}