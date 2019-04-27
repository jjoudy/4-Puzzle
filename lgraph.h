#ifndef UGRAPH_H
#define UGRAPH_H

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

// assumption: vertices are numbered 0, 1, ..., n-1

class lgraph
{
public:

    // pre: none
    // post: an empty graph has been created
    lgraph();

    // pre: none
    // post: returns the number of vertices in this graph
    std::size_t n() const;

    // pre: none
    // post: returns the number of edges in this graph
    std::size_t m();

    // pre: none
    // post: returns the number of connected components of this graph
    std::size_t ncc() const;

    // pre: none
    // post: returns true if this graph is connected
    bool is_connected() const;

    // pre: i < n() && j < n()
    // post: returns true iff {i, j} is an edge of this graph
    bool is_edge(std::string i, std::string j);

    // pre: none
    // post: returns true if this graph has no cycles
    bool is_acyclic() const;

    // pre: none
    // post: returns true iff this graph is a complete graph
    bool is_complete() const;

    // pre: i < n()
    // post: returns the adjacency list of i in this graph
    std::set<std::string> adj(std::string i);

    // pre: none
    // post: a new vertex with label n() has been added to this graph
    void add_vertex(std::string s);

    // pre: i < n() && j < n()
    // post: edge {i, j} has been added to this graph
    //       if it is not an edge already
    void add_edge(std::string i, std::string j);

    // pre: i < n() && j < n()
    // post: edge {i, j} has been removed from this graph
    //       if it is currently an edge; otherwise do nothing
    void remove_edge(std::string i, std::string j);
    
    void printall();
    void bfs();
    
    
    //hw part 3
    std::vector<std::string> solve_4_puzzle(const std::string & initial); //solve the 4 puzzle

 private:
    std::map<std::string, std::set<std::string> > data_;

};

// pre: none
// post: outputs g to stream os in the following format
//  n m
//  i1 j1  (where i1 < j1)
//  ...
//  im jm
std::ostream & operator << (std::ostream & os, lgraph & g);
std::istream & operator >> (std::istream & is, lgraph & g);

//not member functions - HW PT. 3
std::vector<std::string> configs(); //generates the various configurations of the 4puzzle
lgraph make_graph(std::vector<std::string> v); //lgraph with transitions between states

//helper functions HW 3b
std::string vert_move(std::string);
std::string horiz_move(std::string);


#endif // UGRAPH_H
