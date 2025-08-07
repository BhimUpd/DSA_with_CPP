#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &a)
{
  int n = a.size();
  for (int i = 0; i < n - 1; i++)
  {
    int minIdx = i;
    for (int j = i + 1; j < n; j++)
      if (a[j] < a[minIdx])
        minIdx = j;
    swap(a[i], a[minIdx]);
  }
}

void insertionSort(vector<int> &a)
{
  int n = a.size();
  for (int i = 1; i < n; i++)
  {
    int key = a[i], j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}

int partition(vector<int> &a, int low, int high)
{
  int pivot = a[high], i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (a[j] < pivot)
    {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[high]);
  return i + 1;
}

void quickSort(vector<int> &a, int low, int high)
{
  if (low < high)
  {
    int pi = partition(a, low, high);
    quickSort(a, low, pi - 1);
    quickSort(a, pi + 1, high);
  }
}

void shellSort(vector<int> &a)
{
  int n = a.size();
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      int temp = a[i], j;
      for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
        a[j] = a[j - gap];
      a[j] = temp;
    }
  }
}

void merge(vector<int> &a, int l, int m, int r)
{
  int n1 = m - l + 1, n2 = r - m;
  vector<int> L(n1), R(n2);
  for (int i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = a[m + 1 + i];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
      a[k++] = L[i++];
    else
      a[k++] = R[j++];
  }
  while (i < n1)
    a[k++] = L[i++];
  while (j < n2)
    a[k++] = R[j++];
}

void mergeSort(vector<int> &a, int l, int r)
{
  if (l < r)
  {
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

void print(const vector<int> &a)
{
  for (int x : a)
    cout << x << " ";
  cout << "\n";
}

int main()
{
  int n, val;
  vector<int> data;
  cout << "Enter number of elements: ";
  cin >> n;

  cout << "Enter " << n << " numbers:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    data.push_back(val);
  }

  vector<int> a;

  a = data;
  selectionSort(a);
  cout << "Selection Sort: ";
  print(a);

  a = data;
  insertionSort(a);
  cout << "Insertion Sort: ";
  print(a);

  a = data;
  quickSort(a, 0, a.size() - 1);
  cout << "Quick Sort: ";
  print(a);

  a = data;
  shellSort(a);
  cout << "Shell Sort: ";
  print(a);

  a = data;
  mergeSort(a, 0, a.size() - 1);
  cout << "Merge Sort: ";
  print(a);

  return 0;
}
