//
// Created by tomas on 10/03/2023.
//

/**
 * @file file_reader.h
 * @brief Contains the declaration of file_reader class for reading network and station data from CSV files.
 */

#ifndef RAILWAYS_FILE_READER_H
#define RAILWAYS_FILE_READER_H


#include "Graph.h"
#include "Program_data.h"

/**
 * @class file_reader
 * @brief Reads network and station data from CSV files.
 */
class file_reader {
public:
    /**
     * @brief Reads network data from a CSV file and adds edges to the graph.
     * @param data The Program_data object to store the parsed data.
     */
    static void readNetworks(Program_data& data);

    /**
     * @brief Reads station data from a CSV file and creates Vertex objects.
     * @param data The Program_data object to store the parsed data.
     */
    static void readStations(Program_data& data);
};



#endif //RAILWAYS_FILE_READER_H
