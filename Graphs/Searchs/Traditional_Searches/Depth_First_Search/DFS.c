#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in a graph
struct Node {
    int vertex ;
    struct Node* next ;
};

// Structure to represent a graph
struct Graph {
    int numVertices ;        // Number of vertices in the graph
    struct Node** adjList ;  // Adjacency list for each vertex
};

// Function to create a new graph with V vertices
struct Graph* createGraph(int numVertices) 
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)) ;
    
    if (graph == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed for the graph.\n") ;
        exit(EXIT_FAILURE) ;
    }
    
    graph->numVertices = numVertices ;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*)) ;
    
    if (graph->adjList == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed for the adjacency list.\n") ;
        free(graph) ;
        exit(EXIT_FAILURE) ;
    }

    for (int i = 0; i < numVertices; i++) 
    {
        graph->adjList[i] = NULL ;
    }

    return graph ;
}

// Function to add an edge between source and destination
void addEdge(struct Graph* graph, int source, int destination) 
{
    if (source < 0 || source >= graph->numVertices || destination < 0 || destination >= graph->numVertices) 
    {
        fprintf(stderr, "Error: Vertex indices out of bounds for the graph.\n") ;
        exit(EXIT_FAILURE) ;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)) ;
    if (newNode == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed for a new node.\n") ;
        exit(EXIT_FAILURE) ;
    }
    newNode->vertex = destination ;
    newNode->next = graph->adjList[source] ;
    graph->adjList[source] = newNode ;

    newNode = (struct Node*)malloc(sizeof(struct Node)) ;
    
    if (newNode == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed for a new node.\n") ;
        exit(EXIT_FAILURE) ;
    }
    newNode->vertex = source ;
    newNode->next = graph->adjList[destination] ;
    graph->adjList[destination] = newNode ;
}

// Function to free the memory allocated for the graph and its adjacency list
void freeGraph(struct Graph* graph) 
{    
    for (int i = 0; i < graph->numVertices; i++) 
    {
        struct Node* current = graph->adjList[i] ;
        
        while (current != NULL) 
        {
            struct Node* temp = current ;
            current = current->next ;
            free(temp) ;
        }
    }
    
    free(graph->adjList) ;
    free(graph) ;
}

// Function to perform Depth-First Search (DFS) starting from a given vertex
void DFS(struct Graph* graph, int vertex, bool* visited) 
{
    visited[vertex] = true ;
    printf("%d ", vertex) ;

    struct Node* current = graph->adjList[vertex] ;
    
    while (current != NULL) 
    {
        int adjacent = current->vertex ;
        
        if (!visited[adjacent]) 
        {
            DFS(graph, adjacent, visited) ;
        }
        current = current->next ;
    }
}

// Wrapper function for DFS traversal
void performDFS(struct Graph* graph, int startVertex) 
{
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool)) ;
    
    if (visited == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed for the visited array.\n") ;
        exit(EXIT_FAILURE) ;
    }

    for (int i = 0; i < graph->numVertices; i++) 
    {
        visited[i] = false ;
    }

    printf("Depth-First Search (DFS): ") ;
    DFS(graph, startVertex, visited) ;
    printf("\n") ;

    free(visited) ;
}

int main() 
{
    int numVertices = 6 ; // Number of vertices in the graph
    struct Graph* graph = createGraph(numVertices) ;

    // Add edges
    addEdge(graph, 0, 1) ; 
    addEdge(graph, 0, 2) ;
    addEdge(graph, 1, 3) ;
    addEdge(graph, 1, 4) ;
    addEdge(graph, 2, 4) ;
    addEdge(graph, 3, 5) ;
    addEdge(graph, 4, 5) ;

    performDFS(graph, 0) ;

    freeGraph(graph) ;
    return 0 ;
}
