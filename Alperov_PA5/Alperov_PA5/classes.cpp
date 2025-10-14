#include "classes.h"

using std::cout;
using std::cin;
using std::endl;

Data::Data()
{
	customerNumber = 0;
	serviceTime = 0;
	totalTime = 0;
}
Data::Data(int customer, int service)
{
	customerNumber = customer;
	serviceTime = service;
	totalTime = 0;
}
void Queue::enqueue(int customer, int service)
{
	Data* newData = new Data(customer, service);

	if (!isEmpty())
	{
		newData->setTotalTime(service + pTail->getData()->getTotalTime()); 
		// Get the total time through adding our serviceTime to our TotalTime,
		// we get from having pTail access the data to TotalTime.
	}
	else
	{
		newData->setTotalTime(service);
	}

	QueueNode* newNode = new QueueNode(newData);


	if (isEmpty())
	{
		pHead = pTail = newNode;
	}
	else
	{
		pTail->setNext(newNode);
		pTail = newNode;
	}
}

void Queue::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl; // Remember to delete this, only for testing purposes.
		return;
	}

	QueueNode* ptr = pHead;

	pHead = pHead->getNext();

	if (isEmpty())
	{
		pTail = nullptr;
	}

	delete ptr->getData();

	delete ptr;		
}

void Queue::printQueue()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl; // Remember to delete this, only for testing purposes.
		return;
	}

	QueueNode* pCur = pHead;

	cout << "Queue: " << endl;

	while (pCur != nullptr)
	{
		Data* customer = pCur->getData();
		cout << "Customer: " << customer->getCustomerNumber() << endl;
		cout << "Service time: " << customer->getServiceTime() << endl;
		cout << "Total time: " << customer->getTotalTime() << endl;

		pCur = pCur->getNext();
	}
}

bool Queue::isEmpty()
{
	
	return (pHead == nullptr); 
	
}



