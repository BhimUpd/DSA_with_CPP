#include<iostream>
using namespace std;
#include<vector>
int main()
{
vector<int>v;
v.push_back(7);
v.push_back(6);
auto x=v.begin();
cout<<*x;
return 0;
}