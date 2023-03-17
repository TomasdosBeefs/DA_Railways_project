//
// Created by tomas on 12/03/2023.
//

#include "Program_data.h"

Program_data::Program_data() {}

void Program_data::set_Name(std::string string, Vertex* vertex) {

    std::unordered_map<std::string,Vertex*>::iterator iterator= this->Name.find(string);

    if(iterator != this->Name.end()){
            iterator->second =vertex;
    }
    else{

        std::pair<std::string,Vertex*> pair (string,vertex);
        this->Name.insert(pair);
    }
    }

void Program_data::set_Municipality(std::string string, Vertex* vertex) {

    Categ::iterator iterator= this->Municipality.find(string);

    if(iterator != this->Municipality.end()){
        iterator->second.push_back(vertex);
    }
    else{
        std::vector<Vertex*> vector;
        vector.push_back(vertex);
        std::pair<std::string,std::vector<Vertex*>> pair (string,vector);
        this->Municipality.insert(pair);
    }
}

void Program_data::set_Township(std::string string, Vertex * vertex) {

    Categ::iterator iterator= this->Township.find(string);

    if(iterator != this->Township.end()){
        iterator->second.push_back(vertex);
    }
    else{
        std::vector<Vertex*> vector;
        vector.push_back(vertex);
        std::pair<std::string,std::vector<Vertex*>> pair (string,vector);
        this->Township.insert(pair);
    }
}

void Program_data::set_Line(std::string string, Vertex * vertex) {

    Categ::iterator iterator= this->Line.find(string);

    if(iterator != this->Line.end()){
        iterator->second.push_back(vertex);
    }
    else{
        std::vector<Vertex*> vector;
        vector.push_back(vertex);
        std::pair<std::string,std::vector<Vertex*>> pair (string,vector);
        this->Line.insert(pair);
    }
}
void Program_data::set_District(std::string string, Vertex * vertex) {

    Categ::iterator iterator= this->District.find(string);

    if(iterator != this->District.end()){
        iterator->second.push_back(vertex);
    }
    else{
        std::vector<Vertex*> vector;
        vector.push_back(vertex);
        std::pair<std::string,std::vector<Vertex*>> pair (string,vector);
        this->District.insert(pair);
    }
}


