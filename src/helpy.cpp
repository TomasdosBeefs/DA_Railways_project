#include "helpy.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <list>
#include <map>
#include <string>

#include "Graph.h"
#include "Program_data.h"
//#include "libfort/fort.hpp"

// cores para o output
#define RESET   "\033[0;m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"
#define BOLD    "\033[1m"
#define BREAK   "- - - - - - - - - - - - - - - - - - - - -"
#define BREAK1  std::cout << std::endl << YELLOW << BREAK << RESET << std::endl << std::endl;

std::map<std::string, int> Helpy::command = {{"display", 1}, {"print", 1}, {"show", 1}};
std::map<std::string, int> Helpy::target = {{"all", 6}, {"shortest", 8}, {"fastest", 8}, {"reachable", 10}};
std::map<std::string, int> Helpy::what = {{"stations", 24}, {"info", 24}, {"route", 27}, {"routes", 27}, {"flight", 27},
                                {"flights", 27}, {"path", 27}, {"paths", 27}, {"airport", 29}, {"airports", 29}};

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
Helpy::Helpy(Program_data& data) : graph(data.graph) {}

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
        case(36) : {
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
    //fazer display por tabela
    for(Vertex* v : graph.vertexSet){
        std::cout << v->getId() << std::endl;
    }
}