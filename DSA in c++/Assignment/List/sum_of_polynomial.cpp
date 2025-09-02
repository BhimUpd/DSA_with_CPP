#include <iostream>
using namespace std;

struct node
{
  int coeff;
  int power;
  node *next;
  node(int c, int p)
  {
    coeff = c;
    power = p;
    next = NULL;
  }
};

node *insertTerm(node *head, int coeff, int power)
{
  node *newNode = new node(coeff, power);
  if (!head || power > head->power)
  {
    newNode->next = head;
    return newNode;
  }
  node *current = head;
  while (current->next && current->next->power > power)
    current = current->next;
  if (current->power == power)
  {
    current->coeff += coeff;
    delete newNode;
  }
  else if (current->next && current->next->power == power)
  {
    current->next->coeff += coeff;
    delete newNode;
  }
  else
  {
    newNode->next = current->next;
    current->next = newNode;
  }
  return head;
}

node *inputPolynomial()
{
  node *head = NULL;
  int n;
  cout << "Enter number of terms: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int c, p;
    cout << "Enter coefficient and power: ";
    cin >> c >> p;
    head = insertTerm(head, c, p);
  }
  return head;
}

node *addPolynomial(node *P, node *Q)
{
  node *result = NULL;
  while (P && Q)
  {
    if (P->power > Q->power)
    {
      result = insertTerm(result, P->coeff, P->power);
      P = P->next;
    }
    else if (P->power < Q->power)
    {
      result = insertTerm(result, Q->coeff, Q->power);
      Q = Q->next;
    }
    else
    {
      result = insertTerm(result, P->coeff + Q->coeff, P->power);
      P = P->next;
      Q = Q->next;
    }
  }
  while (P)
  {
    result = insertTerm(result, P->coeff, P->power);
    P = P->next;
  }
  while (Q)
  {
    result = insertTerm(result, Q->coeff, Q->power);
    Q = Q->next;
  }
  return result;
}

void printPolynomial(node *head)
{
  node *current = head;
  while (current)
  {
    cout << current->coeff << "x^" << current->power;
    current = current->next;
    if (current)
      cout << " + ";
  }
  cout << endl;
}

int main()
{
  cout << "Enter first polynomial:\n";
  node *P = inputPolynomial();
  cout << "Enter second polynomial:\n";
  node *Q = inputPolynomial();

  node *sum = addPolynomial(P, Q);

  cout << "Sum of polynomials:\n";
  printPolynomial(sum);

  return 0;
}
