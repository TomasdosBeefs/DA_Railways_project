//
// Created by tomas on 17/03/2023.
//

#include <cfloat>
#include <functional>
#include "algorithms.h"
#include "Program_data.h"
#include "Vertex_Edge.h"
#include "Graph.h"


//2.1 -- provavelmente maximum flow ( os que conseguem atravessar simultaneamente duas estaçoes)
//2.2 -- de cada 2 estaçoes o numero de


double Graph::edmondskarp(Vertex *source, Vertex *sink) { // retornar o max-flow?
    double maxflow = 0;


    while (Find_path(source, sink)) {
        double f = Find_Bottleneck(source, sink);
        maxflow += f;
        augmentPath(source, sink, f);
    }
    // std::cout << '\n' << "FLOW" << maxflow <<'\n';
    return maxflow;

}

double Graph::Find_Bottleneck(Vertex *src, Vertex *sink) {
    double bottleneck = INF;
    Vertex *currVertex = sink;


    while (currVertex != src) {
        Edge *e = currVertex->getPath();

        if (e->getDest() == currVertex) {
            bottleneck = std::min(currVertex->getPath()->getWeight() - currVertex->getPath()->getBiFlow(), bottleneck);
            currVertex = currVertex->getPath()->getOrig();
        } else if (e->getOrig() == currVertex) {
            //   std::cout<< "auiq";
            bottleneck = std::min(currVertex->getPath()->getBiFlow(), bottleneck);
            currVertex = currVertex->getPath()->getDest();

        }

    }
    return bottleneck;

}

bool Graph::Find_path(Vertex *source, Vertex *dest) {

    std::queue<Vertex *> q;
    q.push(source);

    for (Vertex *v: vertexSet) {
        v->setVisited(false);
        v->setPath(nullptr);
    }

    source->setVisited(true);
    while (!q.empty() && !dest->isVisited()) {

        Vertex *v = q.front();

        q.pop();


        for (Edge *e: v->getAdj()) {

            if (!e->getDest()->isVisited() && e->getWeight() - e->getBiFlow() >
                                              0) { // n faz mais sentido aqui meter no flow o que resta e guardar no reverse o flow?
                e->getDest()->setVisited(true); // nao sei o que fazer com as reverse n entendo a utilidade do reverse
                e->getDest()->setPath(e);
                q.push(e->getDest());
                //  std::cout << e->getDest()->getName() << ' ';
            }
        }

        for (Edge *e: v->getIncoming()) {

            if (!e->getOrig()->isVisited() && e->getBiFlow() > 0 && e->getFlow() > 0) {
                std::cout << '\n' << e->getBiFlow() << ' ' << e->getFlow() << '\n';
                e->getOrig()->setVisited(true);
                e->getOrig()->setPath(e);
                q.push(e->getOrig());
                //     std::cout << e->getOrig()->getName()<< ' ';
            }
        }

        //  std::cout << "next" << '\n';

    }
    //  std::cout << "end"<<'\n';
    return dest->isVisited();

}


void Graph::augmentPath(Vertex *source, Vertex *sink, double f) {

    Vertex *currVertex = sink;

    while (currVertex != source) {
        std::cout << " Caminho " << currVertex->getPath()->getDest()->getName() << ' '
                  << currVertex->getPath()->getOrig()->getName();
        Edge *e = currVertex->getPath();
        if (e->getDest() == currVertex) {
            e->setFlow(e->getFlow() + f);
            e->getReverse()->setFlow(e->getFlow());
            currVertex = e->getOrig();

        } else if (e->getOrig() == currVertex) {
            // std::cout << "até os comemos \n" << e->getOrig();
            e->setFlow(e->getFlow() - f);
            e->getReverse()->setFlow(e->getFlow());
            // e->setCapacity(e->getWeight()-e->getFlow());
            // e->getReverse()->setBiFlow(e->getBiFlow()-f); // wut? faz sentido usar o reverse aqui sequer? pra que serve o reverse?
            currVertex = e->getDest();
        }
        //bidirectional edge //frente) adicionar flow e ir ao reverse tirar o flow
    }
    std::cout << '\n' << "next" << '\n';
}

void Graph::Most_fluent_stations() {

    double maxflow = 0;
    std::pair<Vertex *, Vertex *> pair;
    for (Vertex *v: vertexSet) {
        for (Vertex *vv: vertexSet) {
            if (v == vv) continue;
            double flow = edmondskarp(v, vv);
            if (flow > maxflow) {
                pair.first = v;
                pair.second = vv;
                //  std::cout << pair.first->getName() << ' ' << pair.second->getName();
                maxflow = flow;
            }

        }
    }
    std::cout << pair.first->getName() << ' ' << pair.second->getName() << ' ' << maxflow;
}

