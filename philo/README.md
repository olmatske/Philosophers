# Philosophers

Checklist

- [ ] Understand threads
- [ ] Understand mutex

- [ ] Validation
	- [ ] Error definition in header
	- [ ] Parsing
	- [ ] Arguments:
		- Number of philosophers
		- time to die
		- time to eat
		- time to sleep
		- number of times each philosopher must eat

- Time loop
	- [X] Timer

- Routine
	- [ ] while loop with threads and ms

- Philosophers
	- [ ] Struct


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

