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

    std::vector<Edge*>::iterator it = this->getAdj().begin();

    while(it != this->getAdj().end()){

        if((*it)->getDest()->getId() == ID){

            std::vector<Edge*>::iterator it2 = (*it)->getDest()->getIncoming().begin();

            while(it2 != (*it)->getDest()->getIncoming().end()){

                if((*it2)->getOrig()->getId() == this->getId()){

                    (*it)->getDest()->getIncoming().erase(it2);

                }
                it2++;
            }

            this->getAdj().erase(it);

        }
        it++;


    }

    return false;

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
    this->getReverse()->setBiFlow(this->biflow);
    this->setCapacity(this->getWeight()-this->biflow);
    this->getReverse()->setCapacity(this->getCapacity());

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