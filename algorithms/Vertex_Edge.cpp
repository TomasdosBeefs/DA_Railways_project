//
// Created by tomas on 10/03/2023.
//

#include "Vertex_Edge.h"


// By: Gonçalo Leão

#include "Vertex_Edge.h"

/************************* Vertex  **************************/

Vertex::Vertex(std::string Name, std::string District,std::string Municipaly,std::string Township, std::string Line) {
    this->Name = Name;
    this->Municipaly = Municipaly;
    this->Township = Township;
    this->Line = Line;
    this->District = District;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Vertex::addEdge(Edge * e) {
    this->adj.push_back(e);
    e->getDest()->incoming.push_back(e);

}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */

bool Vertex::removeEdge(double ID) {

    bool removedEdge = false;
    auto it = adj.begin();
    while (it != adj.end()) {
        Edge *edge = *it;
        Vertex *dest = edge->getDest();
        if (dest->getId() == id) {
            it = adj.erase(it);
            // Also remove the corresponding edge from the incoming list
            auto it2 = dest->incoming.begin();
            while (it2 != dest->incoming.end()) {
                if ((*it2)->getOrig()->getId() == id) {
                    it2 = dest->incoming.erase(it2);
                }
                else {
                    it2++;
                }
            }
            delete edge;
            removedEdge = true; // allows for multiple edges to connect the same pair of vertices (multigraph)
        }
        else {
            it++;
        }
    }
    return removedEdge;
}
bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}

double Vertex::getId() const {
    return this->id;
}

std::vector<Edge*> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}

bool Vertex::isProcessing() const {
    return this->processing;
}

unsigned int Vertex::getIndegree() const {
    return this->indegree;
}

double Vertex::getDist() const {
    return this->dist;
}

Edge *Vertex::getPath() const {
    return this->path;
}

std::vector<Edge *> Vertex::getIncoming() const {
    return this->incoming;
}

void Vertex::setId(int id) {
    this->id = id;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex::setProcesssing(bool processing) {
    this->processing = processing;
}

void Vertex::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}

void Vertex::setPath(Edge *path) {
    this->path = path;
}


/********************** Edge  ****************************/

Edge::Edge(Vertex *orig, Vertex *dest, double w): orig(orig), dest(dest), weight(w) {}

Edge::Edge(Vertex* Station_A,Vertex* Station_B, double weight, std::string Service, double cost):orig(Station_A), dest(Station_B), weight(weight), Service(Service), cost(cost) {}

Vertex * Edge::getDest() const {
    return this->dest;
}

double Edge::getWeight() const {
    return this->weight;
}

Vertex * Edge::getOrig() const {
    return this->orig;
}

Edge *Edge::getReverse() const {
    return this->reverse;
}

bool Edge::isSelected() const {
    return this->selected;
}

double Edge::getFlow() const {
    return flow;
}

void Edge::setSelected(bool selected) {
    this->selected = selected;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}

void Edge::setFlow(double flow) {
    this->biflow +=  flow - this->flow;
    this->flow = flow;
    this->setCapacity(this->getWeight()-this->biflow);
    this->segment_cost = flow * cost;
    if(this->getOtherDirection() != nullptr){
    this->getOtherDirection()->setBiFlow(this->biflow);
    this->getOtherDirection()->setCapacity(this->getCapacity());}

}

std::string Vertex::getName() const {
    return this->Name;
}

void Vertex::set_INC_capacity(double capacity){
    this->INC_capacity+=capacity;
}


void Vertex::set_OUT_capacity(double capacity) {
    this->OUT_capacity+=capacity;
}

double Vertex::get_OUT() const {
    return this->OUT_capacity;
}


double Vertex::get_INC() const {
    return this->INC_capacity;
}

void Vertex::removeIncomingEdge(Edge *const &edge) {
    std::vector<Edge*>::iterator iter = find(incoming.begin(),incoming.end(), edge);
    if (iter != incoming.end()) {
        incoming.erase(iter);
        Vertex* orig = edge->getOrig();
        orig->removeOutgoingEdge(edge);
        delete edge;
    }
}

void Vertex::removeOutgoingEdge(Edge *const &pe) {
    std::vector<Edge*> edgesToRemove;
    for (Edge *e : this->getAdj()) {
        edgesToRemove.push_back(e);
    }
    for (Edge *e : edgesToRemove) {
        Vertex *dest = e->getDest();
        dest->removeIncomingEdge(e);
        this->removeOutgoingEdge(e);
    }
}

void Edge::setCapacity(double cap){
    this->capacity = cap;
}
double Edge::getCapacity() const{
    return this->capacity;
}
double Edge::getBiFlow() const {
    return biflow;
}
void Edge::setBiFlow(double biflow)  {
    this->biflow =  biflow;
}
void Edge::setOtherDirection(Edge* e){
    this->otherdirection = e;
}
Edge* Edge::getOtherDirection() const {
    return this->otherdirection;
}

void Edge::setSegment_cost(double segment_cost)  {
    this->segment_cost = segment_cost;
}
double Edge::getSegment_cost() const  {
    return this->segment_cost;
}