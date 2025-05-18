# 🍝 Philosophers

## Overview
This project is a solution to the classic Dining Philosophers problem, implemented as part of the 42 School curriculum. It simulates philosophers sitting at a round table doing one of three things: eating, thinking, or sleeping, while preventing deadlocks and resource starvation.

![Philosophers](https://user-images.githubusercontent.com/54292953/147155376-b47162a6-5d3f-4010-b887-57e9a0814ce5.jpg)

## 📖 About the Project

The Dining Philosophers problem is a classic example used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

### The Problem

- N philosophers sit at a round table with a bowl of spaghetti in the center
- There are N forks placed between each pair of adjacent philosophers
- Each philosopher needs two forks to eat (one from their left and one from their right)
- After eating, they put down both forks and start sleeping
- When they finish sleeping, they start thinking
- The simulation stops when a philosopher dies of starvation or after a specified number of meals

### Constraints

- Philosophers don't speak with each other
- Philosophers don't know if another philosopher is about to die
- Each philosopher needs two forks to eat
- Philosophers must avoid dying (not eating for a specified time period)

## ✨ Features

- **Thread Safety**: Implemented with mutexes to prevent race conditions
- **Real-time Monitoring**: Displays state changes of philosophers with timestamps
- **Customizable Parameters**: Configurable number of philosophers, time to die, time to eat, time to sleep, and optional number of meals
- **Death Detection**: Accurately detects and reports when a philosopher dies
- **Resource Management**: Proper allocation and deallocation of resources

## 🚀 Installation & Usage

### Prerequisites

- GCC compiler
- Make utility
- UNIX-based operating system (Linux/Mac)

### Compilation

```bash
# Navigate to the philo directory
cd philo

# Compile the project
make
```

### Running the Program

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Parameters:

- `number_of_philosophers`: The number of philosophers and forks
- `time_to_die` (in milliseconds): If a philosopher doesn't start eating within this time after their last meal or the beginning of the simulation, they die
- `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat (must hold two forks)
- `time_to_sleep` (in milliseconds): The time a philosopher spends sleeping
- `[number_of_times_each_philosopher_must_eat]` (optional): If all philosophers eat this many times, the simulation stops

### Example

```bash
./philo 5 800 200 200
```
This will simulate 5 philosophers, where each philosopher dies if they don't eat for 800ms, takes 200ms to eat, and sleeps for 200ms.

## 📁 Project Structure

```
philo/
├── includes/
│   └── philosophers.h     # Header file with data structures and function declarations
├── srcs/
│   ├── actions.c          # Philosopher actions (eating, sleeping, thinking)
│   ├── checks.c           # Monitoring and death checking functions
│   ├── free.c             # Memory cleanup functions
│   ├── init.c             # Initialization of data structures
│   ├── main.c             # Main program entry point
│   ├── mutex.c            # Mutex handling functions
│   ├── threads.c          # Thread creation and management
│   └── utils.c            # Utility functions
└── Makefile               # Build instructions
```

## 🧠 Key Concepts Learned

- **Multithreading**: Creating and managing multiple threads to represent philosophers
- **Mutex Locks**: Using mutexes to protect shared resources (forks) from concurrent access
- **Race Conditions**: Identifying and preventing race conditions in concurrent programming
- **Deadlocks**: Understanding and avoiding deadlock situations where processes are blocked forever
- **Resource Allocation**: Efficiently managing and scheduling resources in a concurrent environment
- **Problem Solving**: Approaching a classic computer science problem with practical implementation
- **Code Organization**: Structuring code for maintainability and clarity

## 📝 License

This project is licensed under the terms in the LICENSE file.

---

*This project was completed as part of the 42 School curriculum.*
