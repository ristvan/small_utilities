#ifndef TRIPDATA_H__
#define TRIPDATA_H__

#include <string>
#include "Date.hh"


enum TripType
{
    Undefined = -1,
    Planned = 0,
    Completed,
    Skipped
};

class TripData
{
public:
    TripData() : type_(Undefined), name_(""), date_(0,0,0), distance_(0), elevation_(0) {}
    TripType type() const { return this-> type_; }
    std::string typeString() const
    {
        switch (type_)
        {
        case Undefined: return std::string("Undefined");
        case Planned: return std::string("Planned");
        case Completed: return std::string("Completed");
        case Skipped: return std::string("Skipped");
        default: return std::string("");
        }
    }
    void setType(TripType type) { this->type_ = type;  }
    std::string name() const { return this->name_; }
    void setName(std::string& name) { this->name_ = name; }
    Common::Date date() const { return this->date_; }
    void setDate(Common::Date& date) { this->date_ = date; }
    int distance() const { return this->distance_; }
    void setDistance(int distance) { this->distance_ = distance; }
    int elevation() const { return this->elevation_; }
    void setElevation(int elevation) { this->elevation_ = elevation; }
private:
    TripType      type_;
    std::string   name_;
    Common::Date  date_;
    int           distance_;
    int           elevation_;
    
};
#endif //TRIPDATA_H__

