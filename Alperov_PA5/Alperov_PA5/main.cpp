/*
Name: Anthony Alperov
Date Started: 10/12/2025
Assingment Details Summarized: Goal of this assignment is to simulate a grocery line using our 
newly learned Data Structure called Queue a (FIFO) order. There will be several test functions
to confirm what we make is fully complete and will be about 2 header files and 3 source files
*/
#include "classes.h"
#include "testFunctions.h"
using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	auto pick = 0;
    Testing test;
    Testing run;

	cout << "=================================================Grocery Store Simulator================================================" << endl;
	do
	{
		cout << "Test out Indivual Functions or Select Simulation." << endl;
		cout << "Select choice below. . ." << endl;
		cout << "1. Run Test Cases" << endl;
		cout << "2. Run Simulator" << endl;
		cout << "3. Exit" << endl;
		cout << "Select a choice: ";
		cin >> pick;
		system("cls");
        switch (pick) 
        {
        case 1:
            test.TEST_RUN();
            break;

        case 2: {
            int n;
            cout << "Enter simulation length in minutes: ";
            cin >> n;
            run.simulation_day_length(n);
            break;
        }

        case 3:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

	} while (pick != 3);
		return 0;
}

