#include "ThreadPoll.h"

ThreadPool::ThreadPool(int initialNumberOfThreads, int maxNumberOfThreads)
{
	initialization(initialNumberOfThreads, maxNumberOfThreads);
}

ThreadPool::ThreadPool(int maxNumberOfThreads)
{
	initialization(DEFAULT_NUMBER_THREADS, maxNumberOfThreads);
}

void ThreadPool::initialization(int initialNumberOfThreads, int maxNumberOfThreads)
{
	setMaxNumberOfThreads(maxNumberOfThreads);
	initializationOfPool(initialNumberOfThreads);
}

void ThreadPool::initializationOfPool(int initialNumberOfThreads)
{
	repositoryThreads_ = new Thread[initialNumberOfThreads];
	numberOfThread_ = initialNumberOfThreads;
}

void ThreadPool::setMaxNumberOfThreads(int value)
{
	maxNumberOfThreads_ = value;
}

bool ThreadPool::isAvailabilityThread(Thread *thread)
{
	DWORD status;
	GetExitCodeThread(thread->getHThread, &status);
	if (status == STILL_ACTIVE)
	{
		thread->setIsFree = false;
	}
	else
	{
		thread->setIsFree = true;
		TerminateThread(thread->getHThread, 0);
	}

	return thread->isFree;
}

int ThreadPool::getNumberOfFreeThread()
{
	for (int i = 0; i < numberOfThread_; i++)
	{
		if (isAvailabilityThread(&repositoryThreads_[i]))
			return i;
	}
	return -1;
}

void ThreadPool::addNewTask(LPTHREAD_START_ROUTINE lpStartAddress)
{
	int currentThreadNumber = getNumberOfFreeThread();
	if (currentThreadNumber != -1)
	{
		repositoryThreads_[currentThreadNumber].createNewThread(lpStartAddress);
	}
	else
	{

	}
}

ThreadPool::~ThreadPool()
{

}