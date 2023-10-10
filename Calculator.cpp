#include "Queue.cpp"

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Calculator{
  public:
    double assessment(string problems);
    double operation(double num_value_1, double num_value_2, char op);
    double trigonometry(double num_value_1, int x);
    int priority(char op);
};

double Calculator::operation(double num_value_1, double num_value_2, char op)
{
  switch (op)
  {
    case '+':
      return num_value_2 + num_value_1;
    case '-':
      return num_value_2 - num_value_1;
    case '*':
      return num_value_2 * num_value_1;
    case '/':
      return num_value_2 / num_value_1;
    case '^':
      return pow(num_value_2, num_value_1);
    default:
      return 0;
  }
}

double Calculator::trigonometry(double num_value_1, int x)
{
  switch (x)
  {
    case 1:
      return sin(num_value_1);
    case 2:
      return cos(num_value_1);
    case 3:
      return tan(num_value_1);
    case 4:
      return log10(num_value_1);
    case 5:
      return log(num_value_1);
    default:
      return 0;
  }
}

int Calculator::priority(char op)
{
  if (op == '+' || op == '-')
  {
    return 1;
  }
  if (op == '*' || op == '/')
  {
    return 2;
  }
  if (op == '^')
  {
    return 3;
  }
  return 0;
}


