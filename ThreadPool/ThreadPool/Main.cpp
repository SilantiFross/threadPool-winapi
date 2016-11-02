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
	try
	{
		threadPool = new ThreadPool(3, 5);
		threadPool->addNewTask((LPTHREAD_START_ROUTINE)testMethod);
		threadPool->addNewTask((LPTHREAD_START_ROUTINE)testMethod2);
		threadPool->addNewTask((LPTHREAD_START_ROUTINE)testMethod2);
		threadPool->addNewTask((LPTHREAD_START_ROUTINE)testMethod2);
		threadPool->~ThreadPool();
	}
	catch (const ThreadPoolException& e)
	{
		printf(e.what());
	}

	_getch();
	return 0;
}