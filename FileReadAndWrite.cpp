// FileReadAndWrite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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


int main()
{
	std::vector<Project> projects;
	readProjectsFile("TestProjectsDoc.txt", projects);

	for each (Project project in projects)
	{
		project.displayProjectData();
	}

	Project testProject = createTestProject();
	projects.push_back(testProject);

	writeProjectsFile("TestProjectsDoc.txt", projects);

	int a;
	std::cin >> a;
	return 0;
}

void readProjectsFile(std::string fileName, std::vector<Project>& allProjects)
{
	std::ifstream projectFile;
	std::string line;
	std::vector<std::string> lineContents;

	projectFile.open(fileName, std::ios::in);

	if (projectFile.is_open())
	{
		while (std::getline(projectFile, line))
		{
			Project thisProject(line);
			lineContents.clear();

			// split input string at commas
			splitLineIntoVector(line, lineContents, ',');

			// sort through lineContents
			thisProject.title = lineContents[0];
			thisProject.summary = lineContents[1];
			thisProject.genre = lineContents[2];
			thisProject.releaseDate = lineContents[3];
			thisProject.language = lineContents[5];
			thisProject.runtime = lineContents[6];
			thisProject.state = lineContents[10];

			splitLineIntoVector(lineContents[4], thisProject.filmingLocations, ';');
			splitLineIntoVector(lineContents[7], thisProject.keywords, ';');
			splitLineIntoVector(lineContents[9], thisProject.weeklyTicketSales, ';');

			std::vector<std::string> crewMembersString;
			splitLineIntoVector(lineContents[8], crewMembersString, ';');
			for each (std::string crewMember in crewMembersString)
			{
				Crew newCrewMember;
				int split = crewMember.find(':');
				newCrewMember.name = crewMember.substr(0, split);
				newCrewMember.job = crewMember.substr(split + 1);
				thisProject.crewMembers.push_back(newCrewMember);
			}

			// add additional materials if project is released
			if (thisProject.state == "released")
			{
				Material newMaterial;

				int currentIndex = 11;

				while (currentIndex < lineContents.size())
				{
					newMaterial.type = lineContents[currentIndex];
					currentIndex++;
					newMaterial.idNumber = lineContents[currentIndex];
					currentIndex++;
					newMaterial.materialTitle = lineContents[currentIndex];
					currentIndex++;
					newMaterial.format = lineContents[currentIndex];
					currentIndex++;
					newMaterial.audioFormat = lineContents[currentIndex];
					currentIndex++;
					newMaterial.materialRuntime = lineContents[currentIndex];
					currentIndex++;
					newMaterial.retailPrice = lineContents[currentIndex];
					currentIndex++;
					newMaterial.frameAspect = lineContents[currentIndex];
					currentIndex++;

					if (newMaterial.type == "VHS")
					{
						newMaterial.packaging = lineContents[currentIndex];
						currentIndex++;
						newMaterial.vhsLanguage = lineContents[currentIndex];
						currentIndex++;
						newMaterial.vhsSubtitleLanguage = lineContents[currentIndex];
						currentIndex++;
					}
					else
					{
						std::vector<std::string> discs;

						splitLineIntoVector(lineContents[currentIndex], newMaterial.languageTracks, ';');
						currentIndex++;
						splitLineIntoVector(lineContents[currentIndex], newMaterial.subtitles, ';');
						currentIndex++;
						splitLineIntoVector(lineContents[currentIndex], discs, '|');

						for each(std::string discContents in discs)
						{
							std::vector<std::string> listOfFeatures;
							splitLineIntoVector(discContents, listOfFeatures, ';');
							newMaterial.featuresPerDisc.push_back(listOfFeatures);
						}
						currentIndex++;
					}

					thisProject.listOfMaterials.push_back(newMaterial);
				}

			}

			allProjects.push_back(thisProject);
		}
		projectFile.close();
	}
	else
	{
		std::cout << "Project File Not Found.";
	}
}

void writeProjectsFile(std::string fileName, std::vector<Project> allProjects)
{
	/// overwrite file with name 'fileName' with data in 'allProjects'
	std::ofstream projectFile;
	projectFile.open(fileName, std::ios::out);
	projectFile.clear();

	for each (Project project in allProjects)
	{
		projectFile << project.convertToString() << '\n';
	}

	projectFile.close();
}

