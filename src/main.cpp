//
// Created by tomas on 15/03/2023.
//


#include <iostream>
#include "Program_data.h"
#include "helpy.h"
#include "file_reader.h"


int main() {

    Program_data data;
    Helpy helpy(data);
    helpy.terminal();

    /*
    Program_data cringe;
    std::string input;
    std::cin >> input;

    if (input == "f"){
        std::vector<std::pair<std::string, int>> test = cringe.graph.Budget_needed_district();
        for (std::pair<std::string, int> par : test){
            std::cout << par.first << " " << par.second << '\n';
        }
    }
    */
}
