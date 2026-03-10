#include <stdio.h>

struct process{
    char pid[10];
    int at, bt, pr;
    int rt;
    int ct, tat, wt;
};

int main()
{
    int n,time=0,completed=0;
    float avg_wt=0,avg_tat=0;

    struct process p[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d %d",p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].rt=p[i].bt;
    }

    while(completed<n)
    {
        int idx=-1;

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].rt>0)
            {
                if(idx==-1 || p[i].pr < p[idx].pr)
                    idx=i;
            }
        }

        if(idx==-1)
        {
            time++;
            continue;
        }

        p[idx].rt--;
        time++;

        if(p[idx].rt==0)
        {
            completed++;

            p[idx].ct=time;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;

            avg_wt+=p[idx].wt;
            avg_tat+=p[idx].tat;
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%s %d %d %d %d %d %d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,
        p[i].ct,p[i].tat,p[i].wt);
    }

    printf("Average Waiting Time: %.2f\n",avg_wt/n);
    printf("Average Turnaround Time: %.2f\n",avg_tat/n);

    return 0;
}
