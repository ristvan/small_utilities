#ifndef STRINGTOKENIZER_HH__
#define STRINGTOKENIZER_HH__

class StringTokenizer
{
public:
    StringTokenizer(const std::string& str,
                    const std::string& delims = " \t\n\r",
                    bool  returnDelims = false);

   int countTokens();
   bool hasMoreToken() { return hasMoreTokens; }
   std::string nextToken();
   std::string nextToken(const std::string& delim);
private:
   void initialize();
   std::string str;
   std::string delims;
   bool returnDelims;
   size_t lastPos;
   bool hasMoreTokens;
   int  numberOfTokens;
};

#endif

