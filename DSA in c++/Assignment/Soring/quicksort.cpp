#include<iostream>
using namespace std;

int quick(int arr[], int first, int last)
{
    int loc=first;
    while(first<last)
    {
        while(first<last && arr[loc]<=arr[last])
            last--;
        if(first==last)
            break;
        swap(arr[loc],arr[last]);
        loc=last;
        while(first<last && arr[loc]>=arr[first])
            first++;
        if(first == last)
            break;
        swap(arr[loc],arr[first]);
        loc=first;
    }
    return loc;
}

void quickSort(int arr[], int first, int last)
{
    if(first>=last)
        return;
    int loc=quick(arr,first,last);
    quickSort(arr,first,loc-1);
    quickSort(arr,loc+1,last);
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
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<endl;
    return 0;
}