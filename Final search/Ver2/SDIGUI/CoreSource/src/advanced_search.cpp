#include "advanced_search.h"
#include <algorithm>

Search::Search()
{
	readProjectsFile("TestProjectsDoc.txt", projects);
}

Search::~Search()
{

}


bool Search::crewFound(std::vector<Crew> crews, std::string crewName)
{
	//if crewName is empty string, that means don't care about this field
	if (crewName == "")
	{
		return true;
	}

	for each(struct Crew crew in crews)
	{
		if (crew.name == crewName)
			return true;
	}
	return false;
}

bool Search::keywordFound(std::vector<std::string> keywords, std::string fkeyword)
{
	//if keyword is empty string, that means don't care about this field
	if (fkeyword == "")
	{
		return true;
	}

	for each(std::string keyword in keywords)
	{
		if (fkeyword == keyword)
			return true;
	}
	return false;
}

bool Search::dataCompare(std::string data, std::string keyword)
{
	//if keyword is empty string, that means don't care about this field
	if (keyword == "")
	{
		return true;
	}
	else if (data == keyword)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<Project*> Search::SearchIt(std::string filmName, std::string crew, std::string state, std::string keyword)
{
	std::vector<Project*> prjList;
	int idx = 0;

	//add Project to a list if all conditions are met
	for each(Project project in projects)
	{
		if (dataCompare(project.title, filmName) && keywordFound(project.keywords, keyword) && 
			crewFound(project.crewMembers,crew) && dataCompare(project.state, state))
		{
			prjList.push_back(&projects[idx]);
		}

		idx++;
	}

	return prjList;
}