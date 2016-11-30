#ifndef TABLE_HH__
#define TABLE_HH__

#include <list>

class TableRow;

class Table
{
public:
    Table();
    ~Table();

    void addRow(TableRow *row);
    void setHeader();

    int getNumberOfRows() const;

private:
    typedef std::list<TableRow *> Rows;

public:
    typedef Rows::iterator Iterator;

    Iterator begin();
    Iterator end();

private:
    Rows rows;
};

#endif /* TABLE_HH__ */

