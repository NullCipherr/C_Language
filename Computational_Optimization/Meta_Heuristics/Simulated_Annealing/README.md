📅 Simulated Annealing for Course Scheduling

Simulated Annealing is a heuristic optimization algorithm that can be used to solve various combinatorial optimization problems. This C code demonstrates the application of Simulated Annealing to solve a course scheduling problem. Given a set of courses, rooms, and time slots, the goal is to find an optimal allocation of courses to rooms and time slots while minimizing conflicts and room occupancy.

Problem Description

1. 📚 Number of Courses: numCourses
2. 🏢 Number of Rooms: numRooms
3. ⏰ Number of Time Slots: numTimeslots

he code uses a simulated annealing approach to iteratively improve the allocation of courses to rooms and time slots.


Implementation Details

1. 📊 calculateCost: Function to calculate the cost of a solution, considering conflicts and room occupancy.
2. 🌡️ acceptanceProbability: Function to calculate the acceptance probability of a new solution based on its cost and the current temperature.
3. 🧩 solve: Function to solve the problem using Simulated Annealing, updating the solution iteratively.


Constants

1. 🔥 INITIAL_TEMPERATURE: Initial temperature for the annealing process.
2. ❄️ COOLING_RATE: Cooling rate used to reduce the temperature in each iteration.
3. 🔁MAX_ITERATIONS: Maximum number of iterations for the annealing process.


Usage

1. Compile the code using a C compiler, such as GCC.

 							   gcc your_code_name.c -o your_executable_name

	Replace your_code_name.c with the name of the source code file and your_executable_name with the desired name for the executable.


2. Run the program.

 								./your_executable_name


3. The program will perform simulated annealing to find an optimal course scheduling solution.


Example Output

The program will output the best solution found, including the allocation of each course to a room and time slot, as well as the cost of the best solution.


Customization

You can customize the problem instance by modifying the conflictData, numCourses, numRooms, and numTimeslots variables in the main function.


This README provides an overview of the Simulated Annealing-based course scheduling algorithm and instructions on how to compile and run the code. You can customize the problem instance according to your needs and observe the results for different scenarios.
