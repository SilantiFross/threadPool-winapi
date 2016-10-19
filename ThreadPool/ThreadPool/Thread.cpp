#include "Thread.h"

Thread::Thread()
{
	_isFree = true;
}

bool Thread::isFree()
{
	return _isFree;
}

HANDLE Thread::getHThread()
{
	return _hThread;
}

void Thread::setIsFree(bool value)
{
	_isFree = value;
}

void Thread::createNewThread(LPTHREAD_START_ROUTINE lpStartAddress)
{
	_hThread = CreateThread(NULL, 0, lpStartAddress, NULL, 0, NULL);
	_isFree = false;
}

Thread::~Thread()
{
	delete _hThread;
}