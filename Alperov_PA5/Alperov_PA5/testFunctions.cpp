#include "testFunctions.h"
using std::cout;
using std::endl;

void Testing::TEST_enqueue_on_empty_queue()
{
	cout << "Test #1 Enqueue on Empty Queue" << endl;

	Queue emptyQ;

	int tempCustomer = 1, tempService = 8;

	emptyQ.enqueue(tempCustomer, tempService);
	
	emptyQ.printQueue();

	if (emptyQ.getHead() && emptyQ.getTail())
	{
		if (emptyQ.getHead() == emptyQ.getTail())
		{
			cout << "Test (EMPTY QUEUE) Passed Successfully." << endl;
		}
	}
	else
	{
		cout << "Test (EMPTY QUEUE) Failed Unsuccessfully" << endl;
	}
	cout << endl;
	return;
}
//DONE

void Testing::TEST_enqueue_with_one_node_in_queue()
{
	cout << "Test #2 Enqueue with One Node In Queue" << endl;

	Queue oneNodeQueue;

	int tempCustomer = 1, tempService = 10;

	int tempCustomerTwo = 2, tempServiceTwo = 6;

	oneNodeQueue.enqueue(tempCustomer, tempService);

	oneNodeQueue.enqueue(tempCustomerTwo, tempServiceTwo);

	oneNodeQueue.printQueue();

	if (oneNodeQueue.getHead() && oneNodeQueue.getTail())
	{
		if (oneNodeQueue.getHead() != oneNodeQueue.getTail())
		{
			cout << "Test (ONE NODE ENQUEUE) Passed Successfully." << endl;
		}
		else
		{
			cout << "Test (ONE NODE ENQUEUE) Failed Unsuccessfully" << endl;
		}
	}
	cout << endl;
	return;
}
//DONE

void Testing::TEST_dequeue_with_queue_with_one_node()
{

	cout << "Test #3 Dequeue with One Node" << endl;

	Queue oneNodeQueue;

	int tempCustomer = 1, tempService = 5;

	oneNodeQueue.enqueue(tempCustomer, tempService);

	cout << "Queue without Dequeue Function:" << endl;
	oneNodeQueue.printQueue();

	oneNodeQueue.dequeue();

	cout << "Queue with Dequeue Function:" << endl;
	oneNodeQueue.printQueue();

	if (oneNodeQueue.getHead() == nullptr && oneNodeQueue.getTail() == nullptr)
	{
		cout << "Test (DEQUEUE ONE NODE) Passed Successfully" << endl;
	}
	else
	{
		cout << "Test (DEQUEUE ONE NODE) Failed Unsuccessfully" << endl;
	}
	cout << endl;
	return;
}
//DONE

void Testing::TEST_dequeue_with_queue_with_two_nodes()
{
	return;
}

void Testing::TEST_simulation_day_length()
{
	return;
}


