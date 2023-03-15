//
// Created by tomas on 12/03/2023.
//

#include "Program_data.h"

Program_data::Program_data() {}

void Program_data::set_Name(std::string string, Vertex* vertex) {

    Categ::iterator iterator= this->District.find(string);

    if(this->District.find(string) != this->District.end()){
            iterator->second.push_back(vertex);
    }
    else{
        std::vector<Vertex*> vector;
        vector.push_back(vertex);
        std::pair<std::string,std::vector<Vertex*>> pair (string,vector);
        this->District.insert(pair);
    }
    }

void Program_data::set_Municipality(std::string string, Vertex* vertex) {

    Categ::iterator iterator= this->Municipality.find(string);

    if(this->Municipality.find(string) != this->Municipality.end()){
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

    if(this->Township.find(string) != this->Township.end()){
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

    if(this->Line.find(string) != this->Line.end()){
        iterator->second.push_back(vertex);
    }
    else{
        std::vector<Vertex*> vector;
        vector.push_back(vertex);
        std::pair<std::string,std::vector<Vertex*>> pair (string,vector);
        this->Line.insert(pair);
    }
}
