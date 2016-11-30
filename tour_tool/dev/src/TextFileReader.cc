#include "TextFileReader.hh"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TextFileListener.hh"

using namespace std;

void TextFileReader::addFileListener(TextFileListener *listener)
{
    this->listener = listener;
}

void TextFileReader::read(const char* filename)
{
    if (filename == NULL || 0 == strcmp(filename, ""))
    {
        cerr << "Invalid filename!"  << endl;
        return;
    }

    FILE *fp = fopen(filename, "rt");
    if (!fp)
    {
        cerr << "Cannot read file: " << filename << endl;
        return;
    }
    char line[1024];
    int lineNumber = 0;
    while (fgets(line, 1024, fp))
    {
        ++ lineNumber;
        if (listener)
        {
            listener->processLine(lineNumber, line);
        }
    }
    fclose(fp);
}


//end of file

