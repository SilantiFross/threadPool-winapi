#pragma once
#include <Windows.h>
#include <list>
#include "Thread.h"

class ThreadPool
{
public:
	ThreadPool(int, int);
	ThreadPool(int);
	~ThreadPool();
	void addNewTask(LPTHREAD_START_ROUTINE);
private:
	Thread *repositoryThreads_;
	int numberOfThread_;
	int maxNumberOfThreads_;
	const int DEFAULT_NUMBER_THREADS = 2;

	int getNumberOfFreeThread();
	bool isAvailabilityThread(Thread *);
	void initialization(int, int);
	void initializationOfPool(int);
	void setMaxNumberOfThreads(int);
};
