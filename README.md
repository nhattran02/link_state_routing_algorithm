# Link State Routing Algorithm 
The Simulation of Link-State Routing Protocol is a part of the project under course EE3019 - Data Communications and Networking. The program accepts the network topology details in terms of the cost of links, and provides the shortest path tree for the network. It uses Dijkstra’s Algorithm to construct its routing table.

This program has written by using C & Python.h 

## Input of program

Input is a adjacency matrix. The adjacency matrix for undirected graphs is **always symmetric** and **Identity**

Adjacency atrix is a 2D array of size V x V where V is the number of vertices in a graph. Let the 2D array be matrix[ ][ ], a slot matrix[ i ][ j ] not equal to 0 indicates the weight of the edge from vertex i to vertex j, otherwise, matrix[ i ][ j ] = 0, do not have any edge from vertex i to vertex j

For example:

    4
    0  4  2  4
    4  0  2  0 
    2  2  0  2
    4  0  2  0
Graph of the above matrix:
![](image/graph1.png)

    9
    0 7 1 2 2 8 7 1 1
    7 0 9 8 5 6 0 9 2
    1 9 0 4 1 3 4 8 9
    2 8 4 0 2 2 4 4 6
    2 5 1 2 0 7 4 8 9
    8 6 3 2 7 0 2 0 0
    7 0 4 4 4 2 0 2 4
    1 9 8 4 8 0 2 0 8
    1 2 9 6 9 0 4 8 0

Graph of the above matrix:
![](image/graph2.png)

## How to build program

### Build directly
Build in linux:

    gcc src/*.c  -o build/output -I./include -I/usr/include/python3.8 -L/usr/lib/python3.8/config-3.8-x86_64-linux-gnu -lpython3.8

Build in window:

    gcc src/*.c -o build/output -I C:Python310\include -L C:Python310\libs -lpython310

Run output object in Linux/Window:

    ./build/output


### Build using Makefile
Build:

    make

Run:

    make run

Clear output file:

    make clean


