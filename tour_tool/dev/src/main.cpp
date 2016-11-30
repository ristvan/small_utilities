#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <cstdlib>
#include <cstring>
#include <sstream>

#include "MainBase.hh"
#include "StringTokenizer.hh"
#include "TripData.hh"
#include "TextFileReader.hh"
#include "TextFileListener.hh"
#include "SummarizedInfo.hh"
#include "CsucsokCsucsa.hh"

#include "Table.hh"
#include "TableRow.hh"
#include "TableCell.hh"
#include "TextTableWriter.hh"


// MainClass -> InformationsAboutTrips
class MainClass : public MainBase
{
public:
    MainClass() {}
    ~MainClass() {}
    virtual void calculate();

private:
    std::string monthName(int month);
};

void MainClass::calculate()
{
    // prepare to calculations
    std::map<int, int> sumElevation;
    std::map<int, int> sumDistance;
    float ttmrValue = 0.0;
    int csucsokCsucsa = 0;
    std::map<int, std::map<int, int> > distPerMonth;
    std::map<int, std::map<int, int> > elevPerMonth;
    for (int type = 0; type < 3; ++type)
    {
        sumElevation[type] = 0;
        sumDistance[type]  = 0;
        for (int month = 1; month < 13; ++month)
        {
            distPerMonth[type][month] = 0;
            elevPerMonth[type][month] = 0;
        }
    }
    // Create output table and add header to it
    Table table;
    TableRow *row = new TableRow;
    TableCell *cell = new TableCell;
    cell->setValue("Type");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);

    cell = new TableCell;
    cell->setValue("Name");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);

    cell = new TableCell;
    cell->setValue("Date");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);

    cell = new TableCell;
    cell->setValue("Distance");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);

    cell = new TableCell;
    cell->setValue("Elevation");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);

    cell = new TableCell;
    cell->setValue("TTMR");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);

    cell = new TableCell;
    cell->setValue("Cs.CS.");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);
    table.addRow(row);

    std::list<TripData*>::iterator tripIt = trips.begin();
    int totalTTMR = 0;
    int plannedTTMR = 0;
    int countCompletedTours = 0;
    while (tripIt != trips.end())
    {
        TripData *trip = *tripIt;
        ttmrValue = trip->distance() / 1000;
        ttmrValue += (trip->elevation() / 100) * 1.5;
        if (trip->type() == Completed)
        {
            totalTTMR += static_cast<int>(ttmrValue);
            ++ countCompletedTours;
        }
        else if (trip->type() == Planned)
        {
            plannedTTMR += static_cast<int>(ttmrValue);
        }
        sumElevation[trip->type()] += trip->elevation();
        sumDistance[trip->type()] += trip->distance();
        csucsokCsucsa = 0;
        if (0 != trip->distance())
        {
            csucsokCsucsa = 1000 * trip->elevation() / trip->distance();
        }
        distPerMonth[trip->type()][trip->date().month()] += trip->distance();
        elevPerMonth[trip->type()][trip->date().month()] += trip->elevation();

        // Add one row to the table
        row = new TableRow;
        // type
        cell = new TableCell;
        cell->setValue(trip->typeString());
        row->addCell(cell);

        // name
        cell = new TableCell;
        cell->setValue(trip->name());
        row->addCell(cell);

        // date
        std::stringstream ss;
        ss << trip->date().year() << "-" << std::setw(2) << std::setfill('0') << trip->date().month() << "-" << std::setw(2) << trip->date().day();
        cell = new TableCell;
        cell->setValue(ss.str());
        row->addCell(cell);

        // Distance
        ss.str("");
        ss << trip->distance() << " m"; 
        cell = new TableCell;
        cell->setValue(ss.str());
        row->addCell(cell);

        // Elevation
        ss.str("");
        ss << trip->elevation() << " m";
        cell = new TableCell;
        cell->setValue(ss.str());
        row->addCell(cell);

        // TTMR
        ss.str("");
        ss << std::setprecision(1) << std::fixed << ttmrValue;
        cell = new TableCell;
        cell->setValue(ss.str());
        row->addCell(cell);

        // Csucsok Csucsa
        ss.str("");
        ss << csucsokCsucsa << " points";
        cell = new TableCell;
        cell->setValue(ss.str());
        row->addCell(cell);

        table.addRow(row);
        ++tripIt;
    }

    TextTableWriter ttw(table);
    ttw.writeTable();

    if (0 != trips.size())
    {
        std::cout << "Number of tours: " << countCompletedTours << "/" << trips.size()  << " (" << (100 * countCompletedTours / trips.size())<< "%)"<< std::endl;
    }
    else
    {
        std::cout << "Number of tours: " << countCompletedTours << "/" << trips.size() << " (0%)" << std::endl;
    }

    std::cout << "+------------+-------------------------+-------------------------+" << std::endl;
    std::cout << "+            |          Planned        |        Completed        |" << std::endl;
    std::cout << "+------------+-------------+-----------+-------------+-----------+" << std::endl;
    std::cout << "|            |   Distance  | Elevation |   Distance  | Elevation |" << std::endl;
    std::cout << "+------------+-------------+-----------+-------------+-----------+" << std::endl;
    for (int month = 1; month < 13; ++month)
    {
        std::cout << "| " << std::setw(10) << monthName(month) << " | ";
        for (int type = 0; type < 2; ++type)
        {
            std::cout << std::setw(8) << std::setprecision(2) << std::fixed << distPerMonth[type][month]/1000.0 << " km | " <<
                         std::setw(7) << elevPerMonth[type][month] << " m | ";
        }
        std::cout <<  std::endl;
    }
    std::cout << "+------------+-------------+-----------+-------------+-----------+" << std::endl;
    std::cout << "| " << std::setw(10) << "Summary" << " | ";
    for (int type = 0; type < 2; ++type)
    {
        std::cout << std::setw(8) << std::setprecision(2) << std::fixed << sumDistance[type] / 1000.0 << " km | " <<
                     std::setw(7) << sumElevation[type] << " m | ";
    }
    std::cout << std::endl;
    std::cout << "+------------+-------------+-----------+-------------+-----------+" << std::endl;
    std::cout << "Total Completed TTMR: " << totalTTMR << std::endl;
    std::cout << "Total Planned TTMR: " << plannedTTMR << std::endl;
}

