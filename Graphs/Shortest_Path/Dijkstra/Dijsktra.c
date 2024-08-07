#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a node in a graph
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices ;      	// Number of vertices in the graph
    struct Node** adjList ; 	// Adjacency list for each vertex
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

// Function to add an edge between source and destination with a given weight
void addEdge(struct Graph* graph, int source, int destination, int weight) 
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
    newNode->weight = weight ;
    newNode->next = graph->adjList[source] ;
    graph->adjList[source] = newNode ;
}

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[], int numVertices) 
{
    int min = INT_MAX, minIndex ;

    for (int v = 0; v < numVertices; v++) 
    {
        if (!visited[v] && dist[v] < min) 
        {
            min = dist[v] ;
            minIndex = v ;
        }
    }

    return minIndex ;
}

// Function to print the path from source to target
void printPath(int parent[], int target) 
{
    if (parent[target] == -1) 
    {
        printf("%d ", target) ;
        return ;
    }
    
    printPath(parent, parent[target]) ;
    printf("%d ", target) ;
}

// Function to free the memory allocated for the graph and its adjacency list
void freeGraph(struct Graph* graph) 
{
    if (graph == NULL) 
    {
        return ; // Verificar se o grafo é nulo antes de liberar
    }

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

// Function to perform Dijkstra's algorithm to find the shortest path
void dijkstra(struct Graph* graph, int source, int target) 
{
    int numVertices = graph->numVertices ;
    int dist[numVertices] ;
    bool visited[numVertices] ;
    int parent[numVertices] ;

    for (int i = 0; i < numVertices; i++) 
    {
        dist[i] = INT_MAX ;
        visited[i] = false ;
        parent[i] = -1 ;
    }

    dist[source] = 0 ;

    for (int count = 0; count < numVertices - 1; count++) 
    {
        int u = minDistance(dist, visited, numVertices) ;
        visited[u] = true ;

        struct Node* current = graph->adjList[u] ; 
        
        while (current != NULL) 
        {
            int v = current->vertex ;
            int weight = current->weight ;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
            {
                dist[v] = dist[u] + weight ;
                parent[v] = u ;
            }
            current = current->next ;
        }
    }

    printf("Shortest path from %d to %d: ", source, target) ;
    printPath(parent, target) ;
    printf("\nShortest distance: %d\n", dist[target]) ;
    
    // Print weights of each vertex
    printf("Weights of each vertex:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() 
{
    int numVertices = 6 ; // Number of vertices in the graph
    struct Graph* graph = createGraph(numVertices) ;

    // Add edges with weights
    addEdge(graph, 0, 1, 4) ;
    addEdge(graph, 0, 2, 2) ;
    
    addEdge(graph, 1, 3, 3) ;
    addEdge(graph, 1, 4, 2) ;
    
    addEdge(graph, 2, 4, 5) ;
    addEdge(graph, 3, 5, 1) ;
    addEdge(graph, 4, 5, 6) ;

    int source = 0 ;   // Source vertex
    int target = 3 ;   // Target vertex

    dijkstra(graph, source, target) ;

    freeGraph(graph) ;
    return 0 ;
}
