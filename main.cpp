//
// Created by tomas on 15/03/2023.
//


#include <iostream>
#include "algorithms/Program_data.h"
#include "algorithms/file_reader.h"



int main() {

    Program_data cringe;

    file_reader::readStations(cringe);
    file_reader::readNetworks(cringe);

}
