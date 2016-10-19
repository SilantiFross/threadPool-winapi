#include "ThreadPoll.h"
#include <conio.h> 

void testMethod2()
{
	Sleep(3000);
	printf("Method 2 done\n");
}

void testMethod()
{
	Sleep(4000);
	printf("Method done\n");
}

int main()
{
	ThreadPool *threadPool;
	threadPool = new ThreadPool(2, 4);
	threadPool->addNewTask((LPTHREAD_START_ROUTINE)testMethod);
	threadPool->addNewTask((LPTHREAD_START_ROUTINE)testMethod2);
	threadPool->addNewTask((LPTHREAD_START_ROUTINE)testMethod2);
	threadPool->~ThreadPool();
	_getch();
	return 0;
}