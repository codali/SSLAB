void fcfs()
{
        int i,n,bt[5],wt[5],tat[5];
        int t=0,ta=0;
        float avg1,avg2;
        printf("enter the number of process : ");
        scanf("%d",&n);
        printf("enter the burst times \n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&bt[i]);
        }
        wt[0]=0;
        for(i=1;i<n;i++)
        {
                wt[i]=wt[i-1]+bt[i-1];
                t=t+wt[i];
        }
        for(i=0;i<n;i++)
        {
                tat[i]=wt[i]+bt[i];
                ta=ta+tat[i];
        }
        avg1=(float)t/n;
        avg2=(float)ta/n;
        printf("Process\tBt\tWT\tTAT\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t%d\t%d\t%d\n",i,bt[i],wt[i],tat[i]);
        }
        printf("Average waiting time = %f\n",avg1);
        printf("Average TAT = %f\n",avg2);

 }
