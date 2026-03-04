#include <stdio.h>

struct process
{
    char pid[10];
    int at, bt, pr;
    int ct, wt, tat;
    int done;
};

int main()
{
    int n, i, time = 0, completed = 0, idx;
    float avg_wt = 0, avg_tat = 0;

    struct process p[20];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].done = 0;
    }

   ....
     ...
     ...
     ...
     ..
     ..
     ...
     ..
     .
    printf("Average Waiting Time: %.2f\n", avg_wt / n);
    printf("Average Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}
