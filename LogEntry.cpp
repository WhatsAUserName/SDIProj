#include "stdafx.h"
#include "LogEntry.h"


LogEntry::LogEntry(std::string newEntryName, int newEntryCreationDay, int newEntryCreationHour)
{
	entryName = newEntryName;
	dayOfMonthOfCreation = newEntryCreationDay;
	hourOfCreation = newEntryCreationHour;
}


LogEntry::~LogEntry()
{
}
