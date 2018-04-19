#pragma once
#include <string>
#include <ctime>

class LogEntry
{
public:
	LogEntry(std::string newEntryName, int newEntryCreationDay, int newEntryCreationHour);
	~LogEntry();
	
	std::string entryName;
	int dayOfMonthOfCreation;
	int hourOfCreation;
	LogEntry* next;
	
};

