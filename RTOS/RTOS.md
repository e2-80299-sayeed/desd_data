##Characteristics of RTOS
Consistentency
Reliability
Predictability


* Types of real time operating system:-
    * Hard real time OS
    * Soft real time OS
    * Firm real time OS

##Hard realtime OS
If interrupt/tasks deadline miss -- catastrophic effect.
Usually doesn't have secondary storage.
Timing: 10 to 100 "usec"
E.g. uC-OS, FreeRTOS, Xenomai, RTAI, ...

##Soft realtime OS
Less time critical - If deadline miss, affect product quality (not catastrophic).
May have secondary storage
Timing: 1 ms to 10 ms
E.g. Linux (PREEMP_RT), ...

##Firm realtime OS
Like hard realtime.
Rare miss of deadline is acceptable (not catastrophic).

##Functions of RTOS
Task Management
Scheduling
Resource Allocation
Interrupt Handling

* Difference between general purpose OS and real time OS:-
#1.customization support:
    * GPOS :GPOS have little or no customizations support(exception : Linux).
    * RTOS :RTOS have full customization support.
#2.Interrupt latencies:
    * GPOS :GPOS have higher interrupt latencies in msec 
    * RTOS :RTOS handle interrupt in deterministic time in usec.
#3.IPC latencies:
    * GPOS :GPOS can have higher IPC latencies.
    * RTOS :RTOS have deterministic time IPC latency.
   	
    * GPOS :In GPOS for IPC buffres allocated at run time means dynamically.
    *In RTOS, IPC buffers are preallocated (system heap).
    
    * GPOS :In GPOS signal handle is not in real time.
    * RTOS :In RTOS signal handle in real time.
    
    * GPOS :In GPOS awakening task is not in real time. 
    * RTOS :In RTOS task awakening is in real time.
   	
#4.cpu arch.:
    * GPOS :GPOS have support for all most every architecture. 
    * RTOS :RTOS have not support for all architecture. RTOS have limited support for CPU architecture.
    
#5.memory 
    * GPOS :GPOS required more memmory space, because processes and threads in GPOS is heavy-wieght.
    * RTOS :RTOS required less memmory space beacuse task in RTOS is light-wieght.
    
#6.Interrupt Management:
     *In GPOS, interrupts are processed in two steps i.e. top half and bottom half to ensure minimal interrupt latency.
     *In RTOS, ISRs are minimal & non-blocking. Also interrpt handlers are executed as highest priority tasks, so that they will be executed before any other task.
     
#7.IO Subsystem & Device Drivers:
     *In GPOS, drivers have higher latencies, because they deal with rest of the OS through multiple layers.
     *In RTOS, drivers and tasks are present in same address space (i.e. kernel space), so that minimal latecies are ensured.
     
#8.Task Management:
*In GPOS, processes & threads are heavy-weight i.e. have higher memory requirements.
*The RTOS tasks are light-weight i.e. with minimum memory requirements.

##CPU scheduling criterias:
1.Cpu utilization: should be max.
2.throughput: (amt of workdone in unit time)should be max
3.waiting time:(total time spent by process in ready queue) should be minimum
4.Response time: ideally: minimum(arrival time of process into ready queue upto 1st time scheduled)
5.Turn around time: (total time of process spent into memory/time from creation to termination) 

TAT=cpu waiting time+IO waiting time + IO burst+ cpu burst.


* Types of Scheduling :-
    1. non-Preemptive scheduling/Co-operative scheduling: 
        * In non-preemptive scheduling algorithm process leaves cpu voluntary(i.e process go  for IO, terminated, yield).
        * yield() function give up CPU by itself.
    
    2. Preemptive scheduling: 
        * In preemptive scheduling algorithm process can leave cpu voluntary or forcefully(because of completed time quntum/slice or high priority process).
         
* NOTE :-
    * Waiting time: Time spend by process in ready queue to get cpu for execution called waiting time.

    * Response time: Time when first time process get chance to access cpu for execution.

    * Turn around time: The total time form arrival of the process till execution completed the process.
    turn around time = cpu burst time + IO burst time + IO waiting time + (cpu)waiting time.

