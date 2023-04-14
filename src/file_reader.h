//
// Created by tomas on 10/03/2023.
//

#ifndef RAILWAYS_FILE_READER_H
#define RAILWAYS_FILE_READER_H


#include "Graph.h"
#include "Program_data.h"

/**
 * @class file_reader
 * @brief Class for reading network and station data from files.
 *
 * This class provides functionality for reading network and station data from external files and populating the
 * relevant data structures in the `Program_data` object.
 */

class file_reader {


public:
    /**
     * @brief Default constructor for file_reader class.
     */
    file_reader();

    /**
     * @brief Reads network data from a file and populates the Program_data object.
     *
     * This static function reads network data from a file and populates the relevant data structures in the Program_data
     * object. It is called by the file_reader class to read and process the network data.
     *
     * @param data The Program_data object to populate with the network data.
     */
    static void readNetworks(Program_data& data);

    /**
     * @brief Reads station data from a file and populates the Program_data object.
     *
     * This static function reads station data from a file and populates the relevant data structures in the Program_data
     * object. It is called by the file_reader class to read and process the station data.
     *
     * @param data The Program_data object to populate with the station data.
     */
    static void readStations(Program_data& data);
};












#endif //RAILWAYS_FILE_READER_H
