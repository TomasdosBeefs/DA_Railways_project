//
// Created by tomas on 15/03/2023.
//


#include <iostream>
#include "Program_data.h"
#include "helpy.h"
#include "file_reader.h"


int main() {

    Program_data data;

    std::vector<Vertex*> LIne = data.Line.find("Linha do Norte")->second;
    for(Edge* e : data.graph.edgeSet){
        if((std::find(LIne.begin(),LIne.end(),e->getOrig()) == LIne.end()) ||(std::find(LIne.begin(),LIne.end(),e->getDest()) == LIne.end()))
        std::cout << e->getOrig()->getName() << "->" << e->getDest()->getName()<<'?';
        }
    }
   /*Helpy helpy(data);
    helpy.terminal();*/

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
    *//*
    Vertex* v = data.Name.find("E")->second;
    Vertex* vv = data.Name.find("D")->second;
    std::cout << data.Cost_Efficient(v,vv);
    Edge* vvv = data.graph.edgeSet[501];
    std::vector<Vertex*> vec;
    std::vector<Edge*>
     edg;
    edg.push_back(vvv);
    data.SubGraphEdit(data.graph, edg,vec);
    data.graph.edmondskarp(v,vv);
    double max = data.graph.Dijkstra(v,vv);
    std::cout << max;*/


