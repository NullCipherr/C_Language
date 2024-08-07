🧬 Genetic Algorithm for Task Scheduling

This C code implements a genetic algorithm to solve a task scheduling problem on multiple machines. Such problems are common in production and logistics systems, where tasks need to be efficiently allocated among a set of available machines.

Problem Description

1. 🔨 Population Size: POPULATION_SIZE
2. 🏭 Number of Machines: NUM_MACHINES (Adjust according to your problem)
3. 📅 Number of Tasks: NUM_TASKS (Adjust according to your problem)

The objective is to minimize the makespan, i.e., the time taken to complete all tasks on the machines.


Implementation Details

1. 🏆 fitness: Function to calculate the fitness of a solution based on makespan.
2. 🤝 crossover: Function for crossover to create new solutions.
3. 🧬 mutation: Function for mutation to introduce diversity.
4. 🌱 initialize_population: Function to initialize the population of solutions.
5. 🔍 solve: Main solver function that evolves the population.


Usage

1. Compile the code using a C compiler, such as GCC.

 							   gcc your_code_name.c -o your_executable_name

	Replace your_code_name.c with the name of the source code file and your_executable_name with the desired name for the executable.


2. Run the program.

 								./your_executable_name


3. The program will perform a genetic algorithm to find the best task scheduling solution.


Example Output

The program will display the best solution found, representing the allocation of tasks to machines.


Customization

You can customize the problem instance, such as the number of machines, tasks, population size, and task times, to suit your specific problem.


This README provides an overview of the Genetic Algorithm applied to a task scheduling problem with figurines for visual appeal. Remember to replace your_code_name.c with the actual name of your source code file and your_executable_name with the desired name for the executable when compiling and running the code.
