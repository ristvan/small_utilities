#ifndef TEXT_FILE_LISTENER_HH__
#define TEXT_FILE_LISTENER_HH__

class TextFileListener
{
public:
    virtual void processLine(int lineNumber, char *lineString) = 0;
};

#endif /* TEXT_FILE_LISTENER_HH__ */

