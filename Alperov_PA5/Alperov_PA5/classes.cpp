#include "classes.h"

using std::cout;
using std::cin;
using std::endl;

// DATA SECTION

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

Data::~Data()
{
	//Destructor
	//cout << "Destructor Acitvated" << endl; //remember to delete this
}

// Getters
int Data::getCustomerNumber()
{
	return customerNumber;
}

int Data::getServiceTime()
{
	return serviceTime;
}

int Data::getTotalTime()
{
	return totalTime;
}

// Setters
void Data::setCustomerNumber(int newCustomer)
{
	customerNumber = newCustomer;
}

void Data::setServiceTime(int newService)
{
	serviceTime = newService;
}

void Data::setTotalTime(int newTotal)
{
	totalTime = newTotal;
}

// QUEUENODE SECTION

QueueNode::QueueNode()
{
	pData = nullptr;
	pNext = nullptr;
}

QueueNode::QueueNode(Data* newData)
{
	pData = newData;
	pNext = nullptr;
}

QueueNode::QueueNode(Data* newData, QueueNode* newNext)
{
	pData = newData;
	pNext = newNext;
}

QueueNode::~QueueNode()
{
	//Destructor
	//cout << "Destructor Activated." << endl; // remember to remove this
}

Data* QueueNode::getData(void)
{
	return pData;
}

QueueNode* QueueNode::getNext(void)
{
	return pNext;
}

void QueueNode::setData(Data* newData)
{
	pData = newData;
}

void QueueNode::setNext(QueueNode* newNext)
{
	pNext = newNext;
}

// QUEUE SECTION

Queue::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

Queue::~Queue()
{
	//Destructor
	//cout << "Destructor Activated" << endl; // remember to remove this
}

QueueNode* Queue::getHead()
{
	return pHead;
}

QueueNode* Queue::getTail()
{
	return pTail;
}

void Queue::setHead(QueueNode* newHead)
{
	pHead = newHead;
}

void Queue::setTail(QueueNode* newTail)
{
	pTail = newTail;
}

bool Queue::isEmpty()
{
	return (pHead == nullptr);
}

void Queue::enqueue(int customer, int service)
{
	Data* newData = new Data(customer, service); // creating space malloc()

	if (!isEmpty())
	{
		newData->setTotalTime(service + pTail->getData()->getTotalTime());
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
	delete ptr; // free space
}

void Queue::printQueue()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl; // Remember to delete this, only for testing purposes.
		return;
	}

	QueueNode* pCur = pHead;

	cout << "Queue" << endl;

	while (pCur != nullptr)
	{
		Data* customer = pCur->getData();
		cout << "Customer: " << customer->getCustomerNumber() << endl;
		cout << "Service time: " << customer->getServiceTime() << endl;
		cout << "Total time: " << customer->getTotalTime() << endl;

		pCur = pCur->getNext();
	}
}



