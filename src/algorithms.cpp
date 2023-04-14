//
// Created by tomas on 17/03/2023.
//

#include <cfloat>
#include <functional>
#include "algorithms.h"
#include "Program_data.h"
#include "Vertex_Edge.h"
#include "Graph.h"


double Graph::edmondskarp(Vertex *source, Vertex *sink) {

    //2.1 -- antes de usar deve-se usar ResetGraphValues()

    double maxflow = 0;
    if(source->getLine() != sink->getLine()) return 0;


    while (Find_path(source, sink)) {
        double f = Find_Bottleneck(source, sink);
        maxflow += f;
        augmentPath(source, sink, f);
    }

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
                                              0) {
                e->getDest()->setVisited(true);
                e->getDest()->setPath(e);
                q.push(e->getDest());
                //  std::cout << e->getDest()->getName() << ' ';
            }
        }

        for (Edge *e: v->getIncoming()) {

            if (!e->getOrig()->isVisited() && e->getBiFlow() > 0 && e->getFlow() > 0) {
                //std::cout << '\n' << e->getBiFlow() << ' ' << e->getFlow() << '\n';
                e->getOrig()->setVisited(true);
                e->getOrig()->setPath(e);
                q.push(e->getOrig());

            }
        }


    }
    return dest->isVisited();

}


void Graph::augmentPath(Vertex *source, Vertex *sink, double f) {

    Vertex *currVertex = sink;

    while (currVertex != source) {
        //std::cout << " Caminho " << currVertex->getPath()->getDest()->getName() << ' '
            //      << currVertex->getPath()->getOrig()->getName();
        Edge *e = currVertex->getPath();
        if (e->getDest() == currVertex) {
            e->setFlow(e->getFlow() + f);
            e->getReverse()->setFlow(e->getFlow());
            currVertex = e->getOrig();

        } else if (e->getOrig() == currVertex) {
            e->setFlow(e->getFlow() - f);
            e->getReverse()->setFlow(e->getFlow());
            currVertex = e->getDest();
        }
    }
}

void Graph::Most_fluent_stations() {
                            //  2.2 -- calcula as estaçoes com maior flow
    double maxflow = 0;
    std::pair<Vertex *, Vertex *> pair;
    for (Vertex *v: vertexSet) {
        for (Vertex *vv: vertexSet) {
            if (v == vv) continue;
            ResetGraphValues();
            double flow = edmondskarp(v, vv);
            if (flow > maxflow) {
                pair.first = v;
                pair.second = vv;
                maxflow = flow;
            }

        }
    }
    std::cout << pair.first->getName() << ' ' << pair.second->getName() << ' ' << maxflow;
}

double Program_data::Cost_Efficient(Vertex *v1, Vertex *v2) {
                // 3.1 cost efficient -- podemos usar Dijkstra our Bellman
     this->graph.edmondskarp(v1, v2);

    double min_cost;

    min_cost = this->graph.Dijkstra(v1, v2);

    return min_cost;


}

typedef std::pair<int, int> pii;

