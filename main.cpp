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

    Vertex *v = cringe.Name.find("A")->second;
    Vertex *vv = cringe.Name.find("G")->second;
    //cringe.graph.Most_fluent_stations();
   // std::cout << cringe.graph.edgeSet.size();
/*
    for (int i = 0; i < cringe.graph.edgeSet.size(); i++) {

        std::cout << cringe.graph.edgeSet[i]->getOrig()->getName() << ' '
                  << cringe.graph.edgeSet[i]->getDest()->getName() << '\n';
    }*/

    //std::cout << '\n' << max;
   // cringe.graph.Most_fluent_stations();
    std::cout << '\n';
    //double a =  cringe.graph.Bellman_Ford(v,vv);
    // std::cout << "is tis correct? " << a << '\n';
   /* double test = cringe.Cost_Efficient(v, vv);
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
*/

    std::cout << cringe.graph.edgeSet.size() << '\n';
   std::vector<Edge*> edge;
   std::vector<Vertex*> vertex;
  // vertex.push_back(vv);
   edge.push_back( v->getAdj()[0]);
   cringe.SubGraphCreate(cringe.graph,edge,vertex);
    std::cout << cringe.graph.vertexSet.size() << '\n';
    std::cout << cringe.graph.edgeSet.size() << '\n';




 //   cringe.OriginalGraph();
   std::cout << cringe.graph.vertexSet.size() << '\n';
   std::cout << cringe.graph.edgeSet.size() << '\n';
   std::cout << cringe.graph.edgeSet[0]->getOrig()->getName() << cringe.graph.edgeSet[0]->getDest()->getName();
   //cringe.SubGraph(cringe.graph,edge,vertex);
    double max = cringe.graph.edmondskarp(v, vv);
std::cout << max;

}