* Scheduling Algorithm:-
    1. FCFS
        * first come first serve
        * Non-preemptive algorithm.
        * Problem of FCFS scheduling algorithm is convoy effect.
        * convoy effect: Because of large process other process slow down to get cpu for execution. 
    		##Convoy Effect: Larger processes slow down execution of other processes, in FCFS.
    
    2. SJF(shortest job first) : non-preemptive algo.
    
    3. SRJF(shortest remaining job first): same as SJF with preemption.

    4. Priority :
        * In this scheduling algorithm starvation can happen because of high priority process.
        * Solution of starvation is aging : Low priority task increase priority of that process at run time. 
    
    5. Round robin : time Quantum is given to every process to minimize response time of processes.
    
    6. Fair share:
        * nice value of a process you can change using command nice or renice. nice command internally call nice() system call.
            >>nice -n 12 ./demo.out
            >>renice -n 12 -p <pid no>
            >>sudo nice -n -12 ./demo.out
            >>sudo renice -n -12 -p <pid no>

* NOTE :-
    * Interrupt latency: Time from arrival of interrupt to call of ISR(or begin execution of ISR).

    * Scheduler latency: Time from completion of ISR execution to begin execution of scheduler.
   
    * Depends on house-keeping work done by system after ISR call.

* Preemptible and Non-preemptible kernel
    * Pre-emptible kernel
        * User space and kernel space preemption of process is supported.
        * Better responsiveness
        * Real time systems
    * Non Pre-emptible kernel
        * User space preemption of process is supported.
        * Better throughput
        * Server systems and heavy computations.

* Completely fair share scheduling algorithm:-
		REFER SLIDES also.
##nice value:
In Linux, processes with time-sharing (TS) class have nice value. Range is -20 (highest priority) to +19 (lowest priority).
**non-real-time priorities:-20 to +19 mapped to 100 to 139
**real-time priorities: 0 to 99
**more NV lesser cpu time
**less NV more cpu time
    
    * weight
    * decay factor (df):Wo/Wi
       1. N=0, df=1 (where N is nice value)
       2. N>0, df>1
       3. N<0, df<1
				* virtual runtime = df*actual runtime       

    * weight of nice value is precalculated to avoid runtime overhead.
        nice value = 0: weight0 = 1024
        nice value = 5: weight5 = 335

    * factor = weight(0) / weight(i)
    * Formula to calculate time share of task:
        TS(i) = (W(i) / summation of all W(i)) * Target latency(epoch).
    * Formula to calculate virtual time:
        vruntime = decay factor * actual runtime.
Interrupt Latency:
1. ARM 7: 24-30 cpu cycles
2. ARM CM: 12 cpu cycles

* Linux scheduling:-
    * O(n) scheduler:
        * Developed by Linus Torvalds, based on UNIX scheduling algo.
        * It go through all processes to pick up next process for the execution.
								*The time complexity for scheduler is O(n).
        * Linked list of processes is called run queue.

    * O(1) scheduler:
        * Developed by INGO MOLAR for real-time behaviour.
        * Created to run queue
            1. Active run queue(array)
            2. Expired run queue(array)
        * Array indices is priority of processes.
        * 0 to 99 priority number for real time task.
        * 100 to 139 priority number for other task(user task).
        
##CFS scheduler
	*introduced in linux kernel 2.6.24 for fair amt of cpu time 
	*internally used (Red black)RB tree, arrangement of process based on vruntime
	*time complexity to pickup process is O(log n).
			  			
    * Linux scheduling have two policies:
        1. real time policy
            SCHED_RR(Roun Robin)
            SCHED_FIFO(FCFS)
        2. Non real time policy
            1.SCHED_OTHER(default scheduling policy of linux for non-real time sched class).
            2.SCHED_BATCH
            3.SCHED_IDLE
(These three are comes under Completely Fair (Time sharing) scheduling)


##linux data structure:
kernel maintain list of all runnable taskes in runqueue ds.
runqueue types:
1. active array: contain all taskes with time remaining in their time slices
2. expired array: contains all expired time slice tasks.
**when there is no  process in active array then active array  becomes expired and expired array becomes active.

* Changing processes classes and priority:
    * we use chrt command(internally sched_setscheduler() syscall) to change class and priority of process.
        >>sudo chrt -o 120 ./a.out(SCHED_OTHER)
        >>sudo chrt -r 30 ./a.out (SCHED_RR)
        >>sudo chrt -f 20 ./a.out (SCHED_FIFO)
        
##To change sched class/priority of current process use sched_setscheduler() or sched_setparam().

