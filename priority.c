#include <stdio.h>

struct process{
    char pid[10];
    int at, bt, pr;
    int rem;
    int ct, wt, tat;
};

int main()
{
    int n, time=0, completed=0, idx;
    float avg_wt=0, avg_tat=0;

    struct process p[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s %d %d %d",p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].rem = p[i].bt;
    }

    while(completed<n)
    {
        idx = -1;

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].rem>0)
            {
                if(idx==-1 || p[i].pr < p[idx].pr)
                    idx=i;
            }
        }

        if(idx!=-1)
        {
            p[idx].rem--;
            time++;

            if(p[idx].rem==0)
            {
                completed++;
                p[idx].ct=time;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;

                avg_wt+=p[idx].wt;
                avg_tat+=p[idx].tat;
            }
        }
        else
        {
            time++;
        }
    }

    printf("Average Waiting Time: %.2f\n",avg_wt/n);
    printf("Average Turnaround Time: %.2f\n",avg_tat/n);

    return 0;
}
