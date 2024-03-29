//
// Created by tomas on 12/03/2023.
//

#ifndef RAILWAYS_PROGRAM_DATA_H
#define RAILWAYS_PROGRAM_DATA_H


#include <set>
#include <unordered_map>
#include "Graph.h"
#include <functional>

typedef std::vector<Vertex*> VE;
typedef std::vector<Edge*> EV;
typedef std::unordered_map<std::string,std::vector<Vertex*>> Categ;

/**
 * Class Program_data: Represents program data for a transportation network.
 * This class contains various member functions for managing and manipulating
 * the data related to the transportation network, including stations, edges,
 * and categories.
 */

class Program_data {

public:
    Graph graph;
    Graph originalgraph;
    /**
     * Constructor: Creates an instance of the Program_data class.
     * Initializes the graph and originalgraph data members.
     */
    Program_data();

    /**
     * Sets the name of a vertex in the program data.
     * @param string The name of the vertex.
     * @param vertex Pointer to the vertex object.
     */
    void set_Name(std::string string, Vertex *vertex);

    /**
     * Sets the municipality category of a vertex in the program data.
     * @param string The municipality category.
     * @param vertex Pointer to the vertex object.
     */
    void set_Municipality(std::string string, Vertex *vertex);

    /**
     * Sets the township category of a vertex in the program data.
     * @param string The township category.
     * @param vertex Pointer to the vertex object.
     */
    void set_Township(std::string string, Vertex *vertex);

    /**
     * Sets the line category of a vertex in the program data.
     * @param string The line category.
     * @param vertex Pointer to the vertex object.
     */
    void set_Line(std::string string, Vertex *vertex);

    /**
     * Sets the district category of a vertex in the program data.
     * @param string The district category.
     * @param vertex Pointer to the vertex object.
     */
    void set_District(std::string string, Vertex *vertex);

    /**
     * Removes a vertex from the program data and its corresponding edges.
     * @param v Pointer to the vertex object to be removed.
     * @return true if the vertex is successfully removed, false otherwise.
     */
    bool removeVertex(Vertex* v);

    /**
     * Removes an edge from the program data.
     * @param e Pointer to the edge object to be removed.
     * @return true if the edge is successfully removed, false otherwise.
     */
    bool removeEdge(Edge *e);


    std::unordered_map<std::string, Vertex *> Name; /**< Map for storing vertex names. */
    std::vector<Vertex *> Stations_Network; /**< Vector for storing vertices in the network. */
    EV Networks_vector; /**< Vector for storing networks. */
    std::vector<Vertex*> keepVertex; /**< Vector for keeping track of vertices. */
    std::vector<Edge*> keepEdge; /**< Vector for keeping track of edges. */
    Categ Municipality; /**< Map for storing vertices categorized by municipality. */
    Categ Township; /**< Map for storing vertices categorized by township. */
    Categ Line; /**< Map for storing vertices categorized by line. */
    Categ District; /**< Map for storing vertices categorized by district. */





    Graph SubGraphCreate(Graph original, std::vector<Edge *> &edges, std::vector<Vertex *> &vertextoRemove);



    /**
    @brief Calculates the cost-efficient value between two vertices in the graph.
    This function calculates and returns the cost-efficient value between two given vertices in the graph. The cost-efficient value represents the efficiency of reaching from one vertex to another, taking into consideration the cost of edges, distances, or other relevant factors.
    The result is returned as a double value, representing the cost-efficient value between the two vertices.
    @param v1 Pointer to the source vertex.
    @param v2 Pointer to the destination vertex.
    @return The cost-efficient value between the two given vertices as a double value.
    Complexity: O(V^2 * E^2)
     */
    double Cost_Efficient(Vertex *v1, Vertex *v2);


    /**
    @brief Creates a subgraph from the original graph, by removing specified edges and vertices.
    This function creates a subgraph from the original graph, by removing the specified edges and vertices. The resulting subgraph will only contain the remaining edges and vertices.
    @param original The original graph from which the subgraph needs to be created.
    @param edges A vector of pointers to the edges that need to be removed from the original graph.
    @param vertextoRemove A vector of pointers to the vertices that need to be removed from the original graph.
    @return The subgraph created from the original graph, after removing the specified edges and vertices.
     */
    bool OriginalGraph();

    /**
   @brief Checks if the current graph is the original graph.
   This function checks if the current graph is the original graph, which means that it has not been modified or altered since its creation.
   @return True if the current graph is the original graph, False otherwise.
   @note This function may be used in conjunction with other functions that modify or create subgraphs, to determine if the current graph is still the original graph or not.
   @see Graph::Vertex
   @see Graph::Edge
     Complexity: O(E)
   */
    bool SubGraphEdit(Graph original, std::vector<Edge *> edges, std::vector<Vertex *> vertextoRemove);

    /**
    @brief Calculates the maximum number of trains that can pass from one vertex to another in a graph with reduced connectivity.
    This function calculates and returns the maximum number of trains that can pass from one vertex (v1) to another vertex (v2) in a graph with reduced connectivity. The reduced connectivity is achieved by removing certain vertices from the graph, as specified in the 'vertex' vector, and edges, as specified in the 'edge' vector. The resulting graph may have reduced connectivity compared to the original graph, and this function calculates the maximum number of trains that can pass between the specified vertices in this reduced connectivity graph.
    @param graph The graph from which the maximum number of trains needs to be calculated.
    @param v1 Pointer to the source vertex.
    @param v2 Pointer to the destination vertex.
    @param vertex A vector of pointers to the vertices that need to be removed from the graph to achieve reduced connectivity.
    @param edge A vector of pointers to the edges that need to be removed from the graph to achieve reduced connectivity.
    @return The maximum number of trains that can pass from v1 to v2 in the reduced connectivity graph as a double value.
     Complexity: O(V * E^2)
     */
    double ReducedConnectivityMaximumTrains(Graph graph, Vertex *v1, Vertex *v2, std::vector<Vertex *> vertex,
                                            std::vector<Edge *> edge);


    /**
 * @brief Returns a priority queue with the most affected segments.
 *
 * This function calculates the maximum flow in a given graph using the Edmonds-Karp algorithm.
 * It then resets the graph values, applies some subgraph edits, and calculates the flow differences
 * for each edge in the graph. The edges are then stored in a priority queue based on their flow differences.
 * Finally, the top `num` edges with the highest flow differences are printed and returned as a priority queue.
 *
 * @param graph The graph object to operate on.
 * @param v1 The source vertex.
 * @param v2 The sink vertex.
 * @param edges A vector of edges to be edited.
 * @param vertex A vector of vertices in the graph.
 * @param num The number of top edges to return.
 * @return A priority queue of edges with the most affected segments.
 Complexity: O(V * E^2)
     */
    std::priority_queue<Edge *, std::vector<Edge *>, std::function<bool(Edge *, Edge *)>>
    unresolved_lines(Graph graph, Vertex *v1, Vertex *v2, std::vector<Edge *> edges, std::vector<Vertex *> vertex);
};


#endif //RAILWAYS_PROGRAM_DATA_H