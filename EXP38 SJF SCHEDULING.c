#include <stdio.h>
typedef struct 
{
    int processID;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
} Process;
void sjfScheduling(Process processes[], int numProcesses) 
{
    int i;
    for (i = 0; i < numProcesses - 1; i++) 
	{
    	int j;
        for (j = 0; j < numProcesses - i - 1; j++) 
		{
            if (processes[j].burstTime > processes[j + 1].burstTime) 
			{
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;
    for (i = 1; i < numProcesses; i++) 
	{
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}
float calculateAverageWaitingTime(Process processes[], int numProcesses) 
{
    int totalWaitingTime = 0;
    int i;
    for (i = 0; i < numProcesses; i++) 
	{
        totalWaitingTime += processes[i].waitingTime;
    }
    return (float)totalWaitingTime / numProcesses;
}
float calculateAverageTurnaroundTime(Process processes[], int numProcesses) 
{
    int totalTurnaroundTime = 0;
    int i;
    for (i = 0; i < numProcesses; i++) 
	{
        totalTurnaroundTime += processes[i].turnaroundTime;
    }
    return (float)totalTurnaroundTime / numProcesses;
}

int main() 
{
    Process processes[3];
    processes[0].processID = 0;
    processes[0].burstTime = 2;
    processes[0].arrivalTime = 0;
    processes[1].processID = 1;
    processes[1].burstTime = 4;
    processes[1].arrivalTime = 0;
    processes[2].processID = 2;
    processes[2].burstTime = 8;
    processes[2].arrivalTime = 0;

    int numProcesses = sizeof(processes) / sizeof(processes[0]);


    sjfScheduling(processes, numProcesses);
    float avgWaitingTime = calculateAverageWaitingTime(processes, numProcesses);
    float avgTurnaroundTime = calculateAverageTurnaroundTime(processes, numProcesses);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    int i;
    for (i = 0; i < numProcesses; i++) 
	{
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processID, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}


