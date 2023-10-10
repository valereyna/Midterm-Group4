//call the Calculator.h and Queue.h
#include "Calculator.h"
#include "Queue.h"

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

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
