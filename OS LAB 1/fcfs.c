#include<stdio.h>

struct schedule {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;   // Response Time
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct schedule processes[n];  // dynamic array

    for(int i=0;i<n;i++) {
        printf("Process %d: \n",(i+1));
        printf("Enter PID: ");
        scanf("%d",&processes[i].pid);
        printf("Enter AT: ");
        scanf("%d",&processes[i].at);
        printf("Enter BT: ");
        scanf("%d",&processes[i].bt);
    }

    // Sort by Arrival Time
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(processes[i].at > processes[j].at){
                struct schedule temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int time = 0;
    for(int i=0;i<n;i++){
        if(time < processes[i].at)
            time = processes[i].at;

        int start_time = time;  // when process actually starts
        time = time + processes[i].bt;

        processes[i].ct = time;
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        processes[i].rt = start_time - processes[i].at;  // Response Time
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        processes[i].pid,
        processes[i].at,
        processes[i].bt,
        processes[i].ct,
        processes[i].tat,
        processes[i].wt,
        processes[i].rt);
    }

    return 0;
}