#include "../inc/dijkstra.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int minDistance(int *distance, int *visited, int n)
{
    int min_value = INT_MAX;
    int min_index;
    for(int i = 0; i < n; i++){
        if(!visited[i] && distance[i] < min_value){
            min_value = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int **matrix, int n, int src, int *distance, int *parent)
{
    int visited[n];
    int minidx;
    for(int i = 0; i < n; i++){
        distance[i] = INT_MAX;
        parent[i] = i;
        visited[i] = 0;
    }
    distance[src] = 0;
    for(int i = 0; i < n; i++){
        minidx = minDistance(distance, visited, n);
        visited[minidx] = 1;   
        for(int j = 0; j < n; j++){
            if(matrix[minidx][j] != -1 && distance[minidx] + matrix[minidx][j] < distance[j]){
                distance[j] = distance[minidx] + matrix[minidx][j];
                parent[j] = minidx;
            }
        }
    }
}


void displayForwardingTable(int *distance, int *parent, int n, int src)
{
    int parent_node;
    int temp = -1;
    int flag = 0;
    printf("\n\t ------------------------------------- ");
    printf("\n\t |THE FORWARDING TABLE FOR THE NODE %c|", src + 'A');
    printf("\n\t ------------------------------------- ");
    printf("\n\t Destination \t\t\t Link");
    for(int i = 0; i < n; i++){
        flag = 0;
        printf("\n\t     %c\t\t\t", i + 'A');
        parent_node = parent[i];
        while (parent_node != src){
            flag = 1;
            temp = parent_node;
            parent_node = parent[parent_node];
        }
        if(flag){
            printf("\t (%c,%c)", src + 'A', temp + 'A');        
        }else{
            printf("\t (%c,%c)", src + 'A', i + 'A');
        }
        printf("\n");
    }
}

void displayShortestPath(int *distance, int *parent, int n, int src, int des)
{
    printf("\n\t The shortest path from node %c to node %c:\n", src + 'A', des + 'A');
    printf("\n\t %c ", des + 'A');
    int parent_node = parent[des];
    while (parent_node != src){
        printf("<- %c ", parent_node + 'A');
        parent_node = parent[parent_node];
    }
    printf("<- %c [Total distance = %d]\n", src + 'A', distance[des]);
}