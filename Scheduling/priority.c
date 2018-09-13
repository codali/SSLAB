void priority() {
  int prcscount,bt[10][2],i,p[10],temp,temp2,t,ta,wt[10],tat[10],j;
  float avg1,avg2;
  printf("Enter number of processes : ");
  scanf("%d",&prcscount);
  printf("Enter the burst times \n");
  for(i=0;i<prcscount;i++) {
    printf("Burst time of P(%d) : ",i);
    scanf("%d",&bt[i][0]);
    printf("Priority of P(%d) : ",i);
    scanf("%d",&bt[i][1]);
  }
  for(i=0;i<prcscount;i++)
      p[i]=i+1;
  for(i=0;i<prcscount;i++)
  {
         for(j=0;j<prcscount-i-1;j++)
         {
              if(bt[j][1]>bt[j+1][1])
              {
              temp=bt[j][1];
              temp2=p[j];
              bt[j][1]=bt[j+1][1];
              p[j]=p[j+1];
              bt[j+1][1]=temp;
              p[j+1]=temp2;
              }
          }
  }
  wt[0]=0;
  t=0;
  for(i=1;i<prcscount;i++)
  {
          wt[i]=wt[i-1]+bt[i-1][0];
          t=t+wt[i];
  }
  ta =0;
  for(i=0;i<prcscount;i++)
  {
          tat[i]=wt[i]+bt[i][0];
          ta=ta+tat[i];
  }
  avg1=(float)t/prcscount;
  avg2=(float)ta/prcscount;
  printf("Process\tPriorityBt\tWT\tTAT\n");
  for(i=0;i<prcscount;i++)
  {
          printf("%d\t%d\t%d\t%d\t%d\n",p[i],bt[i][0],bt[i][1],wt[i],tat[i]);
  }
  printf("Average waiting time = %f\n",avg1);
  printf("Average TAT = %f\n",avg2);
}
