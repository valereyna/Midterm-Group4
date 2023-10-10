//call the Calculator.h and Queue.h
#include "Calculator.h"
#include "Queue.h"

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

double Calculator::assessment(string problems)
{
	int i;
	double pi = 3.141592;
	Queue values(100);
	Queue ops(100);

	for (i = 0; i < problems.length(); i++)
	{
		if (problems[i] == ' ')
		{
			continue;
		}

		// Determining and evaluating expressions
		// Pushing the open bracket to the ops queue
		else if (problems[i] == '(')
		{
			ops.characterEnqueue(problems[i]);
		}

		// sin
		else if (problems[i] == 's')
		{
			int x = 1;
			double result_value = 0;
			
			// Tracking the number
			while (i < problems.length() && problems[i] != ')')
			{
				i++;
				double val = 0;
				if (isdigit(problems[i]))
				{
					while (i < problems.length() && isdigit(problems[i]))
					{
						val = (val * 10) + (problems[i] - '0');
						i++;
						if (problems[i] == '.' || problems[i] == ',')
						{
							i = i + 1;
							int j = -1;
							while (i < problems.length() && isdigit(problems[i]))
							{
								float point = ((problems[i] - '0') * pow(10, j--));
								val = (double)(val) + point;
								i++;
							}
						}
					}
					i--;
					result_value = trigonometry(val * pi / 180, x);
				}
			}
			values.Enqueue(result_value);
		}
		// cos
		else if (problems[i] == 'c')
		{
			int x = 2;
			double result_value = 0;

			while (i < problems.length() && problems[i] != ')')
			{
				i++;
				double val = 0;
				if (isdigit(problems[i]))
				{
					while (i < problems.length() && isdigit(problems[i]))
					{
						val = (val * 10) + (problems[i] - '0');
						i++;
						if (problems[i] == '.' || problems[i] == ',')
						{
							i = i + 1;
							int j = -1;
							while (i < problems.length() && isdigit(problems[i]))
							{
								float point = ((problems[i] - '0') * pow(10, j--));
								val = (double)(val) + point;
								i++;
							}
						}
					}
					i--;
					result_value = trigonometry(val * pi / 180, x);
				}
			}
			values.Enqueue(result_value);
		}

		// tan
		else if (problems[i] == 't')
		{
			int x = 3;
			double result_value = 0;
			while (i < problems.length() && problems[i] != ')')
			{
				i++;
				double val = 0;
				if (isdigit(problems[i]))
				{
					while (i < problems.length() && isdigit(problems[i]))
					{
						val = (val * 10) + (problems[i] - '0');
						i++;
						if (problems[i] == '.' || problems[i] == ',')
						{
							i = i + 1;
							int j = -1;
							while (i < problems.length() && isdigit(problems[i]))
							{
								float point = ((problems[i] - '0') * pow(10, j--));
								val = (double)(val) + point;
								i++;
							}
						}
					}
					i--;
					result_value = trigonometry(val * pi / 180, x);
				}
			}
			values.Enqueue(result_value);
		}

		// log or ln
		else if (problems[i] == 'l')
		{
			int x;
			double result_value = 0;
			i++;
			switch (problems[i])
			{
			case 'o':
				x = 4;
				break;
			case 'n':
				x = 5;
				break;
			}
			while (i < problems.length() && problems[i] != ')')
			{
				i++;
				double val = 0;
				if (isdigit(problems[i]))
				{
					while (i < problems.length() && isdigit(problems[i]))
					{
						val = (val * 10) + (problems[i] - '0');
						i++;
						if (problems[i] == '.' || problems[i] == ',')
						{
							i = i + 1;
							int j = -1;
							while (i < problems.length() && isdigit(problems[i]))
							{
								float point = ((problems[i] - '0') * pow(10, j--));
								val = (double)(val) + point;
								i++;
							}
						}
					}
					i--;
					result_value = trigonometry(val, x);
				}
			}
			values.Enqueue(result_value);
		}

		// If input is number
		else if (isdigit(problems[i]))
		{
			double val = 0;

			while (i < problems.length() && isdigit(problems[i]))
			{
				val = (val * 10) + (problems[i] - '0');
				i++;
				if (problems[i] == '.' || problems[i] == ',')
				{
					i = i + 1;
					int j = -1;
					while (i < problems.length() && isdigit(problems[i]))
					{
						float point = ((problems[i] - '0') * pow(10, j--));
						val = (double)(val) + point;
						i++;
					}
				}
			}

			values.Enqueue(val);
			i--;
		}

		// If the input is square root
		else if (problems[i] == 'r')
		{
			double result_value = 0;
			while (i < problems.length() && problems[i] != ')')
			{
				i++;
				double val = 0;
				if (isdigit(problems[i]))
				{
					while (i < problems.length() && isdigit(problems[i]))
					{
						val = (val * 10) + (problems[i] - '0');
						i++;
						if (problems[i] == '.' || problems[i] == ',')
						{
							i = i + 1;
							int j = -1;
							while (i < problems.length() && isdigit(problems[i]))
							{
								float point = ((problems[i] - '0') * pow(10, j--));
								val = (double)(val) + point;
								i++;
							}
						}
					}
					i--;
					result_value = sqrt(val);
				}
			}
			values.Enqueue(result_value);
		}

		// For closed bracket, the input will be solved inside the bracket
		else if (problems[i] == ')')
		{
			// To see if the ops queue is empty and the not the open bracket
			while (!ops.Empty() && ops.getRear() != '(')
			{
				// Taking the first number
				double val1 = values.getRear();
				values.Dequeue();

				// Taking the second number
				double val2 = values.getRear();
				values.Dequeue();

				// Taking the operator
				char op = ops.getRear();
				ops.Dequeue();
				// Pushing result_value to queue
				values.Enqueue(operation(val1, val2, op));
			}

			if (!ops.Empty())
			{
				ops.Dequeue();
			}
		}

		// If the input is operator
		else
		{
			// Checking if the queue is empty and the precendance
			while (!ops.Empty() && priority(ops.getRear()) >= priority(problems[i]))
			{
				double val1 = values.getRear();
				values.Dequeue();

				double val2 = values.getRear();
				values.Dequeue();

				char op = ops.getRear();
				ops.Dequeue();
				// Pushing the result_value to queue
				values.Enqueue(operation(val1, val2, op));
			}

			// If the precendance is smaller, pushing the operator to queue
			ops.characterEnqueue(problems[i]);
		}
	}

	while (!ops.Empty())
	{
		double val1 = values.getRear();
		values.Dequeue();
		double val2 = values.getRear();
		values.Dequeue();
		char op = ops.getRear();
		ops.Dequeue();
		values.Enqueue(operation(val1, val2, op));
	}

	return values.getRear();
}
