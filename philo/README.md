*This project has been created as part of the 42 curriculum by olmatske.*


# Philosophers

## Description

This repository contains an implementation of the classical Dining Philosophers problem, adapted to the requirements of the 42 “philosophers” project. The goal is to simulate a group of philosophers who repeatedly eat, think, and sleep while sharing limited forks, without causing data races, deadlocks, or starvation.

Each philosopher is represented by a thread, and each fork is protected by a mutex to model concurrent access to shared resources. The program focuses on precise timing (eating, sleeping, dying) and correct synchronization so that output remains consistent and philosophers respect the configured constraints.

## Instructions

1. Call the directory in which the project is located
2. compile the project like shown below

```
cd philo
make
./philo 5 800 200 200 3
```
**Note: The input has a clear order of arguments one must follow:**
1. ./philo
2. number of philosophers (should not exceed 200 for optimal performance)
3. time the philosopher can go without eating aka 'time to die'
4. how long the philosopher eats aka 'time to eat'
5. how long the philosopher sleeps aka 'time to sleep' 
6. **OPTIONAL:** how many meals each philosopher must eat

If you do not conform to the order of arguments, an error will occur. If you leave out the number of meals the simulation will either run until you kill the program or a philosopher dies.


## Recources

- Peers
- [gettimeofday manual](https://pubs.opengroup.org/onlinepubs/9699919799/functions/gettimeofday.html)
- [Multithreading Explanation](https://www.geeksforgeeks.org/c/multithreading-in-c/)
- [Mutex Explanation](https://www.geeksforgeeks.org/linux-unix/mutex-lock-for-linux-thread-synchronization/)
- [Philosophers guide](https://42-cursus.gitbook.io/guide/3-rank-03/philosophers/understand-philosophers)
- AI was only used to help find and debug issues I couldn't fix with the help of my peers or the internet, no code was written by AI


---


## Checklist

*The following is my personal checklist I used to structure and track my progress throughout the project.*

- [X] Understand threads
- [X] Understand mutex

- arrays for forks and philo
- bool for alive status -> if dead, 

- Validation
	- [X] Error definition in header
	- [X] Parsing
	- [X] Arguments:
		- Number of philosophers
		- time to die
		- time to eat
		- time to sleep
		- number of times each philosopher must eat

- [X] remove msg of full when done

- Functions 
	Use Wrapper !!!
	- [X] Timer
	- [X] while loop with threads and ms
	- [X] ft_usleep for more precise timing (compare with < ms)
	- [X] ft_sleep
	- [X] grab fork/put down fork
	- [X] check status of death and whether eaten enough
	- [X] exit in pthread function to substitute pthread_cancel
	- [X] free function for philo and table

- Header file
	- [X] Error Messages
	- [X] actions

- Files
	- [X] cleanup
	- [X] validation
	- [X] init
	- [X] 

- Struct
	- [X] mutex protected threads (e.g meal, fork, sleep)
	- [X] mutex protected printf
	- [X] philo eaten enough?

- Routine
	- [X] eat, sleep, think, repeat
	- [X] think if no fork available
