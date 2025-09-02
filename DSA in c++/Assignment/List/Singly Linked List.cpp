#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

class SLL
{
  node *start;

public:
  SLL()
  {
    start = NULL;
  }

  void insertAtBeginning(int data)
  {
    node *n = new node();
    n->data = data;
    n->next = start;
    start = n;
  }

  void insertAtEnd(int data)
  {
    node *n = new node();
    n->data = data;
    n->next = NULL;
    if (start == NULL)
    {
      start = n;
      return;
    }
    node *temp = start;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = n;
  }

  void insertAfter(int key, int data)
  {
    node *temp = start;
    while (temp != NULL && temp->data != key)
      temp = temp->next;
    if (temp != NULL)
    {
      node *n = new node();
      n->data = data;
      n->next = temp->next;
      temp->next = n;
    }
  }

  void insertBefore(int key, int data)
  {
    if (start == NULL)
      return;
    if (start->data == key)
    {
      insertAtBeginning(data);
      return;
    }
    node *prev = NULL, *curr = start;
    while (curr != NULL && curr->data != key)
    {
      prev = curr;
      curr = curr->next;
    }
    if (curr != NULL)
    {
      node *n = new node();
      n->data = data;
      n->next = curr;
      prev->next = n;
    }
  }

  void insertAtPosition(int pos, int data)
  {
    if (pos <= 0)
      return;
    if (pos == 1)
    {
      insertAtBeginning(data);
      return;
    }
    node *temp = start;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
      temp = temp->next;
    if (temp != NULL)
    {
      node *n = new node();
      n->data = data;
      n->next = temp->next;
      temp->next = n;
    }
  }

  void deleteFromBeginning()
  {
    if (start == NULL)
      return;
    node *temp = start;
    start = start->next;
    delete temp;
  }

  void deleteFromEnd()
  {
    if (start == NULL)
      return;
    if (start->next == NULL)
    {
      delete start;
      start = NULL;
      return;
    }
    node *temp = start;
    while (temp->next->next != NULL)
      temp = temp->next;
    delete temp->next;
    temp->next = NULL;
  }

  void deleteAfter(int key)
  {
    node *temp = start;
    while (temp != NULL && temp->data != key)
      temp = temp->next;
    if (temp != NULL && temp->next != NULL)
    {
      node *del = temp->next;
      temp->next = del->next;
      delete del;
    }
  }

  void deleteFromPosition(int pos)
  {
    if (pos <= 0 || start == NULL)
      return;
    if (pos == 1)
    {
      deleteFromBeginning();
      return;
    }
    node *temp = start;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
      temp = temp->next;
    if (temp->next != NULL)
    {
      node *del = temp->next;
      temp->next = del->next;
      delete del;
    }
  }

  void display()
  {
    node *temp = start;
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  SLL list;
  list.insertAtBeginning(10);
  list.insertAtEnd(20);
  list.insertAfter(10, 15);
  list.insertBefore(20, 17);
  list.insertAtPosition(3, 12);
  list.display();

  list.deleteFromBeginning();
  list.deleteFromEnd();
  list.deleteAfter(10);
  list.deleteFromPosition(2);
  list.display();

  return 0;
}
