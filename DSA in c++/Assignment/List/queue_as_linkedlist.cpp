#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

node *front = NULL;
node *rear = NULL;

void enqueue(int data)
{
  if (rear == NULL)
  {
    node *n = new node();
    n->data = data;
    n->next = NULL;
    rear = n;
    front = rear;
  }
  else
  {
    node *n = new node();
    n->data = data;
    n->next = NULL;
    rear->next = n;
    rear = n;
  }
}

void dequeue()
{
  if (front == NULL)
  {
    cout << "\nQueue UnderFlow\n";
    return;
  }
  if (front->next != NULL)
  {
    cout << "\n"
         << front->data << " is dequeued from the Queue.\n";
    node *temp = front;
    front = front->next;
    delete temp;
  }
  else
  {
    cout << "\n"
         << front->data << " is dequeued from the Queue.\n";
    delete front;
    front = rear = NULL;
  }
}

void display()
{
  if (front == NULL)
  {
    cout << "Queue is Empty";
    return;
  }
  node *temp = front;
  cout << "\nQueue Elements are : \n";
  while (temp != NULL)
  {
    cout << temp->data << "\n";
    temp = temp->next;
  }
}

int main()
{
  int choice, value;
  do
  {
    cout << "\n\nEnter your choice : \n\n";
    cout << "1.Enqueue" << endl;
    cout << "2.Dequeue" << endl;
    cout << "3.Display" << endl;
    cout << "4.Exit" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "\nEnter Value to push : ";
      cin >> value;
      enqueue(value);
      break;

    case 2:
      dequeue();
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