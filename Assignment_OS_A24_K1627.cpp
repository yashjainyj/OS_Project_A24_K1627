#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
int main()
{
    int at[100],bt[100],rt[100],endTime,i,pid;
    int remain=0,n,time,sum_wait=0,sum_turnaround=0;
    printf("Enter no of Processes : ");
    scanf("\n\n%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for  P%d Process  : ",i+1);
        scanf("%d",&at[i]);
        printf("Enter burst time for P%d Process  : ",i+1);
        scanf("%d",&bt[i]);
        if (at[i]==0)
    	{
    		printf("\n!!!!!!!!!!!!!! Arrival Time is Zero !!!!!!!!!!!!!!  \n\n");
    		continue;
		}
		rt[i]=bt[i];
    
	}
    printf("\n\nProcess\t| Arrival Time | Burst Time(BT) | Completion Time|TurnAround Time| Waiting time\n\n"); 
    printf("     P  |    (AT)      |     (BT)       |       (CT)     |   (CT - AT)   |   (TAT - BT)\n\n");
    rt[99]=9999;
    for(time=0;remain!=n;time++)
    {
        pid=99;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]<rt[pid] && rt[i]>0)
            {
                pid=i;
            }
        }
        rt[pid]--;
        if(rt[pid]==0)
        {
            remain++;
            endTime=time+1;
            printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",pid+1,at[pid],bt[pid],endTime,endTime-at[pid],endTime-bt[pid]-at[pid]);
            Sleep(2000);
	        sum_wait+=endTime-bt[pid]-at[pid];
            sum_turnaround+=endTime-at[pid];
        }
    }
    printf("\n\n %f is Average Turn around Time (TaT) ",sum_turnaround*1.0/5);
    printf("\n\n %f is Average Waiting Time (WT)",sum_wait*1.0/n);
    return 0;
}

