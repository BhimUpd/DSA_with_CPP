#include<iostream>
using namespace std;
void insertionSort(int arr[], int size)
{
    int temp,i,j;
    for(i=1; i<size; i++)
    {
            temp=arr[i];
            for(j=i-1; j>=0 && temp<arr[j]; j--)
                arr[j+1]=arr[j];
            arr[j+1]=temp;
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