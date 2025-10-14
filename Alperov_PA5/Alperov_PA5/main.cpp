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
using std::endl;

int main(void)
{

	cout << "=================================================Grocery Store Simulator================================================" << endl;
	system("pause");
	system("cls");
	Testing test;
	test.TEST_enqueue_on_empty_queue();
	test.TEST_enqueue_with_one_node_in_queue();
	test.TEST_dequeue_with_queue_with_one_node();



	return 0;
}
