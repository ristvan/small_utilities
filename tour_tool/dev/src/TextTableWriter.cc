#include "TextTableWriter.hh"
#include "TableRow.hh"
#include "TableCell.hh"
#include <iostream>
#include <iomanip>

using namespace std;

TextTableWriter::TextTableWriter(Table &table_) : table(table_)
{
}

TextTableWriter::~TextTableWriter()
{
}

void TextTableWriter::calculateWidthOfColumns()
{
    Table::Iterator rowIt = table.begin();
    while (rowIt != table.end())
    {
        TableRow *tRow = *rowIt;
        int colId = 0;
        TableRow::Iterator cellIt = tRow->begin();
        while (cellIt != tRow->end())
        {
            int colWid = (*cellIt)->getValue().size();
            if (colWidth[colId] < colWid)
            {
                colWidth[colId] = colWid;
            }
            ++cellIt;
            ++colId;
        }
        ++rowIt;
    }
}

void TextTableWriter::writeRowSeparator()
{
    for(map<int, int>::iterator widthIt = colWidth.begin();
        widthIt != colWidth.end(); ++widthIt)
    {
        cout <<  "+" << setfill('-') << setw(widthIt->second + 2) << "-";
    }
    cout << setfill(' ') << "+" << endl;
}

void TextTableWriter::writeTable()
{

    calculateWidthOfColumns();

    writeRowSeparator();

    Table::Iterator rowIt = table.begin();

    // header
    TableRow *tRow = *rowIt;
    TableRow::Iterator cellIt = tRow->begin();
    int colId = 0;
    while (cellIt != tRow->end())
    {
        cout << "| " << setw (colWidth[colId]) << (*cellIt)->getValue() << " ";
        ++cellIt;
        ++colId;
    }
    ++rowIt;
    cout << "|" << endl;

    writeRowSeparator();

    // content of the table
    while (rowIt != table.end())
    {
        TableRow *tRow = *rowIt;
        int colId = 0;
        TableRow::Iterator cellIt = tRow->begin();
        while (cellIt != tRow->end())
        {
            cout << "| " << setw (colWidth[colId]) << (*cellIt)->getValue() << " ";
            ++cellIt;
            ++colId;
        }
        cout << "|" << endl;
        ++rowIt;
    }

    writeRowSeparator();
}

// end of file

