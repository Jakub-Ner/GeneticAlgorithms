#ifndef GENETICALG_FILEREADER_H
#define GENETICALG_FILEREADER_H

#include <fstream>
#include <iostream>

class FileReader {
    std::fstream m_file;
    std::string m_filename;
    bool m_is_opened;

public:
    FileReader(std::string fileName);

    ~FileReader();

    bool readFromFile(float *capacity, int *itemsNum, float **spaceTable, float **valueTable);

private:
    bool openFile();

    bool isFileExists();

    template<typename T>
    bool readRow(T *leftColumn, float *rightColumn);
};


#endif //GENETICALG_FILEREADER_H
