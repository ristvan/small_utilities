#include "CsucsokCsucsa.hh"
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

CsucsokCsucsa::CsucsokCsucsa()
{
}

CsucsokCsucsa::~CsucsokCsucsa()
{
}

void CsucsokCsucsa::calculate()
{
    list<TripData*>::iterator tripIt = trips.begin();
    const int check[5] = {500, 1000, 2000, 5000, 10000000};

    int totalTTMR = 0;
    int sumElevation = 0;
    int sumCsucsokCsucsa = 0;
    unsigned int completedToursNum = 0;
    int numOfCsucsokCsucsa = 0;
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
//    cell = new TableCell;
//    cell->setValue("Total TTMR");
//    cell->setAlignment(Center);
//    cell->setVerticalAlignment(Middle);
//    row->addCell(cell);
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
//            ss << totalTTMR;
//            cell = new TableCell;
//            cell->setValue(ss.str());
//            row->addCell(cell);

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

            if (sumCsucsokCsucsa >= check[numOfCsucsokCsucsa])
            {
                ++numOfCsucsokCsucsa;
                sumCsucsokCsucsa = 0;
                sumElevation = 0;
            }

        }
        ++tripIt;
    }

    TextTableWriter ttw(t);
    ttw.writeTable();


    cout << "Number of completed trips: " << completedToursNum << endl;
    switch (numOfCsucsokCsucsa)
    {
    case 0:
       cout << "You have no result on Csucsok Csucsa " << endl;
       break;
    case 1:
      cout << "Level of Csucsok Csucsa: Bronz" << endl;
      break;
    case 2:
      cout << "Level of Csucsok Csucsa: Ezust" << endl;
      break;
    case 3:
      cout << "Level of Csucsok Csucsa: Arany" << endl;
      break;
    case 4:
      cout << "Level of Csucsok Csucsa: Gyemant" << endl;
      break;
    default:
      cout << "Level of Csucsok Csucsa: " << numOfCsucsokCsucsa << endl;
      break;
    }
    cout << "Remained Csucsok Csucs: " << check[numOfCsucsokCsucsa] - sumCsucsokCsucsa << endl;
}

//end of file
