#include<iostream>
using namespace std;
void bubbleSort(int arr[], int size)
{
    bool flag;
    for(int i=0; i<size-1; i++)
    {
        flag=true;
        for(int j=0; j<size-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag)
            break;
    }
}
int main()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int arr[n];
    cout<<"Enter array Elements:\n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<endl;
    bubbleSort(arr,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<endl;
    return 0;
}