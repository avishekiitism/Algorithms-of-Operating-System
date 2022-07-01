# Algorithms-of-Operating-System
Important concept of operating system with cpp code.

1. First Come First Serve (FCFS)

CRITERIA: Arrival time

MODE: Non- preemptive

First come first serve scheduling algorithm states that the process that requests the CPU first is allocated the CPU first.
Note: First come first serve suffers from convey effect.{In FCFS if any process is having high burst time (CPU Bound Time),then it will have major effect on average WAITING TIME of processes. This effect is called CONVEY EFFECT}

2. Shortest Job First (SJF)

CRITERIA: Burst time

MODE: Non- preemptive

Processes which have the shortest burst time are scheduled first. If two processes have the same bust time then FCFS is used to break the tie. It is a non-preemptive scheduling algorithm.

3. Shortest Remaining Time First (SRTF)

CRITERIA: Burst time

MODE:  Preemptive

It is preemptive mode of SJF algorithm in which jobs are schedule according to shortest remaining time.

4. Priority Based Scheduling(PBS_N):

CRITERIA:  Priority 

MODE:  Non-Preemptive

Priority scheduling is a non-preemptive algorithm and one of the most common scheduling algorithms in batch systems. Each process is assigned first arrival time (less arrival time process first) if two processes have same arrival time, then compare to priorities (highest process first). Also, if two processes have same priority then compare to process number (less process number first). This process is repeated while all process will get executed.

5. Priority Based Scheduling(PBS_P):

CRITERIA:  Priority

MODE:  Preemptive

In Preemptive Priority Scheduling, at the time of arrival of a process in the ready queue, its Priority is compared with the priority of the other processes present in the ready queue as well as with the one which is being executed by the CPU at that point of time. The One with the highest priority among all the available processes will be given the CPU next.

![image](https://user-images.githubusercontent.com/81633786/176913472-1b415567-f054-462c-8e83-f44de0fc3257.png)

![image](https://user-images.githubusercontent.com/81633786/176913645-6a66b300-31f6-464f-8474-065bc3524e1d.png)

![image](https://user-images.githubusercontent.com/81633786/176913721-2343e202-287d-4faf-9e94-9262b317b53f.png)

***********************************************************************************************************************************************************************
 
1. Longest Job First (LJF)

CRITERIA: Burst time in descending order

MODE: Non- preemptive

Processes which have the longest burst time are scheduled first. If two processes have the same bust time then FCFS is used to break the tie. It is a non-preemptive scheduling algorithm.

2. Longest Remaining Time First (LRTF)

CRITERIA: Burst time in descending order

MODE:  Preemptive

It is preemptive mode of LJF algorithm in which jobs are schedule according to longest remaining time.

3. Round Robin Scheduling(RRS)

CRITERIA:  Arrival Time 

MODE:  Preemptive

Round Robin is a CPU scheduling algorithm where each process is assigned a fixed time slot in a cyclic way. It is simple, easy to implement, and starvation-free as all processes get fair share of CPU. One of the most commonly used technique in CPU scheduling as a core.

![image](https://user-images.githubusercontent.com/81633786/176914081-08a93ff3-66b7-47da-b2c2-2895418c3c35.png)

![image](https://user-images.githubusercontent.com/81633786/176914136-c5ee8a15-5bf6-4a9c-a8f8-98af0a7434f8.png)

![image](https://user-images.githubusercontent.com/81633786/176914230-f35fe368-a7ab-44f4-84c0-63bae62b788d.png)

***********************************************************************************************************************************************************************

1. Highest Response Ratio Next(HRRN)

CRITERIA: Highest response ratio

MODE: Non- preemptive

Highest Response Ratio Next (HRNN) is one of the most optimal scheduling algorithms. This is a non-preemptive algorithm in which, the scheduling is done on the basis of an extra parameter called Response Ratio. A Response Ratio is calculated for each of the available jobs and the Job with the highest response ratio is given priority over the others.

2. Multilevel Queue(MLQ)

Multilevel queue scheduling is used when processes in the ready queue can be divided into different classes where each class has its own scheduling needs. 
For instance, foreground or interactive processes and background or batch processes are commonly divided. Foreground and background processes have different time requirements and hence will have different scheduling needs. In this case, multilevel queue scheduling will be used. 

3.Multilevel Feedback Queue(MLFQ)

This Scheduling is like Multilevel Queue(MLQ) Scheduling but in this process can move between the queues. Multilevel Feedback Queue Scheduling (MLFQ) keep analyzing the behavior (time of execution) of processes and according to which it changes its priority

![image](https://user-images.githubusercontent.com/81633786/176914741-43fdb3f7-b32c-4c76-a501-9ba00f8139e2.png)

![image](https://user-images.githubusercontent.com/81633786/176914789-59f1d243-5a0f-490f-bc45-2e3c9d2fb630.png)

![image](https://user-images.githubusercontent.com/81633786/176914850-aec2af6d-755e-43bd-a334-b85ed7a4bd0a.png)

***********************************************************************************************************************************************************************

1. Bankers Algorithm:

The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for possible activities, before deciding whether allocation should be allowed to continue.

![image](https://user-images.githubusercontent.com/81633786/176915390-8dccbbc1-e368-4aa1-85d1-c1e473a6172c.png)

***********************************************************************************************************************************************************************

1.	First In First Out (FIFO) Page Replacement Algorithm:

This is the simplest page replacement algorithm. In this algorithm, the operating system keeps track of all pages in the memory in a queue, the oldest page is in the front of the queue. When a page needs to be replaced, page in the front of the queue is selected for removal.

2.	Optimal Page Replacement Algorithm:

In this algorithm, pages are replaced which would not be used for the longest duration of time in the future.

3.	Least Recently Used (LRU) Page Replacement Algorithm:

 In this algorithm page will be replaced which is least recently used.

![image](https://user-images.githubusercontent.com/81633786/176916381-61695343-32a8-467c-ab21-d09b12a88492.png)

![image](https://user-images.githubusercontent.com/81633786/176916477-5bdadeb7-2197-4605-aafa-2a472133f303.png)

![image](https://user-images.githubusercontent.com/81633786/176916550-673d21d7-30b3-485c-b411-132bfdb9e837.png)



