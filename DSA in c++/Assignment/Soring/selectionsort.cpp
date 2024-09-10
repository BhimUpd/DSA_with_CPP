#include<iostream>
using namespace std;
int smallestElement(int arr[], int size, int k)
{
    int min=arr[k],minIndex=k;
    for(int i=k+1; i<size; i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void insertionSort(int arr[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        swap(arr[i],arr[smallestElement(arr,size,i)]);
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
    insertionSort(arr,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<endl;
    return 0;
}