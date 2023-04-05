//
// Created by tomas on 10/03/2023.
//

#include "Graph.h"
#include "Vertex_Edge.h"



bool Graph::addBidirectionalEdge(Vertex* v1,Vertex* v2, double weight, std::string Service) {

    if (v1 == nullptr || v2 == nullptr)
        return false;
    double cost;
    Service == "STANDARD" ?  cost = 2 : cost = 4;
    v1->set_OUT_capacity(weight);
    v2->set_INC_capacity(weight);
    auto e1 =  new Edge(v1,v2,weight,Service,cost);
    auto e2 = new Edge(v2,v1,weight,Service,cost);
    auto e1res =  new Edge(v1,v2,weight,Service,cost);
    auto e2res = new Edge(v2,v1,weight,Service,cost);
    e1->setReverse(e2res);
    e2->setReverse(e1res);
    e1->setOtherDirection(e2);
    e2->setOtherDirection(e1);
     v1->addEdge(e1);
     v2->addEdge(e2);

     this->edgeSet.push_back(e1);
     this->edgeSet.push_back(e2);



    return true;
}
int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */


/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */


void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}