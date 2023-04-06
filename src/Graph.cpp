//
// Created by tomas on 10/03/2023.
//

#include "Graph.h"
#include "Vertex_Edge.h"

Graph::Graph() {};

Graph::Graph(const Graph & graph) {

    for(Vertex* v : graph.vertexSet){
        Vertex* a = new Vertex(*v);
        this->vertexSet.push_back(a);
    }

    for(Edge* e : graph.edgeSet){
        Edge* d = new Edge(*e);
        addEdge(d);
    }


}

Graph::Graph(const Graph& graph,std::vector<Edge*> &edge,std::vector<Vertex*> &vertex){ // quando adiciona ao vetor vertex deve por todas as edges no vetor edge

  /*  for(Vertex* v : graph.vertexSet){
        if(std::find(vertex.begin(),vertex.end(),v) == vertex.end()){
        Vertex* a = new Vertex(*v);
        this->addVertex(a);
        }
    }*/
  for(Vertex* v : vertex){
      edge.insert(v->getAdj().begin(),v->getAdj().end(),edge.end());
      edge.insert(v->getIncoming().begin(),v->getIncoming().end(),edge.end());

  }

    for(Edge* e : graph.edgeSet){
        if(std::find(edge.begin(),edge.end(),e) == edge.end()){
            Vertex* v1 = this->findVertex(e->getOrig()->getId());
            Vertex* v2 = this->findVertex(e->getDest()->getId());
            Edge* a = new Edge(v1,v2,e);
            this->addEdge(a);
            }

    }


}


bool Graph::addBidirectionalEdge(Vertex *v1, Vertex *v2, double weight, std::string Service) {

    if (v1 == nullptr || v2 == nullptr)
        return false;
    double cost;
    Service == "STANDARD" ? cost = 2 : cost = 4;
    v1->set_OUT_capacity(weight);
    v2->set_INC_capacity(weight);
    auto e1 = new Edge(v1, v2, weight, Service, cost);
    auto e2 = new Edge(v2, v1, weight, Service, cost);
    auto e1res = new Edge(v1, v2, weight, Service, cost);
    auto e2res = new Edge(v2, v1, weight, Service, cost);
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

bool Graph::addVertex(Vertex *v) {

    this->vertexSet.push_back(v);
    return true;
}
bool Graph::removeVertex(Vertex *v) {
    auto iter = this->vertexSet.begin();

    while(iter != this->vertexSet.end()){
        if((*iter) == v){
            for(Edge*e : (*iter)->getAdj()){
                removeEdge(e);
            }
            this->vertexSet.erase(iter);
            break;
        }
        iter++;
    }
    return true;
}

bool Graph::removeEdge(Edge *e) {
    auto iter = this->edgeSet.begin();
    int removed = 0;
    Edge* e1 = e->getOtherDirection();
    Edge* e2;
    while (iter != this->edgeSet.end()) {
        if ((*iter) == e) {
            removed++;
            iter = this->edgeSet.erase(iter);
            continue;
        }
        else if((*iter) == e->getOtherDirection()){
            removed++;
            iter = this->edgeSet.erase(iter);
            continue;
        }
        if (removed == 2)break;
        iter++;
    }
    (e)->getOrig()->removeEdge((e)->getDest()->getId());
    (e1)->getOrig()->removeEdge((e1)->getDest()->getId());
return true;
}

std::vector<Edge *> Graph::getEdgeSet() {

    return this->edgeSet;

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
Vertex *Graph::findVertex(const int &id) const {
    for (auto v: vertexSet)
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
                delete[] m[i];
        delete[] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete[] m[i];
        delete[] m;
    }
}

bool Graph::addEdge(Edge *e) {
    this->edgeSet.push_back(e);
    e->getOrig()->addEdge(e);
    return true;
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}