##Task states
1. Suspended:
*infinite blk
*task will suspend only when vTaskSuspend() called.
*task will resume only if vTaskResume() called.
2. Ready:
*if task is waiting to get cpu time
3. Blocked:task will blk if :
*IO/event request
*synchronisation
*ITC-queue
*blocking code like DelayUntil()
*xSemaphoreTake()
*xQueueReceive()

##task creation
1. xTaskCreate():
    1. return pdTRUE: if successful
    2. errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY: not created cuz of insufficient heap memory

2. vTaskPrioritySet():change the priority of any task
    1. return currently assigned priority to task being created

3. vTaskDelete():delete itself or any other task

4. xTaskResumeAll():
   1. return pdTRUE: if successful
   2. return pdFALSE: if failed

NOTE : x --> return type is xTaskHandle.
       v --> return type is void.
    
##The idle task is created automatically when vTaskStartScheduler() is called


##Blocking API functions:
*vTaskDelay()
*vT
* Interrupt handling in RTOS
    * keep ISR code minimal.
    * In ISR never blocking code.

* Synchronization:
    1. Critical section:if multiple prcesses execute critical section concurrently then result will be wrong
        portENTER_CRITICAL()
        //----
        portEXIT_CRITICAL()

    2. Semaphore
        a. Event/Flag (s = 0)(like conditional variable semaphore)
        b. Binary semaphore(s = 1)
        c. Counting semaphore(s = n)

##Semaphore:
1. vSemaphoreCreateBinary():

2. xSemaphoreTake():equivalent to a P() operation.
    1. return pdTRUE: if successful
    2. return pdFALSE: if failed
    
3. xSemaphoreGiveFromISR():is a special form of xSemaphoreGive() specifically for use within an interrupt service routine.
    1. return pdTRUE: if successful
    2. return pdFALSE: failed if already available

##counting semaphore:
1. xSemaphoreCreateCounting(): 
    1. return NULL: if failed
    2. non-zero : if successfull
    
    
##Queue:
*xQueueCreate(): create a queue and returns an xQueueHandle 
   1. return NULL if failed
   2. return non-zero if successfull
*xQueueSendToBack()/xQueueSendToFront()//xQueueSendToBackFromISR() and xQueueReceiveFromISR():
   1. return pdPASS: if successful data sent
   2. return errQUEUE_FULL: if failed
*xQueueReceive():receive (read) an item from a queue. The item that is received is removed from the queue.
   1. return pdPASS: if successfully read
   2. return errQUEUE_EMPTY : if data reading failed
*xQueuePeek():receive an item from a queue without the item being removed from the queue.
*xQueueMessagesWaiting():
   1. return no. of items in queue
   2. return 0 if queue is empty


##Memory Management
1. xPortGetFreeHeapSize():
*Return The number of bytes that remain unallocated in the heap.
* NOTE:-
    * Gate keeper task: Only one task can perform all operations of that peripheral called Gate keeper task.

* Types of Scheduling algo in RTOS:-
    1. RMS(Rate monotic scheduling)
        * High priority assign to task with least period .
        * All formula:
            Hyper period = LCM(period1, period2,...)
            CPU utilization = (cpu burst(p0) / period(p0)) + (cpu burst(p1) / period(p1)) +.....
            Max CPU utilization = n*(2^(1/n) - 1)   here n is number of process.
        *if cpu utilization > max cpu utilization then task are not schedulable (liu & layland Test)

    2. DMS(Deadline monotic scheduling)
        * High periority assign by least deadline of task.
        * Similar as RMS scheduling.

    3. EDF(Earliest deadline first)
        * Priority decide at run time. First deadline process get first chance.

    4. LSTF(Least slack time first)
        * Slack time calculated after every unit time.
        * slack time is less priority is high.

    * Types of test in RTOS scheduling:
        1. Liu and Layland test: If CPU utilization > Max CPU utilization then task is not scheduable.
        
        2. Liu and Lehoczky test: 
            According to Liu layland test if task is not scheduable try again at least one to schedule in hyper period(lcm of periof of all process ). If in first hyper period task scheduable then your task is scheduable.

* Priority Inversion :
    High priority task need to wait for execution cuz of low priority task is executing

* Solution for Priority inversion is Priority inheritance/Priority ceiling:
    In priority inheritance we change the priority of task(inherit high priority from high priority task in low priority task) at run time. This is responsiblity of synchronization mechanism because this problem occur because of mutex or semaphore.
