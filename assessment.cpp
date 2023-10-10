//call the Calculator.cpp and Queue.cpp
#include "Calculator.cpp"
#include "Queue.cpp"

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

