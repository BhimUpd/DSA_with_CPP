#include <iostream>
using namespace std;

class Stack
{
private:
  int *arr;
  int top;
  int n;

public:
  Stack(int size)
  {
    n = size;
    arr = new int[n];
    top = -1;
  }

  void push(int data)
  {
    if (top == n - 1)
    {
      cout << "Stack Overflow\n";
      return;
    }
    arr[++top] = data;
  }

  int pop()
  {
    if (top == -1)
    {
      cout << "Stack Underflow\n";
      return -1;
    }
    return arr[top--];
  }

  int peek()
  {
    if (top == -1)
    {
      cout << "Stack is Empty\n";
      return -1;
    }
    return arr[top];
  }

  void display()
  {
    if (top == -1)
    {
      cout << "Stack is Empty\n";
      return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  ~Stack()
  {
    delete[] arr;
  }
};

int main()
{
  Stack s(100);
  int choice, value;

  while (true)
  {
    cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter value to push: ";
      cin >> value;
      s.push(value);
      break;
    case 2:
      cout << "Popped: " << s.pop() << endl;
      break;
    case 3:
      cout << "Top element: " << s.peek() << endl;
      break;
    case 4:
      s.display();
      break;
    case 5:
      return 0;
    default:
      cout << "Invalid choice\n";
    }
  }

  return 0;
}
