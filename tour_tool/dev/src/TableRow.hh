#ifndef TABLE_ROW_HH__
#define TABLE_ROW_HH__

#include <list>

class TableCell;

class TableRow
{
public:
    TableRow();
    ~TableRow();

    void addCell(TableCell*);
    int getNumberOfCells() const;
private:
    typedef std::list<TableCell*> Cells;
public:
    typedef Cells::iterator Iterator;

    Iterator begin();
    Iterator end();
private:
    Cells cells;
};

#endif // TABLE_ROW_HH__

