#include <stdio.h>

void main()
{
	int process[10], allocation[10][3],max[10][3],need[10][3],avail[3],total[3];
	int finish[10], i;
	printf("Enter number of process :");
	int count = 0,j,ex;
	scanf("%d",&count);
	for (i = 0; i < count; ++i) 
		finish[i] = 0;
	for (i = 0; i < count; ++i) 
		for (j = 0; j < 3; ++j) 
			need[i][j] = 0;
	for (i = 0; i < count; ++i)
	{
		printf("Enter Allocatons (R1, R2, R3) :");
		scanf("%d %d %d",&allocation[i][0],&allocation[i][1],&allocation[i][2]);
		printf("Enter Max (R1, R2, R3) :");
		scanf("%d %d %d",&max[i][0],&max[i][1],&max[i][2]);
	}
	printf("Enter Current available (R1, R2, R3) :");
	scanf("%d %d %d",&avail[0],&avail[1],&avail[2]);
	total[0] = avail[0];
	total[1] = avail[1];
	total[2] = avail[2];
	for (i = 0; i < count; ++i) 
	{
		total[0] += allocation[i][0];
		total[1] += allocation[i][1];
		total[2] += allocation[i][2];
	}
	i = 0;
	printf("Execution order ");
	ex = 0;
	while(1) 
	{
		for (j = 0; j < 3; ++j) 
		{
			need[i][j] = max[i][j] - allocation[i][j];

		}
		if (need[i][0] <= avail[0] && need[i][1] <= avail[1] && need[i][2] <= avail[2] )
		{
			avail[0]= avail[0] + allocation[i][0];
			avail[1]= avail[1] + allocation[i][1];
			avail[2]= avail[2] + allocation[i][2];
			if(finish[i] != 1)
				printf("P%d,",i);
			finish[i] = 1;
			
		}
		for (int k = 0; k < count; k++) {
			if(finish[k] != 0)
				ex++;
			else 
				ex = 0;
		}
		if(ex == count )
			break;

		++i;
		if ( i == 4)
			i = 0;
	}
	printf("\n");
}


/// need[i][0] <= total[0] && need[i][1] <= total[1] && need[i][2] <= total[2]