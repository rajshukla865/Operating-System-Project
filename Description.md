# Operating-System-Project
This Project is for college assignment.

QUESTION--

Assume that a finite number of resources of a single resource type must
be managed. Processes may ask for a number of these resources and will
return them once finished. As an example, many commercial software
packages provide a given number of licenses, indicating the number of
applications that may run concurrently. When the application is started,
the license count is decremented. When the application is terminated, the
license count is incremented. If all licenses are in use, requests to start
the application are denied. Such requests will only be granted when
an existing license holder terminates the application and a license is
returned.
The following program segment is used to manage a finite number of
instances of an available resource. The maximum number of resources
and the number of available resources are declared as follows:
#define MAX RESOURCES 5
int available resources = MAX RESOURCES;
When a process wishes to obtain a number of resources, it invokes the
decrease count() function:
/* decrease available resources by count resources */
/* return 0 if sufficient resources available, */
/* otherwise return -1 */
int decrease count(int count) {
if (available resources < count)
return -1;
else {
available resources -= count;
return 0;
}
}


When a process wants to return a number of resources, it calls the
increase count() function:
/* increase available resources by count */
int increase count(int count) {
available resources += count;
return 0;
}
The preceding program segment produces a race condition. Do the
following:
a. Identify the data involved in the race condition.
b. Identify the location (or locations) in the code where the race
condition occurs.
c. Using a semaphore or mutex lock, fix the race condition. It is
permissible to modify the decrease count() function so that the
calling process is blocked until sufficient resources are available.
