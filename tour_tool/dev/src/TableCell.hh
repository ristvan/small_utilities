#ifndef TABLE_CELL_HH__
#define TABLE_CELL_HH__

#include <string>

enum Alignment
{
    Left   = 0,
    Center,
    Right
};

enum VerticalAlignment
{
    Top    = 0,
    Middle,
    Bottom
};

class TableCell
{
public:
    explicit TableCell(int colSpan_                         = 1,
                       int rowSpan_                         = 1,
                       Alignment         alignment_         = Left,
                       VerticalAlignment verticalAlignment_ = Top,
                       std::string       value_             = "");
    virtual ~TableCell();

    int getColSpan() const;
    void setColSpan(int colSpan_ = 1);
    int getRowSpan() const;
    void setRowSpan(int rowSpan_ = 1);
    Alignment getAlignment() const;
    void setAlignment(Alignment alignment_);
    VerticalAlignment getVerticalAlignment() const;
    void setVerticalAlignment(VerticalAlignment verticalAlignment_);
    std::string getValue() const;
    void setValue(const std::string& value_);
private:
    int               colSpan;
    int               rowSpan;
    Alignment         alignment;
    VerticalAlignment verticalAlignment;
    std::string       value;
};

#endif /* TABLE_CELL_HH__ */

