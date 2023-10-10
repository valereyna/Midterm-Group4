// Call the header
#include "Calculator.h"
#include "Queue.h"

// Call the .cpp file
#include "assessment.cpp"
#include "trigonometry.cpp"
#include "priority.cpp"
#include "operation.cpp"
#include "Queue.cpp"

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

    // Welcome Page
    cout << endl;
    cout << "|*******************************************************|\n";
	cout << "|-----------------Scientific Calculator-----------------|\n";
	cout << "| by Group 4: Ferry, Leonard, Michelle, Melinda, Reyna  |\n";
    cout << "|*******************************************************|\n";
	cout << "|                  Input requirements:                  |\n";
    cout << "|               1. Addition       = a + b               |\n";
	cout << "|               2. Subtraction    = a - b               |\n";
	cout << "|               3. Multiplication = a * b               |\n";
	cout << "|               4. Division       = a / b               |\n";
	cout << "|       5. Trigonometry   = sin(x), cos(x), tan(x)      |\n";
	cout << "|               6. Square root    = r(a)                |\n";
	cout << "|               7. Exponent       = a^b                 |\n";
	cout << "|               8. Logarithm      = log(a)              |\n";
	cout << "|               9. Natural log    = ln(a)               |\n";
    cout << "|*******************************************************|\n";
	cout << "|                Additional Information:                |\n";
	cout << "|           - You can input up to 10 variables          |\n";
	cout << "|           - Use () for priority                       |\n";
	cout << "|           - a and b can be integer or decimal         |\n";
	cout << "|           - x is in degrees                           |\n";
    cout << "|*******************************************************|\n" << endl; 

    do
	{
	cout << "Enter to Start!";
	}
	while (cin.get() != '\n');

    // Program directory
    i: // For looping
    cout << endl;
    cout << "|*******************************************************|\n";
	cout << "|               What Do You Want To Do?:                |\n";
	cout << "|           1 - Use The Scientific Calculator           |\n";
	cout << "|           2 - Check History                           |\n";
	cout << "|           3 - Delete History                          |\n";
	cout << "|           0 - END!                                    |\n";
    cout << "|*******************************************************|\n" << endl;
	cout << "Enter Option Here: ";
    cin >> ch;

	while (ch != 0)
	{
		// Calculator
		if (ch == 1)
		{
			cout << "\nInsert your math problems here: ";
			cin.ignore();
			getline(cin, problems);
			history[key++] = result_value = calculator.assessment(problems);
			cout << "Answer: " << result_value << endl;

			do
			{
				cout << "\nEnter to continue . . .";
			}
            while (cin.get() != '\n');
		}

		// Printing history
		else if (ch == 2)
		{
			// Key as the index
			if (key != 0)
			{
                cout << endl;
                cout << "|*******************************************************|\n";
				cout << "|                       History:                        |\n";
                cout << "|*******************************************************|\n";
				for (int i = 0; i < key; i++)
				{
				cout << "\t" << i + 1 << ". " << history[i] << "\n";
				}
			}
			else
			{
                cout << endl;
                cout << "|*******************************************************|\n";
				cout << "|                No Calculation History                 |\n";
                cout << "|*******************************************************|\n" << endl;
			}
		}

		// Delete history
		else if (ch == 3)
		{
			char c;
            cout << endl;
            cout << "|*******************************************************|\n";
			cout << "|  All history will be deleted and can not be restored  |\n";
            cout << "|         Enter 1 for continue and 0 for cancel         |\n";
            cout << "|*******************************************************|\n" << endl;
            cout << "Enter: ";
			cin >> c;
            
			// If the user wants to continue, then
			if (c == '1')
			{
                cout << endl;
                cout << "|*******************************************************|\n";
				cout << "|              ===== History Deleted =====              |\n";
                cout << "|*******************************************************|\n" << endl;

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
            cout << "|*******************************************************|\n";
			cout << "|                    Invalid Command                    |\n";
            cout << "|*******************************************************|\n" << endl;
		}
		// Go back to directory
		goto i;
	}
	// The message shown to exit the program

	if (ch == 0)
	{
		char c;
        cout << endl;
        cout << "|*******************************************************|\n";
		cout << "|                Do you want to exit?:(                 |\n";
        cout << "|        Enter 0 to confirm exit and 1 to cancel        |\n";
        cout << "|*******************************************************|\n" << endl;
        cout << "Enter: ";
		cin >> c;

		if (c == '0')
		{
            cout << endl;
		    cout << "|*******************************************************|\n";
            cout << "|                 Thank You & Good Bye!                 |\n";
            cout << "|*******************************************************|\n";
		}
		else
			goto i;
	}

	return 0;
}
	