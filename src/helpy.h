#ifndef HELPY_H
#define HELPY_H

#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "Graph.h"
#include "Program_data.h"

#define uMap std::unordered_map
#define uSet std::unordered_set

class Helpy {
    private:
        Graph graph;

        // for search purposes

        // maps used to process commands
        static std::map<std::string, int> command, target, what;
               
    public:
        // constructor
        Helpy(Program_data& data);

        // methods
        static void lowercase(std::string& s, bool uppercase = false);
        std::string readInput(const std::string& instruction, uSet<std::string>& options);

        void displayAllStations();

        void terminal();
        void advanced_mode();
        void guided_mode();
        bool process_command(std::string& s1, std::string& s2, std::string& s3);
};

#endif