//
// Created by tomas on 10/03/2023.
//

#ifndef RAILWAYS_GRAPH_H
#define RAILWAYS_GRAPH_H

/**
 * @file graph.h
 * @brief Definition of Graph class and related functions for graph manipulation.
 */


#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "Vertex_Edge.h"

/**
 * @class Graph
 * @brief Represents a graph data structure.
 */

class Graph {
public:


    ~Graph();
    Graph();

    /**
     * @brief Constructs a Graph object by copying another Graph object.
     * @param graph The Graph object to be copied.
     * @param edge The vector of Edge pointers to be populated with the edges of the graph.
     * @param vertex The vector of Vertex pointers to be populated with the vertices of the graph.
     */
    Graph(const Graph &graph, std::vector<Edge *> &edge, std::vector<Vertex *> &vertex);


    /**
     * * @brief Finds a vertex with a given content.
     * @param id The content of the vertex to find.
     * @return A pointer to the vertex with the given content, or nullptr if not found.
     * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const int &id) const;
    /**
     * @brief Adds a vertex to the graph.
     * @param v Pointer to the vertex to be added.
     * @return True if the vertex was added successfully, false otherwise.
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(Vertex* v);

    /**
    @brief Augments a path in the graph with a given flow.
    This function augments a path in the graph from a source vertex to a sink vertex with a given flow value. The path is determined
    using the path information stored in the vertices during the graph traversal. The flow value is added to the forward edges
    and subtracted from the backward edges along the path.
     Complexity: O(V)
    @param source The source vertex of the path.
    @param sink The sink vertex of the path.
    @param f The flow value to augment the path with.
     */
    void augmentPath(Vertex* source, Vertex* sink, double f);


    /**
     * @brief Finds an augmenting path from the source to the destination vertex in the Edmonds-Karp algorithm.
     * @param source The source vertex of the augmenting path.
     * @param dest The destination vertex of the augmenting path.
     * @return True if an augmenting path is found, False otherwise.
     * Complexity: O(V + E)
     *
     * This function performs a breadth-first search starting from the source vertex to find an augmenting path to the destination vertex.
     * It marks visited vertices and sets the path from the visited vertices to the source vertex.
     * The function returns True if an augmenting path is found, and False otherwise.
     */
    bool Find_path(Vertex* source, Vertex* dest);

    /**
     * @brief Finds the bottleneck capacity of the augmenting path from source to sink vertex in the Edmonds-Karp algorithm.
     * @param src The source vertex of the augmenting path.
     * @param sink The sink vertex of the augmenting path.
     * @return The bottleneck capacity of the augmenting path.
     * Complexity: O(V)
     */
    double Find_Bottleneck(Vertex* source, Vertex* dest);

    /**
     * @brief Finds the maximum flow between a source and sink vertex using the Edmonds-Karp algorithm.
     * @param source The source vertex of the graph.
     * @param sink The sink vertex of the graph.
     * @return The maximum flow between the source and sink vertices.
     * Complexity: O(V^2 * E^2)
     */
    double edmondskarp(Vertex* source, Vertex* sink);

    /**
    @brief Finds the pair of stations with the highest flow in the graph.
    This function calculates the maximum flow between all pairs of stations in the graph using the Edmonds-Karp algorithm,
    and identifies the pair of stations with the highest flow. The result is printed to std::cout, including the names of the
    two stations and the corresponding maximum flow.
     Complexity: O(V^2 * E^2)
     */
    void Most_fluent_stations();

    /**
    @brief Calculates the shortest path between two vertices using the Bellman-Ford algorithm.
    This function calculates the shortest path between two vertices in the graph using the Bellman-Ford algorithm.
    The algorithm computes the shortest path in terms of total segment cost, which is stored in the "segment_cost" field
    of the edges in the graph. The result is returned as the shortest distance between the two vertices.
    If there is no path between the two vertices, or if there is a negative-weight cycle in the graph, -1 is returned.
    @param v1 Pointer to the source vertex.
    @param v2 Pointer to the destination vertex.
     Complexity: O(V * E)
     */
    double Bellman_Ford(Vertex* v1, Vertex* v2);

    /**
    @brief Calculates the shortest path between two vertices using Dijkstra's algorithm.
    This function calculates the shortest path between two vertices in the graph using Dijkstra's algorithm.
    The algorithm computes the shortest path in terms of total distance, which is stored in the "dist" field of the vertices
    in the graph. The result is returned as the shortest distance between the two vertices.
    @param v1 Pointer to the source vertex.
    @param v2 Pointer to the destination vertex.
    @return The shortest distance between v1 and v2.
     Complexity: O(V^2)
     */
    double Dijkstra(Vertex* v1, Vertex* v2);

    /**
    @brief Performs edge relaxation on a given edge during Dijkstra's algorithm.
    This function performs edge relaxation on a given edge during Dijkstra's algorithm.
    Edge relaxation is the process of updating the distance and path of the destination vertex of an edge
    if a shorter path is found from the source vertex through the given edge.
    @param e Pointer to the edge to be relaxed.
     Complexity: O(N)
     */
    void Edge_Relaxation(Edge* e);

