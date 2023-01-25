#include <sstream>
#include "FileReader.h"

FileReader::FileReader(std::string fileName) {
    m_filename = fileName;
    m_is_opened = false;
}

bool FileReader::isFileExists() {
    std::fstream file(m_filename);
    return file.good();
}

FileReader::~FileReader() {
    if (m_is_opened) {
        m_file.close();
    }
}

bool FileReader::openFile() {
    if (isFileExists()) {
        m_file.open(m_filename);
        m_is_opened = true;
        return true;
    }
    return false;
}


bool FileReader::readFromFile(float *capacity, int *itemsNum, float **valueTable, float **spaceTable) {
    if (!isFileExists()) {
        return false;
    }
    if (!openFile()) {
        return false;
    }
    float tmpCapacity = 0;
    int tmpItemsNum = 0;

    bool ok = readRow(&tmpItemsNum, &tmpCapacity);
    if (!ok) {
        return false;
    }
    float *tmpValueTable = new float[tmpItemsNum];
    float *tmpSpaceTable = new float[tmpItemsNum];

    for (int i = 0; i < tmpItemsNum; i++) {
        ok = readRow(&tmpValueTable[i], &tmpSpaceTable[i]);
        if (!ok) {
            delete[] tmpValueTable;
            delete[] tmpSpaceTable;
            return false;
        }
    }
    *capacity = tmpCapacity;
    *itemsNum = tmpItemsNum;
    *valueTable = tmpValueTable;
    *spaceTable = tmpSpaceTable;
    return true;
}

template<typename T>
bool FileReader::readRow(T *leftColumn, float *rightColumn) {
    std::string line;
    std::getline(m_file, line);
    std::stringstream ss(line);
    ss >> *leftColumn >> *rightColumn;

    if (ss.fail()) {
        return false;
    }


    if (*leftColumn < 0 || *rightColumn < 0) {
        return false;
    }
    return true;
}