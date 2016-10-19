#pragma once
#include <Windows.h>
#include "Thread.h"
#include "Logger.h"

class ThreadPool
{
public:
	ThreadPool(int, int);
	ThreadPool(int);
	~ThreadPool();
	void addNewTask(LPTHREAD_START_ROUTINE);
	void addNewThreadInPool();
	void deleteThreadInPool();
private:
	Thread *_repositoryThreads;
	int _numberOfThreads;
	int _maxNumberOfThreads;
	const int DEFAULT_NUMBER_THREADS = 2;

	int getNumberOfFreeThread();
	bool isAvailabilityThread(Thread *);
	void initialization(int, int);
	void initializationOfPool(int, int);
	void setMaxNumberOfThreads(int);

	Logger *_logger;
};
