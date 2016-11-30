#pragma once

#include "Table.hh"
#include <map>

class TextTableWriter
{
public:
    TextTableWriter(Table &table_);
    ~TextTableWriter();

    void writeTable();
private:
    void calculateWidthOfColumns();
    void writeRowSeparator();

    Table& table;
    std::map<int, int> colWidth;
};

