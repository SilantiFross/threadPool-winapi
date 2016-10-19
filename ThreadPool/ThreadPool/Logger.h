#pragma once
#include <WinBase.h>
#include <iostream>

class Logger
{
public:
	Logger(char *);
	~Logger();
	void logInitializeThreadPool(int, int);
	void logNewTask(int);
	void logWarningAvailability();
	void logErrorExcess();
	void logShutdown();
private:
	SYSTEMTIME _systemTime;
	FILE *_fileHandler;
	char *_logFileName;

	void logTime();
};