#include<iostream>
using namespace std;
void merge(int arr[],int start, int mid, int end)
{
    int left=start, right=mid+1, index=0;
    int temp[end-start+1];
    while(left<=mid && right<=end)
    {
        if(arr[left]<=arr[right])
            temp[index++]=arr[left++];
        else
            temp[index++]=arr[right++];
    }
    while(left<=mid)
        temp[index++]=arr[left++];
    while(right<=end)
        temp[index++]=arr[right++];
    index=0;
    while(start<=end)
        arr[start++]=temp[index++];
}
void mergeSort(int arr[], int start, int end)
{
    if(start==end)
        return;
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
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
    mergeSort(arr,0,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<endl;
    return 0;
}