### What are Memory Management Techniques ?

    Desired Out Come 1. More Memory Space
                     2. Less Access Time
                     3. Less per unit Cost
                     
    | CPU | -----> | Cache | -----> | Main Memory |  -----> | Physical Address |
    
    OS Duties 1. "Address Allocation" for the process between Physical Address abd logical address.
              2. "Address Translation" for translating addresses between logical address and physical address.


Types of Memory Allocation : 
	1. Contiguous Memory Allocation : Allocation memory in to logical memory as it is.
		-- Access time is faster due direct address computation.
        -- Suffers from External fragmentation which is, the various free spaced holes that are generated in either your memory or disk space.
           i.e, required memory is available but still can not allocate to memory because memory is no in contiguous manner.
			1. Fix Sized Partition
			2. Variable Sized Partition 

        2. Non-contiguous Memory Allocation : Dividing process in chunk of blocks (pages) and load in logical memory irrespective of its order.
		-- Access time more due to shifting to new address after reading one block memory completely.
        -- Suffers from Internal fragmentation which is the wasted space within each allocated block because of rounding up from the actual
           requested allocation to the allocation granularity.
                1. Segmentation
    			2. Paging
	    		3. Swapping

1. Fix sized partition :
	-- Available memory is divided into blocks or partitions and the size of the partitions can not be changed.
	-- Easy to manage
	-- Suffers from Internal fragmentation
	-- Only one process can have one partition

2. Variable Sized Partition :
	-- Entire memory block is treated as single block. If some process requires some amount of space only that amount of space is allocated
	   instead of allocating entire partition.
	-- No internal fragmentation.
	-- Hard to manage compared to fixed size partition tech.

Algorithm for memory management 
	1. First fit Policy
	2. Best fit policy
	3. Worst fit policy
*************************************************************************************************************************************
### What is Paging and Frames ?

In computer operating systems, paging is a memory management scheme by which the secondary memory of the computer is divided into
same-size blocks of memory called "Pages" to solve the problem of the non-contiguous memory allocation.

A computer stores and retrieves data from secondary storage for use in main memory.In this scheme, the operating system retrieves
data from secondary storage, stored in pages. Paging is an important part of virtual memory implementations in modern operating
systems, using secondary storage to let programs exceed the size of available physical memory.

In Case of main memory, In order to copy the data from the pages(memory blocks) of the secondary memory the memory blocks on primary
memory should be of same size. These memory blocks on the Primary memory are called "Frames"

Main Memory :   RAM (an acronym of "random-access memory")  ---------> Physical Address
Secondary Memory : Disk (a shorthand for "hard disk drive") ---------> Logical Address

Maintaining "Page Table" :
1. It is a Data structure which maintains the address of the Frame present in main memory of the corresponding Page in secondary memory.
2. Every process has a different Pages table and no of entries in the page table is equal to the no of pages in that process.

Sequence for process execution :
1. CPU generates a logical address of the Page. (Logical Address contains Page number and Instruction offset).
2. With the help of PTBR (Page Table Base Register) holds the the value of appropriate PT. PTBR is stored in the PCB (Process Control Block)
3. Now with Page no present in the logical address PC identifies the address og the corresponding frame in tne main memory and combines
    it with the instruction offset received from logical address. when frame address and instruction address comes together it forms
    Physical address.

Advantages :
 --Fast Access
 --No External Fragmentation.

Disadvantages :
 --Internal Fragmentation
 --Suffers from the double time for Instruction Access.(Still better than reading from the secondary)

The hardware implementation of page table can be done by using dedicated registers. But the usage of register for the page table is
satisfactory only if page table is small. If page table contain large number of entries then we can use TLB(translation Look-aside buffer),
a special, small, fast look up hardware cache.
*************************************************************************************************************************************
### Scheduling Algorithm :

