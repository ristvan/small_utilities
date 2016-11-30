#ifndef MAIN_BASE_HH__
#define MAIN_BASE_HH__

#include "TextFileListener.hh"
#include <list>
#include <string>

// forward declaration
class TripData;

class MainBase : public TextFileListener
{
public:
    MainBase() {}
    virtual ~MainBase();

    void run(const char*);
    virtual void calculate() = 0;

    // TextFileListener implementation
    void processLine(int lineNumber, char* lineString);
private:
    void processToken(int tokenNumber, std::string& token, TripData& tripData);
    void processType(std::string& typeStr, TripData& tripData);
    void processName(std::string& nameStr, TripData& tripData);
    void processDate(std::string& dateStr, TripData& tripData);
    void processDistance(std::string& distanceStr, TripData& tripData);
    void processElevation(std::string& elevationStr, TripData& tripData);

protected:
    std::list<TripData*> trips;
};

#endif /* MAIN_BASE_HH__ */
