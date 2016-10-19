#include "Logger.h"

Logger::Logger(char *logFileName)
{
	_fileHandler = fopen(logFileName, "a");
}

Logger::~Logger()
{
	fclose(_fileHandler);
}

void Logger::logInitializeThreadPool(int numberOfThread, int maxNumberOfThreads)
{
	logTime();
	fprintf(_fileHandler, "Message: INITIALIZE: Created %d threads. The max threads: %d\n", numberOfThread, maxNumberOfThreads);
}

void Logger::logNewTask(int hThread)
{
	logTime();
	fprintf(_fileHandler, "Message: Create a new task. Thread id: %d\n", hThread);
}

void Logger::logWarningAvailability()
{
	logTime();
	fprintf(_fileHandler, "Warning! No available threads in the pool.\n");
}

void Logger::logErrorExcess()
{
	logTime();
	fprintf(_fileHandler, "Error! The excess of the maximum number of working threads\n");
}

void Logger::logShutdown()
{
	logTime();
	fprintf(_fileHandler, "Message: The thread pool has completed work\n");
}

void Logger::logTime()
{
	GetLocalTime(&_systemTime);
	fprintf(_fileHandler, "%02d:%02d:%02d ", _systemTime.wHour, _systemTime.wMinute, _systemTime.wSecond);
}

