//
// Created by tomas on 10/03/2023.
//

#ifndef RAILWAYS_VERTEX_EDGE_H
#define RAILWAYS_VERTEX_EDGE_H


// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_VERTEX_EDGE
#define DA_TP_CLASSES_VERTEX_EDGE

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
//#include "../data_structures/MutablePriorityQueue.h"

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

class Vertex {
public:
    Vertex(std::string Name, std::string District,std::string Municipaly,std::string Township, std::string Line);
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
    Vertex(const Vertex &other);

    std::string getName() const;
    std::string getDistrict() const;
    std::string getMunicipality() const;
    std::string getTownship() const;
    std::string getLine() const;
    double get_INC() const;
    double get_OUT() const;

    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    double getId() const;
    Edge *getPath() const;
    std::vector<Edge *> getIncoming() const;

    void set_INC_capacity(double capacity);
    void set_OUT_capacity(double capacity);
    void setId(int id);
    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Edge *path);
    void addEdge(Edge* e);
    bool removeEdge(double ID);
    //removeEdge com Id tambem parece boa idea
    bool operator==(const Vertex& other) const {
        return (id == other.id); // Compare the id of the vertices
    }
    bool operator<(const Vertex& other) const {
        return dist < other.dist;
    }

   // friend class MutablePriorityQueue<Vertex>;
    void removeIncomingEdge(Edge *const &pEdge);

    void removeOutgoingEdge(Edge *const &pEdge);

protected:
    std::string Name;
    std::string District;
    std::string Municipaly;
    std::string Township;
    std::string Line;
    //Vertex* prev = nullptr;
    double cost = 0;
    double INC_capacity = 0;
    double OUT_capacity = 0;
    double id;                // identifier
    std::vector<Edge *> adj;  // outgoing edges

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = INF;
    Edge *path = nullptr;

    std::vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double w);
    Edge(Vertex* Station_A,Vertex* Station_B, double weight, std::string Service, double cost);

    Vertex * getDest() const;
    double getWeight() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;
    double getCapacity() const;
    double getBiFlow() const;
    Edge* getOtherDirection() const;
    double getSegment_cost() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setFlow(double flow);
    void setCapacity(double cap);
    void setBiFlow(double biflow);
    void setOtherDirection(Edge* e);
    void setSegment_cost(double segment_cost);

    bool operator==(const Edge& other) const {
        return orig == other.orig &&
               dest == other.dest &&
               weight == other.weight &&
               Service == other.Service;
    }
protected:

    std::string Service;
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity
    double capacity = 0;
    double cost = 0;

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;
    Edge *otherdirection = nullptr;

    double flow = 0; // for flow-related problems
    double biflow = 0;
    double segment_cost = 0;
};

#endif /* DA_TP_CLASSES_VERTEX_EDGE */

#endif //RAILWAYS_VERTEX_EDGE_H
