#include "helpy.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

#include "Graph.h"
#include "Program_data.h"
#include "lib/fort.hpp"

// cores para o output
#define RESET   "\033[0;m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define BOLD    "\033[1m"
#define BREAK   "- - - - - - - - - - - - - - - - - - - - -"
#define BREAK1  std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;

std::map<std::string, int> Helpy::command = {{"display", 1}, {"print", 1}, {"show", 1}};
std::map<std::string, int> Helpy::target = {{"all", 6}, {"shortest", 8}, {"fastest", 8}, {"reachable", 10}, {"maximum", 11}};
std::map<std::string, int> Helpy::what = {{"stations", 24}, {"info", 24}, {"route", 27}, {"routes", 27}, {"flight", 27},
                                {"flights", 27}, {"path", 27}, {"paths", 27}, {"trains", 29}, {"trains", 29}};

/**
 * @brief turns all the characters of a string into lowercase or uppercase
 * @complexity O(n)
 * @param s string to be modified
 * @param uppercase if true turns all the characters of the string to uppercase; if false turns all the characters of the string to lowercase
 */
void Helpy::lowercase(std::string & s, bool uppercase){
    for (char& c : s){
        c = (uppercase) ? (char) toupper(c) : (char) tolower(c);
    }
}

/**
 * @brief Construct a new Helpy:: Helpy object
 * @param graph graph that contains all the data regarding Airports, Airlines and flights
 */
Helpy::Helpy(Program_data& data) : graph(data.graph), data(data) {}

/**
 * @brief reads a line of user input
 * @complexity O(n^2)
 * @param instruction the instruction that will be displayed before prompting the user to type
 * @param options the options that will be displayed to the user
 * @return read input
 */
std::string Helpy::readInput(const std::string& instruction, uSet<std::string>& options){
    std::string res;
    bool valid = false;

    while (true){
        std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;
        std::cout << instruction << std::endl << std::endl;

        std::string line; getline(std::cin >> std::ws, line);
        lowercase(line);

        std::istringstream line_(line);

        while (line_ >> res){
            if (options.find(res) != options.end()){
                valid = true;
                break;
            }
        }

        if (valid) break;

        std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;
        std::cout << RED << "Invalid command! Please, try again." << RESET << std::endl;
    }
    return res;
}


/**
 * @brief allostd::ws the user to choose the mode of the UI
 * @complexity O(n^2)
 */
void Helpy::terminal(){
    std::string instruction = "Which mode would you prefer?\n\n"
                         "* Guided\n"
                         "* Advanced";
    uSet<std::string> options = {"guided", "advanced"};

    if (readInput(instruction, options) == "guided"){
        guided_mode();
    }
    else{
        advanced_mode();
    }
}

/**
 * @brief executes the advanced mode of the UI
 * @complexity O(1)
 */
void Helpy::advanced_mode(){
b1: std::cout << std::endl << YELLOW << BREAK << RESET << std::endl;
    std::cout << std::endl << "How can I be of assistance?" << std::endl << std::endl;

    std::string s1, s2, s3;
    std::istringstream s_;

    std::cin >> s1; lowercase(s1);

    if (s1 == "quit" || s1 == "no" || s1 == "die"){
        goto e1;
    }

    std::cin >> s2;
    lowercase(s2);

    std::cin >> s3;
    lowercase(s3);

    // processar o comando
    if (!process_command(s1, s2, s3)){
        goto b1;
    }

    std::cout << std::endl << YELLOW << BREAK << RESET << std::endl;
    std::cout << std::endl << "Anything else? (Yes/No)" << std::endl << std::endl;

    s1.clear(); getline(std::cin >> std::ws, s1);
    lowercase(s1);

    s_.clear(); s_.str(s1);

    while (s_ >> s1){
        if (s1 == "yes" || s1 == "y"){
            goto b1;
        }
    }

e1: std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;
    std::cout << "See you next time!" << std::endl << std::endl;
}

/**
 * @brief executes the guided mode of the UI
 * @complexity O(1)
 */
void Helpy::guided_mode(){
b2: std::cout << std::endl << YELLOW << BREAK << RESET << std::endl;
    std::cout << std::endl << "Hello! How can I be of assistance?" << std::endl;
    std::cout << std::endl;
    std::cout << "* Display" << std::endl;
    std::cout << std::endl;

    std::string s1, s2, s3;
    std::istringstream s_;

    std::cin >> s1; lowercase(s1);
    if (s1 == "display"){
        std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;
        std::cout << "* Airport" << std::endl;
        std::cout << "* Shortest" << std::endl;
        std::cout << "* Reachable" << std::endl;
        std::cout << std::endl;
    }
    else if (s1 == "quit"){
        goto e2;
    }
    else { // erro
        process_command(s1, s2, s3);
        goto b2;
    }

    std::cin >> s2; lowercase(s2);

    if (s2 == "airport"){
        std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;
        std::cout << "* Information" << std::endl;
        std::cout << std::endl;
    }
    else if (s2 == "shortest"){
        std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;
        std::cout << "* Routes" << std::endl;
        std::cout << std::endl;
    }
    else if (s2 == "reachable"){
        std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;
        std::cout << "* Airports" << std::endl;
        std::cout << std::endl;
    }
    else if (s2 == "quit"){
        goto e2;
    }
    else{ // erro
        process_command(s1, s2, s3);
        goto b2;
    }

    std::cin >> s3; lowercase(s3);

    if (s3 == "quit"){
        goto e2;
    }

    // processar o comando
    if (!process_command(s1, s2, s3)){
        goto b2;
    }

t2: std::cout << std::endl << YELLOW << BREAK << RESET << std::endl;
    std::cout << std::endl << "Anything else? (Yes/No)" << std::endl;

    s1.clear(); getline(std::cin >> std::ws, s1);
    lowercase(s1);

    s_.clear(); s_.str(s1);

    while (s_ >> s1){
        if (s1 == "yes" || s1 == "y"){
            goto b2;
        }
    }

e2: std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;
    std::cout << "See you next time!" << std::endl << std::endl;
}

