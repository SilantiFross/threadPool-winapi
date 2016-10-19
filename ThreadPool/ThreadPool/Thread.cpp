#include "Thread.h"

Thread::Thread()
{
}

HANDLE Thread::getHThread()
{
	return _hThread;
}

void Thread::createNewThread(LPTHREAD_START_ROUTINE lpStartAddress)
{
	_hThread = CreateThread(NULL, 0, lpStartAddress, NULL, 0, NULL);
}

Thread::~Thread()
{
	delete _hThread;
}