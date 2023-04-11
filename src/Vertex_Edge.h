//
// Created by tomas on 10/03/2023.
//

#ifndef RAILWAYS_VERTEX_EDGE_H
#define RAILWAYS_VERTEX_EDGE_H


// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_VERTEX_EDGE
#define DA_TP_CLASSES_VERTEX_EDGE

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
//#include "../data_structures/MutablePriorityQueue.h"

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/
/**@brief Class representing a vertex in a graph.
This class represents a vertex in a graph, which can be used in various graph algorithms and data structures.
*/

class Vertex {
public:
/*

@brief Constructor for Vertex class.
@param Name The name of the vertex.
@param District The district of the vertex.
@param Municipaly The municipality of the vertex.
@param Township The township of the vertex.
@param Line The line of the vertex.
*/
    Vertex(std::string Name, std::string District, std::string Municipaly, std::string Township, std::string Line);
/**

@brief Less than operator overload for use in priority queues.
This function overloads the less than operator for Vertex objects, which is required by some priority queue implementations.
@param vertex The vertex to compare against.
@return True if this vertex is less than the given vertex, false otherwise.
*/
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
/**

@brief Copy constructor for Vertex class.
@param other The vertex to be copied.
*/
    Vertex(const Vertex &other);
/**

@brief Get the name of the vertex.
@return The name of the vertex as a string.
*/
    std::string getName() const;
/**

@brief Get the district of the vertex.
@return The district of the vertex as a string.
*/
    std::string getDistrict() const;
/**

@brief Get the municipality of the vertex.
@return The municipality of the vertex as a string.
*/
    std::string getMunicipality() const;
/**

@brief Get the line of the vertex.
@return The line of the vertex as a string.
*/
    std::string getLine() const;
/**

@brief Get the township of the vertex.
@return The township of the vertex as a string.
*/
    std::string getTownship() const;
/**

@brief Get the incoming capacity of the vertex.
@return The incoming capacity of the vertex as a double value.
*/
    double get_INC() const;
/**

@brief Get the outgoing capacity of the vertex.
@return The outgoing capacity of the vertex as a double value.
*/
    double get_OUT() const;
/**

@brief Get the adjacent edges of the vertex.
@return A vector of pointers to the adjacent edges of the vertex.
*/
    std::vector<Edge *> getAdj() const;
/**

@brief Check if the vertex has been visited in a graph traversal.
@return True if the vertex has been visited, false otherwise.
*/
    bool isVisited() const;

    /**

@brief Check if the vertex is currently being processed.
@return true if the vertex is being processed, false otherwise.
*/
    bool isProcessing() const;
/**

@brief Get the indegree of the vertex, i.e., the number of incoming edges.
@return The indegree of the vertex.
*/
    unsigned int getIndegree() const;
/**

@brief Get the current distance of the vertex from a source vertex in a graph traversal algorithm.
@return The current distance of the vertex.
*/
    double getDist() const;
/**

@brief Get the identifier of the vertex.
@return The identifier of the vertex.
*/
    double getId() const;
/**

@brief Get the path of the vertex in a graph traversal algorithm.
@return The path of the vertex, which is an outgoing edge from the previous vertex in the traversal.
*/
    Edge *getPath() const;
/**

@brief Get the incoming edges of the vertex.
@return A vector of incoming edges of the vertex.
*/
    std::vector<Edge *> getIncoming() const;
/**

@brief Set the incoming capacity (INC) of the vertex.
@param capacity The incoming capacity of the vertex to be set.
*/
    void set_INC_capacity(double capacity);
/**

@brief Set the outgoing capacity (OUT) of the vertex.
@param capacity The outgoing capacity of the vertex to be set.
*/
    void set_OUT_capacity(double capacity);
/**

@brief Set the identifier of the vertex.
@param id The identifier of the vertex to be set.
*/
    void setId(int id);
/**

@brief Set the visited status of the vertex.
@param visited The visited status of the vertex to be set.
*/
    void setVisited(bool visited);
/**

@brief Set the processing status of the vertex.
@param processing The processing status of the vertex to be set.
*/
    void setProcesssing(bool processing);


