#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int linearSearch(const vector<int> &a, int key)
{
  for (int i = 0; i < a.size(); i++)
    if (a[i] == key)
      return i;
  return -1;
}

int binarySearchIterative(const vector<int> &a, int key)
{
  int low = 0, high = a.size() - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int binarySearchRecursive(const vector<int> &a, int low, int high, int key)
{
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  if (a[mid] == key)
    return mid;
  else if (a[mid] < key)
    return binarySearchRecursive(a, mid + 1, high, key);
  else
    return binarySearchRecursive(a, low, mid - 1, key);
}

void printVector(const vector<int> &a)
{
  for (int x : a)
    cout << x << " ";
  cout << "\n";
}

int main()
{
  int n, val, key;
  vector<int> data;

  cout << "Enter number of elements: ";
  cin >> n;

  cout << "Enter " << n << " numbers:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    data.push_back(val);
  }

  cout << "Enter key to search: ";
  cin >> key;

  int index;

  index = linearSearch(data, key);
  if (index != -1)
    cout << "Linear Search: Found at index " << index << "\n";
  else
    cout << "Linear Search: Not found\n";

  sort(data.begin(), data.end());
  cout << "Sorted data for Binary Search: ";
  printVector(data);

  index = binarySearchIterative(data, key);
  if (index != -1)
    cout << "Binary Search (Iterative): Found at index " << index << "\n";
  else
    cout << "Binary Search (Iterative): Not found\n";

  index = binarySearchRecursive(data, 0, data.size() - 1, key);
  if (index != -1)
    cout << "Binary Search (Recursive): Found at index " << index << "\n";
  else
    cout << "Binary Search (Recursive): Not found\n";

  return 0;
}
