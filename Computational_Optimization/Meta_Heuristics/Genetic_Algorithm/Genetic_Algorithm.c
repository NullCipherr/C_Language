#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

	implementation of a genetic algorithm to solve a task scheduling problem on machines. This problem is commonly encountered in 
	production and logistics systems, where multiple tasks need to be allocated efficiently among a set of available machines.

*/

#define POPULATION_SIZE 100
#define NUM_MACHINES 5 // Adjust this according to your problem
#define NUM_TASKS 20    // Adjust this according to your problem

// Function to calculate fitness
int fitness(int solution[], int task_times[]) 
{
    int machine_times[NUM_MACHINES] = {0} ;

    for (int i = 0; i < NUM_TASKS; i++) 
    {
        int machine = solution[i] ;
        machine_times[machine] += task_times[i] ;
    }

    int max_machine_time = machine_times[0] ;

    for (int i = 1; i < NUM_MACHINES; i++) 
    {
        if (machine_times[i] > max_machine_time) 
        {
            max_machine_time = machine_times[i] ;
        }
    }

    return max_machine_time ;
}

// Function for crossover
void crossover(int parent1[], int parent2[], int child[], int crossover_point) 
{
    for (int i = 0; i < crossover_point; i++) 
    {
        child[i] = parent1[i] ;
    }

    for (int i = crossover_point; i < NUM_TASKS; i++) 
    {
        child[i] = parent2[i] ;
    }
}

// Function for mutation
void mutation(int solution[]) 
{
    int mutation_point = rand() % NUM_TASKS ;
    int new_machine = rand() % NUM_MACHINES ;
    solution[mutation_point] = new_machine ;
}

// Function to initialize population
void initialize_population(int population[][NUM_TASKS], int task_times[]) 
{
    for (int i = 0; i < POPULATION_SIZE; i++) 
    {
        for (int j = 0; j < NUM_TASKS; j++) 
        {
            population[i][j] = rand() % NUM_MACHINES ;
        }
    }
}

// Main solver function
void solve(int max_iterations, int population[][NUM_TASKS], int task_times[], int best_solution[]) 
{
    for (int iteration = 0; iteration < max_iterations; iteration++) 
    {
        int new_population[POPULATION_SIZE][NUM_TASKS] ;

        for (int i = 0; i < POPULATION_SIZE; i++) 
        {
            int parent1[NUM_TASKS], parent2[NUM_TASKS], child[NUM_TASKS];
            int crossover_point = rand() % NUM_TASKS ; 

            int selected_parent1 = rand() % POPULATION_SIZE ;
            int selected_parent2 = rand() % POPULATION_SIZE ;

            for (int j = 0; j < NUM_TASKS; j++) 
            {
                parent1[j] = population[selected_parent1][j] ;
                parent2[j] = population[selected_parent2][j] ;
            }

            crossover(parent1, parent2, child, crossover_point) ;
            mutation(child);

            for (int j = 0; j < NUM_TASKS; j++) 
            {
                new_population[i][j] = child[j] ;
            }
        }

        for (int i = 0; i < POPULATION_SIZE; i++) 
        {
            for (int j = 0; j < NUM_TASKS; j++) 
            {
                population[i][j] = new_population[i][j];
            }
        }
    }

    int min_fitness = fitness(population[0], task_times) ;
    int best_index = 0 ;

    for (int i = 1; i < POPULATION_SIZE; i++) 
    {
        int current_fitness = fitness(population[i], task_times) ;

        if (current_fitness < min_fitness) 
        {
            min_fitness = current_fitness ;
            best_index = i ;
        }
    }

    for (int i = 0; i < NUM_TASKS; i++) 
    {
        best_solution[i] = population[best_index][i] ;
    }
}

int main() 
{
    srand(time(NULL)) ;
    int task_times[NUM_TASKS] ;

    // Initialize task times (you can set these values accordingly)
    for (int i = 0; i < NUM_TASKS; i++) 
    {
        task_times[i] = rand() % 10 + 1 ; // Adjust the range according to your problem
    }

    int population[POPULATION_SIZE][NUM_TASKS] ;
    int best_solution[NUM_TASKS] ;

    initialize_population(population, task_times);
    solve(1000, population, task_times, best_solution);

    printf("Best solution found: ") ;
    for (int i = 0; i < NUM_TASKS; i++) 
    {
        printf("%d ", best_solution[i]) ;
    }
    printf("\n") ;

    return 0 ;
}
