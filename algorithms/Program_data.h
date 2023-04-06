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
    Graph originalgraph;
    Program_data();

    void set_Name(std::string,Vertex*);
    void set_District(std::string,Vertex*);
    void set_Municipality(std::string,Vertex*);
    void set_Township(std::string,Vertex*);
    void set_Line(std::string,Vertex*);
    std::vector<std::pair<std::string, double>> most_visited_municipalities();
    Graph unresolved_lines(Graph graph, Vertex* v1, Vertex* v2,std::vector<Edge*> edges,std::vector<Vertex*> vertex);


    VE Stations_Network;
    std::unordered_map<std::string,Vertex*> Name;
    std::vector<Vertex*> keepVertex;
    std::vector<Edge*> keepEdge;
//private:

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






    std::vector<std::pair<std::string, double>> most_visited_district();

    double Cost_Efficient(Vertex *v1, Vertex *v2);


    Graph SubGraph(Graph graph1, std::vector<Edge *> edges, std::vector<Vertex *> vertex);

    Graph SubGraph(Graph original, std::vector<Edge *> edges, std::vector<std::string> verticesToRemove);

    Graph SubGraphCreate(Graph original, std::vector<Edge *> edges, std::vector<Vertex *> vertextoRemove);

    bool OriginalGraph();

    bool SubGraphEdit(Graph original, std::vector<Edge *> edges, std::vector<Vertex *> vertextoRemove);
};


#endif //RAILWAYS_PROGRAM_DATA_H
