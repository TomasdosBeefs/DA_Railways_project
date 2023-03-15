//
// Created by tomas on 10/03/2023.
//

#ifndef RAILWAYS_GRAPH_H
#define RAILWAYS_GRAPH_H

#include<iostream>
#include <vector>
#include "Vertex_Edge.h"


class Graph {
public:
    void add_Vertex(Vertex *);
    Vertex* get_Vertex(std::string Station_A);
    std::vector<Vertex*> get_Vertex_vector();



private:
    std::vector<Vertex *> Graph_Vertex;

};


#endif //RAILWAYS_GRAPH_H
