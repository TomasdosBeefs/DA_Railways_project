//
// Created by tomas on 10/03/2023.


#include<iostream>
#include <fstream>
#include <sstream>
#include "file_reader.h"
#include "Vertex_Edge.h"

void file_reader::readNetworks(Program_data& data) {
    std::string line;
    std::ifstream ifs("../data/networks.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){

        std::stringstream iss(line);
        std::string Station_A, Station_B,Service;
        int Capacity;
        char comma;
        iss >> Station_A >> comma >> Station_B >> comma >> Capacity >> comma >> Service;

        Edge edge = Edge(data.Name.find(Station_A)->second,data.Name.find(Station_B)->second,Capacity,Service);

        Vertex* vertex = data.Name.find(Station_A)->second;

        vertex->addEdge(&edge);




        /*Vertex* a = graph.get_Vertex(Station_A);
        Vertex* b = graph.get_Vertex(Station_B);
        Edge edgee = Edge(a,b,Capacity,Service);
        Edge* edge = &edgee;

        a->addEdge(edge);
        b->addEdge(edge);*/


    }
}


void file_reader::readStations(Program_data& data) {


    std::string line;
    std::ifstream ifs("../data/stations.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){

        std::stringstream iss(line);
        std::string Name,District,Municipality,Township,Line;
        char comma;
        iss >> Name >> comma >> District >> comma >> Municipality >> Township >> Line;

        Vertex vertex = Vertex(Name,District,Municipality,Township,Line);

        data.Stations_Network.push_back(&vertex);

        data.set_Name(Name,&vertex);
        data.set_District(District,&vertex);
        data.set_Line(District,&vertex);
        data.set_Municipality(Municipality,&vertex);
        data.set_Township(Township,&vertex);
        /*Vertex vertex = Vertex(Name,District,Municipality,Township,Line);
        pointer = &vertex;
        data.set_VE(pointer);*/

        /*Vertex vertex = Vertex(Name,District,Municipality,Township,Line);
        pointer = &vertex;
        graph.add_Vertex(pointer);*/

    }

}