    /**
     *  * @brief Removes an edge from the graph.
    * @param e Pointer to the edge to be removed.
    * @return True if the edge was removed successfully, false otherwise.
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool removeEdge(Edge* e);

    /**
     * @brief Removes a vertex from the graph.
     * @param v Pointer to the vertex to be removed.
     * @return True if the vertex was removed successfully, false otherwise.
     */
    bool removeVertex(Vertex* v);

    /**
     * @brief Adds an edge to the graph.
     * @param e The edge to add.
     * @return True if successful, false if the edge already exists in the graph.
     */
    bool addEdge(Edge*);

    /**
     * @brief Adds a bidirectional edge between two vertices in the graph.
     * @param v1 Pointer to the first vertex.
     * @param v2 Pointer to the second vertex.
     * @param weight The weight of the edge.
     * @param Service The service type of the edge (e.g., "STANDARD").
     * @return True if the edge was added successfully, false otherwise.
     */
    bool addBidirectionalEdge(Vertex* v1, Vertex* v2, double weight, std::string Service);

    /**
     * @brief Gets the number of vertices in the graph.
     * @return The number of vertices in the graph.
     */
    int getNumVertex() const;

    /**
     * @brief Gets the vertex set of the graph.
     * @return The vertex set of the graph.
     */
    std::vector<Vertex *> getVertexSet() const;
    std::vector<Vertex*> vertexSet; /**< The vertex set of the graph. */
    std::vector<Edge*> edgeSet; /**< The edge set of the graph. */

    /**
     * @brief Gets the edge set of the graph.
     * @return The edge set of the graph.
     */
    std::vector<Edge *> getEdgeSet();

    /**
    @brief Resets the values of the graph vertices for a fresh traversal or computation.
    This function resets the values of the graph vertices, such as "visited", "dist", and "path", to their initial state.
    It is useful to call this function before starting a fresh traversal or computation on the graph.
    Complexity: O(V + E)
     */
    void ResetGraphValues();

    /**
    @brief Calculates the budget needed for each district in the graph.
    This function calculates the budget needed for each district in the graph based on some predefined rules or algorithms.
    The result is returned as a vector of pairs, where each pair contains the name of the district and the corresponding budget needed.
    @return A vector of pairs, where each pair contains the name of a district and the corresponding budget needed.
     Complexity: O(V log V)
     */
    std::vector<std::pair<std::string, int>> Budget_needed_district();

    /**
    @brief Calculates the budget needed for each municipality in the graph.
    This function calculates the budget needed for each municipality in the graph based on some predefined rules or algorithms.
    The result is returned as a vector of pairs, where each pair contains the name of the municipality and the corresponding budget needed.
    @return A vector of pairs, where each pair contains the name of a municipality and the corresponding budget needed.
    Complexity: O(V log V)
     */
    std::vector<std::pair<std::string, int>> Budget_needed_municipality();

    /**
    @brief Calculates the maximum number of trains that can reach a given vertex (station) in the graph.
    This function calculates and returns the maximum number of trains that can reach the given vertex (station) in the graph, based on the connectivity of the graph and other relevant factors.
    The result is returned as a double value, representing the maximum number of trains that can reach the vertex.
    @param sink Pointer to the vertex (station) for which the maximum number of trains needs to be calculated.
    @return The maximum number of trains that can reach the given vertex (station) as a double value.
     Complexity: O(V * (V + E + V * E))
     */
    double MaxTrainsAtStation(Vertex *sink);

protected:
       // vertex set

    double ** distMatrix = nullptr;  /**< The distance matrix of the graph. */
    int **pathMatrix = nullptr;   /**< The path matrix of the graph. */

    /**
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;


/**
* @brief Finds the index of an Edge pointer in a vector of Edge pointers.
*
* This function performs a linear search in the vector of Edge pointers to find the index of an Edge pointer that
* matches the given value.
*
* @param vector The vector of Edge pointers to search in.
* @param value The Edge pointer to find.
* @return The index of the found Edge pointer in the vector, or -1 if not found.
* Complexity: O(N)
 */
int find(std::vector<Edge *> vector, Edge *value);

/**
 * @brief Adds a bidirectional edge between two vertices in the graph.
 *
 * This function creates two edges between the given vertices, one in each direction, and adds them to the graph's edge set.
 * The new edges are created based on the given edge and its reverse and other direction edges.
 * The function also updates the reverse and other direction edges of the newly created edges, as well as the edge sets and
 * adjacency lists of the vertices.
 *
 * @param v1 The first vertex to add the bidirectional edge.
 * @param v2 The second vertex to add the bidirectional edge.
 * @param e The base edge to create the bidirectional edges.
 * @return True if the bidirectional edge was successfully added, false otherwise.
 */
bool subaddBidirectionalEdge(Vertex *v1, Vertex *v2, Edge* e );


};

/**
 * @brief Deletes a matrix of integers.
 * @param m The matrix to delete.
 * @param n The size of the matrix.
 */
void deleteMatrix(int **m, int n);

/**
 * @brief Deletes a matrix of doubles.
 * @param m The matrix to delete.
 * @param n The size of the matrix.
 */
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */


#endif //RAILWAYS_GRAPH_H
