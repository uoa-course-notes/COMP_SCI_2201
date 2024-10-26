#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node{
    int vertex;
    struct Node* next;
}Node;


typedef struct Graph{
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

Node* createNode(int);
Graph* createGraph(int);
void addEdge(Graph*, int, int);
void BFS(Graph*, int);
void DFS(Graph*, int);





int main(int argc, char **argv){



    return 0;
}


Node* createNode(int v){
    Node* newNode = malloc(sizeof(Node));
    newNode -> vertex = v;
    newNode -> next = NULL;

    return newNode;
}


Graph* createGraph(int vertices){
    Graph* graph = malloc(sizeof(Graph));
    graph -> numVertices = vertices;
    graph -> adjLists = malloc(vertices * sizeof(Node*));
    graph -> visited = malloc(vertices *sizeof(int));

    for(int i=0; i<vertices; i++){
        graph -> adjLists[i] = NULL;
        graph -> visited[i] = 0;
    }

    return graph;
}


void addEdge(Graph* graph, int src, int des){
    Node* newNode = createNode(des);
    newNode -> next = graph -> adjLists[src];
    graph -> adjLists[src] = newNode;


    newNode = createNode(src);
    newNode -> next = graph -> adjLists[des];
    graph -> adjLists[des] = newNode;
}



