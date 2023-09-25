#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in a graph
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;      // Number of vertices in the graph
    struct Node** adjList; // Adjacency list for each vertex
};

// Function to create a new graph with V vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    
    if (graph == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for the graph.\n");
        exit(EXIT_FAILURE);
    }
    
    graph->numVertices = numVertices;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    
    if (graph->adjList == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for the adjacency list.\n");
        free(graph);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge between source and destination
void addEdge(struct Graph* graph, int source, int destination) {
    if (source < 0 || source >= graph->numVertices || destination < 0 || destination >= graph->numVertices) {
        fprintf(stderr, "Error: Vertex indices out of bounds for the graph.\n");
        exit(EXIT_FAILURE);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for a new node.\n");
        exit(EXIT_FAILURE);
    }
    
    newNode->vertex = destination;
    newNode->next = graph->adjList[source];
    graph->adjList[source] = newNode;
}

// Function to free the memory allocated for the graph and its adjacency list
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->adjList[i];
        
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    free(graph->adjList);
    free(graph);
}

// Function to perform breadth-first search (BFS) starting from a given startVertex
void BFS(struct Graph* graph, int startVertex, bool* visited, int* queue, int* rear) {
    visited[startVertex] = true;
    queue[(*rear)++] = startVertex;
}

// Function to check if there is an intersection between the forward and backward BFS searches
int isIntersection(bool* forwardVisited, bool* backwardVisited, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (forwardVisited[i] && backwardVisited[i]) {
            return i; // Intersection found
        }
    }
    return -1; // No intersection found
}

// Function to perform bidirectional breadth-first search (Bidirectional BFS)
void BidirectionalBFS(struct Graph* forwardGraph, struct Graph* backwardGraph, int startVertex, int targetVertex) {
    int numVertices = forwardGraph->numVertices;

    bool* forwardVisited = (bool*)malloc(numVertices * sizeof(bool));
    bool* backwardVisited = (bool*)malloc(numVertices * sizeof(bool));
    
    if (forwardVisited == NULL || backwardVisited == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for visited arrays.\n");
        exit(EXIT_FAILURE);
    }

    int* forwardQueue = (int*)malloc(numVertices * sizeof(int));
    int* backwardQueue = (int*)malloc(numVertices * sizeof(int));
    
    if (forwardQueue == NULL || backwardQueue == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for queues.\n");
        exit(EXIT_FAILURE);
    }

    int forwardFront = 0, forwardRear = 0;
    int backwardFront = 0, backwardRear = 0;

    for (int i = 0; i < numVertices; i++) {
        forwardVisited[i] = false;
        backwardVisited[i] = false;
    }

    BFS(forwardGraph, startVertex, forwardVisited, forwardQueue, &forwardRear);
    BFS(backwardGraph, targetVertex, backwardVisited, backwardQueue, &backwardRear);

    int intersectionVertex = isIntersection(forwardVisited, backwardVisited, numVertices);

    if (intersectionVertex != -1) {
        printf("Intersection found at vertex %d\n", intersectionVertex);
    } else {
        printf("No intersection found\n");
    }

        free(forwardVisited);
    free(backwardVisited);
    free(forwardQueue);
    free(backwardQueue);
}

int main() {
    int numVertices = 6; // Number of vertices in the graph
    struct Graph* forwardGraph = createGraph(numVertices);
    struct Graph* backwardGraph = createGraph(numVertices);

    // Add edges
    addEdge(forwardGraph, 0, 1);
    addEdge(forwardGraph, 0, 2);
    addEdge(forwardGraph, 1, 3);
    addEdge(forwardGraph, 1, 4);
    addEdge(forwardGraph, 2, 4);
    addEdge(forwardGraph, 3, 5);
    addEdge(forwardGraph, 4, 5);

    // Create a backward graph with reverse edges
    addEdge(backwardGraph, 1, 0);
    addEdge(backwardGraph, 2, 0);
    addEdge(backwardGraph, 3, 1);
    addEdge(backwardGraph, 4, 1);
    addEdge(backwardGraph, 4, 2);
    addEdge(backwardGraph, 5, 3);
    addEdge(backwardGraph, 5, 4);

    int startVertex = 0; // Starting vertex for forward BFS
    int targetVertex = 5; // Target vertex for backward BFS

    printf("Bidirectional Breadth-First Search (Bidirectional BFS):\n");
    BidirectionalBFS(forwardGraph, backwardGraph, startVertex, targetVertex);
    printf("\n");

    freeGraph(forwardGraph);
    freeGraph(backwardGraph);
    
    return 0;
}

