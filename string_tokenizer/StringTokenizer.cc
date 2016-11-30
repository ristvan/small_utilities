//#include <iostream>
//#include "StringTokenizer.hh"

using namespace std;

/*StringTokenizer::StringTokenizer(const std::string& str) 
    : str(str), delims(" "), 
      returnDelims(false), 
      lastPos(0), 
      hasMoreTokens(false), 
      numberOfTokens(-1)
{
    initialize();
}
*/
StringTokenizer::StringTokenizer(const std::string& str,
                                 const std::string& delims,
                                 bool  returnDelims)
    : str(str), delims(delims), 
      returnDelims(returnDelims), 
      lastPos(-1), 
      hasMoreTokens(false), 
      numberOfTokens(-1)
{
    initialize();
}

int StringTokenizer::countTokens()
{
    if (numberOfTokens == -1)
    {
        numberOfTokens = 0;

        size_t found = str.find_first_not_of(delims);
        while ( found != std::string::npos )
        {
            ++ numberOfTokens;
            found = str.find_first_of(delims, found);
            found = str.find_first_not_of(delims, found);
        }
    }

    return numberOfTokens;
}

std::string StringTokenizer::nextToken()
{
    if ( !hasMoreTokens )
    {
        // TODO: throw exception
        return string("");
    }
    size_t from = lastPos;
    size_t to   = str.find_first_of(delims, from);
    lastPos = str.find_first_not_of(delims, to);
    hasMoreTokens = lastPos != string::npos;
    return str.substr(from, to - from);
}

std::string StringTokenizer::nextToken(const std::string& delim)
{
}

void StringTokenizer::initialize()
{
    hasMoreTokens = 0 <= countTokens();
    lastPos = str.find_first_not_of(delims);
}

// end of file

