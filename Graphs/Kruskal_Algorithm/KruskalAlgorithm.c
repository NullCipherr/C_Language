#include <stdio.h>
#include <limits.h>

#define V 5

int parent[V] ;

int find(int i) 
{
    while (parent[i] != i) 
    {
        i = parent[i] ;
    }
    
    return i ;
}

void unionSet(int i, int j) 
{
    int x = find(i) ;
    int y = find(j) ;
    parent[y] = x ;
}

void kruskal(int cost[V][V]) 
{
    int minCost = 0 ;
    int edgeCount = 0 ;

    // Initialize the parent array
    for (int i = 0; i < V; i++) 
    {
        parent[i] = i ;
    }

    while (edgeCount < V - 1) 
    {
        int min = INT_MAX, x = -1, y = -1 ;
	
	// Find the minimum cost edge
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                if (find(i) != find(j) && cost[i][j] < min) 
                {
                    min = cost[i][j] ;
                    x = i ;
                    y = j ;
                }
            }
        }
	
	// Union the sets of x and y
        unionSet(x, y) ;
        
        // Print the edge and its cost
        printf("Edge %d: (%d, %d) cost: %d\n", edgeCount, x, y, min) ;
        
        minCost += min ;
        edgeCount++ ;
    }
	
    // Print the minimum cost
    printf("\nMinimum Cost: %d\n", minCost) ;
}

int main() 
{
    int cost[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    } ;
	
    // Call the Kruskal's algorithm function
    kruskal(cost) ;
    return 0 ;
}
