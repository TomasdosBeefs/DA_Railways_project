//
// Created by tomas on 10/03/2023.
//

#ifndef RAILWAYS_FILE_READER_H
#define RAILWAYS_FILE_READER_H


#include "Graph.h"
#include "Program_data.h"

class file_reader {

private:

public:
    file_reader();

    static void readNetworks(Program_data&);
    static void readStations(Program_data&);
};












#endif //RAILWAYS_FILE_READER_H
