#include "lgraph.h"
#include <cassert>
#include <queue>
#include <algorithm>

lgraph::lgraph() //fine
{
    data_ = std::map<std::string, std::set<std::string> >();
}

std::size_t lgraph::n() const //fine
{
    return data_.size();
}

std::size_t lgraph::m() //fine
{
    std::size_t loops = 0;
    std::size_t edges = 0;
    for(auto e: data_){
        for(auto u: e.second){
            if(e.first == u)
                ++loops; 
            else
                ++edges;
        }
    }
    return loops+ (edges/2);
}

bool lgraph::is_edge(std::string i, std::string j) //fine
{
    return data_[i].find(j) != data_[i].end();
}


std::set<std::string> lgraph::adj(std::string i) //fine
{
    assert(data_.find(i) != data_.end());
    return data_[i];;
}

void lgraph::add_vertex(std::string i) //fine
{
    //add to the vector
    data_[i] = std::set<std::string>();
}

void lgraph::add_edge(std::string i, std::string j) //okay
{
    if(data_.find(i) != data_.end() && (data_.find(j) != data_.end())){
      data_[i].insert(j);
      data_[j].insert(i);
    }
}

void lgraph::remove_edge(std::string i,std::string j)  //fine
{
    data_[i].erase(j);
    data_[j].erase(i);
}

void lgraph::bfs(){ //fine
    std::queue<std::string> q;
    std::map<std::string, bool> visited;
    
    std::string s = (data_.begin())->first;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        std::string v = q.front();
        q.pop();
        std::cout << v<< " ";
        for(auto n:data_[v]){
                if(!visited[n]){
                 q.push(n); 
                 visited[n] = true;
                }
        }
    }
    std::cout << std::endl;
}

//Problem 3
std::vector<std::string> configs(){ //generates the various configurations of the 4puzzle
    std::vector<std::string> ret; //empty vector
    
    for(int i = 1; i <= 4; i++){ //adds all 24 permutations of 1234 to the vector 
      for(int j = 1; j <= 4; j++){
        if(j == i) //do not want to add to vector if will have for ex. 1123
          continue;
        for(int k = 1; k <= 4; k++){
            if(k == i || k == j)
              continue;
            for(int l = 1; l <= 4; l++){
              if(l == k || l == j || l == i)
                continue;
              std::string ad = "";
              ad += std::to_string(i) + std::to_string(j) + std::to_string(k) + std::to_string(l);
              ret.push_back(ad);
            }
        }
      }
    }
    return ret;
}
//helper functions to generate the correct moves that can be made
std::string vert_move(std::string i){ //move up and down
  //for each position of 4.
  if(i[0] == '4'){
    std::swap(i[0], i[2]);
  }else if(i[1] == '4'){
    std::swap(i[1], i[3]);
  }else if(i[2] == '4'){
    std::swap(i[2], i[0]);
  }else{
    std::swap(i[3], i[1]);
  }
  
  return i;
}
std::string horiz_move(std::string i){ //move side to side
  //technically for both move funcs can have one if/else, but this is more explicit via the pseudocode
  if(i[0] == '4'){
    std::swap(i[0], i[1]); 
  }else if(i[1] == '4'){
    std::swap(i[0], i[1]);
  }else if(i[2] == '4'){
    std::swap(i[2], i[3]);
  }else{
    std::swap(i[3], i[2]);
  }
  return i;
}


lgraph make_graph(std::vector<std::string> v){ //return lgraph with transitions between states
    lgraph g;
    
    for(auto e: v){
      g.add_vertex(e);
    }
    for(auto s: v){
      //add edges to lgraph ret which are possible moves
      std::string m1 = horiz_move(s); 
      std::string m2 = vert_move(s);
      g.add_edge(s, m1);
      g.add_edge(s, m2);
    }
    
    return g;
  
}

std::vector<std::string> lgraph::solve_4_puzzle(const std::string & initial){
  //start with BFS
  std::queue<std::string> q;
  std::map<std::string, bool> visited;
  std::map<std::string, std::string> parent;
  
  std::string s = initial;
  q.push(s);
  visited[s] = true;
  while(!q.empty()){
    std::string v = q.front();
    q.pop();
    for(auto n: data_[v]){
      if(!visited[n]){
        q.push(n); 
        visited[n] = true;
        parent[n] = v;
      }
    }
  }
  
  std::vector<std::string> path;
  if(parent["1234"] == ""){
    path = std::vector<std::string>(); //if it never reaches 1234/is unsolved, create empty vector
    return path;
  }else{
    std::string dest = "1234";
    path.push_back(dest);
    while(dest != initial){
      path.push_back(parent[dest]);
      dest = parent[dest];
    }
    std::reverse(path.begin(), path.end());
    return path;
  }
}