    /**

@brief Set the indegree of the vertex.
@param indegree The indegree of the vertex to be set.
*/
    void setIndegree(unsigned int indegree);
/**

@brief Set the distance of the vertex from a source vertex in a graph traversal algorithm.
@param dist The distance of the vertex to be set.
*/
    void setDist(double dist);
/**

@brief Set the path of the vertex in a graph traversal algorithm.
@param path The path of the vertex to be set, which is an outgoing edge from the previous vertex in the traversal.
*/
    void setPath(Edge *path);
/**

@brief Add an outgoing edge to the vertex.
@param e The outgoing edge to be added.
/
void addEdge(Edge e);
/**

@brief Remove an outgoing edge from the vertex by its ID.
@param ID The ID of the edge to be removed.
@return true if the edge is successfully removed, false otherwise.
*/
    bool removeEdge(double ID);
/**

@brief Compare if two vertices are equal based on their IDs.
@param other The other vertex to be compared to.
@return true if the vertices have the same ID, false otherwise.
*/
    bool operator==(const Vertex& other) const;
/**

@brief Compare if the current vertex is less than another vertex based on their distances.
@param other The other vertex to be compared to.
@return true if the current vertex has a smaller distance than the other vertex, false otherwise.
*/
    bool operator<(const Vertex& other) const;
// friend class MutablePriorityQueue<Vertex>;

/**

@brief Remove an incoming edge from the vertex.
@param pEdge The incoming edge to be removed.
*/
    void removeIncomingEdge(Edge *const &pEdge);
/**

@brief Remove an outgoing edge from the vertex.
@param pEdge The outgoing edge to be removed.
*/
    void removeOutgoingEdge(Edge *const &pEdge);

protected:
    /**
     * @brief Name of the vertex.
     */
    std::string Name;

    /**
     * @brief District of the vertex.
     */
    std::string District;

    /**
     * @brief Municipality of the vertex.
     */
    std::string Municipaly;

    /**
     * @brief Township of the vertex.
     */
    std::string Township;

    /**
     * @brief Line of the vertex.
     */
    std::string Line;

    /**
     * @brief Cost associated with the vertex.
     */
    double cost = 0;

    /**
     * @brief Incoming capacity of the vertex.
     */
    double INC_capacity = 0;

    /**
     * @brief Outgoing capacity of the vertex.
     */
    double OUT_capacity = 0;

    /**
     * @brief Identifier of the vertex.
     */
    double id;

    /**
     * @brief Outgoing edges from the vertex.
     */
    std::vector<Edge *> adj;

    /**
     * @brief Visited status of the vertex, used by DFS, BFS, Prim, etc.
     */
    bool visited = false;

    /**
     * @brief Processing status of the vertex, used by isDAG (in addition to the visited attribute).
     */
    bool processing = false;

    /**
     * @brief Indegree of the vertex, used by topsort.
     */
    unsigned int indegree;

    /**
     * @brief Distance of the vertex from a source vertex in a graph traversal algorithm.
     */
    double dist = INF;

    /**
     * @brief Path of the vertex in a graph traversal algorithm.
     */
    Edge *path = nullptr;

    /**
     * @brief Incoming edges to the vertex.
     */
    std::vector<Edge *> incoming;

    /**
     * @brief Queue index of the vertex, required by MutablePriorityQueue and UFDS.
     */
    int queueIndex = 0;

};

