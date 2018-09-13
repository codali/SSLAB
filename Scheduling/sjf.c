void sjf()
{
   int i,j,n,bt[5],wt[5],tat[5],p[5],t,ta,temp,temp2;
   float avg1,avg2;
   printf("enter the number of process : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
       p[i]=i+1;
   printf("enter the burst times \n");
   for(i=0;i<n;i++)
   {
           scanf("%d",&bt[i]);
   }
   for(i=0;i<n;i++)
   {
          for(j=0;j<n-i-1;j++)
          {
               if(bt[j]>bt[j+1])
               {
               temp=bt[j];
               temp2=p[j];
               bt[j]=bt[j+1];
               p[j]=p[j+1];
               bt[j+1]=temp;
               p[j+1]=temp2;
               }
           }
   }
    wt[0]=0;
    t= 0;
    for(i=1;i<n;i++)
    {
            wt[i]=wt[i-1]+bt[i-1];
            t=t+wt[i];
    }
    ta =0;
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
            printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Average waiting time = %f\n",avg1);
    printf("Average TAT = %f\n",avg2);

 }
