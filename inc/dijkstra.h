
#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

int minDistance(int *distance, int *visited, int n);
void dijkstra(int **matrix, int n, int src, int *distance, int *parent);
void displayForwardingTable(int *distance, int *parent, int n, int src);
void displayShortestPath(int *distance, int *parent, int n, int src, int des);


#endif 