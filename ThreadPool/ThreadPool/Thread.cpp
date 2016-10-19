#include "Thread.h"

Thread::Thread()
{
	isFree_ = true;
}

bool Thread::isFree()
{
	return isFree_;
}

HANDLE Thread::getHThread()
{
	return hThread_;
}

void Thread::setIsFree(bool value)
{
	isFree_ = value;
}

void Thread::createNewThread(LPTHREAD_START_ROUTINE lpStartAddress)
{
	hThread_ = CreateThread(NULL, 0, lpStartAddress, NULL, 0, NULL);
	isFree_ = false;
}

Thread::~Thread()
{

}