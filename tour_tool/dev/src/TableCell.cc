#include "TableCell.hh"

TableCell::TableCell(int               colSpan_,
                     int               rowSpan_,
                     Alignment         alignment_,
                     VerticalAlignment verticalAlignment_,
                     std::string       value_)
    : colSpan(colSpan_),
      rowSpan(rowSpan_),
      alignment(alignment_),
      verticalAlignment(verticalAlignment_),
      value(value_)
{
}

TableCell::~TableCell()
{
}

int TableCell::getColSpan() const
{
    return colSpan;
}

void TableCell::setColSpan(int colSpan_)
{
    colSpan = colSpan_;
}

int TableCell::getRowSpan() const
{
    return rowSpan;
}

void TableCell::setRowSpan(int rowSpan_)
{
    rowSpan = rowSpan_;
}

Alignment TableCell::getAlignment() const
{
    return alignment;
}

void TableCell::setAlignment(Alignment alignment_)
{
    alignment = alignment_;
}

VerticalAlignment TableCell::getVerticalAlignment() const
{
    return verticalAlignment;
}

void TableCell::setVerticalAlignment(VerticalAlignment verticalAlignment_)
{
    verticalAlignment = verticalAlignment_;
}

std::string TableCell::getValue() const
{
    return value;
}

void TableCell::setValue(const std::string& value_)
{
    value = value_;
}

// end of ile