void splitLineIntoVector(std::string line, std::vector<std::string>& newVector, char splitChar)
{
	std::string substring;
	bool midstring = false;

	for (char c : line)
	{
		// if entry is in quotation marks, don't seperate values at commans
		if (c == '"')
		{
			if (midstring == false)
			{
				midstring = true;
			}
			else if (midstring == true)
			{
				midstring = false;
			}
		}
		else
		{
			// seperate values if comma is reached
			if (c == splitChar && !midstring)
			{
				newVector.push_back(substring);
				substring = "";
			}
			// add character to current substring
			else
			{
				substring += c;
			}
		}
	}

	// push final substring to vector
	newVector.push_back(substring);
}

/*
	test project for testing file writing. Can be deleted.
*/
Project createTestProject()
{
	Project testProject;

	testProject.title = "Fast and Furious";
	testProject.summary = "It's about street racing I think? Maybe drag racing, more specifically";
	testProject.genre = "VroomVroom";
	testProject.releaseDate = "Like, 2002 or something?";
	testProject.filmingLocations.push_back("Somewhere in the US");
	testProject.filmingLocations.push_back("Another place in the US");
	testProject.language = "English";
	testProject.runtime = "2 hours maybe";
	testProject.keywords.push_back("Cars");
	testProject.keywords.push_back("FastCars");
	Crew VD;
	VD.name = "Is this the one with Vin Diesel in it?";
	VD.job = "Cast";
	Crew guy;
	guy.name = "That guy who died";
	guy.job = "Cast";
	testProject.crewMembers.push_back(VD);
	testProject.crewMembers.push_back(guy);
	testProject.weeklyTicketSales.push_back("first week sales");
	testProject.weeklyTicketSales.push_back("second week sales");
	testProject.state = "released";

	Material doubleSidedDVD;
	doubleSidedDVD.type = "Double-Sided DVD";
	doubleSidedDVD.idNumber = "001";
	doubleSidedDVD.materialTitle = "F&F: DVD";
	doubleSidedDVD.format = "F&F Format";
	doubleSidedDVD.audioFormat = "F&F Audio Format";
	doubleSidedDVD.materialRuntime = "A bit over 2 hours";
	doubleSidedDVD.retailPrice = "A Fiver";
	doubleSidedDVD.frameAspect = "16:9";
	doubleSidedDVD.languageTracks.push_back("English");
	doubleSidedDVD.languageTracks.push_back("Italian");
	doubleSidedDVD.subtitles.push_back("English");
	doubleSidedDVD.subtitles.push_back("Italian");
	doubleSidedDVD.subtitles.push_back("Spanish");
	doubleSidedDVD.subtitles.push_back("French");

	std::vector<std::string> disc;
	disc.push_back("Disc1Feature1");
	disc.push_back("Disc1Feature2");

	std::vector<std::string> disc2;
	disc2.push_back("Disc2Feature1");
	disc2.push_back("Disc2Feature2");

	doubleSidedDVD.featuresPerDisc.push_back(disc);
	doubleSidedDVD.featuresPerDisc.push_back(disc2);

	testProject.listOfMaterials.push_back(doubleSidedDVD);

	return testProject;
}

Project::Project(std::string stringRepresentation)
{
	/// String that gets read from or written to file
	projectString = stringRepresentation;
}

/*
	Lists all data in console. Needs to be replaced with function which sends data to controller.
*/
void Project::displayProjectData()
{
	/// displays each project detail on a new line in console app
	std::cout << title << std::endl << summary << std::endl << genre << std::endl << releaseDate << std::endl << language << std::endl << runtime << std::endl << state << std::endl;
	for each (Crew crew in crewMembers)
	{
		std::cout << crew.name << ": " << crew.job << std::endl;
	}
	for each (std::string location in filmingLocations)
	{
		std::cout << location << " - ";
	}
	std::cout << std::endl;
	for each (std::string keyword in keywords)
	{
		std::cout << keyword << " - ";
	}
	std::cout << std::endl;
	for each (std::string ticketSales in weeklyTicketSales)
	{
		std::cout << ticketSales << " - ";
	}
	std::cout << std::endl;

	for each (Material material in listOfMaterials)
	{
		std::cout << '\t' << material.type << std::endl;
		std::cout << '\t' << material.idNumber << std::endl;
		std::cout << '\t' << material.materialTitle << std::endl;
		std::cout << '\t' << material.format << std::endl;
		std::cout << '\t' << material.audioFormat << std::endl;
		std::cout << '\t' << material.materialRuntime << std::endl;
		std::cout << '\t' << material.retailPrice << std::endl;
		std::cout << '\t' << material.frameAspect << std::endl;

		if (material.type == "VHS")
		{
			std::cout << '\t' << material.packaging << std::endl;
			std::cout << '\t' << material.vhsLanguage << std::endl;
			std::cout << '\t' << material.vhsSubtitleLanguage << std::endl;
		}
		else
		{
			std::cout << '\t';
			for each (std::string language in material.languageTracks)
			{
				std::cout << language << " - ";
			}
			std::cout << std::endl;

			std::cout << '\t';
			for each (std::string subtitle in material.subtitles)
			{
				std::cout << subtitle << " - ";
			}
			std::cout << std::endl;

			for each (std::vector<std::string> disc in material.featuresPerDisc)
			{
				std::cout << '\t';
				for each(std::string feature in disc)
				{
					std::cout << feature << " - ";
				}
				std::cout << std::endl;
			}
		}
	}

	std::cout << std::endl << "*******************************************************************" << std::endl << std::endl;
}

