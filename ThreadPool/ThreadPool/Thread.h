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
	bool isFree_;
	HANDLE hThread_;
};
