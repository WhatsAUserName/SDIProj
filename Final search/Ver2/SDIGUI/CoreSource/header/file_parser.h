#pragma once
//#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>




struct Crew
{
	std::string name;
	std::string job;
};


class Material
{
public:
	std::string type, idNumber, materialTitle, format, audioFormat, materialRuntime, retailPrice, frameAspect;

	// VHS only
	std::string packaging, vhsLanguage, vhsSubtitleLanguage;

	// Other types
	std::vector<std::string> languageTracks, subtitles;
	std::vector<std::vector<std::string>> featuresPerDisc;
};


class Project
{
public:
	std::string title, summary, genre, releaseDate, language, runtime, state;
	std::vector<Crew> crewMembers;
	std::vector<std::string> filmingLocations, keywords, weeklyTicketSales;

	std::vector<Material> listOfMaterials;

	Project(std::string stringRepresentation = std::string());

	void displayProjectData();

	std::string convertToString();

private:
	std::string projectString; // used for writing project to file
};


void readProjectsFile(std::string fileName, std::vector<Project>& allProjects);
void writeProjectsFile(std::string fileName, std::vector<Project> allProjects);
void splitLineIntoVector(std::string line, std::vector<std::string>& newVector, char splitChar);
Project createTestProject();
