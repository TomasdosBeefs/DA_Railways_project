//
// Created by tomas on 15/03/2023.
//


#include <iostream>
#include "Program_data.h"



int main() {

    Program_data cringe;

    file_reader::readStations(&cringe);
    file_reader::readNetworks(&cringe);

}
