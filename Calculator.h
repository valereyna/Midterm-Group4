#ifndef CALCULATORH
#define CALCULATORH

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

#endif
