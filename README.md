# 4-Puzzle
A class project for Data Structures that I found very fulfilling to create. Solves a 4-puzzle (a simplified version of the 8-puzzle https://en.wikipedia.org/wiki/15_puzzle with a 2x2 board).

Done using breadth-first search on the graph whose vertices are different board positions and whose edges connect two board positions reachable from one another via a valid move.
For example, if the input is the string "4132" i.e. representing a board of format:
       1
    3  2
then the output is a vector containing the following strings, meant to describe the steps taken to solve the puzzle, with '4' representing the empty spot: {"3124","3421","4321","2341","2314","2413","4213","1243","1234"}. If there is no solution, then the vector returned will be empty.
