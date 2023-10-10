//call the Queue.h

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class Queue
{
private:
	int front, rear, size;
	double *array;

public:
	Queue(int size);
	~Queue();
	bool Full();
	bool Empty();
	void Enqueue(double K);
	void characterEnqueue(char C);
	void Dequeue();
	double getFront();
	double getRear();
};


Queue::Queue(int size)
{
	front = rear = 0;
	this->size = size;
	array = new double[size];
	if (array == nullptr)
	{
		cout << "Error" << endl;
		exit(EXIT_FAILURE);
	}
}

Queue::~Queue()
{
	delete[] array;
}

bool Queue::Full()
{
	return (size == rear);
}

bool Queue::Empty()
{
	return (front == rear);
}

void Queue::Enqueue(double K)
{
	if (Full())
	{
		cout << "\n\tOverflow" << endl;
		return;
	}
	array[rear] = K;
	rear++;
}

void Queue::characterEnqueue(char C)
{
	if (Full())
	{
		cout << "\n\tOverflow" << endl;
		return;
	}
	array[rear] = C;
	rear++;
}

void Queue::Dequeue()
{
	if (Empty())
	{
		cout << "\n\tUnderflow" << endl;
		return;
	}
	rear--;
}

double Queue::getFront()
{
	if (Empty())
	{
		cout << "\n\tUnderflow" << endl;
	}
	return array[front];
}

double Queue::getRear()
{
	if (Empty())
	{
		cout << "\n\tUnderflow" << endl;
	}
	return array[rear - 1];
}