double Graph::Dijkstra(Vertex *v1, Vertex *v2) {

    for (Vertex *v: this->vertexSet) {
        v->setVisited(false);
    }

    std::priority_queue<Vertex *> pq;
    v1->setDist(0);
    pq.push(v1);

    while (!pq.empty()) {

        Vertex *v = pq.top();
        pq.pop();
        if (v->isVisited()) continue;
        v->setVisited(true);

        for (Edge *e: v->getAdj()) {
            Edge_Relaxation(e);
            pq.push(e->getDest());
        }

    }
    return v2->getDist();

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

    if (org->getDist() + e->getSegment_cost() < dest->getDist()) {

        dest->setDist(org->getDist() + e->getSegment_cost());

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
    this->graph.ResetGraphValues();

    return true;
}

Graph Program_data::SubGraphCreate(Graph original, std::vector<Edge *> &edges, std::vector<Vertex *> &vertextoRemove) {

    Graph subgraph = Graph(original, edges, vertextoRemove);

    return subgraph;
}

double Program_data::ReducedConnectivityMaximumTrains(Graph graph,Vertex* v1,Vertex* v2,std::vector<Vertex*> vertex,std::vector<Edge*> edge){
                        // 4.1 -- ele retira as edegs e vertex dos vetores e faz edmondkarp, depois restitui o grafo, se quiseres restituir atraves do menu será melhor
    double max = 0;
    SubGraphEdit(this->graph,edge,vertex);
    graph.ResetGraphValues();
    max = this->graph.edmondskarp(v1,v2);
    OriginalGraph();
    return max;
}


std::priority_queue<Edge *, std::vector<Edge *>, std::function<bool(Edge *, Edge *)>>
Program_data::unresolved_lines(Graph graph, Vertex *v1, Vertex *v2, std::vector<Edge *> edges,
                               std::vector<Vertex *> vertex) {
    double max = 0;                                           //4.2 -- função que retorna uma priority queue com os segmentos mais afetados, 4.2;
    std::unordered_map<Edge *, double> oldflow;
    max = graph.edmondskarp(v1, v2);
    for (Edge *e: graph.edgeSet) {
        std::pair<Edge *, double> pairr = {e, e->getFlow()};
        oldflow.insert(pairr);
    }
    graph.ResetGraphValues();

    SubGraphEdit(graph, edges, vertex);
    std::priority_queue<Edge *, std::vector<Edge *>, std::function<bool(Edge *, Edge *)>> pq(
            [](Edge *a, Edge *b) { return a->getFlowDifference() < b->getFlowDifference(); });
    max = graph.edmondskarp(v1, v2);
    for (Edge *e: graph.edgeSet) {
        double diff = abs(e->getFlow() - oldflow.find(e)->second);
        e->setFlowDifference(diff);
        pq.push(e);
    }



    while (!pq.empty()) {
        std::cout << pq.top()->getOrig()->getName() << "->" << pq.top()->getDest()->getName() << ' '
                  << pq.top()->getFlowDifference() << '\n';
        pq.pop();
    }

    OriginalGraph();
    return pq;


}

void Graph::ResetGraphValues() {
    for (auto v: vertexSet) {
        v->setPath(nullptr);
        v->setVisited(0);
        for (Edge *e: v->getAdj()) {
            e->setFlow(0);
            e->getReverse()->setFlow(0);
        }
    }
}


std::vector<std::pair<std::string, int>> Graph::Budget_needed_district() {
    std::vector<std::pair<std::string, int>> networkCount;
    for (Vertex *vertex: vertexSet) {
        auto it = std::find_if(networkCount.begin(), networkCount.end(),
                               [&](const auto &pair) { return pair.first == vertex->getDistrict(); });
        if (it != networkCount.end()) {
            it->second += vertex->getAdj().size();
        } else {
            networkCount.emplace_back(vertex->getDistrict(), vertex->getAdj().size());
        }
    }

    sort(networkCount.begin(), networkCount.end(),
         [](std::pair<std::string, int> district1, std::pair<std::string, int> district2) {
             if (district1.second == district2.second)
                 return district1.first > district2.first;
             return district1.second > district2.second;
         });
    return networkCount;
}

std::vector<std::pair<std::string, int>> Graph::Budget_needed_municipality() {
    std::vector<std::pair<std::string, int>> networkCount;
    for (Vertex *vertex: vertexSet) {
        auto it = std::find_if(networkCount.begin(), networkCount.end(),
                               [&](const auto &pair) { return pair.first == vertex->getMunicipality(); });
        if (it != networkCount.end()) {
            it->second += vertex->getAdj().size();
        } else {
            networkCount.emplace_back(vertex->getMunicipality(), vertex->getAdj().size());
        }
    }

    sort(networkCount.begin(), networkCount.end(),
         [](std::pair<std::string, int> municipality1, std::pair<std::string, int> municipality2) {
             if (municipality1.second == municipality2.second)
                 return municipality1.first > municipality2.first;
             return municipality1.second > municipality2.second;
         });
    return networkCount;
}




double Graph::MaxTrainsAtStation(Vertex* sink){

    // 2.4 -

        double maxFlow = 0;

        for (auto & v : getVertexSet()) {
            if(v != sink){

                double flow = edmondskarp(v, sink);

                if (flow > maxFlow) {
                    maxFlow = flow;
                }
            }
        }

        return maxFlow;
}
