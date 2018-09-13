#include <stdio.h>
#include "fcfs.c"
#include "sjf.c"
#include "roundrobin.c"
#include "priority.c"

void main() {
  printf("<Menu\n" );
  printf("1. FCFS\n" );
  printf("2. SJF\n" );
  printf("3. Round Robin\n" );
  printf("4. Priority Scheduling\n" );
  printf("5. Exit\n");
  printf("\n\n\tCHOOSE : ");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1: fcfs();break;
    case 2: sjf();break;
    case 3: roundRobin();break;
    case 4: priority();break;
    case 5: break;
    default: printf("Invalid choice");break;
  }
  if (choice != 5) {
    printf("Do you want to restart (y/Y)" );
    char opt;
    scanf("%s", &opt);
    if(opt == 'y' || opt == 'Y'){
      main();
    }
  }
}