std::string Project::convertToString()
{
	if (projectString != "")
	{
		return projectString;
	}
	else
	{
		projectString += "\"" + title + "\","; // title
		projectString += "\"" + summary + "\","; // summary
		projectString += "\"" + genre + "\","; // genre
		projectString += "\"" + releaseDate + "\","; // release date

		projectString += "\""; // filming locations
		for (int i = 0; i < filmingLocations.size(); i++)
		{
			projectString += filmingLocations[i];
			if (i < filmingLocations.size() - 1)
			{
				projectString += ";"; // if not the last location to add, add a ; to seperate values
			}
		}
		projectString += "\",";

		projectString += "\"" + language + "\","; // language
		projectString += "\"" + runtime + "\","; // runtime

		projectString += "\""; // keywords
		for (int i = 0; i < keywords.size(); i++)
		{
			projectString += keywords[i];
			if (i < keywords.size() - 1)
			{
				projectString += ";"; // if not the last keyword to add, add a ; to seperate values
			}
		}
		projectString += "\",";

		projectString += "\""; // crew
		for (int i = 0; i < crewMembers.size(); i++)
		{
			projectString += crewMembers[i].name + ":" + crewMembers[i].job;
			if (i < crewMembers.size() - 1)
			{
				projectString += ";"; // if not the last crew to add, add a ; to seperate values
			}
		}
		projectString += "\",";

		projectString += "\""; // weekly ticket sales
		for (int i = 0; i < weeklyTicketSales.size(); i++)
		{
			projectString += weeklyTicketSales[i];
			if (i < weeklyTicketSales.size() - 1)
			{
				projectString += ";"; // if not the last weekly ticket sale to add, add a ; to seperate values
			}
		}
		projectString += "\",";

		projectString += "\"" + state + "\","; // state

		for each (Material material in listOfMaterials)
		{
			projectString += "\"" + material.type + "\","; // type
			projectString += "\"" + material.idNumber + "\","; // id number
			projectString += "\"" + material.materialTitle + "\","; // material title
			projectString += "\"" + material.format + "\","; // format
			projectString += "\"" + material.audioFormat + "\","; // audio format
			projectString += "\"" + material.materialRuntime + "\","; // runtime
			projectString += "\"" + material.retailPrice + "\","; // price
			projectString += "\"" + material.frameAspect + "\","; // frame aspect

			if (material.type == "VHS")
			{
				projectString += "\"" + material.packaging + "\","; // packaging
				projectString += "\"" + material.vhsLanguage + "\","; // language
				projectString += "\"" + material.vhsSubtitleLanguage + "\""; // subtitles
			}
			else
			{
				projectString += "\""; // disc languages
				for (int i = 0; i < material.languageTracks.size(); i++)
				{
					projectString += material.languageTracks[i];
					if (i <  material.languageTracks.size() - 1)
					{
						projectString += ";"; // if not the last language to add, add a ; to seperate values
					}
				}
				projectString += "\",";

				projectString += "\""; // disc subtitles
				for (int i = 0; i < material.subtitles.size(); i++)
				{
					projectString += material.subtitles[i];
					if (i <  material.subtitles.size() - 1)
					{
						projectString += ";"; // if not the last subtitle to add, add a ; to seperate values
					}
				}
				projectString += "\",";

				projectString += "\""; // disc features
				for (int i = 0; i < material.featuresPerDisc.size(); i++) // loop through discs
				{
					for (int j = 0; j < material.featuresPerDisc[i].size(); j++) // lopp through features on this disc
					{
						projectString += material.featuresPerDisc[i][j];
						if (j < material.featuresPerDisc[i].size() - 1)
						{
							projectString += ";"; // if not the last feature on this disc, add a ; to seperate values
						}
					}
					if (i < material.featuresPerDisc.size() - 1)
					{
						projectString += "|"; // if not last disc, add | to serperate values
					}
				}
				projectString += "\"";
			}
		}
	}

	return projectString;
}
