
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>
#include <numpy/arrayobject.h>
#include "../inc/matrix.h"
#include "../inc/graph.h"
#include "../inc/dijkstra.h"
#include <termios.h>


int main(int argc, char const *argv[])
{
    int **cppMatrix;
    int size;
    char *inputMenuKey = malloc(sizeof(char) * 3);

    int src;
    int des;
    int distance[MAX];
    int parent[MAX];

    PyObject *pyMatrix;
    printf("%s%s%s", "\x1b[36;1m", "\n\t LINK STATE ROUTING ALGORITHM\n", "\x1b[39;49m");
    cppMatrix = readMatrixFromFile(&size);

    while (atoi(inputMenuKey) != 5){

        printf("%s%s%s","\x1b[36;1m","\n\t (1) Generate a graph visualization from the input matrix\
                        \n\t (2) Display the forwarding table           \
                        \n\t (3) Shortest path to destination router    \
                        \n\t (4) Modify the Network Topology            \
                        \n\t (5) Exit                                   \
                        \n\n\t Command: ","\x1b[39;49m");  
        scanf("%s", inputMenuKey);
        switch (atoi(inputMenuKey)){
        case 1:
            printMatrix(cppMatrix, size);
            // Initialize Python interpreter
            Py_Initialize();

            pyMatrix = convertcppMatrix2pyMatrix(cppMatrix, size);
            if(!pyMatrix){
                printf("%s%s%s", "\x1b[31;1m", "\t Failed to convert cppMatrx to pyMatrix", "\x1b[39;49m");
            }
            DrawGraph(pyMatrix);
            // Finalize Python interpreter
            Py_Finalize();
            break;
        case 2:
            do{
                printf("\t Enter your start node (In range of %c -> %c or %c -> %c): ", 65, 65 + (size - 1), 97, 97 + (size -1 ));
                scanf("%s", inputMenuKey);
                if(inputMenuKey[0] < 'A' || ((inputMenuKey[0] > ('A' + size -1)) && (inputMenuKey[0] < 'a')) || (inputMenuKey[0] > ('a' + size -1))){
                    printf("%s%s%s", "\x1b[31;1m", "\t Wrong node entered. Try again!\n", "\x1b[39;49m");
                }
            }while(inputMenuKey[0] < 'A' || ((inputMenuKey[0] > ('A' + size -1)) && (inputMenuKey[0] < 'a')) || (inputMenuKey[0] > ('a' + size -1)));
            if(inputMenuKey[0] >= 'A' && inputMenuKey[0] <= 'A' + size - 1){
                src = inputMenuKey[0] - 'A';
            }else if(inputMenuKey[0] >= 'a' && inputMenuKey[0] <= 'a' + size - 1){
                src = inputMenuKey[0] - 'a';
            }

            dijkstra(cppMatrix, size, src, distance, parent);
            displayForwardingTable(distance, parent, size, src);
            
            break;
        case 3:
            do{
                printf("\t Enter your start node (In range of %c -> %c or %c -> %c): ", 65, 65 + (size - 1), 97, 97 + (size -1 ));
                scanf("%s", inputMenuKey);
                if(inputMenuKey[0] < 'A' || ((inputMenuKey[0] > ('A' + size -1)) && (inputMenuKey[0] < 'a')) || (inputMenuKey[0] > ('a' + size -1))){
                    printf("%s%s%s", "\x1b[31;1m", "\t Wrong node entered. Try again!\n", "\x1b[39;49m");
                }
            }while(inputMenuKey[0] < 'A' || ((inputMenuKey[0] > ('A' + size -1)) && (inputMenuKey[0] < 'a')) || (inputMenuKey[0] > ('a' + size -1)));
            if(inputMenuKey[0] >= 'A' && inputMenuKey[0] <= 'A' + size - 1){
                src = inputMenuKey[0] - 'A';
            }else if(inputMenuKey[0] >= 'a' && inputMenuKey[0] <= 'a' + size - 1){
                src = inputMenuKey[0] - 'a';
            }

            do{
                printf("\t Enter your end node   (In range of %c -> %c or %c -> %c): ", 65, 65 + (size - 1), 97, 97 + (size -1 ));
                scanf("%s", inputMenuKey);
                if(inputMenuKey[0] < 'A' || ((inputMenuKey[0] > ('A' + size -1)) && (inputMenuKey[0] < 'a')) || (inputMenuKey[0] > ('a' + size -1))){
                    printf("%s%s%s", "\x1b[31;1m", "\t Wrong node entered. Try again!\n", "\x1b[39;49m");
                }
            }while(inputMenuKey[0] < 'A' || ((inputMenuKey[0] > ('A' + size -1)) && (inputMenuKey[0] < 'a')) || (inputMenuKey[0] > ('a' + size -1)));
            if(inputMenuKey[0] >= 'A' && inputMenuKey[0] <= 'A' + size - 1){
                des = inputMenuKey[0] - 'A';
            }else if(inputMenuKey[0] >= 'a' && inputMenuKey[0] <= 'a' + size - 1){
                des = inputMenuKey[0] - 'a';
            }

            dijkstra(cppMatrix, size, src, distance, parent);
            displayShortestPath(distance, parent, size, src, des);
            break;
        case 4:
            while(1);

            break;
        case 5:
            printf("\n\t EXITED\n");
            return 0;
            break;
        default:
            printf("%s%s%s", "\x1b[31;1m", "\t Wrong menu key entered. Try again!", "\x1b[39;49m");

            break;
        }
    }
    
    free(inputMenuKey);
    freeMemory(cppMatrix, size);
    return 0;
}



