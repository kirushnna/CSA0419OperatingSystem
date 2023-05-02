#include <stdio.h>
int main() 
{
    int burst_times[] = {6, 8, 7, 3};
    int n = sizeof(burst_times) / sizeof(int);
    int completion_times[n], waiting_times[n], turnaround_times[n];
    int i, j, min_index;
    for (i = 0; i < n; i++) 
	{
        min_index = i;
        for (j = i+1; j < n; j++)
		{
            if (burst_times[j] < burst_times[min_index]) 
			{
                min_index = j;
            }
        }
        int temp = burst_times[i];
        burst_times[i] = burst_times[min_index];
        burst_times[min_index] = temp;
    }
    completion_times[0] = burst_times[0];
    for (i = 1; i < n; i++) 
	{
        completion_times[i] = completion_times[i-1] + burst_times[i];
    }
    for (i = 0; i < n; i++) 
	{
        waiting_times[i] = completion_times[i] - burst_times[i];
    }
    for (i = 0; i < n; i++) 
	{
        turnaround_times[i] = waiting_times[i] + burst_times[i];
    }
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (i = 0; i < n; i++) 
	{
        avg_waiting_time += waiting_times[i];
        avg_turnaround_time += turnaround_times[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("Process\t Burst Time\t Completion Time\t Waiting Time\t Turnaround Time\n");
    for (i = 0; i < n; i++) 
	{
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_times[i], completion_times[i], waiting_times[i], turnaround_times[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    return 0;
}

