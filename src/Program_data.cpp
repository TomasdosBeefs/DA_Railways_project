//
// Created by tomas on 12/03/2023.
//

#include "Program_data.h"
#include "file_reader.h"


Program_data::Program_data() {

    this->graph = Graph();
    file_reader::readStations(*this);
    file_reader::readNetworks(*this);
    this->originalgraph = this->graph;
}

void Program_data::set_Name(std::string string, Vertex *vertex) {

    std::unordered_map<std::string, Vertex *>::iterator iterator = this->Name.find(string);

    if (iterator != this->Name.end()) {
        iterator->second = vertex;
    } else {

        std::pair<std::string, Vertex *> pair(string, vertex);
        this->Name.insert(pair);
    }
}

void Program_data::set_Municipality(std::string string, Vertex *vertex) {

    Categ::iterator iterator = this->Municipality.find(string);

    if (iterator != this->Municipality.end()) {
        iterator->second.push_back(vertex);
    } else {
        std::vector<Vertex *> vector;
        vector.push_back(vertex);
        std::pair<std::string, std::vector<Vertex *>> pair(string, vector);
        this->Municipality.insert(pair);
    }
}

void Program_data::set_Township(std::string string, Vertex *vertex) {

    Categ::iterator iterator = this->Township.find(string);

    if (iterator != this->Township.end()) {
        iterator->second.push_back(vertex);
    } else {
        std::vector<Vertex *> vector;
        vector.push_back(vertex);
        std::pair<std::string, std::vector<Vertex *>> pair(string, vector);
        this->Township.insert(pair);
    }
}

void Program_data::set_Line(std::string string, Vertex *vertex) {

    Categ::iterator iterator = this->Line.find(string);

    if (iterator != this->Line.end()) {
        iterator->second.push_back(vertex);
    } else {
        std::vector<Vertex *> vector;
        vector.push_back(vertex);
        std::pair<std::string, std::vector<Vertex *>> pair(string, vector);
        this->Line.insert(pair);
    }
}

void Program_data::set_District(std::string string, Vertex *vertex) {

    Categ::iterator iterator = this->District.find(string);

    if (iterator != this->District.end()) {
        iterator->second.push_back(vertex);
    } else {
        std::vector<Vertex *> vector;
        vector.push_back(vertex);
        std::pair<std::string, std::vector<Vertex *>> pair(string, vector);
        this->District.insert(pair);
    }
}

bool Program_data::removeVertex(Vertex* v){
    auto iter = this->Stations_Network.begin();

    while(iter != this->Stations_Network.end()){
        if((*iter) == v){
            for(Edge*e : (*iter)->getAdj()){
                removeEdge(e);
            }
            this->Stations_Network.erase(iter);
            break;
        }
        iter++;
    }
    return true;
}

bool Program_data::removeEdge(Edge *e) {
    auto iter = this->Networks_vector.begin();
    int removed = 0;
    Edge* e1 = e->getOtherDirection();
    Edge* e2;
    while (iter != this->Networks_vector.end()) {
        if ((*iter) == e) {
            removed++;
            iter = this->Networks_vector.erase(iter);
            continue;
        }
        else if((*iter) == e->getOtherDirection()){
            removed++;
            iter = this->Networks_vector.erase(iter);
            continue;
        }
        if (removed == 2)break;
        iter++;
    }
    return true;


}




