#include <stdio.h>
#include "linked.c"
#include "indexed.c"
#include "sequential.c"
void main() {

  printf("FILE ALLOCATION\n");
  printf("1. Sequential\n");
  printf("2. Linked List\n");
  printf("3. Indexed\n");
  printf("0. Exit\n");

  int opt;
  printf("\tChoose : ");
  scanf("%d",&opt);

  switch(opt) {
    case 1:sequential();break;
    case 2:linked();break;
    case 3:indexed();break;
    case 0: break;
    default : printf("Invalid");break;
  }

}
