#include "testFunctions.h"
using std::cout;
using std::cin;
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


void Testing::simulation_day_length(int runTime)
{
	srand(time(NULL));

	cout << "Simulation Day Length" << endl;

	Queue expressQueue;
	Queue normalQueue;

	int totalTime = 0;
	int customerCounter = 0;

	int expressArrival = rand() % 5 + 1; // 1-5 minutes
	int normalArrival = rand() % 6 + 3;  // 3-8 minutes

	while (totalTime < runTime)
	{
		if (expressArrival <= 0)
		{
			customerCounter++;
			int serviceTime = rand() % 5 + 1; // 1-5 minutes
			expressQueue.enqueue(customerCounter, serviceTime);
			cout << "Customer " << customerCounter << " enters EXPRESS queue at time " << totalTime << " minutes. Service time: " << serviceTime << endl;
			expressArrival = rand() % 5 + 1;
		}

		if (normalArrival <= 0)
		{
			customerCounter++;
			int serviceTime = rand() % 6 + 3; // 3-8 minutes
			normalQueue.enqueue(customerCounter, serviceTime);
			cout << "Customer " << customerCounter << " enters NORMAL queue at time " << totalTime << " minutes. Service time: " << serviceTime << endl;
			normalArrival = rand() % 6 + 3;
		}

		if (!expressQueue.isEmpty())
		{
			Data* customer = expressQueue.getHead()->getData();
			customer->setServiceTime(customer->getServiceTime() - 1);

			if (customer->getServiceTime() <= 0)
			{
				cout << "Customer " << customer->getCustomerNumber() << " FINISHED in EXPRESS queue at time " << totalTime << " minutes. Total time: " << customer->getTotalTime() << " min." << endl;
				expressQueue.dequeue();
			}
		}

		if (!normalQueue.isEmpty())
		{
			Data* customer = normalQueue.getHead()->getData();
			customer->setServiceTime(customer->getServiceTime() - 1);

			if (customer->getServiceTime() <= 0)
			{
				cout << "Customer " << customer->getCustomerNumber() << " FINISHED in NORMAL queue at time " << totalTime << " minutes. Total time: " << customer->getTotalTime() << " min." << endl; 
				normalQueue.dequeue();
			}
		}

		if (totalTime % 10 == 0)
		{
			cout << "EXPRESS QUEUE at time " << totalTime << endl;
			expressQueue.printQueue(); 
			cout << "NORMAL QUEUE at time " << totalTime << endl;
			normalQueue.printQueue();
		}

		totalTime++;
		expressArrival--;
		normalArrival--;
	}

	cout << "Simulation ended after " << runTime << " minutes." << endl;
}


void Testing::TEST_simulation_24_hour()
{
	srand(time(NULL));

	Queue expressQueue;
	Queue normalQueue;

	int totalTime = 0;
	int customerCounter = 0;

	int expressArrival = rand() % 5 + 1; // 1-5 minutes
	int normalArrival = rand() % 6 + 3;  // 3-8 minutes

	int runTime = 24 * 60; // 24 hours

	while (totalTime < runTime || !expressQueue.isEmpty() || !normalQueue.isEmpty())
	{
		if (expressArrival <= 0 && totalTime < runTime)
		{
			customerCounter++;
			int serviceTime = rand() % 5 + 1;
			expressQueue.enqueue(customerCounter, serviceTime);
			expressArrival = rand() % 5 + 1;
		}

		if (normalArrival <= 0 && totalTime < runTime)
		{
			customerCounter++;
			int serviceTime = rand() % 6 + 3;
			normalQueue.enqueue(customerCounter, serviceTime);
			normalArrival = rand() % 6 + 3;
		}

		if (!expressQueue.isEmpty())
		{
			Data* customer = expressQueue.getHead()->getData();
			customer->setServiceTime(customer->getServiceTime() - 1);

			if (customer->getServiceTime() <= 0)
			{
				expressQueue.dequeue();
			}
		}

		if (!normalQueue.isEmpty())
		{
			Data* customer = normalQueue.getHead()->getData();
			customer->setServiceTime(customer->getServiceTime() - 1);

			if (customer->getServiceTime() <= 0)
			{
				normalQueue.dequeue();
			}
		}

		totalTime++;
		expressArrival--;
		normalArrival--;
	}

	if (expressQueue.isEmpty() && normalQueue.isEmpty())
	{
		cout << "TEST #5 24-hour simulation test PASSED successfully!" << endl;
	}
	else
	{
		cout << "TEST #5 24-hour simulation test FAILED." << endl;
	}
}



void Testing::TEST_RUN()
{
	Testing test;
	test.TEST_enqueue_on_empty_queue();
	test.TEST_enqueue_with_one_node_in_queue();
	test.TEST_dequeue_with_queue_with_one_node();
	test.TEST_dequeue_with_queue_with_two_nodes();
	test.TEST_simulation_24_hour();
}