std::string MainClass::monthName(int month)
{
    std::string monthName[13] = { "Invalid Month", "January", "February", "March", "April", "May", "June", "July", "August",
                                  "September", "October", "November", "December"};

    if (month < 1 || month > 12)
    {
        return monthName[0];
    }
    
    return monthName[month];
}

class ArgumentParser
{
public:
    ArgumentParser();
    void parse(int argc, char* argv[]);
    bool isValid() const { return isValid_; }
    bool isHelp() const { return isHelp_; }
    bool isSummarize() const { return isSummarize_; }
    bool isCsucsokCsucsa() const {return isCsucsokCsucsa_; }
    std::string getFileName() const { return fileName; }
private:
    bool isHelp_;
    bool isValid_;
    bool isSummarize_;
    bool isCsucsokCsucsa_;
    std::string fileName;

};

ArgumentParser::ArgumentParser() :
    isHelp_(false),
    isValid_(false),
    isSummarize_(false),
    isCsucsokCsucsa_(false),
    fileName("")
{
}

void ArgumentParser::parse(int argc, char* argv[])
{
    for (unsigned int idx = 1; idx < argc; ++idx)
    {
        if (strcmp("-summarize", argv[idx]) == 0)
        {
            isSummarize_ = true;
        }
        else if (strcmp("-csucsokCsucsa", argv[idx]) == 0)
        {
            isCsucsokCsucsa_ = true;
        }
        else
        {
            fileName = argv[idx];
        }
    }

    if (fileName != "")
    {
        isValid_ = true;
    }
}

int main(int argc, char* argv[])
{
    ArgumentParser argParser;
//    argParser.addArgument();
    std::cout << "Main Program" << std::endl;
    argParser.parse(argc, argv);
    if (not argParser.isValid())
    {
        std::cout << "Invalid argument!" << std::endl;
        return 1;
    }

    MainBase *mc;
    if (argParser.isSummarize())
    {
        mc = new SummarizedInfo;
        
    }
    else if  (argParser.isCsucsokCsucsa())
    {
        mc = new CsucsokCsucsa;
    }
    else
    {
        mc = new MainClass;
    }
    mc->run(argParser.getFileName().c_str());
    delete mc;
    return 0;
}

// end of file

