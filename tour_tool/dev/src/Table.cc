#include "Table.hh"
#include "TableRow.hh"

Table::Table()
{
}

Table::~Table()
{
    for (Iterator it = begin();
                  it != end();
                  ++it)
    {
        TableRow *tr = *it;
        delete tr;
    }
    rows.clear();
}

void Table::addRow(TableRow* row)
{
    rows.push_back(row);
}

void Table::setHeader()
{
    // TODO
}

int Table::getNumberOfRows() const
{
    return rows.size();
}

Table::Iterator Table::begin()
{
    return rows.begin();
}

Table::Iterator Table::end()
{
    return rows.end();
}

// end of file

