// Donald J Freiday
// CISC 125 : Computer Science 2
// Carwash Final
// @file CS2 Carwash.cpp

#include <iostream>
#include <iomanip>
#include "Queue.h"

float random();

int main()
{
	cout << "Donald J Freiday \nCar Wash Final \n\n";
	srand(time(nullptr));
	int timeForWash = 0,
		minute = 0,
		timeEnteredQueue = 0,
		carsWashed = 0,
		carsTotal = 0,
		totalQueueMin = 0,
		timeLeftOnCar = 0,
		idleTime = 0;
	float probOfArrival = 0;
	Queue<int> carQueue;

	cout << "Enter the time to wash one car: ";
	cin >> timeForWash;
	cout << "Enter the probability of arrival in any minute (0 - 1.0): ";
	cin >> probOfArrival;

	for (minute = 0; minute < 600; ++minute) // Changed to start at 0 minutes.
	{
		if (random() < probOfArrival)
		{
			if (carsTotal == 0)
				cout << "\nThe first car arrived at minute " << minute << ".\n";
			carQueue.enqueue(minute);
			carsTotal++;
		}
		if (timeLeftOnCar == 0 && !carQueue.isEmpty())
		{
			timeEnteredQueue = carQueue.peekFront();
			carQueue.dequeue();
			totalQueueMin += (minute - timeEnteredQueue);
			++carsWashed;
			timeLeftOnCar = timeForWash;
		}
		if (timeLeftOnCar != 0)
			--timeLeftOnCar;
	}
	idleTime = minute - carsWashed * timeForWash;
	while (!carQueue.isEmpty()) // Finish the queue
	{
		timeEnteredQueue = carQueue.peekFront();
		carQueue.dequeue();
		totalQueueMin += (minute - timeEnteredQueue);
		++carsWashed;
		minute += timeForWash;
	}
	cout << carsTotal << " cars arrived, and " << carsWashed << " cars were washed. \n";
	if (carsWashed > 0) // Prevent div by zero in wait time calculation
	{
		cout << "The last car left at minute " << minute << ".\n"
			<< setiosflags(ios::fixed | ios::showpoint)
			<< "The average wait time was " << setprecision(2) << float(totalQueueMin) / carsWashed << " minutes. \n"
			<< "The carwash was idle for " << idleTime << " minutes. \n\n";
	}
	return 0;
}

float random()
{
	return (rand() % 100)*0.01;
}