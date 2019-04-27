#include <iostream>
#include <fstream>
#include "lgraph.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<string> vs = configs(); 
    
    /*cout << vs.size() << endl; //make sure size is 24
    for(auto a: vs)
      cout << a << "  "; //tests to make sure generates vector of configurations properly- 3a
    cout << endl;*/
      
    lgraph puz = make_graph(vs); //generate lgraph for puzzle
    
    vector<string> solve = puz.solve_4_puzzle("3124");
    
    cout << "Solve for 3124: " << endl;
    for(auto e: solve)
      cout << e << endl;
    
    vector<string> solve2 = puz.solve_4_puzzle("2413");
    
    cout << endl << "Solve for 2413: " << endl;
    for(auto a: solve2)
      cout << a << endl;
    
    
    vector<string> solve3 = puz.solve_4_puzzle("1324");
    cout << endl << "Solve for 1324: " << endl;
    for(auto a: solve3)
      cout << a << endl;
    
	vector<string> solve4 = puz.solve_4_puzzle("2314");
    cout << endl << "Solve for 2314: " << endl;
    for(auto a: solve4)
      cout << a << endl;
    
    return 0;
}
