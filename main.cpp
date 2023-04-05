//
// Created by tomas on 15/03/2023.
//


#include <iostream>
#include "algorithms/Program_data.h"
#include "algorithms/file_reader.h"


int main() {

    Program_data cringe;
    std::vector<Vertex *> vector;

    std::cout << '\n';

    Vertex *v = cringe.Name.find("Lisboa Santa Apolónia")->second;
    Vertex *vv = cringe.Name.find("Lisboa Oriente")->second;
    //cringe.graph.Most_fluent_stations();
    std::cout << cringe.graph.edgeSet.size();

    for (int i = 0; i < cringe.graph.edgeSet.size(); i++) {

        std::cout << cringe.graph.edgeSet[i]->getOrig()->getName() << ' '
                  << cringe.graph.edgeSet[i]->getDest()->getName() << '\n';
    }

    double max = cringe.graph.edmondskarp(v, vv);
    std::cout << '\n' << max;
    cringe.graph.Most_fluent_stations();
    std::cout << '\n';
    //double a =  cringe.graph.Bellman_Ford(v,vv);
    // std::cout << "is tis correct? " << a << '\n';
    double test = cringe.Cost_Efficient(v, vv);
    std::cout << "pff dá p " << test << '\n';
    for (Vertex *v: cringe.graph.vertexSet) {
        for (Edge *e: v->getAdj()) {
            std::cout << "Origin->" << v->getName() << ' ' << "Destiny->" << e->getDest()->getName() << ' '
                      << "weight->" << e->getWeight() << ' ' << "Biflow->" << e->getBiFlow() << ' ' << "Flow->"
                      << e->getFlow() << ' ' << "Capacity->" << e->getCapacity() << ' ' << "Reverse flow->"
                      << e->getReverse()->getFlow() << '\n';
        }
    }


    std::cout << "Siuu";


}
