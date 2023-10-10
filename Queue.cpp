// Call the Queue.h
#include "Queue.h"

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

// Make new queue
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

// For delete the queue
Queue::~Queue()
{
	delete[] array;
}

// Check if the queue is full
bool Queue::Full()
{
	// The queue is full if size is equal to rear
	return (size == rear);
}

// Check if the queue is empty
bool Queue::Empty()
{
	// The queue is empty if front equal to rear
	return (front == rear);
}

// Pushing the number values
void Queue::Enqueue(double K)
{
	// Check if the queue is full 
	if (Full())
	{
		cout << "\n\tOverflow" << endl;
		return;
	}
	array[rear] = K; // Put inside the array
	rear++;			 // And add the rear
}

// Pushing the character values
void Queue::characterEnqueue(char C)
{
	// Check if the queue is full
	if (Full())
	{
		cout << "\n\tOverflow" << endl;
		return;
	}
	array[rear] = C; // Put inside the array
	rear++;			 // And add the rear
}

// The queue is last in first out
void Queue::Dequeue()
{
	// Check if it is empty
	if (Empty())
	{
		cout << "\n\tUnderflow" << endl;
		return;
	}
	rear--; // Then decrease the rear
}

// Get the front
double Queue::getFront()
{
	// Check if it is empty
	if (Empty())
	{
		cout << "\n\tUnderflow" << endl;
	}
	return array[front]; // Return to array
}

// Get the rear
double Queue::getRear()
{
	// Check is it is empty
	if (Empty())
	{
		cout << "\n\tUnderflow" << endl;
	}
	return array[rear - 1]; // Return to array with decreasing the rear - 1
}

