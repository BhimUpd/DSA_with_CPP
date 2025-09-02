#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

node *top = NULL;

void push(int data)
{
  node *n = new node();
  n->data = data;
  n->next = top;
  top = n;
}

void pop()
{
  if (top == NULL)
  {
    cout << "Stack UnderFlow";
    return;
  }
  cout << "\nPoped element : " << top->data;
  top = top->next;
}

void display()
{
  cout << "\n";
  if (top == NULL)
  {
    cout << "Stack is Empty";
    return;
  }
  node *temp = top;
  while (temp != NULL)
  {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}

int main()
{
  int choice, value;
  do
  {
    cout << "\n\nEnter your choice : \n\n";
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.Display" << endl;
    cout << "4.Exit" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "\nEnter Value to push : ";
      cin >> value;
      push(value);
      break;

    case 2:
      pop();
      break;

    case 3:
      cout << endl;
      display();
      break;

    case 4:
      cout << "\nExited";
      break;

    default:
      cout << "\nInvalid Choice";
    }
  } while (choice != 4);

  return 0;
}