#ifndef TEXT_FILE_READER_HH
#define TEXT_FILE_READER_HH

class TextFileListener;

class TextFileReader
{
public:
    TextFileReader() : listener(0) {}
    void addFileListener(TextFileListener *listener);
    void read(const char* fileName);
private:
    TextFileListener *listener;
};

#endif /* TEXT_FILE_READER_HH */

