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
    auto i = cringe.Name.begin();
    auto e = cringe.District.begin();

    std::cout << cringe.Name.size() << '\n';
    while( i != cringe.Name.end()){

        std::cout << cringe.Name.size() <<  i->first << "\n";
        i++;
    }
    while( e != cringe.District.end()){

        std::cout << cringe.District.size() << e->first << "\n";
        e++;
    }

}
