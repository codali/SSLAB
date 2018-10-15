#include <stdlib.h>
#include <string.h>
void linked() {

  struct block {
    char fname[15];
    struct block *next;
  }*startBlock[10];
  struct block *ptr,*temp;
  int fileNum=0,nb[10];
  char name[15];

  printf("Enter the number of files : ");
  scanf("%d",&fileNum);
  int i,j;
  for (i = 0; i < fileNum; i++) {
    printf("Block numbers (File %d) : ",i);
    scanf("%d",&nb[i]);
    printf("File Name of File (%d) : ",i);
    char name[15];
    scanf("%s",name);
    ptr = (struct block*) malloc (sizeof(struct block));
    startBlock[i] = ptr;
    strcpy(ptr -> fname, name);
    for(j=1;j < nb[i]; j++) {
      temp = (struct block*) malloc (sizeof(struct block));
      ptr -> next = temp;
      ptr = ptr -> next;
      strcpy(ptr -> fname, name);
    }
    ptr -> next = NULL;
  }
  printf("FNAME\tBlock Count\tAlloted Blocks\n");
  for (i = 0; i < fileNum; i++) {
    ptr = startBlock[i];
    printf("%s\t%d\t", ptr -> fname, nb[i]);
    while (ptr != NULL) {
      printf("%p",ptr);
      if(ptr -> next != NULL)
        printf(" --> ");
      ptr = ptr -> next;
    }
    printf("\n");
  }
}
