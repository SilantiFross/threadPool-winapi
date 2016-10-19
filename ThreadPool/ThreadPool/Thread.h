#pragma once
#include <Windows.h>

class Thread
{
public:
	Thread();
	~Thread();
	HANDLE getHThread();
	void createNewThread(LPTHREAD_START_ROUTINE);
private:
	HANDLE _hThread;
};
