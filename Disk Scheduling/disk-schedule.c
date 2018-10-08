#include <stdio.h>
#include <stdlib.h>

int queue[100],head,seek = 0,n,i;
void sort() {
  int i, j, temp;
  for( i = 1 ; i < size ;i ++ ) {
    for(j =1 ; j < size -1 ; j++ ){
      if( queue[j] < queue[j - 1]) {
        temp = queue[j];
        queue[j] = queue[j - 1];
        queue[j -1] = temp;
      }
    }
  }
}
void main() {
  printf("Enter the queue count : ");
  scanf("%d",&n);
  printf("Enter the queue elements\n");
  for(i = 1 ;  i <= n  ; i++) {
    scanf("%d",&queue[i]);
  }
  printf("Enter the head position :");
  scanf("%d",&head);
  queue[0] = head;
  printf("\n 1. FCFS\n" );
  printf(" 2. Scan\n" );
  printf(" 3. C - Scan\n" );
  int opt;
  scanf("%d",&opt);
  int diff;
  switch(opt) {
    case 1:
      for( i = 0 ; i <= n - 1 ; i++ ) {
        diff = abs( queue [i + 1] - queue [i]);
        seek += diff;
        printf("Seeking from %d to %d takes %d time\n",queue[i],queue[i+1],diff);
      }
      printf("Average seek time is %f \n", (float) seek / n);
      break;

    case 2:

  }
}
