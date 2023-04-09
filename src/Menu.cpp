//
// Created by ritac on 09/04/2023.
//

#include "Menu.h"
#include <string>
#include <iostream>
#include "Program_data.h"
#include "Graph.h"

Menu::Menu(Program_data data) {
    this->data_ = data;

    std::cout << "\n\n ----------------------------------------------\n"
            "|                 Main Menu                    |\n"
            " ----------------------------------------------\n";
    std::cout << "All aboard, captain!\n";
    std::cout << "Select the number of the topic...\n"
            "[1]> Basic Service Metrics\n"
            "[2]> Operation Cost Optimization\n"
            "[3]> Reliability and Sensitivity to Line Failures\n"

            "\n[0]> Quit\n";

    int topic_in_main_menu;
    std::string striTemp;

    while (true) {
        topic_in_main_menu = 0;
        striTemp = "";
        std::cin >> striTemp;
        try {
            topic_in_main_menu = stoi(striTemp);
        }
        catch (...) {
            topic_in_main_menu = 100;
        }


        if (topic_in_main_menu == 1) {
            //Basic Service Metrics
            std::cout << "\n\n ----------------------------------------------\n"
                         "|                Metrics Menu                  |\n"
                         " ----------------------------------------------\n";
            std::cout << "Analysis of the network for management purposes\n";
            std::cout << "Select the number of the topic...\n"
                         "[1]> Maximum number of simultaneous trains between two stations (2.1)\n"
                         "[2]> Stations that require the most amount of trains (2.2)\n"
                         "[3]> Top-k municipalities that should be assigned larger budgets (2.3)\n"
                         "[4]> Top-k districts that should be assigned larger budgets (2.3)\n"
                         "[5]> Maximum trains in a station (2.4)\n"

                         "\n[0]> Quit\n";

            int topic_in_metrics_menu;
            std::cin >> topic_in_metrics_menu;
            std::string striTemp;

            if (topic_in_metrics_menu == 1) {
                std::string station1;
                auto it1 = data.Stations_Network.end(); // Initialize iterator to end

                while (it1 == data.Stations_Network.end() || station1 == "") {
                    std::cout << "Enter station1: \n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n'); // Ignore any remaining input from previous input
                    std::getline(std::cin, station1);

                    it1 = std::find_if(data.Stations_Network.begin(), data.Stations_Network.end(),
                                       [&station1](Vertex *vertex) {
                                           return station1 == vertex->getName();
                                       });
                }

                std::string station2;
                auto it2 = data.Stations_Network.end(); // Initialize iterator to end

                while (it2 == data.Stations_Network.end() || station2 == "") {
                    std::cout << "Enter station2: \n";
                    std::getline(std::cin, station2);

                    it2 = std::find_if(data.Stations_Network.begin(), data.Stations_Network.end(),
                                       [&station2](Vertex *vertex) {
                                           return station2 == vertex->getName();
                                       });
                }


            //function

            //cout the number of simultaneous trains between two stations

            std::cout << "The maximum number of simultaneous trains between the stations " + station1 + " and " +
                         station2 + " is " "\n";
        }
            else if (topic_in_metrics_menu == 2){
                std::cout <<"The stations that require the most amount of trains are is \n";
                //for cycle to print the vector

            }
            else if (topic_in_metrics_menu == 3){
                std::string input ;
                std::cout <<" Introduce the number of municipalities to display... \n";
                std::cin >> input;
                int k = std::stoi(input);

                while(k>data.Municipality.size() || k<data.Municipality.size()){
                    std::cout <<" Introduce the number of stations to display... \n";
                    std::cin >> input;
                    k = std::stoi(input);
                }

                std::cout <<"The top " + input + " municipalities that require the largest  of trains are is \n";

                //for cycle to print the vector

            }
            else if (topic_in_metrics_menu == 4){
                std::string input ;
                std::cout <<" Introduce the number of districts to display... \n";
                std::cin >> input;
                int k = std::stoi(input);
                //verify if number is valid

                while(k>data.District.size() || k<data.District.size()){
                    std::cout <<" Introduce the number of districts to display... \n";
                    std::cin >> input;
                    k = std::stoi(input);
                }

                std::cout <<"The top ", k, " districts that require the largest  of trains are is \n";

                //for cycle to print the vector
            }
            else if (topic_in_metrics_menu == 5){
                std::string station;
                auto it = data.Stations_Network.end(); // Initialize iterator to end

                while (it == data.Stations_Network.end() || station == "") {
                    std::cout << "Enter station: \n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any remaining input from previous input
                    std::getline(std::cin, station);

                    it = std::find_if(data.Stations_Network.begin(), data.Stations_Network.end(), [&station](Vertex* vertex){
                        return station == vertex->getName();
                    });
                }

                //verify if station exists

                std::cout <<"The maximum number of simultaneous trains in the station ", station, ", having the entire railway system in mind, is  " "\n";

            }


            backToMainMenu();
            break;

        } else if (topic_in_main_menu == 2) {
            //Operation Cost Optimization
            std::cout << "\n\n ----------------------------------------------\n"
                         "|              Optimization Menu               |\n"
                         " ----------------------------------------------\n";
            std::cout << "Optimization analysis to minimize costs maintaning the level of service\n";
                         std::cout << "Select the number of the topic...\n"
                         "[1]> Maximum number of simultaneous trains between two stations with minimum cost (3.1)\n"
                         "\n[0]> Quit\n";

            int topic_in_optimization_menu;
            std::string striTemp;

            if (topic_in_optimization_menu == 1) {
                std::string station1;
                auto it1 = data.Stations_Network.end(); // Initialize iterator to end

                while (it1 == data.Stations_Network.end() || station1 == "") {
                    std::cout << "Enter station1: \n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n'); // Ignore any remaining input from previous input
                    std::getline(std::cin, station1);

                    it1 = std::find_if(data.Stations_Network.begin(), data.Stations_Network.end(),
                                       [&station1](Vertex *vertex) {
                                           return station1 == vertex->getName();
                                       });
                }

                std::string station2;
                auto it2 = data.Stations_Network.end(); // Initialize iterator to end

                while (it2 == data.Stations_Network.end() || station2 == "") {
                    std::cout << "Enter station2: \n";
                    std::getline(std::cin, station2);

                    it2 = std::find_if(data.Stations_Network.begin(), data.Stations_Network.end(),
                                       [&station2](Vertex *vertex) {
                                           return station2 == vertex->getName();
                                       });
                }

                //check if stations exist

                //function

                //cout the number of simultaneous trains between two stations

                std::cout <<"The maximum number of simultaneous trains between the stations " + station1 + " and " + station2 +" , with minimum cost, is " "\n";

            }

            backToMainMenu();
            break;
        } else if (topic_in_main_menu == 3) {
            //Reliability and Sensitivity to Line Failures
            std::cout << "\n\n ----------------------------------------------\n"
                         "|               Failures Menu                  |\n"
                         " ----------------------------------------------\n";
            std::cout << "Analysis of the sensitivity of network segments to failure\n";
            std::cout << "Select the number of the topic...\n"
                         "[1]> Maximum number of simultaneous trains between two stations with reduced connectivity (4.1)\n"
                         "[2]> Stations most affected by each segment failure (4.2)\n"
                         "\n[0]> Quit\n";

            int topic_in_failures_menu;
            std::string striTemp;

            if (topic_in_failures_menu == 1) {
                std::string station1;
                auto it1 = data.Stations_Network.end(); // Initialize iterator to end

                while (it1 == data.Stations_Network.end() || station1 == "") {
                    std::cout << "Enter station1: \n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n'); // Ignore any remaining input from previous input
                    std::getline(std::cin, station1);

                    it1 = std::find_if(data.Stations_Network.begin(), data.Stations_Network.end(),
                                       [&station1](Vertex *vertex) {
                                           return station1 == vertex->getName();
                                       });
                }

                std::string station2;
                auto it2 = data.Stations_Network.end(); // Initialize iterator to end

                while (it2 == data.Stations_Network.end() || station2 == "") {
                    std::cout << "Enter station2: \n";
                    std::getline(std::cin, station2);

                    it2 = std::find_if(data.Stations_Network.begin(), data.Stations_Network.end(),
                                       [&station2](Vertex *vertex) {
                                           return station2 == vertex->getName();
                                       });
                }

                //function

                //cout the number of simultaneous trains between two stations

                std::cout <<"The maximum number of simultaneous trains between the stations " + station1 + " and " + station2 + " with reduced connectivity is " "\n";
            }
            else if (topic_in_failures_menu == 2){
                std::string input ;
                std::cout <<" Introduce the number of stations to display... \n";
                std::cin >> input;
                int k = std::stoi(input);

                while(k>data.Stations_Network.size() || k<data.Stations_Network.size()){
                    std::cout <<" Introduce the number of stations to display... \n";
                    std::cin >> input;
                    k = std::stoi(input);
                }

                std::cout <<"The top ", k, " stations that are the most affected by each segment failure \n";

                //for cycle to print the vector

            }

            backToMainMenu();
            break;
        }


        else if (topic_in_main_menu == 0) break;
        else std::cout << "Error: Choose one number of the Main Menu.\n";
    }
}



void Menu::Error(const std::string &erro) {
    std::cout << "Error: " << erro << std::endl;

}

void Menu::backToMainMenu( ){
    std::cout << "\n[1]> Back to Main Menu.\n"
                 "[0]> Quit.\n";
    int back;
    std::string striBack;
    while (true) {
        back = 0;
        striBack = "";
        std::cin >> striBack;
        try {
            back = stoi(striBack);
        }
        catch (...) {
            back = 10;
        }
        if (back == 1) Menu menu(data_);
        else if (back == 0) break;
        std::cout << "> Invalid choice.\n"
                     "[1]> Back to Main Menu.\n"
                     "[0]> Quit.\n";
    }

}