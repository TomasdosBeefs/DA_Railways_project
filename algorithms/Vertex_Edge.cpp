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
    this->getAdj().push_back(e);
    e->getDest()->getIncoming().push_back(e);

}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Vertex::removeEdge(int ID) {

    for(auto e : this->getAdj()){

        if(e->getDest()->getId() == ID){

            std::remove(this->getAdj().begin(), this->getAdj().end(),e);
            std::remove(e->getDest()->getIncoming().begin(),e->getDest()->getIncoming().end(),e);
            return true;
        }

    }

    return false;

}
bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}

int Vertex::getId() const {
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

Edge::Edge(Vertex* Station_A,Vertex* Station_B, double Capacity, std::string Service):orig(Station_A), dest(Station_B), weight(Capacity), Service(Service) {}

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
    this->flow = flow;
}
