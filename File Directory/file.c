#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "single.c"
#include "double.c"
#include "hierach.c"

void main() {

  printf("File Directory Structures\n" );
  printf(" 1. Single Level \n");
  printf(" 2. Two Level \n");
  printf(" 3. Hierarichal\n");
  printf(" 0. Exit\n");
  printf("\t Choose :");
  int opt;
  scanf("%d", &opt);
  system("clear");

  switch (opt) {
    case 1: single();break;
    case 2: two();break;
    case 3: hierarichal();break;
    case 0: exit(0);
    default: printf("Invalid option!! TRY AGAIN\n" );main();break;

  }

}
