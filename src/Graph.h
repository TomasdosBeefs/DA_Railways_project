//
// Created by tomas on 10/03/2023.
//

#ifndef RAILWAYS_GRAPH_H
#define RAILWAYS_GRAPH_H



#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
//#include "../data_structures/MutablePriorityQueue.h"

#include "Vertex_Edge.h"

class Graph {
public:

    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const int &id) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(Vertex* v);
    void augmentPath(Vertex* source, Vertex* sink, double f);
    bool Find_path(Vertex* source, Vertex* dest);
    double Find_Bottleneck(Vertex* source, Vertex* dest);
    double edmondskarp(Vertex* source, Vertex* sink);
    void Most_fluent_stations();
    double Bellman_Ford(Vertex* v1, Vertex* v2);
    void Edge_Relaxation(Edge* e);

    /*
     * Adds an edge to a graph (this), given the contents of vethe source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool removeEdge(Edge* e);
    bool removeVertex(Vertex* v);
    bool addEdge(const int &sourc, const int &dest, double w);
    bool addEdge(Edge*);
    bool addBidirectionalEdge(Vertex* v1, Vertex* v2, double weight, std::string Service);

    int getNumVertex() const;
    std::vector<Vertex *> getVertexSet() const;
    std::vector<Vertex *> vertexSet;
    std::vector<Edge *> edgeSet;
    std::vector<Edge *> getEdgeSet();

protected:
       // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;


    int find(std::vector<Edge *> vector, Edge *value);
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */


#endif //RAILWAYS_GRAPH_H
