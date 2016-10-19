#pragma once
#include <Windows.h>

class Thread
{
public:
	Thread();
	~Thread();
	bool isFree();
	HANDLE getHThread();
	void setIsFree(bool);
	void createNewThread(LPTHREAD_START_ROUTINE);
private:
	bool _isFree;
	HANDLE _hThread;
};
