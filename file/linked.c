void linked() {
  struct block {
    char fname[15];
    struct block *next;
  }*blocks[10];
  int fileNum=0,nb[10];
  printf("Enter the number of files : ");
  scanf("%d",&fileNum);
  int i;
  for (i = 0; i < fileNum; i++) {
    printf("Block numbers : ");
    scanf("%d",&nb[i]);
  }
}
