//
// Created by tomas on 10/03/2023.


#include<iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "file_reader.h"
#include "Vertex_Edge.h"

 void file_reader::readNetworks(Program_data& data) {
    std::string Station_A, Station_B,Service,Capacitystring;
    int Capacity;
    std::string line;
    std::ifstream ifs("../data/network.csv");
    std::getline(ifs,line, '\n');
    while(std::getline(ifs,line, '\n')){
        std::regex rgx(",(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))");
        std::sregex_token_iterator iter(line.begin(), line.end(), rgx, -1);

        Station_A = *iter;
        iter++;
        Station_B = *iter;
        iter++;
        Capacitystring = *iter;
        iter++;
        Service = *iter;

        std::stringstream number(Capacitystring);
        number >> Capacity;

        data.graph.addBidirectionalEdge(data.Name.find(Station_A)->second,data.Name.find(Station_B)->second,Capacity,Service);
    }
}


 void file_reader::readStations(Program_data& data) {
    int id = 0;
    std::string Name,District,Municipality,Township,Line;
    std::string line;
    std::ifstream ifs("../data/stations.csv");
    std::getline(ifs,line, '\n');
    while(std::getline(ifs,line, '\n')){
        std::regex rgx(",(?=(?:[^\"]*\"[^\"]*\")*(?![^\"]*\"))");
        std::sregex_token_iterator iter(line.begin(), line.end(), rgx, -1);

        Name = *iter;
        iter++;
        District = *iter;
        iter++;
        Municipality = *iter;
        iter++;
        Township = *iter;
        iter++;
        Line = *iter;

        if(data.Name.find(Name) != data.Name.end()){continue;}
        Vertex * vertex = new Vertex(Name,District,Municipality,Township,Line);
        vertex->setId(id);
        id++;

        data.Stations_Network.push_back(vertex);

        data.set_Name(Name,vertex);
        data.set_District(District,vertex);
        data.set_Line(Line,vertex);
        data.set_Municipality(Municipality,vertex);
        data.set_Township(Township,vertex);
    }
}

