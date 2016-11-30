#include "MainBase.hh"
#include "StringTokenizer.hh"
#include "TripData.hh"
#include "TextFileReader.hh"

#include <iostream>
#include <cstdlib>

void MainBase::processLine(int lineNumber, char* lineString)
{
    std::string line(lineString);
    int ind = line.length() - 1;
    while (ind >= 0 && line[ind] == '\n')
    {
        line[ind] = '\0';
        --ind;
    }

    Common::StringTokenizer strTok(line, std::string(":"));
    int tokenNum = 0;
    TripData *tripData = new TripData;
    while (strTok.hasMoreTokens())
    {
        ++tokenNum;
        std::string token = strTok.nextToken();
        processToken(tokenNum, token, *tripData);
    }
    trips.push_back(tripData);
}

void MainBase::processToken(int tokenNumber, std::string& token, TripData& tripData)
{
    switch (tokenNumber)
    {
    case 1:
        processType(token, tripData);
        break;
    case 2:
        processName(token, tripData);
        break;
    case 3:
        processDate(token, tripData);
        break;
    case 4:
        processDistance(token, tripData);
        break;
    case 5:
        processElevation(token, tripData);
        break;
    default:
        std::cerr << "Invalid token number!" << std::endl;
    }
}

void MainBase::processType(std::string& typeStr, TripData& tripData)
{
    std::string type = "";
    if (typeStr == "C")
    {
        tripData.setType(Completed);
        type = "Completed";
    }
    else if (typeStr == "P")
    {
        tripData.setType(Planned);
        type = "Planned";
    }
    else if (typeStr == "S")
    {
        tripData.setType(Skipped);
        type = "Skipped";
    }
    else
    {
        tripData.setType(Undefined);
        type = "Invalid";
    }

//    std::cout << "Type: " << type << std::endl;
}

void MainBase::processName(std::string& nameStr, TripData& tripData)
{
    tripData.setName(nameStr);
//    std::cout << "Name: " << nameStr <<  std::endl;
}

void MainBase::processDate(std::string& dateStr, TripData& tripData)
{
    Common::StringTokenizer dateTok(dateStr, std::string("-"));
    int year = atoi(dateTok.nextToken().c_str());
    int month = atoi(dateTok.nextToken().c_str());
    int day = atoi(dateTok.nextToken().c_str());
    Common::Date date(year, month, day);
    tripData.setDate(date);
//    std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
}

void MainBase::processDistance(std::string& distanceStr, TripData& tripData)
{
    int distance = atoi(distanceStr.c_str());
    tripData.setDistance(distance);
//    std::cout << "Distance: " << distance << " km" << std::endl;
}

void MainBase::processElevation(std::string& elevationStr, TripData& tripData)
{
    int elevation = atoi(elevationStr.c_str());
    tripData.setElevation(elevation);
//    std::cout << "Elevation: " << elevation << " m" << std::endl;
}


MainBase::~MainBase()
{
    std::list<TripData*>::iterator it = trips.begin();
    while ( it != trips.end())
    {
        TripData *tripData = *it;
        ++it;
        delete tripData;
    }
}

void MainBase::run(const char* fileName)
{
    std::cout << "Filename: " << fileName << std::endl;
    TextFileReader mReader;
    mReader.addFileListener(this);
    mReader.read(fileName);

    calculate();
}

// end of file

