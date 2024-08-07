#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000
#define TABU_TENURE 10
#define PROBLEM_SIZE 10
#define MAX_RANDOM_VALUE 100

// Objective function - simple example
double objective_function(int solution[]) 
{
    // This function calculates the objective value of a solution.
    double value = 0.0 ;
    
    for (int i = 0; i < PROBLEM_SIZE; i++) 
    {
        value += solution[i] ;
    }
    
    return value ;
}

// Function to copy a solution
void copy_solution(int from[], int to[]) 
{
    // This function copies the content of one solution to another.
    for (int i = 0; i < PROBLEM_SIZE; i++) 
    { 
        to[i] = from[i] ;
    }
}

// Function to update the best solution
void update_best_solution(int current[], int best[], double *best_value) 
{
    // This function updates the best solution if a better solution is found.
    double current_value = objective_function(current) ;
    if (current_value < *best_value) 
    {
        *best_value = current_value ;
        copy_solution(current, best) ;
    }
}

// Initialize the initial solution with random values
void initialize_solution(int solution[]) 
{
    // This function initializes the initial solution with random values
    for (int i = 0; i < PROBLEM_SIZE; i++) 
    {
        solution[i] = rand() % MAX_RANDOM_VALUE ; // Use any appropriate range for random values according to your problem.
    }
}

// Generate a neighboring solution by swapping two random elements
void generate_neighbor(int solution[], int neighbor[]) 
{
    for (int i = 0; i < PROBLEM_SIZE; i++) 
    {
        neighbor[i] = solution[i] ;
    }

    int i = rand() % PROBLEM_SIZE ;
    int j = rand() % PROBLEM_SIZE ;
    
    // Avoid swapping the same element
    while (i == j) 
    {
        j = rand() % PROBLEM_SIZE ;
    }

    // Swap elements i and j to create a neighboring solution
    int temp = neighbor[i] ;
    neighbor[i] = neighbor[j] ;
    neighbor[j] = temp ;
}

int main() 
{
    srandom(time(NULL)) ; // Initialize the random number generator based on time

    int initial_solution[PROBLEM_SIZE] ;
    initialize_solution(initial_solution) ;

    int best_solution[PROBLEM_SIZE] ;
    copy_solution(initial_solution, best_solution) ; // Initialize the best solution with the initial solution
    double best_solution_value = objective_function(initial_solution) ;

    int tabu_list[TABU_TENURE][PROBLEM_SIZE] ;
    int tabu_tenure[TABU_TENURE] ;
    for (int i = 0; i < TABU_TENURE; i++) 
    {
        tabu_tenure[i] = 0 ;
    }

    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) 
    {
        int neighbor[PROBLEM_SIZE] ;
        generate_neighbor(initial_solution, neighbor) ;

        // Check if the neighboring solution is better than the current best solution
        double neighbor_value = objective_function(neighbor) ;
        if (neighbor_value < best_solution_value) 
        {
            best_solution_value = neighbor_value ;
            copy_solution(neighbor, best_solution) ; // Update the best solution found
            update_best_solution(neighbor, best_solution, &best_solution_value) ; // Update the best solution using the function
        }

        // Update the tabu list
        for (int i = 0; i < TABU_TENURE - 1; i++) 
        {
            for (int j = 0; j < PROBLEM_SIZE; j++) 
            {
                tabu_list[i][j] = tabu_list[i + 1][j] ;
            }
            tabu_tenure[i] = tabu_tenure[i + 1] ;
        }

        copy_solution(neighbor, tabu_list[TABU_TENURE - 1]) ; // Update the tabu list with the neighboring solution
        tabu_tenure[TABU_TENURE - 1] = TABU_TENURE ;

        // Check and update the duration of the tabu list
        for (int i = 0; i < TABU_TENURE; i++) 
        {
            if (tabu_tenure[i] > 0) 
            {
                tabu_tenure[i]-- ;
            }
        }

        // Print the current iteration, best solution value, and tabu list status
        printf("Iteration %d:\n", iteration) ;
        printf("Best Value = %lf\n", best_solution_value) ;
        printf("Best Solution: ") ;
        
        for (int i = 0; i < PROBLEM_SIZE; i++) 
        {
            printf("%d ", best_solution[i]) ;
        }
        
        printf("\nTabu List:\n") ;
        
        for (int i = 0; i < TABU_TENURE; i++) 
        {
            printf("Tenure %d: ", i) ;
            for (int j = 0; j < PROBLEM_SIZE; j++) 
            {
                printf("%d ", tabu_list[i][j]) ;
            }
            printf("Remaining Tenure: %d\n", tabu_tenure[i]) ;
        }
        printf("\n") ;
    }

    // Output results
    printf("Best solution found: ") ;
    
    for (int i = 0; i < PROBLEM_SIZE; i++) 
    {
        printf("%d ", best_solution[i]);
    }
    
    printf("\nValue of Objective Function: %lf\n", best_solution_value) ;

    return 0 ;
}
