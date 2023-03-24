//
// Created by tomas on 17/03/2023.
//

#include "algorithms.h"
#include "Program_data.h"
#include "Vertex_Edge.h"
#include "Graph.h"


//2.1 -- provavelmente maximum flow ( os que conseguem atravessar simultaneamente duas estaçoes)
//2.2 -- de cada 2 estaçoes o numero de


double Graph::edmondskarp(Vertex* source, Vertex* sink){ // retornar o max-flow?
    double maxflow = 0;

    for(auto v : vertexSet){
        v->setPath(nullptr);
        v->setVisited(0);
        for(Edge* e:  v->getAdj()){
            e->setFlow(0);
           // e->getReverse()->setFlow(0);
        }
    }

    while(Find_path(source,sink)){
        double f = Find_Bottleneck(source,sink);
        maxflow += f;
        augmentPath(source,sink,f);
    }
    return maxflow;

}

double Graph::Find_Bottleneck(Vertex* src, Vertex* sink) {
    double bottleneck = INF;
    Vertex * currVertex = sink;


    while (currVertex != src) {
        Edge *e = currVertex->getPath();

        if (e->getDest() == currVertex) {
            bottleneck = std::min(currVertex->getPath()->getWeight() - currVertex->getPath()->getFlow(), bottleneck);
            currVertex = currVertex->getPath()->getOrig();
        } else if (e->getOrig() == currVertex) {
            bottleneck = std::min(currVertex->getPath()->getFlow(), bottleneck);
            currVertex = currVertex->getPath()->getDest();

        }

    }
        return bottleneck;

}

bool Graph::Find_path(Vertex* source, Vertex* dest) {

    std::queue<Vertex*> q;
    q.push(source);

    for(Vertex* v : vertexSet){
        v->setVisited(false);
        v->setPath(nullptr);
    }

    while(!q.empty() && !dest->isVisited()){

        Vertex* v = q.front();
        q.pop();

        for(Edge* e : v->getAdj()){

            if(!e->getDest()->isVisited() && e->getWeight() - e->getFlow() > 0){ // n faz mais sentido aqui meter no flow o que resta e guardar no reverse o flow?
                e->getDest()->setVisited(true); // nao sei o que fazer com as reverse n entendo a utilidade do reverse
                e->getDest()->setPath(e);
                q.push(e->getDest());
            }
        }

        for(Edge* e : v->getIncoming()){

            if(!e->getOrig()->isVisited() && e->getFlow() > 0){
                e->getOrig()->setVisited(true);
                e->getOrig()->setPath(e);
                q.push(e->getOrig());
            }
        }

    }

    return dest->isVisited();

}




void Graph::augmentPath(Vertex* source, Vertex* sink, double f) {

        Vertex* currVertex = sink;

      //  std::cout << '\n';
    while (currVertex != source){
        Edge* e = currVertex->getPath();
       // std::cout << "Caminho "<< e->getDest()->getName() << ' ' << e->getOrig()->getName() << "\t";
        if(e->getDest() == currVertex){
            e->setFlow(e->getFlow()+f);             // perguntar se faz mal estar baseado na solução dos exercicios
            e->getReverse()->setFlow(e->getFlow()); // pra que a utilidade disto?
            currVertex = e->getOrig();

        }
        else if( e->getOrig() == currVertex){
            e->setFlow(e->getFlow() - f);
            e->getReverse()->setFlow(e->getFlow()); // wut? faz sentido usar o reverse aqui sequer? pra que serve o reverse?
            currVertex = e->getDest();
        }
        //bidirectional edge //frente) adicionar flow e ir ao reverse tirar o flow
    }
      //  std::cout << '\n' <<"next" << '\n';
}

void Graph::Most_fluent_stations(){

    double maxflow = 0;
    std::pair<Vertex*,Vertex*> pair;
    for(Vertex* v : vertexSet){
        for(Vertex* vv :vertexSet){
            if(v == vv ) continue;
            double flow = edmondskarp(v,vv);
            if(flow > maxflow){
                pair.first = v;
                pair.second = vv;
              //  std::cout << pair.first->getName() << ' ' << pair.second->getName();
                maxflow = flow;
            }

        }}
    std::cout << pair.first->getName() << ' ' << pair.second->getName();
}

std::vector<std::string> Graph::Budget_needed


  /*  double maxflow = 0;
    std::vector<Vertex*> vector;

    Vertex* source_vertex = new Vertex("Source","none","none","none","none");
    Vertex* sink_vertex = new Vertex("Sink","none","none","none","none");

    for(Vertex* vertex : vertexSet){
        //auto e = new Edge(source_vertex,vertex,vertex->get_INC(),"none");
        addBidirectionalEdge(source_vertex,vertex,vertex->get_INC(),"none");
        //auto ee = new Edge(vertex,sink_vertex,vertex->get_OUT(),"none");
        addBidirectionalEdge(vertex,sink_vertex,vertex->get_OUT(),"none");
    }
    vertexSet.push_back(source_vertex);
    vertexSet.push_back(sink_vertex);

    for(Vertex* vertex : vertexSet){

       vertex->removeEdge(sink_vertex->getId());

       maxflow = std::max(edmondskarp(source_vertex,sink_vertex),maxflow);

       addBidirectionalEdge(vertex,sink_vertex,vertex->get_OUT(),"none"); */



/*
bool compare_(std::pair<std::string,double> p1, std::pair<std::string,double> p2){

    if(p1.second == p2.second){

        return p1.first < p2.first;

    }

    return p1.second > p2.second;


}

std::vector<std::pair<std::string, double>> Program_data::most_visited_municipalities(){

    std::vector<std::pair<std::string,double>> Muni;

    Categ::iterator it = this->Municipality.begin();

    while(it != this->Municipality.end()){

        double weight = 0;

        for(Vertex* c : it->second){
            weight += c->get_INC() + c->get_OUT();
        }

        std::pair<std::string,double> pair = {it->first,weight};

        Muni.push_back(pair);
        it++;
    }

    std::sort(Muni.begin(),Muni.end(),compare_);

    return Muni;

}

std::vector<std::pair<std::string, double>> Program_data::most_visited_district(){

    std::vector<std::pair<std::string,double>> Disct;

    Categ::iterator it = this->District.begin();

    while(it != this->District.end()){

        double weight = 0; // posso mudar o District para ter municipios em vez de vertex

        for(Vertex* c : it->second){
            weight += c->get_INC() + c->get_OUT();
        }

        std::pair<std::string,double> pair = {it->first,weight};

        Disct.push_back(pair);
        it++;
    }

    std::sort(Disct.begin(),Disct.end(),compare_);

    return Disct;

}
*/
double Program_data::Cost_Efficient(Vertex* v1, Vertex* v2){

    double maxflow = graph.edmondskarp(v1,v2);

        //através do residual graph encontrar o min cut

    

return 0.0;
}




