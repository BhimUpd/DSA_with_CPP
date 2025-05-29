#include <iostream>
using namespace std;
// infix to prefix
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

string reverseString(string s)
{
  string temp;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] == '(')
      temp += ')';
    else if (s[i] == ')')
      temp += '(';
    else
      temp += s[i];
  }
  return temp;
}

string infixToPrefix(string &s)
{
  string s_rev = reverseString(s);
  char arr[s.size()];
  int top = -1;
  string temp;
  for (int i = 0; i < s.size(); i++)
  {

    if ((s_rev[i] >= 'a' && s_rev[i] <= 'z') || (s_rev[i] >= 'A' && s_rev[i] <= 'Z') || (s_rev[i] >= '0' && s_rev[i] <= '9'))
      temp += s_rev[i];

    else if (s_rev[i] == '(')
    {
      arr[++top] = s_rev[i];
    }

    else if (s_rev[i] == ')')
    {
      while (arr[top] != '(')
        temp += arr[top--];
      top--;
    }

    else if (isAnOperator(s_rev[i]))
    {
      if (top == -1 || arr[top] == '(')
        arr[++top] = s_rev[i];
      else if (getPrecedence(s_rev[i]) >= getPrecedence(arr[top]))
        arr[++top] = s_rev[i];
      else
      {
        while (top != -1 && arr[top] != '(' && (getPrecedence(s_rev[i]) < getPrecedence(arr[top])))
        {
          temp += arr[top--];
        }
        arr[++top] = s_rev[i];
      }
    }
  }

  while (top != -1)
    temp += arr[top--];

  return reverseString(temp);
}

int main()
{
  string s = "a+b/c*(g+e-f)";
  cout << infixToPrefix(s); //+a*/bc-+gef
  return 0;
}
