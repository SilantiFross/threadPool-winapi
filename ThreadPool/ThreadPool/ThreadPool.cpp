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
	initializationOfPool(initialNumberOfThreads, maxNumberOfThreads);

	_logger = new Logger("logfile.dat");
	_logger->logInitializeThreadPool(initialNumberOfThreads, maxNumberOfThreads);

}

void ThreadPool::initializationOfPool(int initialNumberOfThreads, int maxNumberOfThreads)
{
	_repositoryThreads = new Thread[maxNumberOfThreads];
	_numberOfThreads = initialNumberOfThreads;
}

void ThreadPool::setMaxNumberOfThreads(int value)
{
	_maxNumberOfThreads = value;
}

bool ThreadPool::isAvailabilityThread(Thread *thread)
{
	DWORD status;
	GetExitCodeThread(thread->getHThread(), &status);
	if (status == STILL_ACTIVE)
	{
		thread->setIsFree(false);
	}
	else
	{
		thread->setIsFree(true);
		TerminateThread(thread->getHThread(), 0);
	}

	return thread->isFree();
}

int ThreadPool::getNumberOfFreeThread()
{
	for (int i = 0; i < _numberOfThreads; i++)
	{
		if (isAvailabilityThread(&_repositoryThreads[i]))
			return i;
	}
	return -1;
}

void ThreadPool::addNewThreadInPool()
{ 
	if (_numberOfThreads < _maxNumberOfThreads)
	{
		_numberOfThreads++;
	}
	else
	{
		_logger->logErrorExcess();
	}
}

void ThreadPool::addNewTask(LPTHREAD_START_ROUTINE lpStartAddress)
{
	int currentThreadNumber = getNumberOfFreeThread();
	if (currentThreadNumber != -1)
	{
		_repositoryThreads[currentThreadNumber].createNewThread(lpStartAddress);

		_logger->logNewTask((int)_repositoryThreads[currentThreadNumber].getHThread());
	}
	else
	{
		_logger->logWarningAvailability();
	}
}

ThreadPool::~ThreadPool()
{
	_logger->logShutdown();
	_logger->~Logger();
}