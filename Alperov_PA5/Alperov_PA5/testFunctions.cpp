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
	cout << "Test #4 Dequeue with Two Nodes" << endl;

	Queue twoNodeQueue;

	int tempCustomer = 1, tempService = 10;

	int tempCustomerTwo = 2, tempServiceTwo = 6;

	twoNodeQueue.enqueue(tempCustomer, tempService);
	twoNodeQueue.enqueue(tempCustomerTwo, tempServiceTwo);


	cout << "Queue without Dequeue Function:" << endl;
	twoNodeQueue.printQueue();

	twoNodeQueue.dequeue();

	if (twoNodeQueue.getHead() != nullptr && twoNodeQueue.getTail() != nullptr)
	{
		if (twoNodeQueue.getHead() == twoNodeQueue.getTail() && twoNodeQueue.getHead()->getData()->getCustomerNumber() == tempCustomerTwo)
		{
			cout << "Test (DEQUEUE TWO NODES) Passed Successfully" << endl;

		}
	} 
	else
	{
		cout << "Test (DEQUEUE TWO NODES) Failed Unsuccessfully" << endl;
	}

	cout << endl;
	return;
}
//DONE


void Testing::TEST_simulation_day_length()
{
	srand(time(NULL));

	cout << "Test #5  Simulation Day Length" << endl;
	Queue fiveNodeQueue;

	int tempCustomer = 1, tempService = rand() % 24 + 1;

	int tempCustomerTwo = 2, tempServiceTwo = rand() % 24 + 1;

	int tempCustomerThree = 3, tempServiceThree = rand() % 24 + 1;

	int tempCustomerFour = 4, tempServiceFour = rand() % 24 + 1;

	int tempCustomerFive = 5, tempServiceFive = rand() % 24 + 1;

	int totalTime = 0, runTime = 24 * 60;

	fiveNodeQueue.enqueue(tempCustomer, tempService);
	fiveNodeQueue.enqueue(tempCustomerTwo, tempServiceTwo);
	fiveNodeQueue.enqueue(tempCustomerThree, tempServiceThree);
	fiveNodeQueue.enqueue(tempCustomerFour, tempServiceFour);
	fiveNodeQueue.enqueue(tempCustomerFive, tempServiceFive);


	while (totalTime < runTime && !fiveNodeQueue.isEmpty())
	{
		Data* tempoCustomer = fiveNodeQueue.getHead()->getData();
		
		tempoCustomer->setServiceTime(tempoCustomer->getServiceTime() - 1);

		if (tempoCustomer->getServiceTime() <= 0)
		{
			cout << "Customer Number " << tempoCustomer->getCustomerNumber() << " finished in " << totalTime << " minutes" << endl;
			fiveNodeQueue.dequeue();
		}
		if (totalTime % 10 == 0)
		{
			cout << "Time: " << totalTime << "minutes." << endl;
			fiveNodeQueue.printQueue();
		}
		totalTime++;

	}

	if (fiveNodeQueue.isEmpty())
	{
			cout << "Test  (SIMULATION DAY LENGTH) Passed Successfully" << endl;
	}
	else
	{
		cout << "Test (SIMULATION DAY LENGTH) Failed Unsuccessfully" << endl;
	}
	cout << endl;
	return;
}

void Testing::TEST_RUN()
{
	Testing test;
	test.TEST_enqueue_on_empty_queue();
	test.TEST_enqueue_with_one_node_in_queue();
	test.TEST_dequeue_with_queue_with_one_node();
	test.TEST_dequeue_with_queue_with_two_nodes();
	test.TEST_simulation_day_length();
}


