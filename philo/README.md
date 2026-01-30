# Philosophers

Checklist

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


- Functions 
	Use Wrapper !!!
	- [X] Timer
	- [ ] while loop with threads and ms
	- [ ] ft_usleep for more precise timing (compare with < ms)
	- [ ] ft_sleep
	- [ ] grab fork/put down fork
	- [ ] check status of death and whether eaten enough


- Header file
	- [X] Error Messages
	- [X] actions


- Files
	- [ ] cleanup
	- [ ] validation
	- [ ] init


- Struct
	- [X] mutex protected threads (e.g meal, fork, sleep)
	- [X] mutex protected printf
	- [X] philo eaten enough?
	- [ ] exit in pthread to substitute pthread_cancel



-> make it so that odd numbered philos grab the right then the left fork,
	and the even numbered philos grab the left then the right one

Allowed Functions:

- memset
- printf
- malloc
- free
- write
- usleep
- gettimeofday
- pthread_create
- pthread_detach
- pthread_join
- pthread_mutex_init
- pthread_mutex_destroy
- pthread_mutex_lock
- pthread_mutex_unlock


	◦ number_of_philosophers: The number of philosophers and also the number
		of forks.

	◦ time_to_die (in milliseconds): If a philosopher has not started eating within
		time_to_die milliseconds since the start of their last meal or the start of the
		simulation, they die.

	◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
		During that time, they will need to hold two forks.

	◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

	◦ number_of_times_each_philosopher_must_eat (optional argument): If all
		philosophers have eaten at least number_of_times_each_philosopher_must_eat
		times, the simulation stops. If not specified, the simulation stops when a
		philosopher dies.





## Recources

[gettimeofday manual](https://pubs.opengroup.org/onlinepubs/9699919799/functions/gettimeofday.html)
[Multithreading Explanation](https://www.geeksforgeeks.org/c/multithreading-in-c/)
[Mutex Explanation](https://www.geeksforgeeks.org/linux-unix/mutex-lock-for-linux-thread-synchronization/)
[Philosophers guide](https://42-cursus.gitbook.io/guide/3-rank-03/philosophers/understand-philosophers)










