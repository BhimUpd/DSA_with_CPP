#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int val)
  {
    data = val;
    prev = next = nullptr;
  }
};

class DoublyLinkedList
{
  Node *head;

public:
  DoublyLinkedList()
  {
    head = nullptr;
  }

  void insertAtBeginning(int val)
  {
    Node *newNode = new Node(val);
    newNode->next = head;
    if (head != nullptr)
      head->prev = newNode;
    head = newNode;
  }

  void insertAtEnd(int val)
  {
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->next)
      temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
  }

  void insertAfter(int key, int val)
  {
    Node *temp = head;
    while (temp && temp->data != key)
      temp = temp->next;
    if (!temp)
    {
      cout << "Node not found.\n";
      return;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
      temp->next->prev = newNode;
    temp->next = newNode;
  }

  void insertBefore(int key, int val)
  {
    Node *temp = head;
    while (temp && temp->data != key)
      temp = temp->next;
    if (!temp)
    {
      cout << "Node not found.\n";
      return;
    }
    Node *newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev)
      temp->prev->next = newNode;
    else
      head = newNode;
    temp->prev = newNode;
  }

  void deleteFromBeginning()
  {
    if (!head)
    {
      cout << "List is empty.\n";
      return;
    }
    Node *temp = head;
    head = head->next;
    if (head)
      head->prev = nullptr;
    delete temp;
  }

  void deleteFromEnd()
  {
    if (!head)
    {
      cout << "List is empty.\n";
      return;
    }
    Node *temp = head;
    while (temp->next)
      temp = temp->next;
    if (temp->prev)
      temp->prev->next = nullptr;
    else
      head = nullptr;
    delete temp;
  }

  void deleteAfter(int key)
  {
    Node *temp = head;
    while (temp && temp->data != key)
      temp = temp->next;
    if (!temp || !temp->next)
    {
      cout << "Invalid position to delete after.\n";
      return;
    }
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next)
      toDelete->next->prev = temp;
    delete toDelete;
  }

  void deleteBefore(int key)
  {
    Node *temp = head;
    while (temp && temp->data != key)
      temp = temp->next;
    if (!temp || !temp->prev)
    {
      cout << "Invalid position to delete before.\n";
      return;
    }
    Node *toDelete = temp->prev;
    if (toDelete->prev)
      toDelete->prev->next = temp;
    else
      head = temp;
    temp->prev = toDelete->prev;
    delete toDelete;
  }

  void display()
  {
    Node *temp = head;
    cout << "List: ";
    while (temp)
    {
      cout << temp->data << " <-> ";
      temp = temp->next;
    }
    cout << "NULL\n";
  }
};

int main()
{
  DoublyLinkedList dll;
  int choice, val, key;

  do
  {
    cout << "\n----- DOUBLY LINKED LIST MENU -----\n";
    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at End\n";
    cout << "3. Insert After a Node\n";
    cout << "4. Insert Before a Node\n";
    cout << "5. Delete from Beginning\n";
    cout << "6. Delete from End\n";
    cout << "7. Delete After a Node\n";
    cout << "8. Delete Before a Node\n";
    cout << "9. Display List\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter value: ";
      cin >> val;
      dll.insertAtBeginning(val);
      break;
    case 2:
      cout << "Enter value: ";
      cin >> val;
      dll.insertAtEnd(val);
      break;
    case 3:
      cout << "Enter key and value: ";
      cin >> key >> val;
      dll.insertAfter(key, val);
      break;
    case 4:
      cout << "Enter key and value: ";
      cin >> key >> val;
      dll.insertBefore(key, val);
      break;
    case 5:
      dll.deleteFromBeginning();
      break;
    case 6:
      dll.deleteFromEnd();
      break;
    case 7:
      cout << "Enter key: ";
      cin >> key;
      dll.deleteAfter(key);
      break;
    case 8:
      cout << "Enter key: ";
      cin >> key;
      dll.deleteBefore(key);
      break;
    case 9:
      dll.display();
      break;
    case 0:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice!\n";
    }
  } while (choice != 0);

  return 0;
}
