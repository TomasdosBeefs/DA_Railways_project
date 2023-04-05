#ifndef HELPY_H
#define HELPY_H

#include <map>
#include <string>

#include "Airport.h"
#include "AirGraph.h"

#define uMap unordered_map
#define uSet unordered_set

class Helpy {
    private:
        AirGraph graph;

        // for search purposes
        uSet<string> airportCodes;
        uMap<string, string> airportNames;
        uSet<string> airlineCodes;
        uMap<string, uSet<string>> cityNames;
        uMap<string, uSet<string>> countryNames;

        // maps used to process commands
        static map<string, int> command, target, what;
               
    public:
        // constructor
        Helpy(AirGraph& graph);

        // methods
        static void lowercase(string& s, bool uppercase = false);
        static void properName(string& s);

        void setAirports(const uSet<string>& codes, const uMap<string, string>& names);
        void setAirlines(const uSet<string>& codes);
        void setLocations(const uMap<string, uSet<string>>& cities, const uMap<string, uSet<string>>& countries);

        string readInput(const string& instruction, uSet<string>& options);
        double readNumber(const string& instruction);
        string readAirport();
        string readCity(bool country = false);
        string readCoordinates();
        string readLocation(string instruction = "");

        uSet<string> readUsableAirlines();
        uSet<string> readUsableCities();
        uSet<string> readUsableCountries();
        uSet<string> readUsableAirports();
        uSet<string>* readRestrictions();

        template <typename T>
        void printAirports(T airports, const list<string>& columnNames);
        void printFlights(const string& airport);
        void printPath(const Path& p);

        void terminal();
        void advanced_mode();
        void guided_mode();
        bool process_command(string& s1, string& s2, string& s3);

        void displayAirportInformation();
        void displayReachableAirports();
        void displayShortestRoutes();
};

#endif