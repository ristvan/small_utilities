#include "SummarizedInfo.hh"
#include "TripData.hh"
#include "Table.hh"
#include "TableRow.hh"
#include "TableCell.hh"
#include "TextTableWriter.hh"
#include <list>
#include <map>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

SummarizedInfo::SummarizedInfo()
{
}

SummarizedInfo::~SummarizedInfo()
{
}

void SummarizedInfo::calculate()
{
    list<TripData*>::iterator tripIt = trips.begin();

    int totalTTMR = 0;
    int sumElevation = 0;
    int sumCsucsokCsucsa = 0;
    unsigned int completedToursNum = 0;
    Table t;
    TableRow *row = new TableRow;
    TableCell *cell = new TableCell;
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
    cell->setValue("Total TTMR");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);
    cell = new TableCell;
    cell->setValue("Sum Elevation");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);
    cell = new TableCell;
    cell->setValue("Csucsok Csucsa");
    cell->setAlignment(Center);
    cell->setVerticalAlignment(Middle);
    row->addCell(cell);
    t.addRow(row);
    while (tripIt != trips.end())
    {
        TripData *trip = *tripIt;
        if (trip->type() == Completed)
        {
            float ttmrValue = trip->distance() / 1000;
            ttmrValue += (trip->elevation() / 100) * 1.5;
            totalTTMR += static_cast<int>(ttmrValue);
            sumElevation += trip->elevation();
            int csucsokCsucsa = 0;
            if (0 != trip->distance())
            {
                csucsokCsucsa = 1000 * trip->elevation() / trip->distance();
            }

            sumCsucsokCsucsa += csucsokCsucsa;
            ++completedToursNum;

            row = new TableRow;
            cell = new TableCell;
            // name of tour
            cell->setValue(trip->name());
            row->addCell(cell);
            cell = new TableCell;
            cell->setValue(trip->date().toString());
            row->addCell(cell);
            
            // total TTMR value
            stringstream ss;
            ss << totalTTMR;
            cell = new TableCell;
            cell->setValue(ss.str());
            row->addCell(cell);

            // summarized elevation in meter
            ss.str("");
            ss << sumElevation << " m";
            cell = new TableCell;
            cell->setValue(ss.str());
            row->addCell(cell);

            // csucsok csucsa value
            ss.str("");
            ss << sumCsucsokCsucsa;
            cell = new TableCell;
            cell->setValue(ss.str());
            row->addCell(cell);

            t.addRow(row);
        }
        ++tripIt;
    }

    TextTableWriter ttw(t);
    ttw.writeTable();


    cout << "Number of completed trips: " << completedToursNum << endl;
}

//end of file
