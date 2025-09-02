#include <iostream>
using namespace std;

#define N 500

struct node
{
  int info;
  int next;
};

class StaticList
{
private:
  struct node n[N];
  int avail;
  int head;

public:
  StaticList()
  {
    initialize();
    head = -1;
  }

  void initialize()
  {
    for (int i = 0; i < N - 1; i++)
      n[i].next = i + 1;
    n[N - 1].next = -1;
    avail = 0;
  }

  int getNode()
  {
    if (avail == -1)
    {
      cout << "Overflow: No space available.\n";
      return -1;
    }
    int p = avail;
    avail = n[avail].next;
    return p;
  }

  void freeNode(int p)
  {
    n[p].next = avail;
    avail = p;
  }

  void insertAtBeginning(int item)
  {
    int p = getNode();
    if (p == -1)
      return;
    n[p].info = item;
    n[p].next = head;
    head = p;
  }

  void insertAtEnd(int item)
  {
    int p = getNode();
    if (p == -1)
      return;
    n[p].info = item;
    n[p].next = -1;

    if (head == -1)
    {
      head = p;
    }
    else
    {
      int q = head;
      while (n[q].next != -1)
      {
        q = n[q].next;
      }
      n[q].next = p;
    }
  }

  void insertAfter(int after, int item)
  {
    int q = head;
    while (q != -1 && n[q].info != after)
    {
      q = n[q].next;
    }
    if (q == -1)
    {
      cout << "Element " << after << " not found.\n";
      return;
    }

    int p = getNode();
    if (p == -1)
      return;

    n[p].info = item;
    n[p].next = n[q].next;
    n[q].next = p;
  }

  void deleteFromBeginning()
  {
    if (head == -1)
    {
      cout << "Underflow: List is empty.\n";
      return;
    }
    int p = head;
    head = n[head].next;
    freeNode(p);
  }

  void deleteFromEnd()
  {
    if (head == -1)
    {
      cout << "Underflow: List is empty.\n";
      return;
    }
    int prev = -1;
    int curr = head;
    while (n[curr].next != -1)
    {
      prev = curr;
      curr = n[curr].next;
    }

    if (prev == -1)
    {
      head = -1;
    }
    else
    {
      n[prev].next = -1;
    }

    freeNode(curr);
  }

  void deleteAfter(int after)
  {
    int p = head;
    while (p != -1 && n[p].info != after)
    {
      p = n[p].next;
    }

    if (p == -1 || n[p].next == -1)
    {
      cout << "No element to delete after " << after << ".\n";
      return;
    }

    int q = n[p].next;
    n[p].next = n[q].next;
    freeNode(q);
  }

  void display()
  {
    if (head == -1)
    {
      cout << "List is empty.\n";
      return;
    }
    int p = head;
    while (p != -1)
    {
      cout << n[p].info << " -> ";
      p = n[p].next;
    }
    cout << "NULL\n";
  }
};

int main()
{
  StaticList list;
  int choice, item, after;

  do
  {
    cout << "\n1. Insert at beginning\n";
    cout << "2. Insert at end\n";
    cout << "3. Insert after element\n";
    cout << "4. Delete from beginning\n";
    cout << "5. Delete from end\n";
    cout << "6. Delete after element\n";
    cout << "7. Display list\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "Enter item to insert at beginning: ";
      cin >> item;
      list.insertAtBeginning(item);
      break;
    case 2:
      cout << "Enter item to insert at end: ";
      cin >> item;
      list.insertAtEnd(item);
      break;
    case 3:
      cout << "Enter element after which to insert: ";
      cin >> after;
      cout << "Enter item to insert: ";
      cin >> item;
      list.insertAfter(after, item);
      break;
    case 4:
      list.deleteFromBeginning();
      break;
    case 5:
      list.deleteFromEnd();
      break;
    case 6:
      cout << "Enter element after which to delete: ";
      cin >> after;
      list.deleteAfter(after);
      break;
    case 7:
      list.display();
      break;
    case 0:
      cout << "Exiting...\n";
      break;
    default:
      cout << "Invalid choice.\n";
    }
  } while (choice != 0);

  return 0;
}
