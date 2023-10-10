//call the Calculator.h and Queue.h
#include "Calculator.h"
#include "Queue.h"

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

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
