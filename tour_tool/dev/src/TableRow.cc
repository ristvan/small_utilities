#include "TableRow.hh"
#include "TableCell.hh"

TableRow::TableRow()
{
}

TableRow::~TableRow()
{
    for (Iterator it = begin(); it != end(); ++it)
    {
        TableCell *tc = *it;
        delete tc;
    }
//    cells.clear();
}

void TableRow::addCell(TableCell* cell)
{
    cells.push_back(cell);
}

int TableRow::getNumberOfCells() const
{
    return cells.size();
}


TableRow::Iterator TableRow::begin()
{
    return cells.begin();
}

TableRow::Iterator TableRow::end()
{
    return cells.end();
}

// end of file

