#include<iostream>
using namespace std;
void bubbleSort(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-1-i; j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
int main()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array Elements:\n";
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