#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h> 


#define INITIAL_TEMPERATURE 1000.0
#define COOLING_RATE 0.95
#define MAX_ITERATIONS 1000


// Define a data structure to represent a solution
typedef struct {
    int *courses ; // Array to store course allocations in time slots and rooms
    int cost ;     // Cost of the solution
} Solution ;


int numCourses ;    // Number of courses
int numRooms ;      // Number of rooms
int numTimeslots ;  // Number of time slots
int **conflicts ;   // Matrix of conflicts between courses and rooms
Solution currentSolution ; // Represents the current solution
Solution bestSolution ;    // Represents the best solution found


// Function to calculate the cost of a solution
int calculateCost(Solution solution) 
{
    int cost = 0 ;
    int *roomOccupancy = (int *)malloc(sizeof(int) * numRooms * numTimeslots) ;

    for (int i = 0; i < numRooms * numTimeslots; i++) 
    {
        roomOccupancy[i] = 0 ;
    }

    for (int i = 0; i < numCourses; i++) 
    {
        int roomIndex = solution.courses[i] % numRooms ;
        int timeslotIndex = solution.courses[i] / numRooms ;

        if (roomIndex < numRooms && conflicts[i][roomIndex] > 0) 
        {
            int newTimeslot = timeslotIndex * numRooms + roomIndex ;
            roomOccupancy[newTimeslot]++ ;
            cost += conflicts[i][roomIndex] ;
        }
    }

    for (int i = 0; i < numRooms * numTimeslots; i++) 
    {
        int occupancy = roomOccupancy[i] ;
        int roomCapacity = numRooms ;

        if (occupancy > roomCapacity) 
        {
            cost += (occupancy - roomCapacity) ;
        }
    }

    free(roomOccupancy) ;
    return cost ;
}


// Function to calculate the acceptance probability of a solution
double acceptanceProbability(int currentCost, int newCost, double temperature) 
{
    if (newCost < currentCost) 
    {
        return 1.0 ;
    }

    double delta = newCost - currentCost ;
    return exp(-delta / temperature) ;
}


// Function to solve the problem using Simulated Annealing
void solve() 
{
    double temperature = INITIAL_TEMPERATURE ;
    int iteration = 0 ;

    while (temperature > 1 && iteration < MAX_ITERATIONS) 
    {
        Solution newSolution ;
        newSolution.courses = (int *)malloc(sizeof(int) * numCourses) ;
        newSolution.cost = currentSolution.cost ;

        for (int i = 0; i < numCourses; i++) 
        {
            newSolution.courses[i] = currentSolution.courses[i] ;
        }

        int courseIndex = rand() % numCourses ;
        int timeslotIndex = rand() % numTimeslots ;
        int roomIndex = rand() % numRooms ;
        int newTimeslot = timeslotIndex * numRooms + roomIndex ;
        newSolution.courses[courseIndex] = newTimeslot ;

        int newCost = calculateCost(newSolution) ;
        int currentCost = currentSolution.cost ;
        double acceptanceProb = acceptanceProbability(currentCost, newCost, temperature) ;

        if (newCost < currentCost || (double)rand() / RAND_MAX < acceptanceProb) 
        {
            for (int i = 0; i < numCourses; i++) 
            {
                currentSolution.courses[i] = newSolution.courses[i] ;
            }
            currentSolution.cost = newCost ;
        }

        int bestCost = bestSolution.cost ;
        
        if (currentCost < bestCost) 
        {
            for (int i = 0; i < numCourses; i++) 
            {
                bestSolution.courses[i] = currentSolution.courses[i] ;
            }
            bestSolution.cost = currentCost ;
        }

        temperature *= COOLING_RATE ;
        iteration++ ;
        free(newSolution.courses) ;
    }
}


int main() 
{
        int conflictData[50][10] = {
        {5, 2, 1, 3, 4, 1, 2, 3, 4, 5},
        {1, 4, 3, 2, 5, 2, 3, 1, 4, 5},
        {2, 3, 1, 4, 5, 5, 4, 3, 2, 1},
        {3, 2, 5, 1, 4, 3, 1, 2, 4, 5},
        {1, 2, 4, 5, 3, 4, 5, 2, 1, 3},
        {3, 1, 2, 4, 5, 1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1, 2, 3, 1, 4, 5},
        {2, 3, 1, 4, 5, 5, 4, 3, 2, 1},
        {4, 5, 2, 1, 3, 3, 2, 5, 1, 4},
        {1, 2, 3, 4, 5, 4, 5, 2, 1, 3},
        {5, 2, 1, 3, 4, 1, 2, 3, 4, 5},
        {1, 4, 3, 2, 5, 2, 3, 1, 4, 5},
        {2, 3, 1, 4, 5, 5, 4, 3, 2, 1},
        {3, 2, 5, 1, 4, 3, 1, 2, 4, 5},
        {1, 2, 4, 5, 3, 4, 5, 2, 1, 3},
        {3, 1, 2, 4, 5, 1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1, 2, 3, 1, 4, 5},
        {2, 3, 1, 4, 5, 5, 4, 3, 2, 1},
        {4, 5, 2, 1, 3, 3, 2, 5, 1, 4},
        {1, 2, 3, 4, 5, 4, 5, 2, 1, 3}
    };

    numCourses = 50 ;
    numRooms = 10 ;
    numTimeslots = 10 ;

    conflicts = (int **)malloc(sizeof(int *) * numCourses) ;

    for (int i = 0; i < numCourses; i++) 
    {
        conflicts[i] = (int *)malloc(sizeof(int) * numRooms) ;

        for (int j = 0; j < numRooms; j++) 
        {
            conflicts[i][j] = conflictData[i][j] ;
        }
    }

    currentSolution.courses = (int *)malloc(sizeof(int) * numCourses) ;
    bestSolution.courses = (int *)malloc(sizeof(int) * numCourses) ;
    currentSolution.cost = INT_MAX ;
    bestSolution.cost = INT_MAX ;

    for (int i = 0; i < numCourses; i++) 
    {
        currentSolution.courses[i] = rand() % (numRooms * numTimeslots) ;
        bestSolution.courses[i] = currentSolution.courses[i] ;
    }

    solve() ;

    printf("Best solution found:\n") ;

    for (int i = 0; i < numCourses; i++) 
    {
        printf("Course %d allocated in room %d, timeslot %d\n", i, bestSolution.courses[i] % numRooms, bestSolution.courses[i] / numRooms) ;
    }

    printf("Cost of best solution: %d\n", bestSolution.cost) ;

    for (int i = 0; i < numCourses; i++) 
    {
        free(conflicts[i]) ;
    }

    free(conflicts) ;
    free(currentSolution.courses) ;
    free(bestSolution.courses) ;

    return 0 ;
}