double Program_data::Cost_Efficient(Vertex *v1, Vertex *v2) {
    Graph Gf = Graph(this->graph);
    Vertex *v = Gf.findVertex(0);
    Vertex *vv = Gf.findVertex(4);

    double maxflow = Gf.edmondskarp(v, vv);

    double min_cost = 0;

    min_cost = Gf.Bellman_Ford(v, vv);


    return min_cost;


}

double Graph::Bellman_Ford(Vertex *v1, Vertex *v2) {
    std::vector<double> distance(vertexSet.size(), INF);
    distance[v1->getId()] = 0;

    for (int j = 0; j < vertexSet.size() - 1; j++) {
        for (int i = 0; i < edgeSet.size(); i++) {
            int u = edgeSet[i]->getOrig()->getId();
            int v = edgeSet[i]->getDest()->getId();
            int segment_cost = edgeSet[i]->getSegment_cost();
            if (distance[u] != INF && distance[u] + segment_cost < distance[v])
                distance[v] = distance[u] + segment_cost;
        }
    }

    for (int i = 0; i < edgeSet.size(); i++) {
        int u = edgeSet[i]->getOrig()->getId();
        int v = edgeSet[i]->getDest()->getId();
        int segment_cost = edgeSet[i]->getSegment_cost();
        if (distance[u] != INF && distance[u] + segment_cost < distance[v])
            return -1;
    }

    return distance[v2->getId()] != INF ? distance[v2->getId()] : -1;
}

void Graph::Edge_Relaxation(Edge *e) {
    Vertex *org = e->getOrig();
    Vertex *dest = e->getDest();

    if (org->getDist() + e->getWeight() < dest->getDist()) {

        dest->setDist(org->getDist() + e->getWeight());

        dest->setPath(e);

    }
}

int Graph::find(std::vector<Edge *> vector, Edge *value) {
    int a = 0;
    std::vector<Edge *>::iterator it = vector.begin();

    while (it != vector.end()) {
        if ((*it) == value) {
            break;
        }
        it++;
        a++;
    }
    return a;
}


bool Program_data::SubGraphEdit(Graph original, std::vector<Edge *> edges, std::vector<Vertex *> vertextoRemove) {


    for (Edge *e: edges) {
        keepEdge.push_back(e);
        keepEdge.push_back(e->getOtherDirection());
        this->graph.removeEdge(e);
    }
    this->keepVertex = vertextoRemove;
    for (Vertex *v: vertextoRemove) {
        for (Edge *e: v->getAdj()) {
            keepEdge.push_back(e);
            keepEdge.push_back(e->getOtherDirection());
        }
        this->graph.removeVertex(v);
    }

    return true;
}

bool Program_data::OriginalGraph() {

    for (Vertex *v: this->keepVertex) {
        this->graph.addVertex(v);
    }

    for (Edge *e: this->keepEdge) {
        this->graph.addEdge(e);
    }

    return true;
}

Graph Program_data::SubGraphCreate(Graph original, std::vector<Edge *> &edges, std::vector<Vertex *> &vertextoRemove) {

    Graph subgraph = Graph(original, edges, vertextoRemove);

    return subgraph;
}


Graph Program_data::unresolved_lines(Graph graph, Vertex *v1, Vertex *v2, std::vector<Edge *> edges,std::vector<Vertex *> vertex) {
    double max = 0;
    std::unordered_map<Edge *, double> oldflow;
    max = graph.edmondskarp(v1, v2);
    for (Edge *e: graph.edgeSet) {
        std::pair<Edge *, double> pairr = {e, e->getFlow()};
        oldflow.insert(pairr);
    }
    graph.ResetGraphValues();
    std::cout << "primeiro Edmond->" << max << ' ' << '\n' << graph.edgeSet.size() << '\n';

    SubGraphEdit(graph,edges,vertex);
    std::priority_queue<Edge*, std::vector<Edge*>, std::function<bool(Edge*, Edge*)>> pq([](Edge* a, Edge* b) {return a->getFlowDifference() < b->getFlowDifference();});
    max = graph.edmondskarp(v1, v2);
    for (Edge *e: graph.edgeSet) {
        double diff = abs(e->getFlow() - oldflow.find(e)->second);
        e->setFlowDifference(diff);
        pq.push(e);
    }
    std::cout << "segundo Edmond->" << max << '\n' << graph.edgeSet.size() << '\n';


    while (!pq.empty()) {
        std::cout << pq.top()->getOrig()->getName() << "->" << pq.top()->getDest()->getName() << ' ' <<  pq.top()->getFlowDifference() << '\n';
        pq.pop();
    }


    return graph;


}

void Graph::ResetGraphValues() {
    for (auto v: vertexSet) {
        v->setPath(nullptr);
        v->setVisited(0);
        for (Edge *e: v->getAdj()) {
            e->setFlow(0);
            e->getReverse()->setFlow(0);
            e->getOtherDirection()->setFlow(0);
        }
    }
}

