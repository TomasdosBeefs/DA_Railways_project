//
// Created by tomas on 15/03/2023.
//


#include <iostream>
#include "algorithms/Program_data.h"
#include "algorithms/file_reader.h"



int main() {

    Program_data cringe;
    std::vector<Vertex*> vector;

    std::cout << '\n';

  Vertex* v = cringe.Name.find("A")->second;
    Vertex* vv = cringe.Name.find("G")->second;
    //cringe.graph.Most_fluent_stations();
    //cringe.graph.edmondskarp(v,vv);
    cringe.graph.edmondskarp(v,vv);
    std::cout << '\n';
    cringe.graph.Most_fluent_stations();
    std::cout << '\n';

    for(Vertex* v : cringe.graph.vertexSet){
        for(Edge* e : v->getAdj()){
            std::cout << "Origin->" << v->getName() << ' ' << "Destiny->" << e->getDest()->getName() << ' ' << "weight->" << e->getWeight() << ' ' << "Biflow->" << e->getBiFlow() << ' ' << "Flow->" << e->getFlow() <<' '<<"Capacity->" << e->getCapacity() << ' ' << "Reverse flow->" << e->getReverse()->getFlow() << '\n';
        }
    }


  std::cout  <<  "Siuu";




}
