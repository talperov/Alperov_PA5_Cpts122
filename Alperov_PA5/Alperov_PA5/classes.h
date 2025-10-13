#pragma once
#include <iostream>
#include <string>

class Data
{
private:

	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int serviceTime; // Random time; varies between express and normal lanes; units in minutes
	int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

public:
	
	//Constructor Copy Constructor Deconstructor
	Data(); 
	Data(int customer, int service, int total); 
	~Data(); 

		//getters
		int getCustomerNumber();
		int getServiceTime();
		int getTotalTime();

		//setters
		void setCustomerNumber(int newCustomer);
		void setServiceTime(int newService);
		void setTotalTime(int newTotal); 



}; // This memory needs to be allocated on the heap!


class QueueNode
{

private:
	Data* pData; // The memory for Data will need to be allocated on the heap as well!
	QueueNode* pNext;

public:

	//Constructor Copy Constructor Destructor
	QueueNode();
	QueueNode(Data* newData);
	QueueNode(Data* newData, QueueNode* newNext);
	~QueueNode();

	//getters
	Data* getData(void);
	QueueNode* getNext(void);

	//setters
	void setData(Data* newData);
	void setNext(QueueNode* newNext);


};

class Queue // WORK ON MONDAY
{

private:
	QueueNode* pHead, 
		*pTail;

public: // Member functions
};
