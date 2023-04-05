//
// Created by tomas on 10/03/2023.


#include<iostream>
#include <fstream>
#include <sstream>
#include "file_reader.h"
#include "Vertex_Edge.h"

#include <cstdlib>

void file_reader::readNetworks(Program_data& data) {
    std::string Station_A, Station_B,Service,Capacitystring;
    int Capacity, i = 0;
    std::string line;
    std::ifstream ifs("../testeNetworks.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        std::stringstream iss(line);
        std::getline(iss,Station_A,',');
        std::getline(iss,Station_B,',');
        std::getline(iss,Capacitystring,',');
        std::getline(iss,Service);
        std::stringstream number(Capacitystring);
        number >> Capacity;
    /*    std::string strinnn = data.Name.find(Station_A)->first;
        Edge edge = Edge(data.Name.find(Station_A)->second,data.Name.find(Station_B)->second,Capacity,Service);*/
        if(Station_A == "Senhora das Dores" || Station_B == "Senhora das Dores"){
            std::cout << "SIUSISU";}
        Vertex* vertex = data.Name.find(Station_A)->second;
        Vertex* vertexx = data.Name.find(Station_B)->second;

        data.graph.addBidirectionalEdge(data.Name.find(Station_A)->second,data.Name.find(Station_B)->second,Capacity,Service);


        std::cout << i << '\n';
        i++;


        /*Vertex* a = graph.get_Vertex(Station_A);
        Vertex* b = graph.get_Vertex(Station_B);
        Edge edgee = Edge(a,b,Capacity,Service);
        Edge* edge = &edgee;

        a->addEdge(edge);
        b->addEdge(edge);*/


    }
}


void file_reader::readStations(Program_data& data) {
    int i = 0;
    std::string Name,District,Municipality,Township,Line;
    std::string line;
    std::ifstream ifs("../teste.csv");
    std::getline(ifs,line);
    std::cout << line;
    while(std::getline(ifs,line)){
        std::stringstream iss(line);
        std::getline(iss,Name,',');
        std::getline(iss,District,',');
        std::getline(iss,Municipality,',');
        std::getline(iss,Township,',');
        std::getline(iss,Line);
        if(data.Name.find(Name) != 0){continue;}
        Vertex * vertex = new Vertex(Name,District,Municipality,Township,Line);
        vertex->setId(i);
        i++;


        data.Stations_Network.push_back(vertex);

        data.set_Name(Name,vertex);
        data.set_District(District,vertex);
        data.set_Line(Line,vertex);
        data.set_Municipality(Municipality,vertex);
        data.set_Township(Township,vertex);
        /*Vertex vertex = Vertex(Name,District,Municipality,Township,Line);
        pointer = &vertex;
        data.set_VE(pointer);*/

        /*Vertex vertex = Vertex(Name,District,Municipality,Township,Line);
        pointer = &vertex;
        graph.add_Vertex(pointer);*/

    }

}