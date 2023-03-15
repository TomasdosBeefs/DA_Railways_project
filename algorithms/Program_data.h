//
// Created by tomas on 12/03/2023.
//

#ifndef RAILWAYS_PROGRAM_DATA_H
#define RAILWAYS_PROGRAM_DATA_H


#include <set>
#include <unordered_map>
#include "Graph.h"


typedef std::vector<Vertex*> VE;
typedef std::unordered_map<std::string,std::vector<Vertex*>> Categ;


class Program_data {
                    //perguntar à stora se faz mais sentido procurar tudo a partir deste struct ou fazer um diferente para cada cidade , distrito essas cenas


public:
    Graph graph;
    Program_data();

    void set_Name(std::string,Vertex*);
    void set_District(std::string,Vertex*);
    void set_Municipality(std::string,Vertex*);
    void set_Township(std::string,Vertex*);
    void set_Line(std::string,Vertex*);

    VE Stations_Network;
    std::unordered_map<std::string,Vertex*> Name;
private:

    Categ District;
    Categ Municipality;
    Categ Township;
    Categ Line;





























    /*std::unordered_map<Vertex*,std::vector<Edge*>> VE; // relações entre estaçõpes e ligações
    std::unordered_map<std::string,std::pair<Vertex*,std::vector<Edge*>*>>;


    std::vector<std::pair<std::string,std::unordered_map<Vertex*,std::vector<Edge*>*>>>* Name; //  VE's por Nome
    std::vector<std::pair<std::string,std::unordered_map<Vertex*,std::vector<Edge*>*>>>*
    std::vector<std::pair<std::string,std::unordered_map<Vertex*,std::vector<Edge*>*>>>*


    std::unordered_map<std::string,std::pair<Vertex*,std::vector<Edge*>*>>;*/






};


#endif //RAILWAYS_PROGRAM_DATA_H