CPU scheduling is a process which allows one process to use the CPU while the execution of another process is on hold(in waiting state)
due to unavailability of any resource like I/O etc, thereby making full use of CPU. The aim of CPU scheduling is to make the system
efficient, fast and fair.
Whenever the CPU becomes idle, the operating system must select one of the processes in the ready queue to be executed. The selection
process is carried out by the short-term scheduler (or CPU scheduler).

Another component involved in the CPU scheduling function is the Dispatcher. The dispatcher is the module that gives control of the CPU
to the process selected by the short-term scheduler. This function involves:

1. Switching context
2. Switching to user mode
3. Jumping to the proper location in the user program to restart that program from where it left last time.

The dispatcher should be as fast as possible, given that it is invoked during every process switch. The time taken by the dispatcher'
to stop one process and start another process is known as the Dispatch Latency.

CPU scheduling decisions may take place under the following four circumstances:
1. When a process switches from the running state to the waiting state(for I/O request or invocation of wait for the termination of
    one of the child processes).
2. When a process switches from the running state to the ready state (for example, when an interrupt occurs).
3. When a process switches from the waiting state to the ready state(for example, completion of I/O).
4. When a process terminates
When Scheduling takes place only under circumstances 1 and 4, we say the scheduling scheme is non-preemptive; otherwise the scheduling
scheme is preemptive.

Non-Preemptive Scheduling   :
Under non-preemptive scheduling, once the CPU has been allocated to a process, the process keeps the CPU until it releases the CPU
either by terminating or by switching to the waiting state.
It is the only method that can be used on certain hardware platforms, because It does not require the special hardware
(for example: a timer) needed for preemptive scheduling.

Preemptive Scheduling   :
In this type of Scheduling, the tasks are usually assigned with priorities. At times it is necessary to run a certain task that
has a higher priority before another task although it is running. Therefore, the running task is interrupted for some time and
resumed later when the priority task has finished its execution.

Types of Process scheduling algorithm :
    1. First come first serve
    2. Shortest job first
    3. Priority Scheduling 
    4. Round Robin
    
CPU Scheduling: Scheduling Criteria
There are many different criteria to check when considering the "best" scheduling algorithm, they are:

1. CPU Utilization  :
    To make out the best use of CPU and not to waste any CPU cycle, CPU would be working most of the time(Ideally 100% of the time).
    Considering a real system, CPU usage should range from 40% (lightly loaded) to 90% (heavily loaded.)
2. Throughput   :
    It is the total number of processes completed per unit time or rather say total amount of work done in a unit of time. This may
    range from 10/second to 1/hour depending on the specific processes.
3. Turnaround Time  :
    It is the amount of time taken to execute a particular process, i.e. The interval from time of submission of the process to
    the time of completion of the process(Wall clock time).
4. Waiting Time :
    The sum of the periods spent waiting in the ready queue amount of time a process has been waiting in the ready queue to acquire
    get control on the CPU.
5. Load Average :
    It is the average number of processes residing in the ready queue waiting for their turn to get into the CPU.
6. Response Time    :
    Amount of time it takes from when a request was submitted until the first response is produced. Remember, it is the time till
    the first response and not the completion of process execution(final response).

Burst Time: Time taken for a precess to complete its execution.
Completion Time: Time taken for the execution to complete, starting from arrival time.
Turn Around Time: Time taken to complete after arrival. In simple words, it is the difference between the Completion time and the
    Arrival time.
Waiting Time: Total time the process has to wait before it's execution begins. It is the difference between the Turn Around time
    and the Burst time of the process.
***

### What is a core dump ?

In computing, a core dump, memory dump, or system dump consists of the recorded state of the working memory of a computer program at
a specific time, generally when the program has crashed or otherwise terminated abnormally.
***

### What is Segmentation Fault ?

Core Dump/Segmentation fault is a specific kind of error caused by accessing memory that “does not belong to you.”
When a piece of code tries to do read and write operation in a read only location in memory or freed block of memory, it is known as
core dump.It is an error indicating memory corruption.
***