/********************** Edge  ****************************/

    /**
  * @class Edge
  * @brief Represents an edge between two vertices in a graph.
  */
    class Edge {
    public:
        /**
         * @brief Constructor for Edge.
         * @param orig Pointer to the origin vertex of the edge.
         * @param dest Pointer to the destination vertex of the edge.
         * @param w Weight of the edge.
         */
        Edge(Vertex *orig, Vertex *dest, double w);

        /**
         * @brief Constructor for Edge with additional parameters.
         * @param Station_A Pointer to the first station vertex of the edge.
         * @param Station_B Pointer to the second station vertex of the edge.
         * @param weight Weight of the edge.
         * @param Service Service associated with the edge.
         * @param cost Cost associated with the edge.
         */
        Edge(Vertex* Station_A, Vertex* Station_B, double weight, std::string Service, double cost);

        /**
         * @brief Constructor for Edge with another Edge object as input.
         * @param e Pointer to another Edge object to copy from.
         */
        Edge(Edge* e);

        /**
         * @brief Get the destination vertex of the edge.
         * @return Pointer to the destination vertex.
         */
        Vertex * getDest() const;

        /**
         * @brief Get the weight of the edge.
         * @return Weight of the edge.
         */
        double getWeight() const;

        /**
         * @brief Check if the edge is selected.
         * @return True if the edge is selected, false otherwise.
         */
        bool isSelected() const;

        /**
         * @brief Get the origin vertex of the edge.
         * @return Pointer to the origin vertex.
         */
        Vertex * getOrig() const;

        /**
         * @brief Get the reverse edge of the edge.
         * @return Pointer to the reverse edge.
         */
        Edge *getReverse() const;

        /**
         * @brief Get the flow of the edge.
         * @return Flow of the edge.
         */
        double getFlow() const;

        /**
         * @brief Get the capacity of the edge.
         * @return Capacity of the edge.
         */
        double getCapacity() const;

        /**
         * @brief Get the bidirectional flow of the edge.
         * @return Bidirectional flow of the edge.
         */
        double getBiFlow() const;

        /**
         * @brief Get the service associated with the edge.
         * @return Service of the edge.
         */
        std::string getService() const;

        /**
         * @brief Get the other direction edge of the edge.
         * @return Pointer to the other direction edge.
         */
        Edge* getOtherDirection() const;

        /**
         * @brief Get the segment cost of the edge.
         * @return Segment cost of the edge.
         */
        double getSegment_cost() const;

        /**
         * @brief Set the flow difference of the edge.
         * @param flow Flow difference to set.
         */
        void setFlowDifference(double flow);

        /**
         * @brief Get the flow difference of the edge.
         * @return Flow difference of the edge.
         */
        double getFlowDifference() const;

        /**
         * @brief Set the selected status of the edge.
         * @param selected Selected status to set.
         */
        void setSelected(bool selected);

        /**
         * @brief Set the reverse edge of the edge.
         * @param reverse Pointer to the reverse edge.
         */
        void setReverse(Edge *reverse);

        /**
     * @brief Set the flow of the edge
     * @param flow The flow value to set
     */
        void setFlow(double flow);

        /**
         * @brief Set the capacity of the edge
         * @param cap The capacity value to set
         */
        void setCapacity(double cap);

        /**
         * @brief Set the bidirectional flow of the edge
         * @param biflow The bidirectional flow value to set
         */
        void setBiFlow(double biflow);

        /**
         * @brief Set the other direction of the edge
         * @param e The other direction edge to set
         */
        void setOtherDirection(Edge* e);

        /**
         * @brief Set the segment cost of the edge
         * @param segment_cost The segment cost value to set
         */
        void setSegment_cost(double segment_cost);

        /**
         * @brief Equality operator for comparing edges
         * @param other The other edge to compare with
         * @return true if the edges are equal, false otherwise
         */
        bool operator==(const Edge& other) const;

        /**
         * @brief Greater than operator for comparing edges
         * @param e1 The other edge to compare with
         * @return true if this edge has a greater flow_difference than the other edge, false otherwise
         */
        bool operator >(const Edge& e1) const;

    protected:
        std::string Service; // Service associated with the edge
        Vertex * dest; // destination vertex
        double weight = 0; // edge weight, can also be used for capacity
        double capacity = 0; // edge capacity
        double cost = 0; // edge cost
        double flow_difference = 0; // flow difference for flow-related problems

        // auxiliary fields
        bool selected = false; // flag to indicate if the edge is selected

        // used for bidirectional edges
        Vertex *orig; // origin vertex
        Edge *reverse = nullptr; // reverse edge
        Edge *otherdirection = nullptr; // edge in the other direction

        double flow = 0; // for flow-related problems
        double biflow = 0; // bidirectional flow
        double segment_cost = 0; // segment cost
    };
#endif /* DA_TP_CLASSES_VERTEX_EDGE */

#endif //RAILWAYS_VERTEX_EDGE_H
