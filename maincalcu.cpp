#include "Calculator.cpp"
#include "Queue.cpp"
#include "assessment.cpp"

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
	Calculator calculator;
	double history[100] = {0};
	string problems;
	double result_value;
	int ch = 1;
	int key = 0;

    cout << endl;
	cout << "----------------Scientific Calculator----------------\n";
	cout << "by Group 4: Ferry, Leonard, Michelle, Melinda, Reyna\n" << endl;

	cout << "Input requirements:\n";
	cout << "1. Addition       = a + b\n";
	cout << "2. Subtraction    = a - b\n";
	cout << "3. Multiplication = a * b\n";
	cout << "4. Division       = a / b\n";
	cout << "5. Trigonometry   = sin(x), cos(x), tan(x)\n";
	cout << "6. Square root    = r(a)\n";
	cout << "7. Exponent       = a^b\n";
	cout << "8. Logarithm      = log(a)\n";
	cout << "9. Natural log    = ln(a)\n" << endl;

	cout << "Additional Information:\n";
	cout << "- You can input up to 10 variables\n";
	cout << "- Use ( ) for priority\n";
	cout << "- a and b can be integer or decimal\n";
	cout << "- x is in degrees\n" << endl;

    do
	{
		cout << "Enter to Start!";
	}
	while (cin.get() != '\n');

    // Program directory
    i: // For looping
	cout << "\nDirectory:" << endl;
	cout << "1 = Calculate a Problem" << endl;
	cout << "2 = Check History" << endl;
	cout << "3 = Clear History" << endl;
	cout << "0 = Exit Calculator" << endl;

	cout << "\nEnter command: ";
	cin >> ch;

	while (ch != 0)
	{
		// The calculator
		if (ch == 1)
		{
			cout << "\nEnter math problems: ";
			cin.ignore();
			getline(cin, problems);
			history[key++] = result_value = calculator.assessment(problems);
			cout << "Answer= " << result_value << endl;
			do
			{
				cout << "\nEnter to return to directory.";
			} while (cin.get() != '\n');
		}

		// Printing history
		else if (ch == 2)
		{
			// Key as the index
			if (key != 0)
			{
				cout << "\nCalculator History: " << endl;
				for (int i = 0; i < key; i++)
				{
					cout << "\t" << i + 1 << ". " << history[i] << endl;
				}
			}
			else
			{
				cout << "\nNo Calculation History\n";
			}
		}

		// Clearing history
		else if (ch == 3)
		{
			char c;
			cout << "\nAll history will be deleted and can not be restored, continue?\nEnter 1 for continue and 0 for cancel:" << endl;
			cin >> c;
			// If the user wants to continue, then
			if (c == '1')
			{
				cout << "\n===History Cleared===" << endl;
				// Deleting history contents with loop
				for (int i = 0; i < key; i++)
				{
					history[i] = 0;
				}
				// Reseting the key to 0 so it can be reused
				key = 0;
			}

			// If the user wants to cancel,
			else
			{
				continue;
			}
		}
		// If the user inputs an invalid command
		else
		{
			cout << "Invalid Command." << endl;
		}
		// Go back to directory
		goto i;
	}
	// The message shown to exit the program

	if (ch == 0)
	{
		char c;
		cout << "\n\n!!!Confirm End Program!!!\nEnter 0 to confirm exit and 1 to cancel" << endl;
		cin >> c;
		if (c == '0')
		{
			cout << "\n\n\n\n\n\nThank you for using this calculator, Goodbye!" << endl;
		}
		else
			goto i;
	}

	return 0;
}
	