/**
 * @brief processes the commands that were inputted
 * @complexity O(n^2 * log(n))
 * @param s1 first word of the command
 * @param s2 second word of the command
 * @param s3 third word of the command
 * @return 'true' if the command exists, 'false' otherwise
 */
bool Helpy::process_command(std::string& s1, std::string& s2, std::string& s3){
    switch (command[s1] + target[s2] + what[s3]){
        case(31) : {
            displayAllStations();
            break;
        }
        case(41) : {
            displayMaximumTrains();
            break;
        }
        case (40) : {
            break;
        }
        default : {
            std::cout << std::endl << YELLOW << BREAK << RESET << std::endl;
            std::cout << std::endl << RED << "Invalid command! Please, type another command." << RESET << std::endl;

            return false;
        }
    }
    return true;
}

void Helpy::displayAllStations() {
    fort::utf8_table table;
    table.set_border_style(FT_NICE_STYLE);

    table << fort::header;

    std::vector<std::string> columnNames = {"ID", "Name", "District", "Municipality", "Line"};

    for (const auto& column : columnNames) {
        table << fort::header << column;
    }

    table << fort::endr;

    for (int i = 1; i < graph.vertexSet.size(); i++) {
        table << graph.vertexSet[i]->getId() << graph.vertexSet[i]->getName() << graph.vertexSet[i]->getDistrict() << graph.vertexSet[i]->getMunicipality() << graph.vertexSet[i]->getLine() << fort::endr;
    }

    // Adjust column width based on maximum length of data in each column
    table.column(0).set_cell_text_align(fort::text_align::center);
    table.column(1).set_cell_text_align(fort::text_align::center);
    table.column(1).set_cell_min_width(20);
    table.column(2).set_cell_text_align(fort::text_align::center);
    table.column(3).set_cell_text_align(fort::text_align::center);
    table.column(3).set_cell_min_width(20);
    table.column(4).set_cell_text_align(fort::text_align::center);

    // Print formatted table
    std::cout << table.to_string() << std::endl;
}

void Helpy::displayMaximumTrains() {

    b1: std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;

    std::cout << "Departure station" <<std::endl << std::endl;
    std::cout << "Choose from: \n\n" << RED << "All Stations \n" << "District \n" << "Municipality \n" << "Line \n";

    std::string s1,s2,s3;
    std::istringstream s_;

    std::cin >> s1; //need to lowecase?

   /* if(s1 != "All Stations" && s1 != "District" && s1 != "Municipality" && s1 != "Line" ){
        std::cout << "Invalid Input\n try again!" << std::endl;//tlvz fzr outra coisa
    }*/
    // if(s1 == "All Stations"){



            // Define page size
            const int page_size = 5;

            // Get total number of pages
            int num_pages = data.Name.size() / page_size + (data.Name.size() % page_size == 0 ? 0 : 1);

            // Print pages
            int current_page = 1;
            while (true) {
                // Get start and end indices for current page
                int start_index = (current_page - 1) * page_size;
                int end_index = start_index + page_size > data.graph.vertexSet.size() ? data.graph.vertexSet.size() : start_index + page_size;

                // Create table for current page
                fort::utf8_table table;
                table << fort::header << "ID" << "Name" << fort::endr;
                for (int i = start_index; i < end_index; i++) {
                    table << data.graph.vertexSet[i]->getId() << data.graph.vertexSet[i]->getName() << fort::endr;
                }

                // Print table and page number
                std::cout << table.to_string() << std::endl;
                std::cout << "Page " << current_page << " of " << num_pages << std::endl;

                // Ask user if they want to go to the next or previous page, or exit
                std::string input;
                std::cout << "Press 'n' for next page, 'p' for previous page, or 'q' to quit: ";
                std::cin >> input;

                // Check input and update current page accordingly
                if (input == "n") {
                    if (current_page == num_pages) {
                        std::cout << "Already on the last page." << std::endl;
                    } else {
                        current_page++;
                    }
                } else if (input == "p") {
                    if (current_page == 1) {
                        std::cout << "Already on the first page." << std::endl;
                    } else {
                        current_page--;
                    }
                } else if (input == "q") {
                    break;
                } else {
                    std::cout << "Invalid input. Please try again." << std::endl;
                }

                // Print separator
                std::cout << "----------------------------------------" << std::endl;
            }


        }













