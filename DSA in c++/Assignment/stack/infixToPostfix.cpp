#include <iostream>
using namespace std;
// infix to postfix or Reverse Polish Notation
bool isAnOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char c)
{
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
}

string infixToPostfix(string &s)
{
  char arr[s.size()];
  int top = -1;
  string temp;
  for (int i = 0; i < s.size(); i++)
  {

    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
      temp += s[i];

    else if (s[i] == '(')
    {
      arr[++top] = s[i];
    }

    else if (s[i] == ')')
    {
      while (arr[top] != '(')
        temp += arr[top--];
      top--;
    }

    else if (isAnOperator(s[i]))
    {
      if (top == -1 || arr[top] == '(')
        arr[++top] = s[i];
      else if (getPrecedence(s[i]) > getPrecedence(arr[top]))
        arr[++top] = s[i];
      else
      {
        while (top != -1 && arr[top] != '(' && (getPrecedence(s[i]) <= getPrecedence(arr[top])))
        {
          temp += arr[top--];
        }
        arr[++top] = s[i];
      }
    }
  }

  while (top != -1)
    temp += arr[top--];

  return temp;
}

int main()
{
  string s = "a+b/c*(g+e-f)";
  cout << infixToPostfix(s);
  return 0;
}