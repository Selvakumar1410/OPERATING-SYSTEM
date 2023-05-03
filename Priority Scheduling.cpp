;l''#include <stdio.h>

// Structure to store process details
struct process {
    int pid;    // process ID
    int bt;     // burst time
    int wt;     // waiting time
    int tat;    // turnaround time
    int ct;     // completion time
    int priority; // priority of the process
};

int main() {
    int n, i, j;
    float avgwt = 0, avgtat = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct process p[n], temp;
    
    // Input process details
    for (i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i+1);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        p[i].pid = i+1;
        p[i].wt = p[i].tat = p[i].ct = 0;
    }
    
    // Sort processes in descending order of priority
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (p[j].priority < p[j+1].priority) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    
    // Calculate waiting time, turnaround time, and completion time
    for (i = 0; i < n; i++) {
        if (i == 0) {
            p[i].ct = p[i].bt;
        } else {
            p[i].ct = p[i-1].ct + p[i].bt;
        }
        p[i].tat = p[i].ct;
        p[i].wt = p[i].tat - p[i].bt;
        
        // Calculate average waiting time and turnaround time
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }
    
    avgwt /= n;
    avgtat /= n;
    
    // Display process details and average waiting time and turnaround time
    printf("\nPriority Scheduling Algorithm\n");
    printf("--------------------------------------------------------\n");
    printf("Process\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    printf("--------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("--------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtat);
    
    return 0;
}
