#pragma once
#include "LogEntry.h"
#include <fstream>

class Queue
{
public:
	Queue(std::tm* now);
	~Queue();
	void dequeue();
	void enqueue(std::string newEntryName, int creationDay, int creationHour);
	void clearOldEntries(std::tm* now);
	void writeToFile();
	void displayAll();

private:
	int queueLength;
	LogEntry* nextElement;
	LogEntry* lastElement;
};

